#pragma once
#include <pqxx/pqxx>
class CercadoraUsuari {
	public:
		pqxx::result cercaUsuari(const std::string &sobrenom);
		
	

};