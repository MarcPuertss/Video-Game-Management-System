#pragma once
#include <string>
#include <pqxx/pqxx>

class CercadoraElemCompra {
public:
    // Funci�n para buscar un elemento por nombre
    pqxx::result cercaElement(const std::string& elem);
    CercadoraElemCompra();

   
};
