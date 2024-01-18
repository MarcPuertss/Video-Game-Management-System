#pragma once
#include <string>
#include <pqxx/pqxx>

class PassarellaElemCompra {
public:
    // Constructor que toma un resultado de la base de datos
    PassarellaElemCompra(const pqxx::result& elem);

    // Funciones para obtener los atributos
    std::string obteNom() const;
    std::string obteDescripcio() const;
    float obtePreu() const;
    std::string obteTipus() const;

private:
    std::string nom;
    std::string descripcio;
    float preu;
    std::string tipus;
};