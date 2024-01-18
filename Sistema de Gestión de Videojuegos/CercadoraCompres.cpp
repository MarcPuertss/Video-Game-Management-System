#include "CercadoraCompres.h"
#include "Connexio.h"
CercadoraCompres::CercadoraCompres() {}
pqxx::result CercadoraCompres::cercarCompres(const std::string& sobrenom) {
    Connexio instCon = Connexio();
    pqxx::work txn(instCon.ObtenirConnexio());

    // Ejemplo de consulta SQL (ajusta según tu esquema de base de datos)
    std::string query = "SELECT * FROM public.compra WHERE usuari = " + txn.quote(sobrenom);

    // Ejecuta la consulta
    pqxx::result resultatConsulta = txn.exec(query);

    if (!resultatConsulta.empty()) {
        return resultatConsulta;
    }
    else {
        pqxx::result null;
        return null;
    }

    // Devuelve el vector de resultados

}
