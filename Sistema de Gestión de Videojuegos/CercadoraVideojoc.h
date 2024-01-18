#pragma once
#include <pqxx/pqxx>
class CercadoraVideojoc {
public:
	pqxx::result cercaVideojoc(const std::string& nomVideojoc);
	CercadoraVideojoc();
	pqxx::result tots();



};