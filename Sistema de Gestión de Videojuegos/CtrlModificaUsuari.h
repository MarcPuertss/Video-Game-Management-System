#pragma once

#include "PassarellaUsuari.h"
#include "TxConsultaUsuari.h"
#include <iostream>
using namespace std;
class CtrlModificaUsuari {
public:
    CtrlModificaUsuari();

    TxConsultaUsuari::Resultat consultaUsuari();
    void modificaUsuari(string nomU, string contraU, string correuU, string neixU);

private:
    PassarellaUsuari usuari;
};