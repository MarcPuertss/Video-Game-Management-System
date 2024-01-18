#include "TxConsultaUsuari.h"
#include "Videoconsola.h"
#include "PassarellaUsuari.h"

// Implementaci�n de la funci�n est�tica crear
TxConsultaUsuari TxConsultaUsuari::crear() {
    return TxConsultaUsuari();
}

// Constructor privado
TxConsultaUsuari::TxConsultaUsuari() {
}

// Funci�n que ejecuta alguna l�gica (por ahora est� vac�a)
void TxConsultaUsuari::executar() {
    Videoconsola& v = Videoconsola::getInstance();
    PassarellaUsuari u = v.obteUsuari();
    resultat.nomComplertU = u.obteNom();
    resultat.sobrenomU = u.obteSobrenom();
    resultat.contrasenyaU = u.obteContrasenya();
    resultat.correuU = u.obteCorreuElectronic();
    resultat.dataNaixementU = u.obteDataNaixament();
}
TxConsultaUsuari::Resultat TxConsultaUsuari::obteResultat() const {
    return resultat;
}

PassarellaUsuari TxConsultaUsuari::obteUsuari() const
{
    return PassarellaUsuari(resultat.nomComplertU,resultat.sobrenomU,resultat.contrasenyaU,resultat.correuU,resultat.dataNaixementU);
}
