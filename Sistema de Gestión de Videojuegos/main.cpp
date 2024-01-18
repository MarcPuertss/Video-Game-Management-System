#include <iostream>
#include <pqxx/pqxx>
#include "ReadConnection.h"
#include "CapaDePresentacion.h"
#include "Connexio.h"
using namespace std;

int main() {

    try {
  
        CapaPresentacio capaPresentacion;
        capaPresentacion.ejecutar();
    }


    catch (const std::exception& e) {
        cerr << "Error en la Capa de Presentación: " << e.what() << std::endl;
        return 1;
    }


    return 0;
}
