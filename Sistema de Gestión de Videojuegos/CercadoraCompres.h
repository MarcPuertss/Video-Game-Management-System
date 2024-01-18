#pragma once
#include <string>
#include "PassarellaUsuari.h"  // Asegúrate de incluir el encabezado necesario

class CercadoraCompres {
public:
    // Función para buscar las compras del usuario por sobrenombre
    static  pqxx::result cercarCompres(const std::string& sobrenom);
    CercadoraCompres();
private:
    // Constructor privado, ya que la clase solo tiene funciones estáticas
   
};
