#include "TxConsultaCompres.h"
#include "CercadoraUsuari.h"
#include "TxConsultaVideojoc.h"
#include "Videoconsola.h"
#include "PassarellaUsuari.h"
#include "CercadoraCompres.h"
#include "PassarellaCompra.h"
#include "CercadoraElemCompra.h"
#include "PassarellaElemCompra.h"
#include "CercadoraConte.h"
#include "PassarellaConte.h"

// Constructor
TxConsultaCompres::TxConsultaCompres() {

	Videoconsola& v = Videoconsola::getInstance();
	PassarellaUsuari u = v.obteUsuari();
	string sobrenomU = u.obteSobrenom();
	CercadoraCompres cercadoraCompres;
	pqxx::result compresU = cercadoraCompres.cercarCompres(sobrenomU);
	total = 0;
	for (size_t i = 0; i < compresU.size() ; ++i) {
		PassarellaCompra c = PassarellaCompra(compresU[i]["usuari"].c_str(), compresU[i]["element"].c_str(), compresU[i]["data"].c_str(), compresU[i]["preu_pagat"].as<float>());
		CercadoraElemCompra cercElm;
		pqxx::result Elmcercat = cercElm.cercaElement(c.obteElementCompra());
		PassarellaElemCompra elemCompra(Elmcercat);
		if (elemCompra.obteTipus() == "videojoc") {
			Paquet ec;
			ec.data = c.obteData();
			ec.nom = elemCompra.obteNom();
			ec.preu = elemCompra.obtePreu();
			ec.descripcio = elemCompra.obteDescripcio();
			videojocs.push_back(ec);
		
		}
		else if (elemCompra.obteTipus() == "paquet") {
			Paquet paquet;
			paquet.data = c.obteData();
			paquet.nom = elemCompra.obteNom();
			paquet.preu = elemCompra.obtePreu();
			paquet.descripcio = elemCompra.obteDescripcio();
			CercadoraConte cercadoraconte;
			pqxx::result conteCercat = cercadoraconte.cercaContePaquet(paquet.nom);
			PassarellaConte passarellaConte(conteCercat);
			pqxx::result videojocs = passarellaConte.totsVideojocs(paquet.nom);
			vector<Paquet>aux;
			for (size_t j = 0; j < videojocs.size(); ++j) {
				Paquet videojoc;
				CercadoraElemCompra cercadoraelem;
				pqxx::result vj =cercadoraelem.cercaElement(videojocs[j]["videojoc"].c_str());
				PassarellaElemCompra pselem(vj);
				videojoc.descripcio = pselem.obteDescripcio();
				videojoc.preu = pselem.obtePreu();
				videojoc.nom = pselem.obteNom();
				aux.push_back(videojoc);
			}
			paquet.videojocs = aux;
			paquets.push_back(paquet);
			
		}
		total += elemCompra.obtePreu();
	}
}




std::vector<TxConsultaCompres::Paquet> TxConsultaCompres::obteTotsElem() {
    // Combina los vectores videojocs y paquets en un solo vector
    std::vector<TxConsultaCompres::Paquet> todosLosElementos;
    todosLosElementos.insert(todosLosElementos.end(), videojocs.begin(), videojocs.end());
	todosLosElementos.insert(todosLosElementos.end(), paquets.begin(), paquets.end());


    // Ordena el vector por fecha
    std::sort(todosLosElementos.begin(), todosLosElementos.end(),
              [](const Paquet& a, const Paquet& b) {
                  return a.data > b.data;
              });

    return todosLosElementos;
}

int TxConsultaCompres::obtepreu()
{
	return total;
}
