#pragma once

#include <vector>
#include <string>
using namespace std;
class TxConsultaCompres {
public:
    // Struct para representar la información de un elemento de compra
    
    struct Paquet {
        std::string data;
        std::string nom;
        std::string descripcio;
        float preu;
        vector<Paquet>videojocs;
    };

    // Constructor
    TxConsultaCompres();

    // Métodos de acceso
   
    std::vector<Paquet> obteTotsElem() ;
    int obtepreu();
private:
    std::vector<Paquet> videojocs;
    std::vector<Paquet> paquets;
    int total;
};
