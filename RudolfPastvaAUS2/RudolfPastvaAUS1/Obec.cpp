#include "Obec.h"



Obec::Obec(string pNazov, int pocZapVol1K, int pocVydOb1K, int pocOdOb1K, int pocOdHl1K, int pocZapVol2k, int pocVydOb2K, int pocOdOb2K, int pocOdHl2K) :UzemnaJednotka(pNazov, pocZapVol1K, pocVydOb1K, pocOdOb1K, pocOdHl1K, pocZapVol2k, pocVydOb2K, pocOdOb2K, pocOdHl2K)
{
	
	
}


Obec::~Obec()
{
	/*for (int i = 0; i < 17; i++)
	{
		delete kandidati[i];
	}*/
}




bool Obec::prislusnostObce(string vyssiaUzOblast)
{
	
	if ((vyssiaUzOblast.compare(getVyssiUzemnyCelokOkres()) == 0) || vyssiaUzOblast.compare(getVyssiUzemnyCelokKraj()) == 0)
		return true;


	return false;
}

void Obec::setVyssiUzemnyCelok(Okres * ptrvyssiUzemnyCelok)
{
	vyssiUzemnyCelok = ptrvyssiUzemnyCelok;
	vyssiaUzemnaJednotka = ptrvyssiUzemnyCelok;
}

string Obec::getVyssiUzemnyCelokKraj()
{
	return vyssiUzemnyCelok->getVyssiUzemnyCelok();
}



string Obec::getVyssiUzemnyCelokOkres()
{
	return vyssiUzemnyCelok->getNazov();
}
