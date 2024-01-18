#include "TxComprarVideojoc.h"
#include "CercadoraVideojoc.h"
#include "Videoconsola.h"
#include "CercadoraCompres.h"
#include "PassarellaCompra.h"
#include <chrono>
#include <ctime>
#include "CercadoraElemCompra.h"
#include "PassarellaElemCompra.h"
#include <iomanip>
#include "CercadoraConte.h"
#include "PassarellaConte.h"
#include "CercadoraPaquet.h"
#include <algorithm>
bool TxComprarVideojoc::compararPorNombre(const PassarellaElemCompra& a, const PassarellaElemCompra& b) {
	return a.obteNom() < b.obteNom();
}
TxComprarVideojoc::TxComprarVideojoc(string nomVideojoc)
{
	CercadoraVideojoc cercadoraVideojoc;

	pqxx::result videojoc = cercadoraVideojoc.cercaVideojoc(nomVideojoc);
	PassarellaVideojoc pvideojoc(videojoc);
	Videoconsola& v = Videoconsola::getInstance();
	PassarellaUsuari u = v.obteUsuari();
	string sobrenomU = u.obteSobrenom();
	CercadoraCompres cercadoraCompres;
	pqxx::result compresU = cercadoraCompres.cercarCompres(sobrenomU);
	bool exit = false;
	for (size_t i = 0; i < compresU.size() and !exit; ++i) {
		PassarellaCompra c = PassarellaCompra(compresU[i]["usuari"].c_str(), compresU[i]["element"].c_str(), compresU[i]["data"].c_str(), compresU[i]["preu_pagat"].as<float>());
		if (c.obteElementCompra() == nomVideojoc) {
			exit = true;
			throw exception("Ja tens comprat el Videojoc!!");
		}
	}
	string edatU = u.obteDataNaixament();
	std::tm tm = {};
	std::istringstream iss(edatU);
	iss >> std::get_time(&tm, "%Y/%m/%d");
	auto birth_time = std::chrono::system_clock::from_time_t(std::mktime(&tm));
	auto now = std::chrono::system_clock::now();
	auto age = std::chrono::duration_cast<std::chrono::years>(now - birth_time);

	int edadUsuario = static_cast<int>(age.count());
	int qualificacioV = pvideojoc.obteQualificacioEdat();
	
	if (edadUsuario < qualificacioV) {
		throw exception("No tens la edad suficient per comprar el Videojoc");
	
	}
	auto now_time_t = std::chrono::system_clock::to_time_t(now);
	std::tm tm_now = {};
	localtime_s(&tm_now, &now_time_t);  
	std::ostringstream oss;
	oss << std::put_time(&tm_now, "%d/%m/%y %H:%M");
	std::string fecha_actual = oss.str();
	CercadoraElemCompra cercadoraElemCompra;
	pqxx::result elemCompra = cercadoraElemCompra.cercaElement(nomVideojoc);
	PassarellaElemCompra pelemCompra(elemCompra);
	PassarellaCompra pcompra(sobrenomU, nomVideojoc, fecha_actual, pelemCompra.obtePreu());
	pcompra.insereix();
	data = fecha_actual;

	
	CercadoraConte cercadoraConte;
	pqxx::result conte = cercadoraConte.cercaConteVideojoc(nomVideojoc);
	PassarellaConte passarellaconte(conte);
	
	string paquetnomVideo = passarellaconte.obtePaquet();
	pqxx::result videojuegosdepaquet = passarellaconte.totsVideojocs(paquetnomVideo);
	
	 
	for (size_t i = 0; i < videojuegosdepaquet.size(); ++i) {
		
		string nomV= videojuegosdepaquet[i]["videojoc"].c_str();
		if (nomV != nomVideojoc) {
			CercadoraElemCompra cercadoraElemCompra;
			PassarellaElemCompra elementCompra = cercadoraElemCompra.cercaElement(nomV);

			videojocs_relacionats.push_back(elementCompra);
		}
		
		
	}

}
std::string TxComprarVideojoc::obteData() const {
	return data;
}
std::vector<PassarellaElemCompra> TxComprarVideojoc::obteVideojocsRelacionats()  {
	std::sort(videojocs_relacionats.begin(), videojocs_relacionats.end(), compararPorNombre);
	return videojocs_relacionats;
}