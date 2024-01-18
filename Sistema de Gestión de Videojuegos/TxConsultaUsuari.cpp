#include "TxConsultaUsuari.h"
#include "Videoconsola.h"
#include "PassarellaUsuari.h"

// Implementación de la función estática crear
TxConsultaUsuari TxConsultaUsuari::crear() {
    return TxConsultaUsuari();
}

// Constructor privado
TxConsultaUsuari::TxConsultaUsuari() {
}

// Función que ejecuta alguna lógica (por ahora está vacía)
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
