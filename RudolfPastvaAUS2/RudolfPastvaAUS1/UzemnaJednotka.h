#pragma once
#include <string>
#include "struktury/array.h"
#include "struktury/heap_monitor.h"
#include "Kandidat.h"
using namespace std;
class UzemnaJednotka
{
	string nazov;
	int pocZapisanychVolicov1Kolo;
	int pocVydanychObalok1Kolo;
	int pocOdovzdanychObalok1Kolo;
	int pocOdovzdanychHlasov1Kolo; 

	int pocZapisanychVolicov2Kolo;
	int pocVydanychObalok2Kolo;
	int pocOdovzdanychObalok2Kolo;
	int pocOdovzdanychHlasov2Kolo;
	structures::Array<Kandidat*> kandidati = structures::Array<Kandidat*>(17);
	bool jeObec = false;
protected:
	UzemnaJednotka * vyssiaUzemnaJednotka = nullptr;
public:
	UzemnaJednotka(string pNazov, int pocZapVol1K, int pocVydOb1K, int pocOdOb1K, int pocOdHl1K, int pocZapVol2k, int pocVydOb2K, int pocOdOb2K, int pocOdHl2K);
	~UzemnaJednotka();
	string getNazov();
	void setNazov(string pNazov);
	string getVyssieUzemnejednotky();
	UzemnaJednotka * getVyssiuUzemnuJednotku();
	void setJeObec();
	bool getJeObec();
	void setHlasyKandidat(int kandidat,int pocetHlasov);
	int getPocetZapisanychVolicov(int kolo);
	int getPocetVydanychObalokVKole(int kolo);
	double getUcastVolicovVKole(int kolo);
	int getPocetOdovzdanychObalokVKole(int kolo);
	int getPocetOdovzdanychHlasov(int kolo, string kandidat);
	int getPocetPlatnychHlasov(int kolo);
	int getHlasyKoalicie(int pKolo, int kandKoalicie);

	void setPocZapisanychVolicov1Kolo(int pocet);
	void setPocVydanychObalok1Kolo(int pocet);
	void setPocOdovzdanychObalok1Kolo(int pocet);
	void setPocOdovzdanychHlasov1Kolo(int pocet);
	void setPocZapisanychVolicov2Kolo(int pocet);
	void setPocVydanychObalok2Kolo(int pocet);
	void setPocOdovzdanychObalok2Kolo(int pocet);
	void setPocOdovzdanychHlasov2Kolo(int pocet);

	int getPocZapisanychVolicov1Kolo();
	int getPocVydanychObalok1Kolo();
	int getPocOdovzdanychObalok1Kolo();
	int getPocOdovzdanychHlasov1Kolo();
	int getPocZapisanychVolicov2Kolo();
	int getPocVydanychObalok2Kolo();
	int getPocOdovzdanychObalok2Kolo();
	int getPocOdovzdanychHlasov2Kolo();
	Kandidat * getKandidata(int index);
	
};

