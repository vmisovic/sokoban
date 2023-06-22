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

void grafika::foo(int i, int j, int mapa[MAPA_Y][MAPA_X], sf::Vector2f igrac_vektor, sf::Vector2f kutija_gurana, bool guranje)
{
	sf::Vector2f poz = pocetak + V_NA_EKRANU * sf::Vector2f(i, j);
	switch (mapa[j][i])
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
	}
	if (guranje && fabsf(kutija_gurana.x - i) < 1.0f && fabsf(kutija_gurana.y - j) < 1.0f) {
		sKutija.setPosition(pocetak + kutija_gurana * V_NA_EKRANU);
		prozor->draw(sKutija);
	}
	if (fabsf(igrac_vektor.x - i) < 1.0f && fabsf(igrac_vektor.y - j) < 1.0f) {
		sIgrac.setPosition(pocetak + igrac_vektor * V_NA_EKRANU);
		prozor->draw(sIgrac);
	}
}

void grafika::crtaj_mapu(int kretanje, int mapa[MAPA_Y][MAPA_X], sf::Vector2f igrac_vektor, sf::Vector2f kutija_gurana, bool guranje)
{
	if (kretanje == GORE || kretanje == DOLE)
		for (int i = 0; i < MAPA_X; i++)
			for (int j = 0; j < MAPA_Y; j++)
				foo(i, j, mapa, igrac_vektor, kutija_gurana, guranje);
	else
		for (int j = 0; j < MAPA_Y; j++)
			for (int i = 0; i < MAPA_X; i++)
				foo(i, j, mapa, igrac_vektor, kutija_gurana, guranje);
}
