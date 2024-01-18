#include "TxComprarPaquet.h"
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
bool TxComprarPaquet::compararPorNombre( const TxComprarPaquet::Resultat &a,const  TxComprarPaquet::Resultat & b) {
    return a.nom < b.nom;
}
TxComprarPaquet::TxComprarPaquet(std::string nomPaquet) {
    CercadoraPaquet cercadoraPaquet;
    pqxx::result paquetResult = cercadoraPaquet.cercaPaquet(nomPaquet);

    if (paquetResult.empty()) {
        throw exception("El paquet no existeix");
    }
    else {

        Videoconsola& v = Videoconsola::getInstance();
        PassarellaUsuari u = v.obteUsuari();
        string sobrenomU = u.obteSobrenom();
        CercadoraCompres cercadoraCompres;
        pqxx::result compresU = cercadoraCompres.cercarCompres(sobrenomU);
        bool exit = false;

        for (size_t i = 0; i < compresU.size() and !exit; ++i) {
            PassarellaCompra c = PassarellaCompra(compresU[i]["usuari"].c_str(), compresU[i]["element"].c_str(), compresU[i]["data"].c_str(), compresU[i]["preu_pagat"].as<float>());
            if (c.obteElementCompra() == nomPaquet) {
                exit = true;
                throw exception("Ja tens comprat el paquet!!");
            }
        }
      
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
void TxComprarPaquet::Comprar() {
    auto now = std::chrono::system_clock::now();
    auto now_time_t = std::chrono::system_clock::to_time_t(now);
    std::tm tm_now = {};
    localtime_s(&tm_now, &now_time_t);
    std::ostringstream oss;
    oss << std::put_time(&tm_now, "%d/%m/%Y %H:%M");
    std::string fecha_actual = oss.str();
    data = fecha_actual;
    Videoconsola& v = Videoconsola::getInstance();
    PassarellaUsuari u = v.obteUsuari();
    string sobrenomU = u.obteSobrenom();
    PassarellaCompra pcompra(sobrenomU, resultat.nom, data, resultat.preu);
    pcompra.insereix();

}

TxComprarPaquet::Resultat TxComprarPaquet::obteInfoPaquet() const {
    return resultat;
}

std::vector<TxComprarPaquet::Resultat> TxComprarPaquet::obteJocsContinguts()  {
    sort(jocs_continguts.begin(), jocs_continguts.end(), compararPorNombre);
    return jocs_continguts;
}

std::string TxComprarPaquet::obteData() const {

    return data;
}

int TxComprarPaquet::obteEstalvi() const {
    return estalvi;
}
