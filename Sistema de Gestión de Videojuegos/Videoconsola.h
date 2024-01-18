#pragma once
#include <iostream>
#include <pqxx/pqxx>
#include "PassarellaUsuari.h"
class Videoconsola{

private:
	PassarellaUsuari passarellaUsuari;
	Videoconsola();
public:
	static Videoconsola& getInstance() {
		static Videoconsola instance;
		return instance;
	}

	void iniciaSessio(pqxx::result usuari);
	void refrescaUsuari();
	void tancaSessio();
	PassarellaUsuari obteUsuari();

};
