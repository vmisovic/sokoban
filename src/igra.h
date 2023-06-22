#ifndef IGRA_H
#define IGRA_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "konstante.h"
#include "grafika.h"

class igra
{
	grafika g;

	int mapa[MAPA_Y][MAPA_X];
	int br_kutija;
	int br_na_mestu;
	int br_poteza;
	int br_guranja;

	sf::Vector2i igrac;
	sf::Vector2f igrac_vektor;
	int kretanje;
	float pomeraj;
	bool guranje;
	sf::Vector2f kutija_gurana;

public:
	igra(sf::RenderWindow* prozor);
	bool ucitaj_nivo(int br);
	void igrac_update();
	void crtaj();
	bool reseno();
};

#endif
