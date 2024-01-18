#pragma once
#include <string>
#include <pqxx/pqxx>
class CercadoraPaquet {
public:
	pqxx::result cercaPaquet(const std::string& paquet);
	CercadoraPaquet();
	pqxx::result tots();



};