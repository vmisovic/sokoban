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

public:
	grafika();
	void setRenderWindow(sf::RenderWindow* prozor);
	void crtaj(sf::Vector2f v, int o);
};

#endif
