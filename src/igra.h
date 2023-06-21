#ifndef IGRA_H
#define IGRA_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

#define BR_NIVOA 50
#define V_FAJLA_X 19
#define V_FAJLA_Y 16

#define ZID 1
#define KUTIJA 2
#define KRAJ 3
#define IGRAC 4
#define NA_MESTU 5

#define LEVO 0
#define GORE 1
#define DESNO 2
#define DOLE 3
#define STOJI -1

#define V_EKR_X0 1400
#define V_EKR_Y0 800
#define V_SLIKE 256
#define SKALIRANJE 0.25f
#define V_NA_EKRANU 50.0f

class igra
{
	sf::RenderWindow *prozor;

	int mapa[V_FAJLA_Y][V_FAJLA_X];
	sf::Vector2i igrac;
	sf::Vector2f igrac_vektor;
	int br_kutija;

	int kretanje;
	int br_poteza;

	sf::Vector2f pocetak;
	sf::Texture tZid, tKutija, tKraj, tIgrac, tNaMestu;
	sf::Sprite sZid, sKutija, sKraj, sIgrac, sNaMestu;
public:
	igra(sf::RenderWindow* prozor1);
	bool ucitaj_nivo(int br);
	void igrac_update();
	void ispis_matrice();
};

#endif
