#include "Stat.h"
#include <algorithm>
#include <math.h>  

Stat::Stat()
{
	
}


Stat::~Stat()
{
	for (auto p : uzemneJednotky)
	{
		
		delete p->accessData();
	}
}

void Stat::vipisInformacieUzemnaJednotka(UzemnaJednotka * uzJed)
{
	kriterium_volici.setKolo(1);
	kriterium_vydane_obalky.setKolo(1);
	kriterium_ucast.setKolo(1);
	kriterium_odovzdane_obalky.setKolo(1);
	kriterium_platne_hlasy.setKolo(1);
	cout << "Nazov: " << kriterium_Nazov.ohodnot(*uzJed)<< uzJed->getVyssieUzemnejednotky()<< endl << "pocet zapisanych volicov v 1 kole: " << kriterium_volici.ohodnot(*uzJed) << endl << "pocet vydanych obalok 1 kolo: " << kriterium_vydane_obalky.ohodnot(*uzJed) << endl;
	cout << "ucast v 1 kole: " << kriterium_ucast.ohodnot(*uzJed) << "%" << endl << "pocet odovzdanych obalok v 1 kole: " << kriterium_odovzdane_obalky.ohodnot(*uzJed) << endl << "pocet platnych hlasov v 1 kole: " << kriterium_platne_hlasy.ohodnot(*uzJed) << endl;
	kriterium_volici.setKolo(2);
	kriterium_vydane_obalky.setKolo(2);
	kriterium_ucast.setKolo(2);
	kriterium_odovzdane_obalky.setKolo(2);
	kriterium_platne_hlasy.setKolo(2);
	cout << "pocet zapisanych volicov v 2 kole: " << kriterium_volici.ohodnot(*uzJed) << endl << "pocet vydanych obalok 2 kolo: " << kriterium_vydane_obalky.ohodnot(*uzJed) << endl;
	cout << "ucast v 2 kole: " << kriterium_ucast.ohodnot(*uzJed) << "%" << endl << "pocet odovzdanych obalok v 2 kole: " << kriterium_odovzdane_obalky.ohodnot(*uzJed) << endl << "pocet odovzdanych hlasov v 2 kole: " << kriterium_platne_hlasy.ohodnot(*uzJed)<<endl<<endl;
	
}

void Stat::nacitaj(const char *menoSuboru)
{
	string krajPredchadzajuci = "";
	string okresPredchadzajuci = "";
	string kraj = "";
	string okres = "";
	string obec = "";
	int pomPocZapisanychVolicov1Kolo;
	int pomPocVydanychObalok1Kolo;
	int pomPocOdovzdanychObalok1Kolo;
	int pomPocOdovzdanychHlasov1Kolo; 
	int pomPocZapisanychVolicov2kolo;
	int pomPocVydanychObalok2Kolo;
	int pomPocOdovzdanychObalok2Kolo;
	int pomPocOdovzdanychHlasov2Kolo;
	int k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14, k15, k16;
	ifstream cin(menoSuboru);

	
	Kraj *kr;
	Okres *okr;
	UzemnaJednotka *uzObl;
	int rozlisenie;
	string ciarka;
	string slovo;
	for (int i = 0; i < 2926; ++i)
	{
		rozlisenie = 0;
		cin >> kraj;
		cin >> slovo;
		while (!(slovo.compare(",") == 0))
		{
			kraj = kraj + " " + slovo;
			cin >> slovo;
		}
		cin >> okres;
		cin >> slovo;
		while (!(slovo.compare(",") == 0))
		{
			okres = okres + " " + slovo;
			cin >> slovo;
		}
		cin >> obec;
		cin >> slovo;
		while (!(slovo.compare(",") == 0))
		{
			obec = obec + " " + slovo;
			cin >> slovo;
		}
		
		cin >> pomPocZapisanychVolicov1Kolo >> ciarka >> pomPocVydanychObalok1Kolo >> ciarka >> pomPocOdovzdanychObalok1Kolo >> ciarka >> pomPocOdovzdanychHlasov1Kolo >> ciarka;
		cin >> pomPocZapisanychVolicov2kolo >> ciarka >> pomPocVydanychObalok2Kolo >> ciarka >> pomPocOdovzdanychObalok2Kolo >> ciarka >> pomPocOdovzdanychHlasov2Kolo >> ciarka;
		cin >> k0 >> ciarka >> k1 >> ciarka >> k2 >> ciarka >> k3 >> ciarka >> k4 >> ciarka >> k5 >> ciarka >> k6 >> ciarka >> k7 >> ciarka >> k8 >> ciarka >> k9 >> ciarka >> k10 >> ciarka >> k11 >> ciarka >> k12 >> ciarka >> k13 >> ciarka >> k14 >> ciarka >> k15 >> ciarka >> k16;

		if (!(krajPredchadzajuci.compare(kraj) == 0))
		{
			
			kr = new Kraj(kraj, pomPocZapisanychVolicov1Kolo, pomPocVydanychObalok1Kolo, pomPocOdovzdanychObalok1Kolo, pomPocOdovzdanychHlasov1Kolo, pomPocZapisanychVolicov2kolo, pomPocVydanychObalok2Kolo, pomPocOdovzdanychObalok2Kolo, pomPocOdovzdanychHlasov2Kolo);
			uzemneJednotky.insert(kraj, kr);
			kr->setHlasyKandidat(0, k0);
			kr->setHlasyKandidat(1, k1);
			kr->setHlasyKandidat(2, k2);
			kr->setHlasyKandidat(3, k3);
			kr->setHlasyKandidat(4, k4);
			kr->setHlasyKandidat(5, k5);
			kr->setHlasyKandidat(6, k6);
			kr->setHlasyKandidat(7, k7);
			kr->setHlasyKandidat(8, k8);
			kr->setHlasyKandidat(9, k9);
			kr->setHlasyKandidat(10, k10);
			kr->setHlasyKandidat(11, k11);
			kr->setHlasyKandidat(12, k12);
			kr->setHlasyKandidat(13, k13);
			kr->setHlasyKandidat(14, k14);
			kr->setHlasyKandidat(15, k15);
			kr->setHlasyKandidat(16, k16);
			
		}
		if (!(okresPredchadzajuci.compare(okres) == 0))
		{
			okr = new Okres(okres, pomPocZapisanychVolicov1Kolo, pomPocVydanychObalok1Kolo, pomPocOdovzdanychObalok1Kolo, pomPocOdovzdanychHlasov1Kolo, pomPocZapisanychVolicov2kolo, pomPocVydanychObalok2Kolo, pomPocOdovzdanychObalok2Kolo, pomPocOdovzdanychHlasov2Kolo);			
			okr->setVyssiUzemnyCelok(kr);
			uzemneJednotky.insert(okres, okr);
			okr->setHlasyKandidat(0, k0);
			okr->setHlasyKandidat(1, k1);
			okr->setHlasyKandidat(2, k2);
			okr->setHlasyKandidat(3, k3);
			okr->setHlasyKandidat(4, k4);
			okr->setHlasyKandidat(5, k5);
			okr->setHlasyKandidat(6, k6);
			okr->setHlasyKandidat(7, k7);
			okr->setHlasyKandidat(8, k8);
			okr->setHlasyKandidat(9, k9);
			okr->setHlasyKandidat(10, k10);
			okr->setHlasyKandidat(11, k11);
			okr->setHlasyKandidat(12, k12);
			okr->setHlasyKandidat(13, k13);
			okr->setHlasyKandidat(14, k14);
			okr->setHlasyKandidat(15, k15);
			okr->setHlasyKandidat(16, k16);
		}

		Obec *ob = new Obec(obec, pomPocZapisanychVolicov1Kolo, pomPocVydanychObalok1Kolo, pomPocOdovzdanychObalok1Kolo, pomPocOdovzdanychHlasov1Kolo, pomPocZapisanychVolicov2kolo, pomPocVydanychObalok2Kolo, pomPocOdovzdanychObalok2Kolo, pomPocOdovzdanychHlasov2Kolo);
		ob->setVyssiUzemnyCelok(okr);
		ob->setHlasyKandidat(0,k0);
		ob->setHlasyKandidat(1,k1);
		ob->setHlasyKandidat(2,k2);
		ob->setHlasyKandidat(3,k3);
		ob->setHlasyKandidat(4,k4);
		ob->setHlasyKandidat(5,k5);
		ob->setHlasyKandidat(6,k6);
		ob->setHlasyKandidat(7,k7);
		ob->setHlasyKandidat(8,k8);
		ob->setHlasyKandidat(9,k9);
		ob->setHlasyKandidat(10,k10);
		ob->setHlasyKandidat(11,k11);
		ob->setHlasyKandidat(12,k12);
		ob->setHlasyKandidat(13,k13);
		ob->setHlasyKandidat(14,k14);
		ob->setHlasyKandidat(15, k15);
		ob->setHlasyKandidat(16, k16);
		while (uzemneJednotky.insert(obec, ob))
		{
			++rozlisenie;
			obec = obec + to_string(rozlisenie);
			ob->setNazov(obec);//asi
		}
		tabulkaObci.insert(obec,ob);
		if ((okresPredchadzajuci.compare(okres) == 0))
		{
			okr->setPocZapisanychVolicov1Kolo(pomPocZapisanychVolicov1Kolo);
			okr->setPocVydanychObalok1Kolo(pomPocVydanychObalok1Kolo);
			okr->setPocOdovzdanychObalok1Kolo(pomPocOdovzdanychObalok1Kolo);
			okr->setPocOdovzdanychHlasov1Kolo(pomPocOdovzdanychHlasov1Kolo);
			okr->setPocZapisanychVolicov2Kolo(pomPocZapisanychVolicov2kolo);
			okr->setPocVydanychObalok2Kolo(pomPocVydanychObalok2Kolo);
			okr->setPocOdovzdanychObalok2Kolo(pomPocOdovzdanychObalok2Kolo);
			okr->setPocOdovzdanychHlasov2Kolo(pomPocOdovzdanychHlasov2Kolo);
			okr->setHlasyKandidat(0, k0);
			okr->setHlasyKandidat(1, k1);
			okr->setHlasyKandidat(2, k2);
			okr->setHlasyKandidat(3, k3);
			okr->setHlasyKandidat(4, k4);
			okr->setHlasyKandidat(5, k5);
			okr->setHlasyKandidat(6, k6);
			okr->setHlasyKandidat(7, k7);
			okr->setHlasyKandidat(8, k8);
			okr->setHlasyKandidat(9, k9);
			okr->setHlasyKandidat(10, k10);
			okr->setHlasyKandidat(11, k11);
			okr->setHlasyKandidat(12, k12);
			okr->setHlasyKandidat(13, k13);
			okr->setHlasyKandidat(14, k14);
			okr->setHlasyKandidat(15, k15);
			okr->setHlasyKandidat(16, k16);
		}
		if ((krajPredchadzajuci.compare(kraj) == 0))
		{
			kr->setPocZapisanychVolicov1Kolo(pomPocZapisanychVolicov1Kolo);
			kr->setPocVydanychObalok1Kolo(pomPocVydanychObalok1Kolo);
			kr->setPocOdovzdanychObalok1Kolo(pomPocOdovzdanychObalok1Kolo);
			kr->setPocOdovzdanychHlasov1Kolo(pomPocOdovzdanychHlasov1Kolo);
			kr->setPocZapisanychVolicov2Kolo(pomPocZapisanychVolicov2kolo);
			kr->setPocVydanychObalok2Kolo(pomPocVydanychObalok2Kolo);
			kr->setPocOdovzdanychObalok2Kolo(pomPocOdovzdanychObalok2Kolo);
			kr->setPocOdovzdanychHlasov2Kolo(pomPocOdovzdanychHlasov2Kolo);
			kr->setHlasyKandidat(0, k0);
			kr->setHlasyKandidat(1, k1);
			kr->setHlasyKandidat(2, k2);
			kr->setHlasyKandidat(3, k3);
			kr->setHlasyKandidat(4, k4);
			kr->setHlasyKandidat(5, k5);
			kr->setHlasyKandidat(6, k6);
			kr->setHlasyKandidat(7, k7);
			kr->setHlasyKandidat(8, k8);
			kr->setHlasyKandidat(9, k9);
			kr->setHlasyKandidat(10, k10);
			kr->setHlasyKandidat(11, k11);
			kr->setHlasyKandidat(12, k12);
			kr->setHlasyKandidat(13, k13);
			kr->setHlasyKandidat(14, k14);
			kr->setHlasyKandidat(15, k15);
			kr->setHlasyKandidat(16, k16);
		}
		krajPredchadzajuci = kraj;
		okresPredchadzajuci = okres;
		
		
	}
	cin.close();
}



void Stat::fNazov_3a(string nazov)
{
	UzemnaJednotka *pom;
	filter_Nazov.setParameter(nazov);
	if (filter_Nazov.urciHodnotu(*uzemneJednotky[(nazov)], kriterium_Nazov))
	{
		pom = uzemneJednotky[(nazov)];
		vipisInformacieUzemnaJednotka(pom);
	}
}
template<typename O, typename T>
int Stat::vyhladanieBisekcia(int kluc, int dolnaHranica, int hornaHranica, structures::ArrayList<UzemnaJednotka*>& zoznam, Kriterium<O, T>& krit)
{
	
	int stred = (dolnaHranica + hornaHranica) / 2;
	if ((krit.ohodnot(*zoznam[stred]) == kluc) || (krit.ohodnot(*zoznam[stred-1]) < kluc && krit.ohodnot(*zoznam[stred+1]) > kluc))
		return stred;
	else
	{
		if (dolnaHranica == hornaHranica)
			return -1;
		else
		{
			if (krit.ohodnot(*zoznam[stred]) < kluc)
			{
				dolnaHranica = stred + 1;
				vyhladanieBisekcia(kluc, dolnaHranica, hornaHranica, zoznam, krit);
			}
			else
			{
				hornaHranica = stred;
				vyhladanieBisekcia(kluc, dolnaHranica, hornaHranica, zoznam, krit);
			}
		}
	}

}
void Stat::fVolici_3b(int OD, int DO, int pKolo)
{
	kriterium_volici.setKolo(pKolo);
	filter_volici.setParametre(OD,DO);
	
	for (auto p : uzemneJednotky)
	{
		if (filter_volici.urciHodnotu(*p->accessData(), kriterium_volici))
			vipisInformacieUzemnaJednotka(p->accessData());
	}
}

void Stat::fUcast_3c(int OD, int DO, int pKolo)
{
	kriterium_ucast.setKolo(pKolo);
	filter_ucast.setParametre(OD, DO);
	for (auto p : uzemneJednotky)
	{
		if (filter_ucast.urciHodnotu(*p->accessData(), kriterium_ucast))
			vipisInformacieUzemnaJednotka(p->accessData());
	}
}

void Stat::kNazov_4a(bool zostupne, int kolo, int OD, int DO, string prislusnost)
{
	kriterium_ucast.setKolo(kolo);
	filter_ucast.setParametre(OD,DO);
	kriterium_prislusnost_obce.setVyssiaUzOblast(prislusnost);
	structures::ArrayList<Obec*> docasnyZoznObci;
	
	for (auto p : tabulkaObci)
	{
		if (filter_prislusnost_obce.urciHodnotu(*p->accessData(), kriterium_prislusnost_obce) && filter_ucast.urciHodnotu(*p->accessData(), kriterium_ucast))
			docasnyZoznObci.add(p->accessData());
	}


	if (zostupne)
	{
		cout << "Usporiadanie zoztupne podla kriteria kNazov a filtrov (fUcast & fPrislusnostObce):" << endl;
		for (int i = docasnyZoznObci.size() - 1; i > -1; --i)
		{
			cout << kriterium_Nazov.ohodnot(*docasnyZoznObci[i]) << endl;
		}
	}

	if (!zostupne)
	{
		cout << "Usporiadanie vzoztupne podla kriteria kNazov a filtrov (fUcast & fPrislusnostObce):" << endl;
		for (int i = 0; i < docasnyZoznObci.size(); i++)
		{
			cout << kriterium_Nazov.ohodnot(*docasnyZoznObci[i]) << endl;
		}
	}
}

void Stat::kVolici_4b(bool zostupne, int kolo,int OD, int DO,string prislusnost)
{
	kriterium_ucast.setKolo(kolo);
	filter_ucast.setParametre(OD, DO);
	kriterium_prislusnost_obce.setVyssiaUzOblast(prislusnost);
	structures::ArrayList<Obec*> docasnyZoznObci;
	kriterium_volici.setKolo(kolo);

	for (auto p : tabulkaObci)
	{
		if (filter_prislusnost_obce.urciHodnotu(*p->accessData(), kriterium_prislusnost_obce) && filter_ucast.urciHodnotu(*p->accessData(), kriterium_ucast))
			docasnyZoznObci.add(p->accessData());
	}
	
	ShellSortObce(docasnyZoznObci.size() / 2, docasnyZoznObci, kriterium_volici);
	if (zostupne)
	{
		cout << "Usporiadanie zoztupne podla kriteria kVolici a filtrov (fUcast & fPrislusnostObce):" << endl;
	for (int i = docasnyZoznObci.size() - 1; i > -1; --i)
		{
			cout << kriterium_Nazov.ohodnot(*docasnyZoznObci[i]) << ": " << kriterium_volici.ohodnot(*docasnyZoznObci[i])<<" zapisanych volicov"<<  endl;
		}
	}

	if (!zostupne)
	{
		cout << "Usporiadanie vzoztupne podla kriteria kVolici a filtrov(fUcast & fPrislusnostObce):" << endl;
		for (int i = 0; i < docasnyZoznObci.size(); i++)
		{
			cout << kriterium_Nazov.ohodnot(*docasnyZoznObci[i]) << ": " << kriterium_volici.ohodnot(*docasnyZoznObci[i]) << " zapisanych volicov" << endl;
		}
	}
}

void Stat::kUcast_4c(bool zostupne, int kolo, int OD, int DO, string prislusnost)
{
	kriterium_ucast.setKolo(kolo);
	filter_ucast.setParametre(OD, DO);
	kriterium_prislusnost_obce.setVyssiaUzOblast(prislusnost);
	structures::ArrayList<Obec*> docasnyZoznObci;
	
	for (auto p : tabulkaObci)
	{
		if (filter_prislusnost_obce.urciHodnotu(*p->accessData(), kriterium_prislusnost_obce) && filter_ucast.urciHodnotu(*p->accessData(), kriterium_ucast))
			docasnyZoznObci.add(p->accessData()); 
	}
	ShellSortObce(docasnyZoznObci.size() / 2, docasnyZoznObci, kriterium_ucast);
	if (zostupne)
	{
		cout << "Usporiadanie zoztupne podla kriteria kVolici a filtrov (fUcast & fPrislusnostObce):" << endl;
		for (int i = docasnyZoznObci.size() - 1; i > -1; --i)
		{
			cout << kriterium_Nazov.ohodnot(*docasnyZoznObci[i]) << ": " << kriterium_ucast.ohodnot(*docasnyZoznObci[i]) <<"%"<< endl;
		}
	}

	if (!zostupne)
	{
		cout << "Usporiadanie vzoztupne podla kriteria kVolici a filtrov(fUcast & fPrislusnostObce):" << endl;
		for (int i = 0; i < docasnyZoznObci.size(); i++)
		{
			cout << kriterium_Nazov.ohodnot(*docasnyZoznObci[i]) << ": " << kriterium_ucast.ohodnot(*docasnyZoznObci[i]) << "%" << endl;
		}
	}
}

void Stat::vypisanieVysledkovKanVUzJednotke_5a(int volicZKola, structures::ArrayList<int> kandidati, string nazovUzJed, int koloPreKVydOb, int koloV, int voliciOd, int voliciDo, int koloU, int ucastOd, int ucastDo)
{
	
	kriterium_ucast.setKolo(koloU);
	filter_ucast.setParametre(ucastOd, ucastDo);
	kriterium_volici.setKolo(koloV);
	filter_volici.setParametre(voliciOd, voliciDo);
	filter_Nazov.setParameter(nazovUzJed);
	kriterium_vydane_obalky.setKolo(koloPreKVydOb);
	structures::ArrayList<UzemnaJednotka*> docasnyZoznamUzJed;

	for (auto p : uzemneJednotky)
	{
		if (filter_Nazov.urciHodnotu(*p->accessData(), kriterium_Nazov) && filter_volici.urciHodnotu(*p->accessData(), kriterium_volici) && filter_ucast.urciHodnotu(*p->accessData(), kriterium_ucast))
			docasnyZoznamUzJed.add(p->accessData());
	}
	cout << "Vypisanie vysledkov kandidatov v uzemnej jednotke:" << endl;
	for (int i = 0; i < docasnyZoznamUzJed.size(); i++)
	{
		cout << kriterium_Nazov.ohodnot(*docasnyZoznamUzJed[i]) << ": " <<endl;
		cout << "Pocet zapisanych volicov: " << kriterium_volici.ohodnot(*docasnyZoznamUzJed[i]) << endl << "Pocet vydanych obalok: " << kriterium_vydane_obalky.ohodnot(*docasnyZoznamUzJed[i]) << endl;
		if (volicZKola == 1)
		{
			for (int k = 0; k < 15  ; k++)
			{
				for (int j = 0; j < kandidati.size(); j++)
				{	filter_meno.setParameter(docasnyZoznamUzJed[i]->getKandidata(kandidati[j])->getMeno());
					if (filter_meno.urciHodnotu(*docasnyZoznamUzJed[i]->getKandidata(k), kriterium_meno))
					{
						cout << docasnyZoznamUzJed[i]->getKandidata(k)->getMeno() << ": " << docasnyZoznamUzJed[i]->getKandidata(k)->getPocetZiskanychHlasov() << " odovzdanych hlasov" << endl;
					}
				}
			}
		}
		if (volicZKola == 2)
		{
			for (int k = 15; k < 17; k++)
			{
				for (int j = 0; j < kandidati.size(); j++)
				{
					filter_meno.setParameter(docasnyZoznamUzJed[i]->getKandidata(kandidati[j])->getMeno());
					if (filter_meno.urciHodnotu(*docasnyZoznamUzJed[i]->getKandidata(k), kriterium_meno))
					{
						cout << docasnyZoznamUzJed[i]->getKandidata(k)->getMeno() << ": " << docasnyZoznamUzJed[i]->getKandidata(k)->getPocetZiskanychHlasov() << " odovzdanych hlasov" << endl;
					}
				}
			}
		}
		
	}

}

void Stat::zoradenieKandidatovPodlaVysledkovVUzemnychjednotkach_6a(int koloKHlasyZiskane, bool zostupne, structures::ArrayList<int> kandidati, string nazovUzJed, int koloV, int voliciOd, int voliciDo, int koloU, int ucastOd, int ucastDo)
{
	kriterium_ucast.setKolo(koloU);
	filter_ucast.setParametre(ucastOd, ucastDo);
	kriterium_volici.setKolo(koloV);
	filter_volici.setParametre(voliciOd, voliciDo);
	filter_Nazov.setParameter(nazovUzJed);
	structures::ArrayList<UzemnaJednotka*> docasnyZoznamUzJed;
	structures::ArrayList<Kandidat*> kandidatiNaZoradovanie;

	for (auto p : uzemneJednotky)
	{
		if (filter_Nazov.urciHodnotu(*p->accessData(), kriterium_Nazov) && filter_volici.urciHodnotu(*p->accessData(), kriterium_volici) && filter_ucast.urciHodnotu(*p->accessData(), kriterium_ucast))
			docasnyZoznamUzJed.add(p->accessData());
	}
	for (int i = 0; i < docasnyZoznamUzJed.size(); i++)
	{
		for (int k = 0; k < kandidati.size(); ++k)
		{
			kandidatiNaZoradovanie.add(docasnyZoznamUzJed[i]->getKandidata(kandidati[k]));
		}
		



		ShellSortKandidati(kandidatiNaZoradovanie.size()/2, kandidatiNaZoradovanie);
		cout << kriterium_Nazov.ohodnot(*docasnyZoznamUzJed[i]) << ": " << endl;
		if (zostupne)
		{
			cout << "Usporiadanie zoztupne podla ziskanych hlasov:" << endl;
			for (int k = kandidatiNaZoradovanie.size() - 1; k > -1; --k)
			{
				cout << kriterium_meno.ohodnot(*kandidatiNaZoradovanie[k]) << ": " << kandidatiNaZoradovanie[k]->getPocetZiskanychHlasov() << " hlasov" << endl;
			}
		}
		if (!zostupne)
		{
			cout << "Usporiadanie vzoztupne podla ziskanych hlasov:" << endl;
			for (int k = 0; k < kandidatiNaZoradovanie.size(); ++k)
			{
				cout << kriterium_meno.ohodnot(*kandidatiNaZoradovanie[k]) <<": "<< kandidatiNaZoradovanie[k]->getPocetZiskanychHlasov() <<" hlasov" <<endl;
			}
		}
		
		kandidatiNaZoradovanie.clear();
	}
}

void Stat::vypisanieVyberovýchKritérii_7a(int koloVybKr, string nazovUzJed, int koloV, int voliciOd, int voliciDo, int koloU, int ucastOd, int ucastDo)
{
	kriterium_ucast.setKolo(koloU);
	filter_ucast.setParametre(ucastOd, ucastDo);
	kriterium_volici.setKolo(koloV);
	filter_volici.setParametre(voliciOd, voliciDo);
	filter_Nazov.setParameter(nazovUzJed);
	structures::ArrayList<UzemnaJednotka*> docasnyZoznamUzJed;
	Kandidat * najviacHlasov;
	Kandidat * najmenejHlasov;

	for (auto p : uzemneJednotky)
	{
		if (filter_Nazov.urciHodnotu(*p->accessData(), kriterium_Nazov) && filter_volici.urciHodnotu(*p->accessData(), kriterium_volici) && filter_ucast.urciHodnotu(*p->accessData(), kriterium_ucast))
			docasnyZoznamUzJed.add(p->accessData());
	}
	for (int i = 0; i < docasnyZoznamUzJed.size(); i++)
	{
		najviacHlasov = vyberoveKNajviacHlasov(koloVybKr, docasnyZoznamUzJed[i]);
		najmenejHlasov = vyberoveKNajmenejHlasov(koloVybKr, docasnyZoznamUzJed[i]);
		cout << docasnyZoznamUzJed[i]->getNazov()  << ": " <<endl;
		cout << "Najviac hlasov ziskal kandidat: " << najviacHlasov->getMeno() << " " << najviacHlasov->getPocetZiskanychHlasov() << " hlasov" << endl;
		cout << "Najmenej hlasov ziskal kandidat: " << najmenejHlasov->getMeno() << " " << najmenejHlasov->getPocetZiskanychHlasov() << " hlasov" << endl;
		cout << vyberoveKNajstabilnejsieVysledky(docasnyZoznamUzJed[i]) <<endl;
	}
}

void Stat::zoradenieFiktivnejKoalicie_8a(bool zostupne, int kolo, structures::ArrayList<int> kandKoalicie, string nazov, int koloV, int voliciOd, int voliciDo, int koloU, int ucastOd, int ucastDo)
{
	kriterium_ucast.setKolo(koloU);
	filter_ucast.setParametre(ucastOd, ucastDo);
	kriterium_volici.setKolo(koloV);
	filter_volici.setParametre(voliciOd, voliciDo);
	filter_Nazov.setParameter(nazov);
	ktirterium_hlasy_koalicie.setKolo(kolo);
	ktirterium_hlasy_koalicie.setKandidatovKoalicie(kandKoalicie);
	structures::ArrayList<UzemnaJednotka*> docasnyZoznamUzJed;

	for (auto p : uzemneJednotky)
	{
		if (filter_Nazov.urciHodnotu(*p->accessData(), kriterium_Nazov) && filter_volici.urciHodnotu(*p->accessData(), kriterium_volici) && filter_ucast.urciHodnotu(*p->accessData(), kriterium_ucast))
			docasnyZoznamUzJed.add(p->accessData());
	}
	ShellSortUzJednotky(docasnyZoznamUzJed.size() / 2, docasnyZoznamUzJed, ktirterium_hlasy_koalicie);
	if (!zostupne)
	{
		for (int i = 0; i < docasnyZoznamUzJed.size(); i++)
		{
			cout << docasnyZoznamUzJed[i]->getNazov() << ": " << endl;
			cout << "Clenovia koalicie = ";
			for (int j = 0; j < kandKoalicie.size(); j++)
			{
				cout << docasnyZoznamUzJed[i]->getKandidata(kandKoalicie[j])->getMeno() << ", ";
			}
			cout << endl << "Koalicia ziskala: " << ktirterium_hlasy_koalicie.ohodnot(*docasnyZoznamUzJed[i]) << " hlasov" << endl;
		}
	}
	if (zostupne)
	{
		for (int i = docasnyZoznamUzJed.size()-1; i >-1; --i)
		{
			cout << docasnyZoznamUzJed[i]->getNazov() << ": " << endl;
			cout << "Clenovia koalicie = ";
			for (int j = 0; j < kandKoalicie.size(); j++)
			{
				cout << docasnyZoznamUzJed[i]->getKandidata(kandKoalicie[j])->getMeno() << ", ";
			}
			cout << endl << "Koalicia ziskala: " << ktirterium_hlasy_koalicie.ohodnot(*docasnyZoznamUzJed[i]) << " hlasov" << endl;
		}
	}
}

Kandidat * Stat::vyberoveKNajviacHlasov(int kolo, UzemnaJednotka * uz)
{
	Kandidat * pomKand;
	if (kolo = 1)
	{
		pomKand = uz->getKandidata(0);
		for (int i = 1; i < 15; i++)
		{
			if (pomKand->getPocetZiskanychHlasov() < uz->getKandidata(i)->getPocetZiskanychHlasov())
				pomKand = uz->getKandidata(i);
		}
		return pomKand;
	}
	if (kolo = 2)
	{
		pomKand = uz->getKandidata(15);
		if (pomKand->getPocetZiskanychHlasov() < uz->getKandidata(16)->getPocetZiskanychHlasov())
			return uz->getKandidata(16);
		return pomKand;
	}

	pomKand = uz->getKandidata(0);
	for (int i = 1; i < 17; i++)
	{
		if (pomKand->getPocetZiskanychHlasov() < uz->getKandidata(i)->getPocetZiskanychHlasov())
			pomKand = uz->getKandidata(i);
	}
	return pomKand;
}

Kandidat * Stat::vyberoveKNajmenejHlasov(int kolo, UzemnaJednotka * uz)
{
	Kandidat * pomKand;
	if (kolo = 1)
	{
		pomKand = uz->getKandidata(0);
		for (int i = 1; i < 15; i++)
		{
			if (pomKand->getPocetZiskanychHlasov() > uz->getKandidata(i)->getPocetZiskanychHlasov())
				pomKand = uz->getKandidata(i);
		}
		return pomKand;
	}
	if (kolo = 2)
	{
		pomKand = uz->getKandidata(15);
		if (pomKand->getPocetZiskanychHlasov() > uz->getKandidata(16)->getPocetZiskanychHlasov())
			return uz->getKandidata(16);
		return pomKand;
	}

	pomKand = uz->getKandidata(0);
	for (int i = 1; i < 17; i++)
	{
		if (pomKand->getPocetZiskanychHlasov() > uz->getKandidata(i)->getPocetZiskanychHlasov())
			pomKand = uz->getKandidata(i);
	}
	return pomKand;
}

string Stat::vyberoveKNajstabilnejsieVysledky(UzemnaJednotka * uz)
{
	int rozdiel1, rozdiel2;
	rozdiel1 = uz->getKandidata(1)->getPocetZiskanychHlasov() - uz->getKandidata(15)->getPocetZiskanychHlasov();
	rozdiel2 = uz->getKandidata(10)->getPocetZiskanychHlasov() - uz->getKandidata(16)->getPocetZiskanychHlasov();
	rozdiel1 = abs(rozdiel1);
	rozdiel2 = abs(rozdiel2);
	if (rozdiel1 < rozdiel2)
		return "Stabilnejsie vysledky mal kandidat: " + uz->getKandidata(15)->getMeno() + ", s rozdielom hlasov: " + to_string(rozdiel1);
	if (rozdiel1 > rozdiel2)
		return "Stabilnejsie vysledky mal kandidat: " + uz->getKandidata(16)->getMeno() + ", s rozdielom hlasov: " + to_string(rozdiel2);
	if (rozdiel1 == rozdiel2)
		return "Obidvaja kandidati mali rovnako stabilne hlasy";
}






void Stat::Quick(int min, int max, structures::ArrayList<UzemnaJednotka*>& arr)
{
	
	int pivot = arr[(min + max) /2]->getPocOdovzdanychHlasov1Kolo();
	int lavy = min;
	int pravy = max;
	do
	{
		while (arr[lavy]->getPocOdovzdanychHlasov1Kolo() < pivot)
			lavy++;
		while (arr[pravy]->getPocOdovzdanychHlasov1Kolo() > pivot)
			pravy--;
		if (lavy <= pravy)
		{
			swap(arr[lavy], arr[pravy]);
			lavy++;
			pravy--;
		}
	} while (lavy <= pravy);
	
		if (min < pravy)
			Quick(min, pravy,arr);
		if (lavy < max )
			Quick(lavy, max,arr);
	
}
template<typename O, typename T>
void Stat::ShellSortObce(int krok, structures::ArrayList<Obec*>& arr, Kriterium<O, T>& krit)
{
	
	for (int delta = 0; delta < krok; ++delta)
	{
		for (int i = delta; i < arr.size(); i += krok)
		{
			int j =i;
			 while(((j- krok) >= delta) && (krit.ohodnot(*arr[j]) < krit.ohodnot(*arr[j- krok])))
			 {
				 swap(arr[j], arr[j- krok]);
				 j -= krok;
			 }
		}
	}
	if (krok > 1)
		ShellSortObce(krok/2, arr,krit);
}
template<typename O, typename T>
void Stat::ShellSortUzJednotky(int krok, structures::ArrayList<UzemnaJednotka*>& arr, Kriterium<O, T>& krit)
{
	for (int delta = 0; delta < krok; ++delta)
	{
		for (int i = delta; i < arr.size(); i += krok)
		{
			int j = i;
			while (((j - krok) >= delta) && (krit.ohodnot(*arr[j]) < krit.ohodnot(*arr[j - krok])))
			{
				swap(arr[j], arr[j - krok]);
				j -= krok;
			}
		}
	}
	if (krok > 1)
		ShellSortUzJednotky(krok / 2, arr, krit);
}
//template<typename O, typename T>
void Stat::ShellSortKandidati(int krok, structures::ArrayList<Kandidat*>& arr)
{

	for (int delta = 0; delta < krok; ++delta)
	{
		for (int i = delta; i < arr.size(); i += krok)
		{
			int j = i;
			while (((j - krok) >= delta) && (arr[j]->getPocetZiskanychHlasov() < arr[j-krok]->getPocetZiskanychHlasov()) )
			{
				swap(arr[j], arr[j - krok]);
				j -= krok;
			}
		}
	}
	if (krok > 1)
		ShellSortKandidati(krok / 2, arr);
}

