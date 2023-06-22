#ifndef GRAFIKA_H
#define GRAFIKA_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "konstante.h"

class grafika
{
	sf::RenderWindow *prozor;

	sf::Vector2f pocetak;
	int sizeX, sizeY;
	sf::Texture tZid, tKutija, tKraj, tIgrac, tNaMestu;
	sf::Sprite sZid, sKutija, sKraj, sIgrac, sNaMestu;

	void foo(int i, int j, int mapa[MAPA_Y][MAPA_X], sf::Vector2f igrac_vektor, sf::Vector2f kutija_gurana, bool guranje);

public:
	grafika();
	void setRenderWindow(sf::RenderWindow* prozor);
	void crtaj_mapu(int kretanje, int mapa[MAPA_Y][MAPA_X], sf::Vector2f igrac_vektor, sf::Vector2f kutija_gurana, bool guranje);
};

#endif
