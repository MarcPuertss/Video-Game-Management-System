#pragma once

class CapaPresentacio {
public:
    void ejecutar();

private:
    
    void mostrarMenuUsuarioNoLoggeado();
    void mostrarMenuUsuarioLoggeado();
    void procesarOpcion(int opcion);
    void iniciSessio();
    void registrarUsuari();
    void gestionarUsuari();
    void gestionarCompres();
    void consultar();
    void tancaSessio();
    void consultarUsuari();
    void modificarUsuari();
    void esborrarUsuari();
    void comprarVideojoc();
    void comprarPaquetVideojoc();
    void consultarCompres();
    void consultarVideojoc();
    void consultarVideojocs();
    void consultarVideojocsEdat();
    void consultarNovetatsVideojocs();
    void consultarPaquet();
    void consultarPaquets();
    int OPCION_SALIR = 3;
    bool usuarioLoggeado = false;
};
