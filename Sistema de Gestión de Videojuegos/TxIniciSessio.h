#pragma once

#include <string>

class TxIniciSessio {
public:
    // Función para crear la instancia de TxIniciSessio
    static TxIniciSessio crear(const std::string& sobrenom, const std::string& contrasenya);

    // Otras funciones miembro si es necesario
    void executar();

private:
    // Constructor privado, solo puede ser llamado por la función crear
    TxIniciSessio(const std::string& sobrenom, const std::string& contrasenya);

    std::string sobrenom;
    std::string contrasenya;
};
