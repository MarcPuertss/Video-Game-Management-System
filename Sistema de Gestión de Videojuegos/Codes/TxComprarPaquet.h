#pragma once

#include <string>
#include <vector>
using namespace std;
class TxComprarPaquet {
public:
    // Struct para representar el resultado
    struct Resultat {
        std::string nom;
        std::string descripcio;
        float preu;
    };

    // Constructor
    TxComprarPaquet(std::string nomPaquet);

    // Métodos de acceso
    Resultat obteInfoPaquet() const;
    std::vector<Resultat> obteJocsContinguts() ;
    std::string obteData() const;
    int obteEstalvi() const;
    void Comprar();
private:
    Resultat resultat;
    std::vector<Resultat> jocs_continguts;
    string data;
    int estalvi;
    static bool compararPorNombre(const Resultat &a, const Resultat &b);
};
