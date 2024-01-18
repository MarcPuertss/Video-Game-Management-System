#pragma once
#include <string>
#include <pqxx/pqxx>
class PassarellaVideojoc {
private:
    std::string nom;
    int qualificacioEdat;
    std::string dataLlansament;
    std::string genere;

public:
    PassarellaVideojoc(pqxx::result videojoc);

    std::string obteNom() const;
    int obteQualificacioEdat() const;
    std::string obteDataLlansament() const;
    std::string obteGenere() const;
};

