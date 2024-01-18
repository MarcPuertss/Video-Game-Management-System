#include "PassarellaElemCompra.h"

// Constructor que toma un resultado de la base de datos
PassarellaElemCompra::PassarellaElemCompra(const pqxx::result& elem) {
    nom = elem[0]["nom"].as<std::string>();
    descripcio = elem[0]["descripcio"].as<std::string>();
    preu = elem[0]["preu"].as<float>();
    tipus = elem[0]["tipus"].as<std::string>();
}

// Funciones para obtener los atributos
std::string PassarellaElemCompra::obteNom() const {
    return nom;
}

std::string PassarellaElemCompra::obteDescripcio() const {
    return descripcio;
}

float PassarellaElemCompra::obtePreu() const {
    return preu;
}

std::string PassarellaElemCompra::obteTipus() const {
    return tipus;
}
