#include "Videoconsola.h"
#include "PassarellaUsuari.h"
#include "Connexio.h"

Videoconsola::Videoconsola(){}

void Videoconsola::iniciaSessio(pqxx::result u) {
	passarellaUsuari = PassarellaUsuari(u);

}
void Videoconsola::refrescaUsuari() {
	Connexio instCon = Connexio();
	pqxx::work txn(instCon.ObtenirConnexio());
	std::string query ="SELECT * FROM public.usuari WHERE sobrenom = " + txn.quote(passarellaUsuari.obteSobrenom());

	pqxx::result result = txn.exec(query);
	passarellaUsuari = PassarellaUsuari(result);


}

void Videoconsola::tancaSessio()
{
	passarellaUsuari = PassarellaUsuari();

}

PassarellaUsuari Videoconsola::obteUsuari()
{
	return passarellaUsuari;
}


