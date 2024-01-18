// PassarellaUsuari.cpp
#include "PassarellaUsuari.h"
#include "Connexio.h"
#include <iostream>
#include "Videoconsola.h"
using namespace std;

// Constructor que toma un resultado de la base de datos
PassarellaUsuari::PassarellaUsuari(const pqxx::result& result) {
    contrasenya_ = result[0]["contrasenya"].as<std::string>();
    sobrenom_ = result[0]["sobrenom"].as<std::string>();
    nom_ = result[0]["nom"].as<std::string>();
    correuElectronic_ = result[0]["correu_electronic"].as<std::string>();
    dataNaixament_ = result[0]["data_naixement"].as<std::string>();
}

// Constructor por defecto
PassarellaUsuari::PassarellaUsuari() {
    // Puedes inicializar los elementos privados aqu� si es necesario
}
// Constructor que toma par�metros
PassarellaUsuari::PassarellaUsuari(string nomU, string sobrenomU, string contrasenyaU, string correuElectronicU, string dataNaixament)
    : nom_(nomU), sobrenom_(sobrenomU), contrasenya_(contrasenyaU), correuElectronic_(correuElectronicU), dataNaixament_(dataNaixament) {
    // Puedes realizar alguna l�gica adicional aqu� si es necesario
}

PassarellaUsuari PassarellaUsuari::crea(string nomU, string sobrenomU, string contrasenyaU, string correuElectronicU, string dataNaixament) {
    return PassarellaUsuari(nomU, sobrenomU, contrasenyaU, correuElectronicU, dataNaixament);
}

// Funci�n para obtener la contrase�a del usuario
std::string PassarellaUsuari::obteContrasenya() const {
    return contrasenya_;
}

// Funci�n para obtener el sobrenombre del usuario
std::string PassarellaUsuari::obteSobrenom() const {
    return sobrenom_;
}

// Funci�n para obtener el nombre del usuario
std::string PassarellaUsuari::obteNom() const {
    return nom_;
}

// Funci�n para obtener el correo electr�nico del usuario
std::string PassarellaUsuari::obteCorreuElectronic() const {
    return correuElectronic_;
}

// Funci�n para obtener la fecha de nacimiento del usuario
std::string PassarellaUsuari::obteDataNaixament() const {
    return dataNaixament_;
}

void PassarellaUsuari::insereix() {
    // Obt�n la conexi�n
    Connexio instCon = Connexio();
    pqxx::work txn(instCon.ObtenirConnexio());

    // Ejecuta la consulta para insertar un nuevo usuario
    std::string query = "INSERT INTO public.usuari (sobrenom, nom, contrasenya, correu_electronic, data_naixement) VALUES ("
        + txn.quote(sobrenom_) + ", "
        + txn.quote(nom_) + ", "
        + txn.quote(contrasenya_) + ", "
        + txn.quote(correuElectronic_) + ", "
        + txn.quote(dataNaixament_) + ")";

    try {
        txn.exec(query);
        txn.commit();
    }
    catch (const exception& e) {
        throw exception("El sobrenom o el correo esta repetit");
        cerr << "Error al insertar usuario: " << e.what() << endl;
        // Tambi�n puedes agregar un throw aqu� para propagar la excepci�n
    }
}
void PassarellaUsuari::posaNom(const std::string& nom) {
    nom_ = nom;
}

void PassarellaUsuari::posaSobrenom(const std::string& sobrenom) {
    sobrenom_ = sobrenom;
}

void PassarellaUsuari::posaContrasenya(const std::string& contrasenya) {
    contrasenya_ = contrasenya;
}

void PassarellaUsuari::posaCorreuElectronic(const std::string& correuElectronic) {
    correuElectronic_ = correuElectronic;
}

void PassarellaUsuari::posaDataNaixament(const std::string& dataNaixament) {
    dataNaixament_ = dataNaixament;
}

void PassarellaUsuari::modifica() {
    // Obt�n la conexi�n
    Connexio instCon = Connexio();
    pqxx::work txn(instCon.ObtenirConnexio());

    // Ejecuta la consulta para actualizar el usuario
    std::string query = "UPDATE public.usuari SET "
        "sobrenom = " + txn.quote(sobrenom_) + ", "
        "nom = " + txn.quote(nom_) + ", "
        "contrasenya = " + txn.quote(contrasenya_) + ", "
        "correu_electronic = " + txn.quote(correuElectronic_) + ", "
        "data_naixement = " + txn.quote(dataNaixament_) +
        " WHERE sobrenom = " + txn.quote(sobrenom_);

    try {
        txn.exec(query);
        txn.commit();
        Videoconsola& v = Videoconsola::getInstance();
        v.refrescaUsuari();
    }
    catch (const exception& e) {
        throw exception("El correo electronic ja existeix ");
        cerr << "Error al modificar usuario: " << e.what() << endl;
        
    }



}

void PassarellaUsuari::esborra()
{
    Connexio instCon = Connexio();
    pqxx::work txn(instCon.ObtenirConnexio());
    std::string query = "DELETE FROM public.usuari WHERE sobrenom = " + txn.quote(sobrenom_);
    try {
        txn.exec(query);
        txn.commit();
        Videoconsola& v = Videoconsola::getInstance();
        v.tancaSessio();
    }
    catch (const exception& e) {
        cerr << "Error al borrar usuario: " << e.what() << endl;
        // Puedes agregar un throw aqu� para propagar la excepci�n si lo deseas
    }
}
