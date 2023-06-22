#include "grafika.h"

grafika::grafika()
{
	prozor = NULL;

	if (!tZid.loadFromFile(ZID_TEX))
		exit(1);
	if (!tKutija.loadFromFile(KUTIJA_TEX))
		exit(2);
	if (!tKraj.loadFromFile(KRAJ_TEX))
		exit(3);
	if (!tIgrac.loadFromFile(IGRAC_TEX))
		exit(4);
	if (!tNaMestu.loadFromFile(NA_MESTU_TEX))
		exit(5);
	pocetak = sf::Vector2f(V_NA_EKRANU, 0.f);

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
