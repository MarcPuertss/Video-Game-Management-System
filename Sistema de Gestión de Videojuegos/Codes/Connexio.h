// Connexio.h
#pragma once

#include <pqxx/pqxx>
#include "ReadConnection.h"
class Connexio {
public:
    Connexio();
    ~Connexio();
    pqxx::connection& ObtenirConnexio();

private:
    pqxx::connection conn;
    std::string configFilePath;
};
