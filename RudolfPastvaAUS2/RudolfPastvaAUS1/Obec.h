#pragma once
#include<string>
#include "struktury/array.h"
#include "struktury/heap_monitor.h"
#include "UzemnaJednotka.h"
#include "Okres.h"
using namespace std;
//using namespace structures;
class Obec:public UzemnaJednotka
{	
	Okres *vyssiUzemnyCelok = nullptr;
public:
	Obec(string pNazov, int pocZapVol1K, int pocVydOb1K, int pocOdOb1K, int pocOdHl1K, int pocZapVol2k, int pocVydOb2K, int pocOdOb2K, int pocOdHl2K);
		~Obec();
	
	bool prislusnostObce(string uzOb);
	void setVyssiUzemnyCelok(Okres *ptrvyssiUzemnyCelok);
	string getVyssiUzemnyCelokOkres();
	string getVyssiUzemnyCelokKraj();
	
};

