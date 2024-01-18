#include "CtrlConsultarPaquets.h"
#include "CercadoraVideojoc.h"
#include "CercadoraPaquet.h"

CtrlConsultarPaquets::CtrlConsultarPaquets()
{
	CercadoraPaquet cercadoraPaquet;
	pqxx::result totsPaquets = cercadoraPaquet.tots();
	for (int i = 0; i < totsPaquets.size();++i) {
		TxConsultarPaquet txConsultarPaquet(totsPaquets[i]["nom"].c_str());
		TxConsultarPaquet::Resultat resultat = txConsultarPaquet.obteInfoPaquet();
		Resultat res;
		res.info = resultat;
		res.estalvi = txConsultarPaquet.obteEstalvi();
		infoPaquets.push_back(res);
	}
}

vector<CtrlConsultarPaquets::Resultat> CtrlConsultarPaquets::obtepaquets()
{
	return infoPaquets;
}
