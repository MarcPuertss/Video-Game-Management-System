#pragma once

#include <string>

class TxEsborraUsuari {
public:
    // Función para crear una instancia de TxEsborraUsuari
    static TxEsborraUsuari crear(const std::string& contraU);

    // Función para ejecutar la transacción
    void executa();

private:
    // Constructor privado, solo puede ser llamado por la función crear
    TxEsborraUsuari(const std::string& contraU);

    // Atributo privado para almacenar la contraseña del usuario
    std::string contraUsuari_;
    
};
