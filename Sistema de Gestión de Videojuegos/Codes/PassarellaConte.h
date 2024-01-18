#pragma once
#include <pqxx/pqxx>

class PassarellaConte {
private:
    std::string paquet;
    std::string videojoc;

public:
    // Constructor que inicializa los par�metros privados a partir de un objeto pqxx::result
    PassarellaConte(pqxx::result conte);

    // M�todos para obtener los valores privados
    std::string obtePaquet() const;
    std::string obteVideojoc() const;
    pqxx::result totsVideojocs(std::string paquet)const;
    pqxx::result totsPaquets(std::string videojoc)const;
};