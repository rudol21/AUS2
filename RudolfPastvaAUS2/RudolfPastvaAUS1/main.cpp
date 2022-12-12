
#include <stdio.h>
#include <iostream>
#include <string>

#include "struktury/structure.h"
#include "struktury/structure_iterator.h"
#include "struktury/array.h"
#include "struktury/vector.h"
#include "struktury/array_list.h"
#include "struktury/linked_list.h"
#include "struktury/list.h"
#include "struktury/ds_routines.h"
#include "struktury/ds_structure_types.h"
#include "struktury/queue.h"
#include "struktury/explicit_queue.h"
#include "struktury/sorted_sequence_table.h"
#include "struktury/sequence_table.h"
#include "struktury/unsorted_sequence_table.h"
#include "struktury/table.h"

#include "Kraj.h"
#include "Okres.h"
#include "Obec.h"
#include "Stat.h"
#include "Filter.h"


using namespace std;
using namespace structures;
int main(){
	initHeapMonitor();
	/*kNazov kritNazov = kNazov();
	filterNazov filterik = filterNazov();
	UzemnaJednotka *uz = new UzemnaJednotka("cadca", 100, 154, 10, 10, 10,10, 4, 4);*/
	Stat *stat = new Stat();
	stat->nacitaj("udajeNaCitanieVolby.txt");

	/*ArrayList<int> k;
	k.add(5);
	k.add(6);
	cout << "zaciatok" << endl;
	stat->zoradenieFiktivnejKoalicie_8a(1, k,"-1", 1, 500, 600, 1, 50, 70);
	//stat->callShellsortSkolsky();
	cout << "koniec" << endl;
	stat->fNazov_3a("Zlkovce");
	//stat->fUcast_3c(50,54,1);
	//stat->kVolici_2b(0,1);*/
	//stat->fVolici_3b(500, 600, 1);
	int x = -1;
	string nazovUzJ,prislusnost;
	int voliciOd, voliciDo,koloV, koloVydObalky;
	int ucastOd, ucastDo,koloU;
	bool zostupne;
	ArrayList<int > vybratyKand;
	while (x != 0)
	{

		printf("Vyberte si moznost.\n");
		printf("1 = Vypisanie informacii o uz.j. podla filtra fNazov_3a.\n");
		printf("2 = Vypisanie informacii o uz.j. podla filtra fVolici_3b.\n");
		printf("3 = Vypisanie informacii o uz.j. podla filtra fUcast_3c.\n");
		printf("4 = kNazov_4a.\n");
		printf("5 = kVolici_4b.\n");
		printf("6 = kUcast_4c.\n");
		printf("7 = vypisanieVysledkovKanVUzJednotke_5a.\n");
		printf("8 = zoradenieKandidatovPodlaVysledkovVUzemnychjednotkach_6a.\n");
		printf("9 = vypisanieVyberovychKriterii_7a.\n");
		printf("10 = zoradenieFiktivnejKoalicie_8a.\n");
		printf("0 = Koniec.\n");

		cin >> x;
		switch (x)
		{
		case 1:
			cout << "Zadajte nazov uzemnej jednotky: ";
				cin.ignore();
				getline(cin, nazovUzJ);
				stat->fNazov_3a(nazovUzJ);
			break;
		case 2:
			cout << "Zadajte spodnu hranicu zapisanych volicov, hornu a kolo: ";
			cin >> voliciOd >> voliciDo >> koloV;
			stat->fVolici_3b(voliciOd, voliciDo, koloV);
			break;
		case 3:
			cout << "Zadajte spodnu hranicu ucasti, hornu a kolo: ";
			cin >> ucastOd >> ucastDo >> koloU;
			stat->fUcast_3c(ucastOd, ucastDo, koloU);
			break;
		case 4:
			cout << "Zadajte ci ma byt vystup zoradeny zostupne true/false, dalej pre filter ucast od(%), ucast do(%), kolo"<<endl;
			cin >> zostupne >> ucastOd >> ucastDo >> koloU;
			cout << "a prislusnost obce: ";
			cin.ignore();
			getline(cin, nazovUzJ);
			stat->kNazov_4a(zostupne, koloU, ucastOd, ucastDo, nazovUzJ);
			break;
		case 5:
			cout << "Zadajte ci ma byt vystup zoradeny zostupne true/false, dalej pre filter ucast od(%), ucast do(%), kolo" << endl;
			cin >> zostupne >> ucastOd >> ucastDo >> koloU;
			cout << "a prislusnost obce: ";
			cin.ignore();
			getline(cin, nazovUzJ);
			stat->kVolici_4b(zostupne, koloU, ucastOd, ucastDo, nazovUzJ);
			break;
		case 6:
			cout << "Zadajte ci ma byt vystup zoradeny zostupne true/false, dalej pre filter ucast od(%), ucast do(%), kolo" << endl;
			cin >> zostupne >> ucastOd >> ucastDo >> koloU;
			cout << "a prislusnost obce: ";
			cin.ignore();
			getline(cin, nazovUzJ);
			stat->kUcast_4c(zostupne, koloU, ucastOd, ucastDo, nazovUzJ);
			break;
		case 7:
			vybratyKand.clear();
				int odpoved;
				cout << "Chcete zadat hodnotu pre filter nazov? 1-ano 2-nie" << endl;
				cin >> odpoved;
				if (odpoved == 1)
				{
					cout << "Zadajte nazov uzemnej jednotky: ";
					cin.ignore();
					getline(cin, nazovUzJ);
				}
				else
					nazovUzJ = "-1";
				cout << "Chcete zadat hodnotu pre filter volici? 1-ano 2-nie" << endl;
				cin >> odpoved;
				if (odpoved == 1)
				{
					cout << "Zadajte spodnu hranicu zapisanych volicov, hornu a kolo: ";
					cin >> voliciOd >> voliciDo >> koloV;
				}
				else
					voliciOd = -1; voliciDo = -1; koloV = 1;
				
				cout << "Chcete zadat hodnotu pre filter ucast? 1-ano 2-nie" << endl;
				cin >> odpoved;
				if (odpoved == 1)
				{
					cout << "Zadajte spodnu hranicu ucasti, hornu a kolo: ";
					cin >> ucastOd >> ucastDo >> koloU;
					//stat->fUcast_3c(ucastOd, ucastDo, koloU);
				}
				else
					ucastOd = -1; ucastDo = -1; koloU = 1;
				int pocetKandidatov,poradie;
				cout << "Zadajte kolo pre kriterium vydane obalky: ";
				cin >> koloVydObalky;
				cout <<"1 = Bugar" <<endl;
				cout <<"2 = Caputova" <<endl;
				cout <<"3 = Dano" <<endl;
				cout <<"4 = Harabin" <<endl;
				cout <<"5 = Chmelar" <<endl;
				cout <<"6 = Kotleba" <<endl;
				cout <<"7 = Krajniak" <<endl;
				cout <<"8 = Menyhart" <<endl;
				cout <<"9 = Miklosko" <<endl;
				cout <<"10 = Mistrik" <<endl;
				cout <<"11 = Sefcovic" <<endl;
				cout <<"12 = Svec" <<endl;
				cout <<"13 = Tauchmannova" <<endl;
				cout <<"14 = Zabojnik" <<endl;
				cout <<"15 = Zuzula" <<endl;
			
				cout << "Zadajte pocet kolkych kandidatoch chcete vybrat a kolo: ";
				int volicZKola;
				cin >> pocetKandidatov >> volicZKola;
				cout << endl;
				cout << "Vyberte kandidatov: ";
				for (int i = 0; i < pocetKandidatov; ++i)
				{
					cin >> poradie; 
					vybratyKand.add(poradie-1);
				}
				stat->vypisanieVysledkovKanVUzJednotke_5a(volicZKola, vybratyKand, nazovUzJ, koloVydObalky, koloV, voliciOd, voliciDo, koloU, ucastOd, ucastDo);
			break;
		case 8:
			vybratyKand.clear();
			int odpoved2;
			cout << "Chcete zadat hodnotu pre filter nazov? 1-ano 2-nie" << endl;
			cin >> odpoved2;
			if (odpoved2 == 1)
			{
				cout << "Zadajte nazov uzemnej jednotky: ";
				cin.ignore();
				getline(cin, nazovUzJ);
			}
			else
				nazovUzJ = "-1";
			cout << "Chcete zadat hodnotu pre filter volici? 1-ano 2-nie" << endl;
			cin >> odpoved2;
			if (odpoved2 == 1)
			{
				cout << "Zadajte spodnu hranicu zapisanych volicov, hornu a kolo: ";
				cin >> voliciOd >> voliciDo >> koloV;
			}
			else
			{
				voliciOd = -1; voliciDo = -1; koloV = 1;
			}

			cout << "Chcete zadat hodnotu pre filter ucast? 1-ano 2-nie" << endl;
			cin >> odpoved2;
			if (odpoved2 == 1)
			{
				cout << "Zadajte spodnu hranicu ucasti, hornu a kolo: ";
				cin >> ucastOd >> ucastDo >> koloU;
				stat->fUcast_3c(ucastOd, ucastDo, koloU);
			}
			else
			{
				ucastOd = -1; ucastDo = -1; koloU = 1;
			}
			int pocetKandidatov2, poradie2, koloKHlasyZiskane, zostupne;
			cout << "Zadajte kolo pre kriterium hlasy ziskane a ci ma byt vystup zoradeny zostupne true/false: ";
			cin >> koloKHlasyZiskane >> zostupne;
			cout << "1 = Bugar" << endl;
			cout << "2 = Caputova" << endl;
			cout << "3 = Dano" << endl;
			cout << "4 = Harabin" << endl;
			cout << "5 = Chmelar" << endl;
			cout << "6 = Kotleba" << endl;
			cout << "7 = Krajniak" << endl;
			cout << "8 = Menyhart" << endl;
			cout << "9 = Miklosko" << endl;
			cout << "10 = Mistrik" << endl;
			cout << "11 = Sefcovic" << endl;
			cout << "12 = Svec" << endl;
			cout << "13 = Tauchmannova" << endl;
			cout << "14 = Zabojnik" << endl;
			cout << "15 = Zuzula" << endl;
			cout << "2.kolo" << endl;
			cout << "16 = Caputova" << endl;
			cout << "17 = Sefcovic" << endl;

			cout << "Zadajte pocet kolkych kandidatoch chcete vybrat : ";
			cin >> pocetKandidatov ;
			cout << endl;
			cout << "Vyberte kandidatov: ";
			for (int i = 0; i < pocetKandidatov; ++i)
			{
				cin >> poradie;
				vybratyKand.add(poradie - 1);
			}
			stat->zoradenieKandidatovPodlaVysledkovVUzemnychjednotkach_6a(koloKHlasyZiskane,zostupne , vybratyKand, nazovUzJ, koloV, voliciOd, voliciDo, koloU, ucastOd, ucastDo);

			break;
		case 9:
			odpoved = -1;
			cout << "Chcete zadat hodnotu pre filter nazov? 1-ano 2-nie" << endl;
			cin >> odpoved;
			if (odpoved == 1)
			{
				cout << "Zadajte nazov uzemnej jednotky: ";
				cin.ignore();
				getline(cin, nazovUzJ);
			}
			else
			{
				nazovUzJ = "-1";
			}
			cout << "Chcete zadat hodnotu pre filter volici? 1-ano 2-nie" << endl;
			cin >> odpoved;
			if (odpoved == 1)
			{
				cout << "Zadajte spodnu hranicu zapisanych volicov, hornu a kolo: ";
				cin >> voliciOd >> voliciDo >> koloV;
			}
			else
			{
				voliciOd = -1; voliciDo = -1; koloV = 1;
			}

			cout << "Chcete zadat hodnotu pre filter ucast? 1-ano 2-nie" << endl;
			cin >> odpoved;
			if (odpoved == 1)
			{
				cout << "Zadajte spodnu hranicu ucasti, hornu a kolo: ";
				cin >> ucastOd >> ucastDo >> koloU;
				//stat->fUcast_3c(ucastOd, ucastDo, koloU);
			}
			else
			{
				ucastOd = -1; ucastDo = -1; koloU = 1;
			}
			int koloVybK;
			cout << "Zadajte kolo pre vyberove kriterium: ";
			cin >> koloVybK;
			stat->vypisanieVyberovýchKritérii_7a(koloVybK, nazovUzJ, koloV, voliciOd, voliciDo, koloU, ucastOd, ucastDo);
			break;
		case 10:
			vybratyKand.clear();
			odpoved = -1;
			cout << "Chcete zadat hodnotu pre filter nazov? 1-ano 2-nie" << endl;
			cin >> odpoved;
			if (odpoved == 1)
			{
				cout << "Zadajte nazov uzemnej jednotky: ";
				cin.ignore();
				getline(cin, nazovUzJ);
			}
			else
			{
				nazovUzJ = "-1";
			}
			cout << "Chcete zadat hodnotu pre filter volici? 1-ano 2-nie" << endl;
			cin >> odpoved;
			if (odpoved == 1)
			{
				cout << "Zadajte spodnu hranicu zapisanych volicov, hornu a kolo: ";
				cin >> voliciOd >> voliciDo >> koloV;
			}
			else
			{
				voliciOd = -1; voliciDo = -1; koloV = 1;
			}

			cout << "Chcete zadat hodnotu pre filter ucast? 1-ano 2-nie" << endl;
			cin >> odpoved;
			if (odpoved == 1)
			{
				cout << "Zadajte spodnu hranicu ucasti, hornu a kolo: ";
				cin >> ucastOd >> ucastDo >> koloU;
				//stat->fUcast_3c(ucastOd, ucastDo, koloU);
			}
			else
			{
				ucastOd = -1; ucastDo = -1; koloU = 1;
			}
			cout << "Zadajte v ktorom kole maju byt spocitane hlasy koalicie a pocet clenov koalicie: ";
			int koloKoalicia,pocetClenov;
			cin >> koloKoalicia >> pocetClenov;
			cout << "1 = Bugar" << endl;
			cout << "2 = Caputova" << endl;
			cout << "3 = Dano" << endl;
			cout << "4 = Harabin" << endl;
			cout << "5 = Chmelar" << endl;
			cout << "6 = Kotleba" << endl;
			cout << "7 = Krajniak" << endl;
			cout << "8 = Menyhart" << endl;
			cout << "9 = Miklosko" << endl;
			cout << "10 = Mistrik" << endl;
			cout << "11 = Sefcovic" << endl;
			cout << "12 = Svec" << endl;
			cout << "13 = Tauchmannova" << endl;
			cout << "14 = Zabojnik" << endl;
			cout << "15 = Zuzula" << endl;
			cout << "Vyberte si clenov koalicie: ";
			for (int i = 0; i < pocetClenov; ++i)
			{
				cin >> poradie;
				vybratyKand.add(poradie - 1);
			}
			cout << "Zadajte ci ma byt vystup zoradeny zostupne true/false:";
			cin >> zostupne;
			stat->zoradenieFiktivnejKoalicie_8a(zostupne,koloKoalicia,vybratyKand, nazovUzJ, koloV, voliciOd, voliciDo, koloU, ucastOd, ucastDo+33333333333
			);
			break;
		case 0:
			
			break;

		}
	}
	
	
	delete stat;
}
/*cout << "uz";
cout << kritNazov.ohodnot(*uz);
filterik.setParameter("cdca");
cout << filterik.urciHodnotu(*uz, kritNazov);*/