#pragma once
#include <iostream>
#include <vector>
#include "TxConsultarPaquet.h"
using namespace std;
class CtrlConsultarPaquets {

public:
	struct Resultat{
		TxConsultarPaquet::Resultat info;
		float estalvi;
	};
	CtrlConsultarPaquets();
	
	vector<Resultat> obtepaquets();

private:
	vector<Resultat> infoPaquets;



};