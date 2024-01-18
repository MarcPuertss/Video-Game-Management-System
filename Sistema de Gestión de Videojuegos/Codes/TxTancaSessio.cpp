#include "TxTancaSessio.h"
#include "Videoconsola.h"
TxTancaSessio::TxTancaSessio() {

}
TxTancaSessio TxTancaSessio::crear()
{
	return TxTancaSessio();
}

void TxTancaSessio::executar()
{
	Videoconsola& v = Videoconsola::getInstance();
	v.tancaSessio();
}
