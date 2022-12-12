#pragma once
#include<string>
#include "struktury/sorted_sequence_table.h"
#include "struktury/heap_monitor.h"
#include "UzemnaJednotka.h"


using namespace std;
class Kraj:public UzemnaJednotka
{
	
public:
	Kraj(string pNazovKraja, int pocZapVol1K, int pocVydOb1K, int pocOdOb1K, int pocOdHl1K, int pocZapVol2k, int pocVydOb2K, int pocOdOb2K, int pocOdHl2K);
	~Kraj();
	

};

