// CtrlModificaUsuari.cpp
#include "CtrlModificaUsuari.h"
#include "TxConsultaUsuari.h"
using namespace std;
CtrlModificaUsuari::CtrlModificaUsuari() {}

TxConsultaUsuari::Resultat CtrlModificaUsuari::consultaUsuari() {
    TxConsultaUsuari txConsultaUsuari = TxConsultaUsuari::crear();
    txConsultaUsuari.executar();
    TxConsultaUsuari::Resultat infoUsu = txConsultaUsuari.obteResultat();
    PassarellaUsuari usu = txConsultaUsuari.obteUsuari();
    usuari = usu;
    return infoUsu;

}

void CtrlModificaUsuari::modificaUsuari(string nomU, string contraU, string correuU,string neixU) {

    if (nomU != "") usuari.posaNom(nomU);
    if (contraU != "")usuari.posaContrasenya(contraU);
    if (correuU != "") usuari.posaCorreuElectronic(correuU);
    if (neixU != "") usuari.posaDataNaixament(neixU);

    if (nomU != "" or contraU != "" or correuU != "" or neixU != "")usuari.modifica();



}