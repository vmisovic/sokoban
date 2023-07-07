#ifndef IGRA_H
#define IGRA_H

#include <SFML/Graphics.hpp>
#include "konstante.h"
#include "grafika.h"
#include "lpoteza.h"

class igra
{
	grafika g;

	int nivo;
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
	bool vracanje;
	sf::Vector2f kutija_gurana;

	lpoteza lp;

public:
	igra(sf::RenderWindow* prozor);
	bool ucitaj_nivo(int br);
	void igrac_update();
	void undo();
	void crtaj_mapu();
	bool reseno();
};

#endif
