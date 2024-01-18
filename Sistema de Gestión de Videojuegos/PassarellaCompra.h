#pragma once
#include <string>
using namespace std;
#include <pqxx/pqxx>
class PassarellaCompra {
public:
    // Constructor que toma un usuario, un elemento, una fecha y un precio pagado
    PassarellaCompra(const std::string& usuari, const std::string& elementComprat, const std::string& data, float preuPagat);

    // Getters
    float obtePreuPagat() const;
    std::string obteElementCompra() const;
    std::string obteUsuari() const;
    std::string obteData() const;
    void insereix();

private:
    std::string usuari_;
    std::string elementComprat_;
    std::string data_;
    float preuPagat_;
};
