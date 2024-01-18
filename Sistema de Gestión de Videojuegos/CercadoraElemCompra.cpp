#include "CercadoraElemCompra.h"
#include "Connexio.h"
CercadoraElemCompra::CercadoraElemCompra()
{
}

pqxx::result CercadoraElemCompra::cercaElement(const std::string& elem) {
    Connexio instCon = Connexio();
    pqxx::work txn(instCon.ObtenirConnexio());

    // Ejemplo de consulta SQL (ajusta según tu esquema de base de datos)
    std::string query = "SELECT * FROM public.element_compra WHERE nom = " + txn.quote(elem);

    pqxx::result resultatConsulta = txn.exec(query);

    // Verifica si se encontró algún resultado
    if (!resultatConsulta.empty()) {
        return resultatConsulta;
    }
    else {
        pqxx::result null;
        return null;
    }
}