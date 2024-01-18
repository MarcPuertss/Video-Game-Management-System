#include "CercadoraVideojoc.h"
#include "Connexio.h"

pqxx::result CercadoraVideojoc::cercaVideojoc(const std::string& nomVideojoc)
{
    Connexio instCon = Connexio();
    pqxx::work txn(instCon.ObtenirConnexio());

    // Ejemplo de consulta SQL (ajusta según tu esquema de base de datos)
    std::string query = "SELECT * FROM public.videojoc WHERE nom = " + txn.quote(nomVideojoc);

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

CercadoraVideojoc::CercadoraVideojoc()
{
}

pqxx::result CercadoraVideojoc::tots()
{

    Connexio instCon = Connexio();
    pqxx::work txn(instCon.ObtenirConnexio());

    // Ejemplo de consulta SQL (ajusta según tu esquema de base de datos)
    std::string query = "SELECT * FROM public.videojoc";

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
