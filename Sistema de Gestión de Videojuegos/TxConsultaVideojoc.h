#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class TxConsultaVideojoc {
public:
    struct Resultat {
        std::string nomVideojoc;
        std::string descripcio;
        int qualificacio;
        std::string genere;
        std::string dataLlansament;
        double preu;
    };

private:
    Resultat resultat;
    TxConsultaVideojoc(const std::string& nomVideojoc);
    vector<string> paquets_;
public:
    vector<string>obtePaquets() const;
    static TxConsultaVideojoc crear(const std::string& nomVideojoc);
    void executar();
    Resultat obteResultat() const;
};