#include <iostream>
#include <fstream>
#include <string>
#include "ReadConnection.h"

std::string ReadConnectionString(const std::string& configFilePath) {
    std::ifstream configFile(configFilePath);
    std::string connectionString;

    if (configFile.is_open()) {
        std::string line;
        while (std::getline(configFile, line)) {
            connectionString += line + " ";
        }
        configFile.close();
    }
    else {
        std::cerr << "Error al abrir el archivo de configuración." << std::endl;
    }

    return connectionString;
}
