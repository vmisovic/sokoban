#include "grafika.h"
#include <string>

grafika::grafika()
{
	prozor = nullptr;
	std::string tex_path = TEX_PATH;
	tex_path += "/";

	if (!tZid.loadFromFile(tex_path + ZID_TEX))
		exit(1);
	if (!tKutija.loadFromFile(tex_path + KUTIJA_TEX))
		exit(2);
	if (!tKraj.loadFromFile(tex_path + KRAJ_TEX))
		exit(3);
	if (!tIgrac.loadFromFile(tex_path + IGRAC_TEX))
		exit(4);
	if (!tNaMestu.loadFromFile(tex_path + NA_MESTU_TEX))
		exit(5);
	pocetak = V_NA_EKRANU * sf::Vector2f(0.5f, 1.0f);

	sZid.setTexture(tZid);
	sKutija.setTexture(tKutija);
	sKraj.setTexture(tKraj);
	sIgrac.setTexture(tIgrac);
	sNaMestu.setTexture(tNaMestu);

	sf::Vector2f skal = sf::Vector2f(SKALIRANJE, SKALIRANJE);
	sZid.setScale(skal);
	sKutija.setScale(skal);
	sKraj.setScale(skal);
	sIgrac.setScale(skal);
	sNaMestu.setScale(skal);

	if (!font.loadFromFile(FONT_PATH))
	    exit(5);
	tekst.setFont(font);
	tekst.setCharacterSize((int)V_NA_EKRANU - 10);
	tekst.setFillColor(sf::Color::Black);
	tekst.setPosition(V_NA_EKRANU * 1.5f, 0.0f);
}

void grafika::setRenderWindow(sf::RenderWindow *prozor)
{
	this->prozor = prozor;
}

void grafika::crtaj(sf::Vector2f v, int o)
{
	sf::Vector2f poz = pocetak + V_NA_EKRANU * v;
	switch (o)
	{
	case ZID:
		sZid.setPosition(poz);
		prozor->draw(sZid);
		break;
	case KRAJ:
		sKraj.setPosition(poz);
		prozor->draw(sKraj);
		break;
	case KUTIJA:
		sKutija.setPosition(poz);
		prozor->draw(sKutija);
		break;
	case NA_MESTU:
		sNaMestu.setPosition(poz);
		prozor->draw(sNaMestu);
		break;
	case IGRAC:
		sIgrac.setPosition(poz);
		prozor->draw(sIgrac);
	}
}

void grafika::crtajTekst(const sf::String &string)
{
	tekst.setString(string);
	prozor->draw(tekst);
}
