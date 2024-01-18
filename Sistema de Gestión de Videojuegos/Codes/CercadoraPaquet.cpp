#include "CercadoraPaquet.h"
#include "Connexio.h"

pqxx::result CercadoraPaquet::cercaPaquet(const std::string& paquet)
{
	Connexio instCon = Connexio();
	pqxx::work txn(instCon.ObtenirConnexio());
	std::string query = "SELECT * FROM public.paquet_videojoc WHERE nom = " + txn.quote(paquet);
    pqxx::result resultatConsulta = txn.exec(query);
    if (!resultatConsulta.empty()) {
        return resultatConsulta;
    }
    else {
        pqxx::result null;
        return null;
    }
}


CercadoraPaquet::CercadoraPaquet()
{
}

pqxx::result CercadoraPaquet::tots()
{
    Connexio instCon = Connexio();
    pqxx::work txn(instCon.ObtenirConnexio());

    // Ejemplo de consulta SQL (ajusta según tu esquema de base de datos)
    std::string query = "SELECT * FROM public.paquet_videojoc";

    pqxx::result resultatConsulta = txn.exec(query);

    // Verifica si se encontró algún resultado
    if (!resultatConsulta.empty()) {
        return resultatConsulta;
    }
    else {
        pqxx::result null;
        return null;
    }

    return pqxx::result();
}
