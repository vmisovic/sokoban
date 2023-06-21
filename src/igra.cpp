#include "igra.h"

igra::igra(sf::RenderWindow* prozor1)
{
	prozor = prozor1;

	br_kutija = 0;
	br_na_mestu = 0;

	kretanje = STOJI;
	guranje = false;
	br_poteza = 0;
	br_guranja = 0;

	if (!tZid.loadFromFile("resource/kocka.png"))
		exit(1);
	if (!tKutija.loadFromFile("resource/kutija.png"))
		exit(2);
	if (!tKraj.loadFromFile("resource/kraj-t256.png"))
		exit(3);
	if (!tIgrac.loadFromFile("resource/igrac.png"))
		exit(4);
	if (!tNaMestu.loadFromFile("resource/na_mestu.png"))
		exit(5);
	pocetak = sf::Vector2f(V_NA_EKRANU, 0.f);

	sZid.setTexture(tZid);
	sKutija.setTexture(tKutija);
	sKraj.setTexture(tKraj);
	sIgrac.setTexture(tIgrac);
	sNaMestu.setTexture(tNaMestu);

	sf::Vector2f skal = sf::Vector2f(SKALIRANJE,SKALIRANJE);
	sZid.setScale(skal);
	sKutija.setScale(skal);
	sKraj.setScale(skal);
	sIgrac.setScale(skal);
	sNaMestu.setScale(skal);
}

bool igra::ucitaj_nivo(int br)
{
	if (br < 1 || br > BR_NIVOA)
		return false;
	std::stringstream naziv;
	naziv << "resource/nivoi/nivo";
	if (br < 10) naziv << "0";
	naziv << br << "\0";
	std::ifstream ulaz(naziv.str());
	std::cout << "Otvaram fajl: " << naziv.str() << "\n";

	kretanje = STOJI;
	guranje = false;
	br_poteza = 0;
	br_guranja = 0;

	br_kutija = 0;
	br_na_mestu = 0;
	for (int j = 0; j < V_FAJLA_Y; j++)
	{
		for (int i = 0; i < V_FAJLA_X; i++)
		{
			ulaz >> mapa[j][i];
			std::cout << mapa[j][i] << " ";
			switch (mapa[j][i]) {
				case IGRAC:
					igrac.x = i;
					igrac.y = j;
					igrac_vektor = sf::Vector2f((float)i, (float)j);
					mapa[j][i] = PRAZNO;
					break;
				case NA_MESTU:
					br_na_mestu++;
				case KUTIJA:
					br_kutija++;
					break;
			}
		}
		std::cout << "\n";
	}
	ulaz.close();
	return true;
}

void igra::igrac_update()
{
	float korak = 0.065;
	sf::Keyboard::Key strelice[4] = {
		sf::Keyboard::Left,
		sf::Keyboard::Up,
		sf::Keyboard::Right,
		sf::Keyboard::Down
	};
	int dx[4] = {-1, 0, +1, 0};
	int dy[4] = {0, -1, 0, +1};
	int suprotno[4] = {DESNO, DOLE, LEVO, GORE};

	int *ispred, *ispred2;
	for (int i = 0; i < 4; i++)
		if (sf::Keyboard::isKeyPressed(strelice[i]))
		{
			if (kretanje == suprotno[i] && !guranje)
			{
				igrac.x += dx[kretanje];
				igrac.y += dy[kretanje];
				kretanje = i;
				continue;
			}
			if (kretanje == STOJI)
			{
				ispred = &mapa[igrac.y + dy[i]][igrac.x + dx[i]];
				ispred2 = &mapa[igrac.y + 2 * dy[i]][igrac.x + 2 * dx[i]];
				if (*ispred == ZID)
					continue;
				if (*ispred == PRAZNO || *ispred == KRAJ)
				{
					kretanje = i;
					continue;
				}
				if (*ispred2 == PRAZNO || *ispred2 == KRAJ)
				{
					kretanje = i;
					guranje = true;
					kutija_gurana.x = igrac.x + dx[i];
					kutija_gurana.y = igrac.y + dy[i];
				}
			}
		}
	if (kretanje != STOJI)
	{
		igrac_vektor += korak * sf::Vector2f(dx[kretanje], dy[kretanje]);
		if (guranje)
			kutija_gurana += korak * sf::Vector2f(dx[kretanje], dy[kretanje]);
	}

	if (fabsf(igrac_vektor.x - (float)igrac.x) >= 1.0f || fabsf(igrac_vektor.y - (float)igrac.y) >= 1.0f)
	{
		br_poteza++;
		igrac.x += dx[kretanje];
		igrac.y += dy[kretanje];
		igrac_vektor = sf::Vector2f((float)igrac.x, (float)igrac.y);
		if (guranje)
		{
			br_guranja++;
			ispred = &mapa[igrac.y][igrac.x];
			ispred2 = &mapa[igrac.y + dy[kretanje]][igrac.x + dx[kretanje]];
			switch (*ispred)
			{
				case KUTIJA:
					*ispred = PRAZNO;
					break;
				case NA_MESTU:
					*ispred = KRAJ;
					br_na_mestu--;
					break;
			}
			switch (*ispred2)
			{
				case PRAZNO:
					*ispred2 = KUTIJA;
					break;
				case KRAJ:
					*ispred2 = NA_MESTU;
					br_na_mestu++;
					break;
			}
		}
		kretanje = STOJI;
		guranje = false;
	}
}

void igra::crtaj_mapu()
{
	for (int j = 0; j < V_FAJLA_Y; j++)
	{
		for (int i = 0; i < V_FAJLA_X; i++)
		{
			sf::Vector2f poz = pocetak + V_NA_EKRANU * sf::Vector2f(i, j), kut;
			kut = poz;
			if (guranje && fabsf(kutija_gurana.x - i) < 1.0f && fabsf(kutija_gurana.y - j) < 1.0f)
				kut = pocetak + kutija_gurana * V_NA_EKRANU;
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
				sKutija.setPosition(kut);
				prozor->draw(sKutija);
				break;
			case NA_MESTU:
				sNaMestu.setPosition(kut);
				prozor->draw(sNaMestu);
				break;
			}
			if (fabsf(igrac_vektor.x - i) < 1.0f && fabsf(igrac_vektor.y - j) < 1.0f) {
				sIgrac.setPosition(pocetak + igrac_vektor * V_NA_EKRANU);
				prozor->draw(sIgrac);
			}
		}
	}
}

bool igra::reseno()
{
	return br_na_mestu == br_kutija;
}
