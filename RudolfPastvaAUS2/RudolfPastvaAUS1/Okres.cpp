#include "Okres.h"


Okres::Okres(string pNazovOkresu, int pocZapVol1K, int pocVydOb1K, int pocOdOb1K, int pocOdHl1K, int pocZapVol2k, int pocVydOb2K, int pocOdOb2K, int pocOdHl2K) :UzemnaJednotka(pNazovOkresu, pocZapVol1K, pocVydOb1K, pocOdOb1K, pocOdHl1K, pocZapVol2k, pocVydOb2K, pocOdOb2K, pocOdHl2K)
{
	
}


Okres::~Okres()
{
	/*for (auto p : obceOkresu)
	{
		delete p->accessData();;
	}*/
}
void Okres::setVyssiUzemnyCelok(Kraj * ptrvyssiUzemnyCelok)
{
	vyssiUzemnyCelok = ptrvyssiUzemnyCelok;
	vyssiaUzemnaJednotka = ptrvyssiUzemnyCelok;
}

string Okres::getVyssiUzemnyCelok()
{
	return vyssiUzemnyCelok->getNazov();
}
