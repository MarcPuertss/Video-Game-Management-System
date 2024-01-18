#pragma once
#include <string>
#include <vector>
using namespace std;
class TxConsultarPaquet {
public:
    // Struct para representar el resultado
    struct Resultat {
        std::string nom;
        std::string descripcio;
        float preu;
    };

    // Constructor
    TxConsultarPaquet(std::string nomPaquet);

    // Métodos de acceso
    Resultat obteInfoPaquet() const;
    std::vector<Resultat> obteJocsContinguts();
    int obteEstalvi() const;
   
private:
    Resultat resultat;
    std::vector<Resultat> jocs_continguts;
    int estalvi;
    static bool compararPorNombre(const Resultat& a, const Resultat& b);
};
