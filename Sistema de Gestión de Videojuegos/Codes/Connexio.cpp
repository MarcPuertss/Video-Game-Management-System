// Connexio.cpp
#include "Connexio.h"
#include "ReadConnection.h"
#include <iostream>
#include <pqxx/pqxx>
using namespace std;
Connexio::Connexio() : conn(ReadConnectionString("config.txt")){
}
Connexio::~Connexio() {
    // Libera los recursos al destruir la instancia
    conn.close();
}

pqxx::connection& Connexio::ObtenirConnexio() {
    return conn;
}
