#include "PassarellaConte.h"
#include "Connexio.h"

// Implementación del constructor
PassarellaConte::PassarellaConte(pqxx::result conte) {
    paquet = conte[0]["paquet"].as<std::string>();
    videojoc = conte[0]["videojoc"].as<std::string>();
}

// Implementación de los métodos para obtener los valores privados
std::string PassarellaConte::obtePaquet() const {
    return paquet;
}

std::string PassarellaConte::obteVideojoc() const {
    return videojoc;
}

pqxx::result PassarellaConte::totsVideojocs(std::string paquet) const
{
    Connexio instCon = Connexio(); // Asegúrate de tener la clase Connexio con la función ObtenirConnexio
    pqxx::work txn(instCon.ObtenirConnexio());

    std::string query = "SELECT * FROM public.conte WHERE paquet = " + txn.quote(paquet);
    pqxx::result result = txn.exec(query);


    return result;
}

pqxx::result PassarellaConte::totsPaquets(std::string videojoc) const
{
    Connexio instCon = Connexio(); // Asegúrate de tener la clase Connexio con la función ObtenirConnexio
    pqxx::work txn(instCon.ObtenirConnexio());

    std::string query = "SELECT * FROM public.conte WHERE videojoc = " + txn.quote(videojoc);
    pqxx::result result = txn.exec(query);


    return result;
}



