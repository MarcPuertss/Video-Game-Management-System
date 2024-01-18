#pragma once
#include <string>
#include <vector>
#include "passarellaVideojoc.h"
#include "PassarellaElemCompra.h"
using namespace std;

class TxComprarVideojoc {
public:
    // Constructor

    TxComprarVideojoc(string nomVideojoc);
    string obteData() const;
    vector<PassarellaElemCompra> obteVideojocsRelacionats() ;
private:
    string data;
    vector<PassarellaElemCompra> videojocs_relacionats;
    static bool compararPorNombre(const PassarellaElemCompra& a, const PassarellaElemCompra& b);
    

    // Otros métodos que puedas necesitar
};
