#include "TxIniciSessio.h"
#include <iostream>
#include "CercadoraUsuari.h"
#include <iostream>
#include "Connexio.h"
#include <pqxx/pqxx>
#include "ReadConnection.h"
#include "CercadoraUsuari.h"
#include "PassarellaUsuari.h"
#include "Videoconsola.h"
using namespace std;


// Implementaci�n de la funci�n est�tica crear
TxIniciSessio TxIniciSessio::crear(const std::string& sobrenom, const std::string& contrasenya) {
    return TxIniciSessio(sobrenom, contrasenya);
}

// Constructor privado
TxIniciSessio::TxIniciSessio(const std::string& sobrenom, const std::string& contrasenya)
    : sobrenom(sobrenom), contrasenya(contrasenya) {
    // Puedes realizar alguna l�gica de inicializaci�n aqu� si es necesario
}

// Funci�n para realizar la iniciaci�n de sesi�n
void TxIniciSessio::executar() {
    //funcion de 
    CercadoraUsuari cercadoraUsuari;
    pqxx::result u = cercadoraUsuari.cercaUsuari(sobrenom);
    
    if (u.empty())throw exception("Hi ha hagut un error amb el sobrenom o la contrasenya");
    else {
        PassarellaUsuari passarellaUsuari(u);
        string contr = passarellaUsuari.obteContrasenya();
        if (contr != contrasenya) throw exception("Hi ha hagut un error amb el sobrenom o la contrasenya");
        Videoconsola& v = Videoconsola::getInstance();
        v.iniciaSessio(u);
    }

}
