#pragma once
#include <iostream>
#include <string>
#include "UzemnaJednotka.h"
#include "Obec.h"
template<typename O, typename T>
class Kriterium
{
public:
	
	virtual T ohodnot(O& object) = 0;
	
};

class kNazov : public Kriterium<UzemnaJednotka, std::string>
{
private:
	UzemnaJednotka *uzOb;
public: 
	std::string ohodnot(UzemnaJednotka& a) override { return a.getNazov(); }

};

class kPrislusnostObce : public Kriterium<Obec, bool>
{
private:
	string vyssiaUzOblast;
public: 
	bool ohodnot(Obec& t) override { return t.prislusnostObce(vyssiaUzOblast); }
	void setVyssiaUzOblast(string u) { vyssiaUzOblast = u; };
};

class kVolici : public Kriterium<UzemnaJednotka, int>
{
private:
	int kolo = 0;
public:
	int ohodnot(UzemnaJednotka& object) override{return object.getPocetZapisanychVolicov(kolo);};
	void setKolo(int pKolo) { kolo = pKolo; };
};

class kVydaneObalky : public Kriterium<UzemnaJednotka, int>
{
private:
	int kolo = 0;
public:
	int ohodnot(UzemnaJednotka& object) override { return object.getPocetVydanychObalokVKole(kolo); };
	void setKolo(int pKolo) { kolo = pKolo; };
};

class kUcast : public Kriterium<UzemnaJednotka, double>
{
private:
	int kolo = 0;
public:
	double ohodnot(UzemnaJednotka& object) override { return object.getUcastVolicovVKole(kolo); };
	void setKolo(int pKolo) { kolo = pKolo; };
};

class kOdovzdaneObalky : public Kriterium<UzemnaJednotka, int>
{
private:
	int kolo = 0;
public:
	int ohodnot(UzemnaJednotka& object) override { return object.getPocetOdovzdanychObalokVKole(kolo); };
	void setKolo(int pKolo) { kolo = pKolo; };
};

class kPlatneHlasy : public Kriterium<UzemnaJednotka, int>// int pocOdovzdanychHlasov1Kolo;
{
private:
	int kolo = 0;
public:
	int ohodnot(UzemnaJednotka& object) override { return object.getPocetPlatnychHlasov(kolo); };
	void setKolo(int pKolo) { kolo = pKolo; };
};
//7.
class kHlasyOdovzdane : public Kriterium<UzemnaJednotka, int>
{
private:
	int kolo = 0;
	string kandidat;
public:
	int ohodnot(UzemnaJednotka& object) override { return object.getPocetOdovzdanychHlasov(kolo,kandidat); };
	void setKolo(int k) { kolo = k; };
	void setKandidat(string kand) { kandidat = kand; };
};

class kMeno : public Kriterium<Kandidat, string>
{
public:
	std::string ohodnot(Kandidat& object) override { return object.getMeno(); };
};

class kHlasyZiskaneKoaliciou : public Kriterium<UzemnaJednotka, int>
{
private:
	int kolo = 0;
	structures::ArrayList<int> kandKoalicie;
public:
	
	int ohodnot(UzemnaJednotka& object) override {
		int hlKoa = 0;
		for (int i = 0; i < kandKoalicie.size(); i++)
		{
			hlKoa = hlKoa + object.getHlasyKoalicie(kolo, kandKoalicie[i]);
		}		
		return hlKoa; };

	void setKolo(int k) { kolo = k; };
	void setKandidatovKoalicie(structures::ArrayList<int> pKandKoalicie) { kandKoalicie = pKandKoalicie; };

};