#include "CercadoraConte.h"
#include "Connexio.h"

pqxx::result CercadoraConte::cercaConteVideojoc(const std::string& videojoc)
{
    Connexio instCon = Connexio();
    pqxx::work txn(instCon.ObtenirConnexio());
    std::string query = "SELECT * FROM public.conte WHERE videojoc = " + txn.quote(videojoc);
    pqxx::result resultatConsulta = txn.exec(query);
    txn.commit();
    return resultatConsulta;
}

pqxx::result CercadoraConte::cercaContePaquet(const std::string& paquet)
{
    Connexio instCon = Connexio();
    pqxx::work txn(instCon.ObtenirConnexio());
    std::string query = "SELECT * FROM public.conte WHERE paquet = " + txn.quote(paquet);
    pqxx::result resultatConsulta = txn.exec(query);
    if (!resultatConsulta.empty()) {
        return resultatConsulta;
    }
    else {
        pqxx::result null;
        return null;
    }
    
    
}

CercadoraConte::CercadoraConte()
{
}
