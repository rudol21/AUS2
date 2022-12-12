#pragma once

#include<string>
#include "struktury/sorted_sequence_table.h"
#include "struktury/heap_monitor.h"
#include "UzemnaJednotka.h"
#include "Kraj.h"

using namespace std;
class Okres:public UzemnaJednotka
{
	Kraj *vyssiUzemnyCelok = nullptr;
public:
	Okres(string pNazovOkresu, int pocZapVol1K, int pocVydOb1K, int pocOdOb1K, int pocOdHl1K, int pocZapVol2k, int pocVydOb2K, int pocOdOb2K, int pocOdHl2K) ;
	~Okres();
	void setVyssiUzemnyCelok(Kraj *ptrvyssiUzemnyCelok);
	string getVyssiUzemnyCelok();
};

