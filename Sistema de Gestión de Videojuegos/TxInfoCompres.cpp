#include "TxInfoCompres.h"
#include "Videoconsola.h"
#include "PassarellaUsuari.h"
#include "CercadoraCompres.h"
#include <pqxx/pqxx>
#include "PassarellaCompra.h"
#include "CercadoraElemCompra.h"
#include "PassarellaElemCompra.h"

// Implementaci�n de la funci�n est�tica crear
TxInfoCompres TxInfoCompres::crear() {
    return TxInfoCompres();
}

// Constructor privado
TxInfoCompres::TxInfoCompres() {
}

// Funci�n que ejecuta alguna l�gica (por ahora est� vac�a)
void TxInfoCompres::executar() {
    // L�gica de la transacci�n (por ahora est� vac�a)
    // Aqu� puedes realizar cualquier operaci�n necesaria y actualizar el resultado
    Videoconsola& v = Videoconsola::getInstance();
    PassarellaUsuari u = v.obteUsuari();
    string sobrenonmU = u.obteSobrenom();
    CercadoraCompres cercadoraCompres;
    pqxx::result compresU = cercadoraCompres.cercarCompres(sobrenonmU);
    resultat.totalPaquets = 0;
    resultat.totalVideojocs = 0;
    resultat.totalEuros = 0.0;
    for (size_t i = 0; i < compresU.size(); ++i) {
        PassarellaCompra c = PassarellaCompra(compresU[i]["usuari"].c_str(), compresU[i]["element"].c_str(), compresU[i]["data"].c_str(), compresU[i]["preu_pagat"].as<float>());
        float preuE= c.obtePreuPagat();
        string elem = c.obteElementCompra();
        CercadoraElemCompra cercadoraElemCompra;
        pqxx::result res = cercadoraElemCompra.cercaElement(elem);
        PassarellaElemCompra ec = PassarellaElemCompra(res);
        string tipusE = ec.obteTipus();
        resultat.totalEuros += preuE;
        if (tipusE == "paquet")++resultat.totalPaquets;
        else if (tipusE == "videojoc")++resultat.totalVideojocs;
     }
    
}
// Funci�n para obtener el resultado
TxInfoCompres::Resultat TxInfoCompres::obteResultat() const {
    return resultat;
}
