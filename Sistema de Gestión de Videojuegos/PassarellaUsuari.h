// PassarellaUsuari.h
#pragma once

#include <pqxx/pqxx>
using namespace std;
class PassarellaUsuari {
public:
    // Constructor que toma un resultado de la base de datos
    PassarellaUsuari(const pqxx::result& result);
    PassarellaUsuari();
    // Función para obtener la contraseña del usuario
    PassarellaUsuari(string nomU, string sobrenomU, string contrasenyaU, string correuElectronicU, string dataNaixament);
    static PassarellaUsuari crea(string nomU, string sobrenomU, string contrasenyaU, string correuElectronicU, string dataNaixament);
    string obteContrasenya() const;
    string obteSobrenom() const;
    string obteNom() const;
    string obteCorreuElectronic() const;
    string obteDataNaixament() const;
    void insereix();
    void posaNom(const std::string& nom);
    void posaSobrenom(const std::string& sobrenom);
    void posaContrasenya(const std::string& contrasenya);
    void posaCorreuElectronic(const std::string& correuElectronic);
    void posaDataNaixament(const std::string& dataNaixament);
    void modifica();
    void esborra();
    
private:
    
    string nom_;
    string sobrenom_;
    string contrasenya_;
    string correuElectronic_;
    string dataNaixament_;
};
