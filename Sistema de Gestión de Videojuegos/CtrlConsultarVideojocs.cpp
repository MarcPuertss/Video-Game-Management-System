// CtrlConsultarVideojocs.cpp
#include "CtrlConsultarVideojocs.h"
#include "CercadoraVideojoc.h"

CtrlConsultarVideojocs::CtrlConsultarVideojocs()
     {
    CercadoraVideojoc cercadoraVideojoc;
    pqxx::result totsVideojocs = cercadoraVideojoc.tots();
    for (int i = 0; i < totsVideojocs.size();++i) {
        TxConsultaVideojoc txConsultaVideojoc = TxConsultaVideojoc::crear(totsVideojocs[i]["nom"].c_str());
        TxConsultaVideojoc::Resultat resultat = txConsultaVideojoc.obteResultat();
        resultats.push_back(resultat);
        vector<string> paquets_rel = txConsultaVideojoc.obtePaquets();
        if (paquets_rel.empty()) {
            vector<string>aux;
            paquets.push_back(aux);
        }
        paquets.push_back(paquets_rel);
    }
}

std::vector<TxConsultaVideojoc::Resultat> CtrlConsultarVideojocs::obteResultats() const {
    return resultats;
}

list<vector<string>> CtrlConsultarVideojocs::obtePaquets() const
{
    return paquets;
}
