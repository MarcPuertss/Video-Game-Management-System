#include "PassarellaCompra.h"
#include "Connexio.h"
#include <iostream>
using namespace std;
// Implementación del constructor
PassarellaCompra::PassarellaCompra(const std::string& usuari, const std::string& elementComprat, const std::string& data, float preuPagat)
    : usuari_(usuari), elementComprat_(elementComprat), data_(data), preuPagat_(preuPagat) {
    // Puedes realizar alguna lógica adicional aquí si es necesario
}

// Implementación de los getters
float PassarellaCompra::obtePreuPagat() const {
    return preuPagat_;
}

std::string PassarellaCompra::obteElementCompra() const {
    return elementComprat_;
}

std::string PassarellaCompra::obteUsuari() const {
    return usuari_;
}

std::string PassarellaCompra::obteData() const {
    return data_;
}

void PassarellaCompra::insereix()
{
    Connexio instCon = Connexio();
    pqxx::work txn(instCon.ObtenirConnexio());
    std::string query = "INSERT INTO public.compra (usuari, element, data, preu_pagat) VALUES ("
        + txn.quote(usuari_) + ", "
        + txn.quote(elementComprat_) + ", "
        + txn.quote(data_) + ", "
        + txn.quote(preuPagat_) +")";
    try {
        txn.exec(query);
        txn.commit();
    }
    catch (const exception& e) {
        cerr << "Error al insertar compra: " << e.what() << endl;
    }
}
