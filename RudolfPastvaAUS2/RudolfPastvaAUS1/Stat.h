#pragma once
#include "Kraj.h"
#include "Okres.h"
#include "Obec.h"
#include "Kriterium.h"
#include "Filter.h"
#include "struktury/heap_monitor.h"
#include <fstream>
#include "UzemnaJednotka.h"
#include "Obec.h"
class Stat
{
	
	
	kNazov kriterium_Nazov = kNazov();
	kVolici kriterium_volici = kVolici();
	kVydaneObalky kriterium_vydane_obalky = kVydaneObalky();
	kUcast kriterium_ucast = kUcast();
	kOdovzdaneObalky kriterium_odovzdane_obalky = kOdovzdaneObalky();
	kPlatneHlasy kriterium_platne_hlasy = kPlatneHlasy();
	kPrislusnostObce kriterium_prislusnost_obce = kPrislusnostObce();
	kMeno kriterium_meno = kMeno();
	kHlasyZiskaneKoaliciou ktirterium_hlasy_koalicie = kHlasyZiskaneKoaliciou();
	filterNazov filter_Nazov = filterNazov();
	filterVolici filter_volici = filterVolici();
	filterUcast filter_ucast = filterUcast();
	filterPrislusnostObce filter_prislusnost_obce =  filterPrislusnostObce();
	filterMeno filter_meno = filterMeno();
	structures::SortedSequenceTable<string, UzemnaJednotka*>  uzemneJednotky = structures::SortedSequenceTable<string, UzemnaJednotka*>();
	/*structures::ArrayList<UzemnaJednotka*> zoznamUzemnychJednotiek = structures::ArrayList<UzemnaJednotka*>();
	structures::ArrayList<UzemnaJednotka*> zoznUsporiadanyPodlaVolicov = structures::ArrayList<UzemnaJednotka*>();
	structures::ArrayList<UzemnaJednotka*> zoznUsporiadanyPodlaUcasti = structures::ArrayList<UzemnaJednotka*>();
	structures::ArrayList<Obec*> zoznObci = structures::ArrayList<Obec*>();*/
	structures::SortedSequenceTable<string, Obec*>  tabulkaObci = structures::SortedSequenceTable<string, Obec*>();
	
	
public:
	Stat();
	~Stat();
	void vipisInformacieUzemnaJednotka(UzemnaJednotka * uzJed);
	void nacitaj(const char *menoSuboru);
	
	
	/*void ShellSort();
	void Shell(int krok);	
	void ShellSortVolici(int kolo);
	void ShellSortUcast(int kolo);*/
	template<typename O, typename T>
	int vyhladanieBisekcia(int kluc, int dolnaHranica, int hornaHranica, structures::ArrayList<UzemnaJednotka*>& zoznam,Kriterium<O,T>& krit);

	//void kNazov_2a(bool zostupne);
	//void kVolici_2b(bool zostupne,int kolo);
	//void kUcast_2c(bool zostupne,int kolo);
	void fNazov_3a(string nazov);
	void fVolici_3b(int OD, int DO, int pKolo);
	void fUcast_3c(int OD, int DO, int pKolo);
	void kNazov_4a(bool zostupne, int kolo, int OD, int DO, string prislusnost);
	void kVolici_4b(bool zostupne, int kolo, int OD, int DO, string prislusnost);
	void kUcast_4c(bool zostupne, int kolo, int OD, int DO, string prislusnost);
	void vypisanieVysledkovKanVUzJednotke_5a(int volicZKola, structures::ArrayList<int> kandidati,string nazovUzJed,int koloPreKVydOb, int koloV, int voliciOd, int voliciDo,int koloU, int ucastOd,int ucastDo);
	void zoradenieKandidatovPodlaVysledkovVUzemnychjednotkach_6a(int koloKHlasyZiskane, bool zostupne, structures::ArrayList<int> kandidati, string nazovUzJed, int koloV, int voliciOd, int voliciDo, int koloU, int ucastOd, int ucastDo);
	void vypisanieVyberovýchKritérii_7a(int koloVybKr, string nazovUzJed, int koloV, int voliciOd, int voliciDo, int koloU, int ucastOd, int ucastDo);
	void zoradenieFiktivnejKoalicie_8a(bool zostupne, int kolo, structures::ArrayList<int> kandKoalicie, string nazov, int koloV, int voliciOd, int voliciDo, int koloU, int ucastOd, int ucastDo);
	
	Kandidat * vyberoveKNajviacHlasov(int kolo, UzemnaJednotka * uz);
	Kandidat * vyberoveKNajmenejHlasov(int kolo, UzemnaJednotka * uz);
	string vyberoveKNajstabilnejsieVysledky(UzemnaJednotka * uz);
	void Quick(int min, int max, structures::ArrayList<UzemnaJednotka*>& arr);
	template<typename O, typename T>
	void ShellSortObce(int krok, structures::ArrayList<Obec*>& arr, Kriterium<O, T>& krit);
	template<typename O, typename T>
	void ShellSortUzJednotky(int krok, structures::ArrayList<UzemnaJednotka*>& arr, Kriterium<O, T>& krit);

	void ShellSortKandidati(int krok, structures::ArrayList<Kandidat*>& arr);
};

