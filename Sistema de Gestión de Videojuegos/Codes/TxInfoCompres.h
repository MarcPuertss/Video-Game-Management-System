#pragma once
#pragma once

class TxInfoCompres {
public:
    // Estructura para almacenar el resultado
    struct Resultat {
        int totalPaquets;
        int totalVideojocs;
        float totalEuros;
    };

    // Funci�n para crear una instancia de TxInfoCompres
    static TxInfoCompres crear();

    // Otras funciones miembro si es necesario
    void executar();

    // Funci�n para obtener el resultado
    Resultat obteResultat() const;

private:
    // Constructor privado, solo puede ser llamado por la funci�n crear
    TxInfoCompres();

    // Resultado de la transacci�n
    Resultat resultat;
};