#include "TxConsultarPaquet.h"
#include "CercadoraPaquet.h"
#include <iostream>
#include "Videoconsola.h"
#include "PassarellaUsuari.h"
#include "CercadoraCompres.h"
#include "PassarellaCompra.h"
#include "CercadoraElemCompra.h"
#include "PassarellaElemCompra.h"
#include "CercadoraConte.h"
#include "PassarellaConte.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <algorithm>

using namespace std;
// Constructor
bool TxConsultarPaquet::compararPorNombre(const TxConsultarPaquet::Resultat& a, const  TxConsultarPaquet::Resultat& b) {
    return a.nom < b.nom;
}
TxConsultarPaquet::TxConsultarPaquet(std::string nomPaquet) {
    CercadoraPaquet cercadoraPaquet;
    pqxx::result paquetResult = cercadoraPaquet.cercaPaquet(nomPaquet);

    if (paquetResult.empty()) {
        throw exception("El paquet no existeix");
    }
    else {
        CercadoraElemCompra cercadoraElemCompra;
        pqxx::result elemCompra = cercadoraElemCompra.cercaElement(nomPaquet);
        PassarellaElemCompra pelemCompra(elemCompra);

        resultat.descripcio = pelemCompra.obteDescripcio();
        resultat.nom = pelemCompra.obteNom();
        resultat.preu = pelemCompra.obtePreu();

        CercadoraConte cercadoraConte;
        pqxx::result conte = cercadoraConte.cercaContePaquet(nomPaquet);
        PassarellaConte passarellaconte(conte);
        pqxx::result videojuegosdepaquet = passarellaconte.totsVideojocs(nomPaquet);
        int preuSeparats = 0;
        for (size_t i = 0; i < videojuegosdepaquet.size(); ++i) {

            string nomV = videojuegosdepaquet[i]["videojoc"].c_str();
            CercadoraElemCompra cercadoraElemCompra;
            PassarellaElemCompra elementCompra = cercadoraElemCompra.cercaElement(nomV);
            Resultat aux;
            aux.preu = elementCompra.obtePreu();
            aux.descripcio = elementCompra.obteDescripcio();
            aux.nom = elementCompra.obteNom();
            preuSeparats += elementCompra.obtePreu();
            jocs_continguts.push_back(aux);
        }
        estalvi = preuSeparats - resultat.preu;
    }

}


TxConsultarPaquet::Resultat TxConsultarPaquet::obteInfoPaquet() const {
    return resultat;
}

std::vector<TxConsultarPaquet::Resultat> TxConsultarPaquet::obteJocsContinguts() {
    sort(jocs_continguts.begin(), jocs_continguts.end(), compararPorNombre);
    return jocs_continguts;
}

int TxConsultarPaquet::obteEstalvi() const {
    return estalvi;
}
