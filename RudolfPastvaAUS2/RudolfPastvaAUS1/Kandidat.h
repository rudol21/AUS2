#pragma once
#include<string>

using namespace std;
class Kandidat
{
	string meno;
	int pocetZiskanychHlasov = 0;
public:
	Kandidat(string pMeno);
	~Kandidat();
	string getMeno();
	int getPocetZiskanychHlasov();
	void setPocetZiskanychhlasov(int pocet);
};

