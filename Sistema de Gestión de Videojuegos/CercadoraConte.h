#pragma once
#include <pqxx/pqxx>
class CercadoraConte {
public:
	static  pqxx::result cercaConteVideojoc(const std::string& videojoc);
	static pqxx::result cercaContePaquet(const std::string& paquet);
	CercadoraConte();

};
