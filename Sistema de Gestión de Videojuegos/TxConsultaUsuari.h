#pragma once
#include <string>
#include "PassarellaUsuari.h"

class TxConsultaUsuari {
public:
    // Función para crear una instancia de TxConsultaUsuari
    struct Resultat {
        std::string nomComplertU;
        std::string sobrenomU;
        std::string contrasenyaU;
        std::string correuU;
        std::string dataNaixementU;

    };

    static TxConsultaUsuari crear();

    // Otras funciones miembro si es necesario
    void executar();
    Resultat obteResultat() const;
    PassarellaUsuari obteUsuari() const;
private:
    // Constructor privado, solo puede ser llamado por la función crear
    TxConsultaUsuari();

    Resultat resultat;
    
   
};