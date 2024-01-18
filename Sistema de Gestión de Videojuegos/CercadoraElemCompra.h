#pragma once
#include <string>
#include <pqxx/pqxx>

class CercadoraElemCompra {
public:
    // Función para buscar un elemento por nombre
    pqxx::result cercaElement(const std::string& elem);
    CercadoraElemCompra();

   
};
