#pragma once
#include <iostream>


class TxRegistraUsuari {
public:
    TxRegistraUsuari(const std::string& nomComplert, const std::string& sobrenom,
        const std::string& contrasenya, const std::string& correu,
        const std::string& dataNaixement);

    static TxRegistraUsuari crear(const std::string& nomComplert, const std::string& sobrenom,
        const std::string& contrasenya, const std::string& correu,
        const std::string& dataNaixement);

    void executar();

private:
    std::string nomComplertU;
    std::string sobrenomU;
    std::string contrasenyaU;
    std::string correuU;
    std::string dataNaixementU;
};