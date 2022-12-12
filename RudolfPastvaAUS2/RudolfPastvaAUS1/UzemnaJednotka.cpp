#include "UzemnaJednotka.h"



UzemnaJednotka::UzemnaJednotka(string pNazov, int pocZapVol1K, int pocVydOb1K, int pocOdOb1K, int pocOdHl1K, int pocZapVol2k, int pocVydOb2K, int pocOdOb2K, int pocOdHl2K)
{
	nazov = pNazov;
	pocZapisanychVolicov1Kolo = pocZapVol1K;
	pocVydanychObalok1Kolo = pocVydOb1K;
	pocOdovzdanychObalok1Kolo = pocOdOb1K;
	pocOdovzdanychHlasov1Kolo = pocOdHl1K;

	pocZapisanychVolicov2Kolo = pocZapVol2k;
	pocVydanychObalok2Kolo = pocVydOb2K;
	pocOdovzdanychObalok2Kolo = pocOdOb2K;
	pocOdovzdanychHlasov2Kolo = pocOdHl2K;

	kandidati[0] = new Kandidat("Bugar");
	kandidati[1] = new Kandidat("Caputova");
	kandidati[2] = new Kandidat("Dano");
	kandidati[3] = new Kandidat("Harabin");
	kandidati[4] = new Kandidat("Chmelar");
	kandidati[5] = new Kandidat("Kotleba");
	kandidati[6] = new Kandidat("Krajniak");
	kandidati[7] = new Kandidat("Menyhart");
	kandidati[8] = new Kandidat("Miklosko");
	kandidati[9] = new Kandidat("Mistrik");
	kandidati[10] = new Kandidat("Sefcovic");
	kandidati[11] = new Kandidat("Svec");
	kandidati[12] = new Kandidat("Tauchmannova");
	kandidati[13] = new Kandidat("Zabojnik");
	kandidati[14] = new Kandidat("Zuzula");
	kandidati[15] = new Kandidat("Caputova");
	kandidati[16] = new Kandidat("Sefcovic");
}


UzemnaJednotka::~UzemnaJednotka()
{
	for (int i = 0; i < 17; i++)
	{
		delete kandidati[i];
	}
}

string UzemnaJednotka::getNazov()
{
	return nazov;
}

void UzemnaJednotka::setNazov(string pNazov)
{
	nazov = pNazov;
}

string UzemnaJednotka::getVyssieUzemnejednotky()
{
	string retazec = "";
	if (vyssiaUzemnaJednotka != nullptr && vyssiaUzemnaJednotka->getVyssiuUzemnuJednotku()!=nullptr)
	{
		retazec = ", patri do okresu " + vyssiaUzemnaJednotka->getNazov() + " a kraja " + vyssiaUzemnaJednotka->getVyssiuUzemnuJednotku()->getNazov();
	}
	if (vyssiaUzemnaJednotka != nullptr && vyssiaUzemnaJednotka->getVyssiuUzemnuJednotku() == nullptr)
	{
		retazec = ",patri do kraja " + vyssiaUzemnaJednotka->getNazov();
	}
	return retazec;
}

UzemnaJednotka * UzemnaJednotka::getVyssiuUzemnuJednotku()
{
	return vyssiaUzemnaJednotka;
}

void UzemnaJednotka::setJeObec()
{
	!jeObec;
}

bool UzemnaJednotka::getJeObec()
{
	return jeObec;
}

void UzemnaJednotka::setHlasyKandidat(int kandidat, int pocetHlasov)
{
	kandidati[kandidat]->setPocetZiskanychhlasov(pocetHlasov);
}



int UzemnaJednotka::getPocetZapisanychVolicov(int kolo)
{
	if(kolo ==1)
		return pocZapisanychVolicov1Kolo;
	if(kolo == 2)
		return pocZapisanychVolicov2Kolo;
}

int UzemnaJednotka::getPocetVydanychObalokVKole(int kolo)
{
	if (kolo == 1)
		return pocVydanychObalok1Kolo;
	if (kolo == 2)
		return pocVydanychObalok2Kolo;
	if (kolo == 0)
		return pocVydanychObalok1Kolo + pocVydanychObalok2Kolo;
}

double UzemnaJednotka::getUcastVolicovVKole(int kolo)
{
	double pom;
	if (kolo == 1)
	{
		pom = pocZapisanychVolicov1Kolo / 100.0;
		return pocVydanychObalok1Kolo/ pom;
	}
	if (kolo == 2)
	{
		pom = pocZapisanychVolicov2Kolo / 100.0;
		return pocVydanychObalok2Kolo / pom;
	}
}

int UzemnaJednotka::getPocetOdovzdanychObalokVKole(int kolo)
{
	if (kolo == 1)
		return pocOdovzdanychObalok1Kolo;
	if (kolo == 2)
		return pocOdovzdanychObalok2Kolo;
	if (kolo == 0)
		return pocOdovzdanychObalok1Kolo + pocOdovzdanychObalok2Kolo;
}

int UzemnaJednotka::getPocetOdovzdanychHlasov(int kolo, string kandidat)
{
	if (kolo == 1)
	{
		for (int i = 0; i < 15; i++)
		{
			if (kandidat.compare(kandidati[i]->getMeno()) == 0)
			{
				return kandidati[i]->getPocetZiskanychHlasov();
			}
		}
	}
	if (kolo = 2)
	{
		if (kandidat.compare(kandidati[15]->getMeno()) == 0)
		{
			return kandidati[15]->getPocetZiskanychHlasov();
		}
		if (kandidat.compare(kandidati[16]->getMeno()) == 0)
		{
			return kandidati[16]->getPocetZiskanychHlasov();
		}
	}
	return -1;
}

int UzemnaJednotka::getPocetPlatnychHlasov(int kolo)
{
	if (kolo == 1)
		return pocOdovzdanychHlasov1Kolo;
	if (kolo == 2)
		return pocOdovzdanychHlasov2Kolo;
}

int UzemnaJednotka::getHlasyKoalicie(int pKolo, int kandKoalicie)
{
	if (pKolo == 1)
		return kandidati[kandKoalicie]->getPocetZiskanychHlasov();
	if (pKolo == 2)
	{
		if (kandKoalicie == 1)
		{
			kandKoalicie = 15;
			return kandidati[kandKoalicie]->getPocetZiskanychHlasov();
		}
		if (kandKoalicie == 10)
		{
			kandKoalicie = 16;
			return kandidati[kandKoalicie]->getPocetZiskanychHlasov();
		}
		return 0;
	}
	if (pKolo == 0)
	{
		if (kandKoalicie == 1)
		{
			return kandidati[kandKoalicie]->getPocetZiskanychHlasov() + kandidati[15]->getPocetZiskanychHlasov();
		}
		if (kandKoalicie == 10)
		{
			return kandidati[kandKoalicie]->getPocetZiskanychHlasov() + kandidati[16]->getPocetZiskanychHlasov();
		}
		return kandidati[kandKoalicie]->getPocetZiskanychHlasov();
	}

}


void UzemnaJednotka::setPocZapisanychVolicov1Kolo(int pocet)
{
	pocZapisanychVolicov1Kolo = pocZapisanychVolicov1Kolo+pocet;
}

void UzemnaJednotka::setPocVydanychObalok1Kolo(int pocet)
{
	pocVydanychObalok1Kolo = pocVydanychObalok1Kolo + pocet;
}

void UzemnaJednotka::setPocOdovzdanychObalok1Kolo(int pocet)
{
	pocOdovzdanychObalok1Kolo = pocOdovzdanychObalok1Kolo + pocet;
}

void UzemnaJednotka::setPocOdovzdanychHlasov1Kolo(int pocet)
{
	pocOdovzdanychHlasov1Kolo = pocOdovzdanychHlasov1Kolo + pocet;
}

void UzemnaJednotka::setPocZapisanychVolicov2Kolo(int pocet)
{
	pocZapisanychVolicov2Kolo = pocZapisanychVolicov2Kolo + pocet;
}

void UzemnaJednotka::setPocVydanychObalok2Kolo(int pocet)
{
	pocVydanychObalok2Kolo = pocVydanychObalok2Kolo + pocet;
}

void UzemnaJednotka::setPocOdovzdanychObalok2Kolo(int pocet)
{
	pocOdovzdanychObalok2Kolo = pocOdovzdanychObalok2Kolo + pocet;
}

void UzemnaJednotka::setPocOdovzdanychHlasov2Kolo(int pocet)
{
	pocOdovzdanychHlasov2Kolo = pocOdovzdanychHlasov2Kolo + pocet;
}

int UzemnaJednotka::getPocZapisanychVolicov1Kolo()
{
	return pocZapisanychVolicov1Kolo;
}

int UzemnaJednotka::getPocVydanychObalok1Kolo()
{
	return pocVydanychObalok1Kolo;
}

int UzemnaJednotka::getPocOdovzdanychObalok1Kolo()
{
	return pocOdovzdanychObalok1Kolo;
}

int UzemnaJednotka::getPocOdovzdanychHlasov1Kolo()
{
	return pocOdovzdanychHlasov1Kolo;
}

int UzemnaJednotka::getPocZapisanychVolicov2Kolo()
{
	return pocZapisanychVolicov2Kolo;
}

int UzemnaJednotka::getPocVydanychObalok2Kolo()
{
	return pocVydanychObalok2Kolo;
}

int UzemnaJednotka::getPocOdovzdanychObalok2Kolo()
{
	return pocOdovzdanychObalok2Kolo;
}

int UzemnaJednotka::getPocOdovzdanychHlasov2Kolo()
{
	return pocOdovzdanychHlasov2Kolo;
}

Kandidat * UzemnaJednotka::getKandidata(int index)
{
	return kandidati[index];
}


