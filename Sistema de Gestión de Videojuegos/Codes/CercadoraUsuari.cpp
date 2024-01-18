#include <pqxx/pqxx>
#include <iostream>
#include "Connexio.h"
#include "CercadoraUsuari.h"


pqxx::result CercadoraUsuari::cercaUsuari(const std::string& sobrenom) {
 
    Connexio instCon = Connexio();
    pqxx::work txn(instCon.ObtenirConnexio());
    pqxx::result u = txn.exec(
        "SELECT * FROM usuari WHERE sobrenom = " + txn.quote(sobrenom));
  

    return u;
}



