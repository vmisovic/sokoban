#ifndef GRAFIKA_H
#define GRAFIKA_H

#include <SFML/Graphics.hpp>
#include "konstante.h"

class grafika
{
	sf::RenderWindow &prozor;

	sf::Vector2f pocetak;
	int sizeX, sizeY;
	sf::Texture tZid, tKutija, tKraj, tIgrac, tNaMestu;
	sf::Sprite sZid, sKutija, sKraj, sIgrac, sNaMestu;

	sf::Font font;
	sf::Text tekst;

public:
	grafika(sf::RenderWindow &prozor);
	void crtaj(sf::Vector2f v, int o);
	void crtajTekst(const sf::String &string);
};

#endif
