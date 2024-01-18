#include "TxEsborraUsuari.h"
#include "Videoconsola.h"

// Constructor privado
TxEsborraUsuari::TxEsborraUsuari(const std::string& contraU)
    : contraUsuari_(contraU) {
    // Puedes realizar alguna l�gica adicional aqu� si es necesario
}

// Funci�n est�tica para crear una instancia de TxEsborraUsuari
TxEsborraUsuari TxEsborraUsuari::crear(const std::string& contraU) {
    return TxEsborraUsuari(contraU);
}

void TxEsborraUsuari::executa()
{
    Videoconsola& v = Videoconsola::getInstance();
    PassarellaUsuari usu = v.obteUsuari();
    string c;
    c = usu.obteContrasenya();
    if (c != contraUsuari_)throw exception("La contrasenya no es correcta, l'usuari no s'esborrat");
    else {
        usu.esborra();
    
    }
}

