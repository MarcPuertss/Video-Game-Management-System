#include "passarellaVideojoc.h"

PassarellaVideojoc::PassarellaVideojoc(pqxx::result videojoc) {
    nom = videojoc[0]["nom"].as<std::string>();
    qualificacioEdat = videojoc[0]["qualificacio_edat"].as<int>();
    dataLlansament = videojoc[0]["data_llansament"].as<std::string>();
    genere = videojoc[0]["genere"].as<std::string>();
  
}

std::string PassarellaVideojoc::obteNom() const {
    return nom;
}

int PassarellaVideojoc::obteQualificacioEdat() const {
    return qualificacioEdat;
}

std::string PassarellaVideojoc::obteDataLlansament() const {
    return dataLlansament;
}

std::string PassarellaVideojoc::obteGenere() const {
    return genere;
}