#pragma once
#include <string>
#include "PassarellaUsuari.h"  // Aseg�rate de incluir el encabezado necesario

class CercadoraCompres {
public:
    // Funci�n para buscar las compras del usuario por sobrenombre
    static  pqxx::result cercarCompres(const std::string& sobrenom);
    CercadoraCompres();
private:
    // Constructor privado, ya que la clase solo tiene funciones est�ticas
   
};
