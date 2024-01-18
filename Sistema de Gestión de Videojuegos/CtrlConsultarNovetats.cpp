#include "CtrlConsultarNovetats.h"
#include "CercadoraVideojoc.h"
CtrlConsultarNovetats::CtrlConsultarNovetats(string data)
{
    CercadoraVideojoc cercadoraVideojoc;
    pqxx::result totsVideojocs = cercadoraVideojoc.tots();
    for (int i = 0; i < totsVideojocs.size();++i) {
        TxConsultaVideojoc txConsultaVideojoc = TxConsultaVideojoc::crear(totsVideojocs[i]["nom"].c_str());
        TxConsultaVideojoc::Resultat resultat = txConsultaVideojoc.obteResultat();
        if (resultat.dataLlansament>=data) {
            resultats.push_back(resultat);
            vector<string> paquets_rel = txConsultaVideojoc.obtePaquets();
            if (paquets_rel.empty()) {
                vector<string>aux;
                paquets.push_back(aux);
            }
            paquets.push_back(paquets_rel);
        }
    }
}
std::vector<TxConsultaVideojoc::Resultat> CtrlConsultarNovetats::obteResultats() const {
    return resultats;
}

list<vector<string>> CtrlConsultarNovetats::obtePaquets() const
{
    return paquets;
}