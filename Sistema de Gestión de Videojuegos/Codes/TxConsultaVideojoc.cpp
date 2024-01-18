#include "TxConsultaVideojoc.h"
#include "CercadoraVideojoc.h"
#include "PassarellaVideojoc.h"
#include "CercadoraElemCompra.h"
#include "PassarellaElemCompra.h"
#include "CercadoraConte.h"
#include "PassarellaConte.h"
using namespace std;
#include <iostream>
#include <vector>
TxConsultaVideojoc::TxConsultaVideojoc(const std::string& nomVideojoc) {
	CercadoraVideojoc cercadoraVideojoc;

	pqxx::result videojoc = cercadoraVideojoc.cercaVideojoc(nomVideojoc);
	if (videojoc.empty()){
		throw exception("El videojoc no existeix");
	}
	else {
		PassarellaVideojoc pvideojoc(videojoc);
		resultat.nomVideojoc = pvideojoc.obteNom();
		resultat.qualificacio = pvideojoc.obteQualificacioEdat();
		resultat.dataLlansament = pvideojoc.obteDataLlansament();
		resultat.genere = pvideojoc.obteGenere();
		CercadoraElemCompra cercadoraelemCompra;
		pqxx::result ec = cercadoraelemCompra.cercaElement(nomVideojoc);
		PassarellaElemCompra passarellaElemCompra(ec);
		resultat.descripcio = passarellaElemCompra.obteDescripcio();
		resultat.preu = passarellaElemCompra.obtePreu();
		CercadoraConte cercadoraConte;
		pqxx::result contecercat = cercadoraConte.cercaConteVideojoc(nomVideojoc);
		PassarellaConte passarellaConte(contecercat);
		pqxx::result paquets = passarellaConte.totsPaquets(nomVideojoc);
		for(int i=0;i<paquets.size();++i){
			paquets_.push_back(paquets[i]["paquet"].c_str());
			 }
	}




}
vector<string> TxConsultaVideojoc::obtePaquets()const
{
	return paquets_;
}
TxConsultaVideojoc TxConsultaVideojoc::crear(const std::string& nomVideojoc)
{
	return TxConsultaVideojoc(nomVideojoc);
}

void TxConsultaVideojoc::executar()
{
}

TxConsultaVideojoc::Resultat TxConsultaVideojoc::obteResultat() const
{
	return resultat;
}
