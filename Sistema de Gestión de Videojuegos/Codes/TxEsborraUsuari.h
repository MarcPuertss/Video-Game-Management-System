#pragma once

#include <string>

class TxEsborraUsuari {
public:
    // Funci�n para crear una instancia de TxEsborraUsuari
    static TxEsborraUsuari crear(const std::string& contraU);

    // Funci�n para ejecutar la transacci�n
    void executa();

private:
    // Constructor privado, solo puede ser llamado por la funci�n crear
    TxEsborraUsuari(const std::string& contraU);

    // Atributo privado para almacenar la contrase�a del usuario
    std::string contraUsuari_;
    
};
