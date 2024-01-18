#include "CapaDePresentacion.h"
#include <iostream>
#include <cstdlib> 
#include "TxIniciSessio.h"
#include <algorithm>
#include "TxTancaSessio.h"
#include "TxRegistraUsuari.h"
#include "TxConsultaUsuari.h"
#include "TxInfoCompres.h"
#include "CtrlModificaUsuari.h"
#include "TxEsborraUsuari.h"
#include "TxConsultaVideojoc.h"
#include "TxComprarVideojoc.h"
#include "PassarellaElemCompra.h"
#include "TxComprarPaquet.h"
#include "TxConsultaCompres.h"
#include "CtrlConsultarVideojocs.h"
#include "CtrlConsutlarVideocojsEdat.h"
#include "CtrlConsultarNovetats.h"
#include "TxConsultarPaquet.h"
#include "CtrlConsultarPaquets.h"

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void CapaPresentacio::ejecutar() {
    int opcion = 0;

    do {
        if (usuarioLoggeado) {
            OPCION_SALIR = 5;
            mostrarMenuUsuarioLoggeado();
        }
        else {
            OPCION_SALIR = 3;
            mostrarMenuUsuarioNoLoggeado();
        }
        std::cout << "Ingrese su eleccion: ";
        std::cin >> opcion;

        clearScreen();

        procesarOpcion(opcion);

       

    } while (opcion != OPCION_SALIR);
}

void CapaPresentacio::mostrarMenuUsuarioNoLoggeado() {
    std::cout << "Menu Principal (No Loggeado)" << std::endl;
    std::cout << "1. Iniciar sessio" << std::endl;
    std::cout << "2. Registrar usuari" << std::endl;
    std::cout << "3. Salir" << std::endl;
}

void CapaPresentacio::mostrarMenuUsuarioLoggeado() {
    std::cout << "Menu Principal (Loggeado)" << std::endl;
    std::cout << "1. Gestionar usuari" << std::endl;
    std::cout << "2. Gestionar compres" << std::endl;
    std::cout << "3. Consultar" << std::endl;
    std::cout << "4. Tancar Sessio" << std::endl;
    std::cout << "5. Sortir" << std::endl;
}

void CapaPresentacio::procesarOpcion(int opcion) {
    switch (opcion) {
    case 1:
        if (!usuarioLoggeado) {
            iniciSessio();
        }
        else {
            gestionarUsuari(); 
        }
        break;
    case 2:
        if (!usuarioLoggeado) {
            registrarUsuari();
        }
        else {
            gestionarCompres();
        }
        break;
    case 3:
        if (!usuarioLoggeado) {
            // Logica para salir
            usuarioLoggeado = false;
        }
        else {
            consultar();
        }
        break;
    case 4:
        // Logica para tancaSessio;
        if (usuarioLoggeado)tancaSessio();
            
        break;
    case 5:
        if (usuarioLoggeado)usuarioLoggeado = false;

        break;
        // Agrega mas casos segun tus necesidades
    default:
        std::cout << "Opcion no valida. Intente nuevamente." << std::endl;
    }
}

void CapaPresentacio::iniciSessio() {
    // Logica para iniciar sesion
    // ...
    string sobrenom;
    string contrasenya;
    cout << " * *INICI SESSIO * * " << endl;
    cout << "Sobrenom: ";
    cin >> sobrenom;
    cout << "Contrasenya: ";
    cin >> contrasenya;
    
    try {

        TxIniciSessio txIniciSessio = TxIniciSessio::crear(sobrenom, contrasenya);
        txIniciSessio.executar();
        usuarioLoggeado = true;
        clearScreen();
        cout << "Sessio Iniciada correctament!" << endl;
        
    }
    catch (const exception& e) {
        clearScreen();
        cerr<<  e.what() << endl;
        
    }

}
void CapaPresentacio::tancaSessio() {
    cout << "Vols tancar la sessio(S/N): ";
    string opcio;
    cin >> opcio;
    clearScreen();
    transform(opcio.begin(), opcio.end(), opcio.begin(), ::tolower);//minusculas la opcio
    if (opcio == "s") {
        
        TxTancaSessio txTancaSessio =TxTancaSessio::crear();
        cout << "Sessio tancada Correctament!!" << endl;
        usuarioLoggeado = false;
    }

}
void CapaPresentacio::registrarUsuari() {
    // Logica para registrar usuario
    // ...
    string sU;
    string nU;
    string cU;
    string ceU;
    string dnU;
    cout << "** Registrar usuari **" << endl;
    cout << "Omplir la informacio que es demana ..." << endl;
    cout << "Nom complert: ";
    cin >> nU;
    cout << "Sobrenom: ";
    cin >> sU;
    cout << "Contrasenya: ";
    cin >> cU;
    cout << "Correu electronic: ";
    cin >> ceU;
    cout << "Data naixament (DD/MM/AAAA): ";
    cin >> dnU;
    clearScreen();
    try
    {
        TxRegistraUsuari txRu = TxRegistraUsuari::crear(nU, sU, cU, ceU, dnU);
        txRu.executar();
        cout << "Nou usuari registrat correctament!!" << endl;
    }
    catch (const std::exception&e)
    {
        cerr <<e.what() << endl;
    }
}

void CapaPresentacio::gestionarUsuari() {
    // Logica para gestion de usuario
    // ...
    int opcio;
    cout << "**** Gestionar Usuari ****" << endl;
    cout << "1. Consultar usuari" << endl;
    cout << "2. Modificar usuari" << endl;
    cout << "3. Esborrar usuari" << endl;
    cout << "4. Tornar" << endl;
    cout << "Opcio: ";
    cin >> opcio;
    clearScreen();
    switch (opcio) {
    case 1:
        consultarUsuari();
        break;
    case 2:
        modificarUsuari();
        break;
    case 3:
        esborrarUsuari();
        break;
    case 4:
        // No es necesario hacer nada, ya que "Tornar" simplemente termina la función
        break;
    default:
        cout << "Opcio no valida. Intente nuevamente." << endl;
    }

}

void CapaPresentacio::gestionarCompres() {
    // Logica para gestion de compras
    // ...
    int opcio;
    cout << "**** Gestionar Compres ****" << endl;
    cout << "1. Comprar videojocs" << endl;
    cout << "2. Comprar paquet videojoc" << endl;
    cout << "3. Consultar compres" << endl;
    cout << "4. Tornar" << endl;
    cout << "Opcio: ";
    cin >> opcio;
    switch (opcio) {
        case 1:
            comprarVideojoc();
            break;
        case 2:
            comprarPaquetVideojoc();
            break;
        case 3:
            consultarCompres();
            break;
        case 4:
            break;
        default:
            cout << "Opcio no valida. Intente nuevamente." << endl;
            
            
    }


}

void CapaPresentacio::consultar() {
 
    int opcio;
    cout << "**** Consultar Videojocs ****" << endl;
    cout << "1. Consultar videojoc" << endl;
    cout << "2. Consultar videojocs" << endl;
    cout << "3. Consultar videojocs per edat" << endl;
    cout << "4. Consultar novetats videojocs" << endl;
    cout << "5. Consultar paquet videojoc" << endl;
    cout << "6. Consultar paquets videojoc" << endl;
    cout << "7. Tornar" << endl;
    cout << "Opcio: ";
    cin >> opcio;

    clearScreen();

    switch (opcio) {
        case 1:
            consultarVideojoc();
            
            break;
        case 2:
            consultarVideojocs();
            break;
        case 3:
            consultarVideojocsEdat();
            break;
        case 4:
            consultarNovetatsVideojocs();
            break;
        case 5:
            consultarPaquet();
            break;
        case 6:
            consultarPaquets();
            break;
        case 7:
            // No es necesario hacer nada, ya que "Tornar" simplemente termina la función
            break;
        default:
            cout << "Opcio no valida. Intente nuevamente." << endl;
        }

}
void CapaPresentacio::consultarUsuari() {
    // Lógica para consultar usuario
    // ... b n
    TxConsultaUsuari txconsultausuari = TxConsultaUsuari::crear();
    txconsultausuari.executar();
    TxConsultaUsuari::Resultat infoUsuari = txconsultausuari.obteResultat();
    TxInfoCompres txInfoCompres = TxInfoCompres::crear();
    txInfoCompres.executar();
    TxInfoCompres::Resultat infoCompres = txInfoCompres.obteResultat();
    clearScreen();
    cout << "**** Consulta  Usuari ****" << endl;
    cout << "Nom: " << infoUsuari.nomComplertU << endl;
    cout << "Sobrenom: " << infoUsuari.sobrenomU << endl;
    cout << "Correu electronic: " << infoUsuari.correuU << endl;
    cout << "Data Naixement: " << infoUsuari.dataNaixementU << endl<<endl;
    cout << infoCompres.totalVideojocs << " videojocs comprats" << endl;
    cout << infoCompres.totalPaquets << " paquet de videojocs comprats" << endl;
    cout << infoCompres.totalEuros << " euros gastats en total" << endl << endl;

    


   
}

void CapaPresentacio::modificarUsuari() {
    // Lógica para modificar usuario
    // ...
    CtrlModificaUsuari ctrlModificaUsuari;
    TxConsultaUsuari::Resultat infoU = ctrlModificaUsuari.consultaUsuari();
    clearScreen();
    cout << "**** Consulta  Usuari ****" << endl;
    cout << "Nom: " << infoU.nomComplertU << endl;
    cout << "Sobrenom: " << infoU.sobrenomU << endl;
    cout << "Correu electronic: " << infoU.correuU << endl;
    cout << "Data Naixement: " << infoU.dataNaixementU << endl << endl;

    string nomU;
    string contraU;
    string correU;
    string neixU;
    cout << "Omplir la informacio que es vol modificar ..." << endl;
    cout << "nom Complert: " ;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, nomU);

    cout << "Contrasenya: ";
    getline(cin, contraU);
    

    cout << "Correu electronic: ";
    getline(cin, correU);
    
    cout << "Data naixament(DD / MM / AAAA) :";

    getline(cin, neixU);


    

    clearScreen();
    try {
        ctrlModificaUsuari.modificaUsuari(nomU, contraU, correU, neixU);
        infoU = ctrlModificaUsuari.consultaUsuari();
        cout << "**** Dades usuari modificades ****" << endl;
        cout << "Nom: " << infoU.nomComplertU << endl;
        cout << "Sobrenom: " << infoU.sobrenomU << endl;
        cout << "Correu electronic: " << infoU.correuU << endl;
        cout << "Data Naixement: " << infoU.dataNaixementU << endl << endl;
    }
    catch (const std::exception& e) {
        cerr << e.what() << endl;
       
    }



}

void CapaPresentacio::esborrarUsuari() {
    // Lógica para esborrar usuario
    // ...
    cout << "Per confirmar l'esborrat, s'ha de entrar la contrasenya... " << endl;
    cout << "Contrasenya: ";
    string contraU;
    cin >> contraU;
    TxEsborraUsuari txEsborraUsuari = TxEsborraUsuari::crear(contraU);
    clearScreen();
    try {
        txEsborraUsuari.executa();
        cout << "Usuari esborrat correctament!!" << endl;
        usuarioLoggeado = false;
    }
    catch (const std::exception& e) {
        cerr << e.what() << endl;

    }
    
    
}

void CapaPresentacio::comprarVideojoc() {
    // Logica para comprar videojocs
    // ...
    string nomVideojoc;
    clearScreen;
    cout << "***Comprar Videojoc***" << endl;
    cout << "Nom videojoc: ";
    cin >> nomVideojoc; 
    try {
        TxConsultaVideojoc txConsultaVideojoc = TxConsultaVideojoc::crear(nomVideojoc);
        TxConsultaVideojoc::Resultat resultat = txConsultaVideojoc.obteResultat();
        cout << "Nom Videojoc: " << resultat.nomVideojoc << endl;
        cout << "Descripcio: " << resultat.descripcio << endl;
        cout << "Qualificacio edad: " << resultat.qualificacio << endl;
        cout << "Genere: " << resultat.genere << endl;
        cout << "Data llansament: " << resultat.dataLlansament << endl;
        cout << "Preu: " << resultat.preu << endl;
        cout << "VOLS CONTINUAR AMB LA COMPRA(S/N): ";
        string opcio;
        cin >> opcio;
        transform(opcio.begin(), opcio.end(), opcio.begin(), ::tolower);
        if (opcio == "s") {
            TxComprarVideojoc txComprarVideojoc(nomVideojoc);
            string data = txComprarVideojoc.obteData();
            vector<PassarellaElemCompra> videojocsRel = txComprarVideojoc.obteVideojocsRelacionats();
            cout << "Compra registrada: " << data << endl;
            cout << "Jocs Relacionats" << endl;
            for (int i = 0; i < videojocsRel.size();++i){
                cout << videojocsRel[i].obteNom() << "; " << videojocsRel[i].obteDescripcio() <<"; "<< videojocsRel[i].obtePreu() << endl;
            
            }
            cout << endl;


        }

    }
    catch (const std::exception& e) {
        cerr << e.what() << endl;

    }
    

    
    
}

void CapaPresentacio::comprarPaquetVideojoc() {
    // Logica para comprar paquetes de videojocs
    // ...
    cout << "***COMPRAR PAQUET***" << endl;
    cout << "Nom paquet: ";
    string nomPaquet;
    cin >> nomPaquet;
    try {
        TxComprarPaquet txComprarPaquet(nomPaquet);
        TxComprarPaquet::Resultat infoPaquet = txComprarPaquet.obteInfoPaquet();
        cout << "Nom paquet: " << infoPaquet.nom << endl;
        cout << "Descripcio: " << infoPaquet.descripcio << endl;
        cout << "Preu: " << infoPaquet.preu << " (estalvi de " << txComprarPaquet.obteEstalvi() << " euros )" << endl << endl;
        vector<TxComprarPaquet::Resultat> jocsContinguts = txComprarPaquet.obteJocsContinguts();
        cout << "Jocs inclosos: " << endl;
        for (int i = 0; i < jocsContinguts.size();++i) {
            cout << "-" << jocsContinguts[i].nom << "; " << jocsContinguts[i].descripcio << "; " << jocsContinguts[i].preu << " euros." << endl;

        }
        cout << "Vols continuar amb la compra(S/N):";
        string opcio;
        cin >> opcio;
        transform(opcio.begin(), opcio.end(), opcio.begin(), ::tolower);
        if (opcio == "s") {
            txComprarPaquet.Comprar();
            cout << "Compra registrada: " << txComprarPaquet.obteData() << endl;
            cout << endl;
        }
    }
    catch (const std::exception& e) {
        cerr << e.what() << endl;

    }
    
}

    void CapaPresentacio::consultarCompres() {
        TxConsultaCompres txConsultaCompres;
        vector<TxConsultaCompres::Paquet>elem= txConsultaCompres.obteTotsElem();

        for (const auto& paquet : elem) {
            cout<< paquet.data;
            cout << ": ";
            if (paquet.videojocs.empty())cout << "Videojoc";
            else {
                cout << "Paquet";
            }
            cout << " " << paquet.nom << "; " << paquet.descripcio << "; " << paquet.preu << " euros" << endl;
            // Iterar sobre cada videojuego dentro del paquete
            if (not paquet.videojocs.empty())cout << "    Videojocs:" << endl;
            for (const auto& videojoc : paquet.videojocs) {
                cout << "       ";
                cout << videojoc.nom << "; " << videojoc.descripcio << "; " << videojoc.preu << " euros" << endl;
            }
            std::cout << std::endl;  
        }
        cout << "Total: " << txConsultaCompres.obtepreu() <<" euros "<< endl;

}
void CapaPresentacio::consultarVideojoc() {
    string nomVideojoc;
    clearScreen;
    cout << "**** Consultar Videojoc ****" << endl;
    cout << "Nom videojoc: ";
    cin >> nomVideojoc;
    try {
        TxConsultaVideojoc txConsultaVideojoc = TxConsultaVideojoc::crear(nomVideojoc);
        TxConsultaVideojoc::Resultat resultat = txConsultaVideojoc.obteResultat();
        cout << "Nom Videojoc: " << resultat.nomVideojoc << endl;
        cout << "Descripcio: " << resultat.descripcio << endl;
        cout << "Qualificacio edad: " << resultat.qualificacio << endl;
        cout << "Genere: " << resultat.genere << endl;
        cout << "Data llansament: " << resultat.dataLlansament << endl;
        cout << "Preu: " << resultat.preu << endl;
        vector<string>paquets = txConsultaVideojoc.obtePaquets();
        cout << "Paquets on esta inclos : ";
        for (int i = 0; i < paquets.size();++i) {
            cout << paquets[i] << " ";
        }
        cout << endl;

         
    }
    catch (const std::exception& e) {
        cerr << e.what() << endl;

    }



}

void CapaPresentacio::consultarVideojocs() {
    CtrlConsultarVideojocs ctrlConsultarVideojocs;
    vector<TxConsultaVideojoc::Resultat> videojocs = ctrlConsultarVideojocs.obteResultats();
   list< vector<string>>paquets = ctrlConsultarVideojocs.obtePaquets();
     cout << "**** Consultar Videojocs ****" << endl;
    for (int i = 0; i < videojocs.size();++i) {
        cout << "Nom Videojoc: " << videojocs[i].nomVideojoc << endl;
        cout << "Descripcio: " << videojocs[i].descripcio << endl;
        cout << "Qualificacio edad: " << videojocs[i].qualificacio << endl;
        cout << "Genere: " << videojocs[i].genere << endl;
        cout << "Data llansament: " << videojocs[i].dataLlansament << endl;
        cout << "Preu: " << videojocs[i].preu << endl;
       
        cout << "Paquets on esta inclos : ";
        if (!paquets.empty()) {
            for (int j = 0;j < paquets.front().size();++j) {
                cout << paquets.front()[j] << " ";
            }
            paquets.pop_front();
        }
        cout << endl << endl;
    }
   

  
}

void CapaPresentacio::consultarVideojocsEdat() {
    cout << "Edat maxima(anys) : ";
    float edat;
    cin >> edat;
    CtrlConsultarVideojocsEdat ctrlConsultarVideojocsEdat(edat);
    vector<TxConsultaVideojoc::Resultat> videojocs = ctrlConsultarVideojocsEdat.obteResultats();
    list< vector<string>>paquets = ctrlConsultarVideojocsEdat.obtePaquets();
    cout << "**** Consultar Videojocs ****" << endl;
    for (int i = 0; i < videojocs.size();++i) {
        cout << "Nom Videojoc: " << videojocs[i].nomVideojoc << endl;
        cout << "Descripcio: " << videojocs[i].descripcio << endl;
        cout << "Qualificacio edad: " << videojocs[i].qualificacio << endl;
        cout << "Genere: " << videojocs[i].genere << endl;
        cout << "Data llansament: " << videojocs[i].dataLlansament << endl;
        cout << "Preu: " << videojocs[i].preu << endl;

        cout << "Paquets on esta inclos : ";
        if (!paquets.empty()) {
            for (int j = 0;j < paquets.front().size();++j) {
                cout << paquets.front()[j] << " ";
            }
            paquets.pop_front();
        }
        cout << endl << endl;
    }

}

void CapaPresentacio::consultarNovetatsVideojocs() {
    // Lógica para consultar las novedades de videojocs
    // ...
    cout << "**** Consultar Novetats Videojocs ****" << endl;
    cout << "Data(AAAA/MM/DD)";
    string data;
    cin >> data;
    CtrlConsultarNovetats ctrlConsultarNovetats(data);
    vector<TxConsultaVideojoc::Resultat> videojocs = ctrlConsultarNovetats.obteResultats();
    list< vector<string>>paquets = ctrlConsultarNovetats.obtePaquets();
    cout << "**** Consultar Videojocs ****" << endl;
    for (int i = 0; i < videojocs.size();++i) {
        cout << "Nom Videojoc: " << videojocs[i].nomVideojoc << endl;
        cout << "Descripcio: " << videojocs[i].descripcio << endl;
        cout << "Qualificacio edad: " << videojocs[i].qualificacio << endl;
        cout << "Genere: " << videojocs[i].genere << endl;
        cout << "Data llansament: " << videojocs[i].dataLlansament << endl;
        cout << "Preu: " << videojocs[i].preu << endl;

        cout << "Paquets on esta inclos : ";
        if (!paquets.empty()) {
            for (int j = 0;j < paquets.front().size();++j) {
                cout << paquets.front()[j] << " ";
            }
            paquets.pop_front();
        }
        cout << endl << endl;
    }

}

void CapaPresentacio::consultarPaquet() {
    cout << "***CONSULTA PAQUET***" << endl;
    cout << "Nom paquet: ";
    string nomPaquet;
    cin >> nomPaquet;
    try {
        TxConsultarPaquet txConsultarPaquet(nomPaquet);
        TxConsultarPaquet::Resultat infoPaquet = txConsultarPaquet.obteInfoPaquet();
        cout << "Nom paquet: " << infoPaquet.nom << endl;
        cout << "Descripcio: " << infoPaquet.descripcio << endl;
        cout << "Preu: " << infoPaquet.preu << " (estalvi de " << txConsultarPaquet.obteEstalvi() << " euros )" << endl << endl;
        vector<TxConsultarPaquet::Resultat> jocsContinguts = txConsultarPaquet.obteJocsContinguts();
        cout << "Jocs inclosos: " << endl;
        for (int i = 0; i < jocsContinguts.size();++i) {
            cout << "-" << jocsContinguts[i].nom << "; " << jocsContinguts[i].descripcio << "; " << jocsContinguts[i].preu << " euros." << endl;

        }
      
    }
    catch (const std::exception& e) {
        cerr << e.what() << endl;

    }

}

void CapaPresentacio::consultarPaquets() {
    // Lógica para consultar todos los paquetes de videojocs
    // ...
    CtrlConsultarPaquets ctrlConsultarPaquets;
    vector<CtrlConsultarPaquets::Resultat> paquets = ctrlConsultarPaquets.obtepaquets();
    cout << "**** Consultar Paquets Videojocs ****" << endl;
    for (int i = 0; i < paquets.size();++i) {
        cout << paquets[i].info.nom << "; " << paquets[i].info.descripcio << "; " << paquets[i].info.preu << "euros (estalvi " << paquets[i].estalvi<<")"<<endl;
    }
    // Agregar lógica específica aquí
}