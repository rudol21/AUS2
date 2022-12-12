#include "Kraj.h"



Kraj::Kraj(string pNazovKraja, int pocZapVol1K, int pocVydOb1K, int pocOdOb1K, int pocOdHl1K, int pocZapVol2k, int pocVydOb2K, int pocOdOb2K, int pocOdHl2K) :UzemnaJednotka(pNazovKraja, pocZapVol1K, pocVydOb1K, pocOdOb1K, pocOdHl1K, pocZapVol2k, pocVydOb2K, pocOdOb2K, pocOdHl2K)
{

}

Kraj::~Kraj()
{
	/*for (auto p : okresyKraja)
	{
		delete p->accessData();
	}*/
}
