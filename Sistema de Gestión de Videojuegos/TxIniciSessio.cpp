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


// Implementación de la función estática crear
TxIniciSessio TxIniciSessio::crear(const std::string& sobrenom, const std::string& contrasenya) {
    return TxIniciSessio(sobrenom, contrasenya);
}

// Constructor privado
TxIniciSessio::TxIniciSessio(const std::string& sobrenom, const std::string& contrasenya)
    : sobrenom(sobrenom), contrasenya(contrasenya) {
    // Puedes realizar alguna lógica de inicialización aquí si es necesario
}

// Función para realizar la iniciación de sesión
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
