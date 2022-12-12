#include "Kandidat.h"



Kandidat::Kandidat(string pMeno)
{
	meno = pMeno;
}


Kandidat::~Kandidat()
{
}

string Kandidat::getMeno()
{
	return meno;
}

int Kandidat::getPocetZiskanychHlasov()
{
	return pocetZiskanychHlasov;
}

void Kandidat::setPocetZiskanychhlasov(int pocet)
{
	pocetZiskanychHlasov = pocetZiskanychHlasov + pocet;
}


