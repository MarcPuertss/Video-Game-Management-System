#pragma once
#pragma once
#include <vector>
#include "TxConsultaVideojoc.h"  // Aseg�rate de incluir el archivo correcto
#include <list>
class CtrlConsultarVideojocsEdat {
public:
    CtrlConsultarVideojocsEdat(float edat);

    std::vector<TxConsultaVideojoc::Resultat> obteResultats() const;
    list<vector<string>>obtePaquets()const;
private:
    std::vector<TxConsultaVideojoc::Resultat> resultats;
    list<vector<string>> paquets;
};