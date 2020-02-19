#include "Enemy.h"
#include "Fire.h"
#include "Ship.h"
#include "rlutil.h"
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;
using namespace rlutil;

char k;

int dusmanYonu;
int dusmanYonSayaci;
int dusmanAtesSayaci = 0;
int dSatir = 8;
int dSutun = 8;
int skor = 0;
int can = 3;
int ix;

bool oluMuyuz = false;

float shipx = 28;
float shipy = 28;

Ship ship(shipx, shipy);

vector<Enemy> enemies;
vector<Fire> fires;

void reset() { // oyun objelerini olustur
	ship = Ship(shipx, shipy);
	for (int i = 0; i < dSutun; i++) {
		for (int j = 0; j < dSatir; j++) {
			Enemy e = Enemy(10 + i * 5, 5 + j);
			enemies.push_back(e);
		}
	}
	dusmanAtesSayaci = rand() % 80 + 80;
	skor = 0;
	oluMuyuz = false;
	dusmanYonu = 0;
	dusmanYonSayaci = 0;
	dusmanAtesSayaci = 0;
}

void draw() { // çizimleri yap
	// göstergeler
	locate(1, 1);
	setColor(5);
	cout << "Skor: " << skor << endl;
	cout << "Can: " << can << endl;
	ship.Ciz();
	for (int i = 0; i < enemies.size(); i++) {
		enemies.at(i).Ciz();
	}
	for (int i = 0; i < fires.size(); i++) {
		Sleep(10);
		fires.at(i).Ciz();
	}
  	// atesleri ilerlet
	for (int i = 0; i < fires.size(); i++) {
		fires.at(i).Sil();
		fires.at(i).Ilerlet();
	}
	// atesler için saha disi kontrolü
	for (int i = 0; i < fires.size(); i++) {
		if (!fires.at(i).AktifMi()) {
			fires.erase(fires.begin() + i);
			i--;
		}
	}
	// ateslerin düsmana çarpmasi
	for (int i = 0; i < fires.size(); i++) {
		if (fires.at(i).BizimMi()) { // bizim ateslerin düsmana çarpmasi
			for (int j = 0; j < enemies.size(); j++) {
				if (enemies.at(j).CarparMi(fires.at(i).X(), fires.at(i).Y())) {
					// ates düsmana çarpti
					enemies.at(j).Sil();
					enemies.erase(enemies.begin() + j);
					fires.erase(fires.begin() + i);
					i--;
					skor += rand()%10 + 40;
					break;
				}
			}
		}
		else { // düsman ateslerinin bize çarpmasi
			if (!oluMuyuz && ship.CarparMi(fires.at(i).X(), fires.at(i).Y())) {
				// öldük!!!
				--can;
				oluMuyuz = true;
			}
		}
	}
	// düsman ates mantigi
	dusmanAtesSayaci--;
	if (dusmanAtesSayaci < 0) {
		if (enemies.size() > 0) {
			int atesEdenSayisi = rand()%1 + 4;
			for (int i = 0; i < atesEdenSayisi; i++) {
				ix = rand()%enemies.size();
				float ex = enemies.at(ix).X();
				float ey = enemies.at(ix).Y();
				fires.push_back(Fire(ex,ey,false,7));
				dusmanAtesSayaci = rand()%50 + 50;
			}
		}
	}
}

int main() {
	srand(time(NULL));
	reset();
	setColor(5);
	std::cout << "Space Invaders" << std::endl;
	std::cout << "a: Sol d: Sag m: Ates" << std::endl;
	anykey("Baslamak icin herhangi bir tusa basiniz...\n");
	rlutil::cls();
	hidecursor();
	while (1) {
		if (kbhit()) {
			k = getch();
    		ship.Sil();
			if (k == 'a') ship.SolaGit();
			else if (k == 'd') ship.SagaGit();
			else if (!oluMuyuz && k == 'm') 
				{
					fires.push_back(Fire(ship.X(),ship.Y()-1,true,7));
				}
			else if (k == 'r') break;
			}
		if (oluMuyuz) reset();
		draw();
		// oyun bitti mi?
		if (enemies.size() <= 0 || (oluMuyuz && can <= 0)) {
			// bitti!
			cls();
			// son göstergeler
			locate(1, 3);
			setColor(5);
			cout << "Skor: " << skor << endl;
			cout << "Can: " << can << endl;
			cout << "Oyun Bitti!";
			break;
		}
	}
}

