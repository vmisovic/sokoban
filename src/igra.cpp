#include "igra.h"

igra::igra(sf::RenderWindow* prozor)
{
	g.setRenderWindow(prozor);

	br_kutija = 0;
	br_na_mestu = 0;

	kretanje = STOJI;
	guranje = false;
	br_poteza = 0;
	br_guranja = 0;
}

bool igra::ucitaj_nivo(int br)
{
	if (br < 1 || br > BR_NIVOA)
		return false;
	std::stringstream naziv;
	naziv << NIVOI_PATH << "/nivo";
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
	for (int j = 0; j < MAPA_Y; j++)
	{
		for (int i = 0; i < MAPA_X; i++)
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
	sf::Keyboard::Key strelice[4] = {
		sf::Keyboard::Left,
		sf::Keyboard::Up,
		sf::Keyboard::Right,
		sf::Keyboard::Down
	};
	sf::Keyboard::Key hjkl[4] = {
		sf::Keyboard::H,
		sf::Keyboard::K,
		sf::Keyboard::L,
		sf::Keyboard::J
	};
	int dx[4] = {-1, 0, +1, 0};
	int dy[4] = {0, -1, 0, +1};
	int suprotno[4] = {DESNO, DOLE, LEVO, GORE};

	int *ispred, *ispred2;
	for (Kretanje i : {LEVO, GORE, DESNO, DOLE})
		if (sf::Keyboard::isKeyPressed(strelice[i]) || sf::Keyboard::isKeyPressed(hjkl[i]))
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
					if (*ispred == KUTIJA)
						*ispred = PRAZNO;
					if (*ispred == NA_MESTU) {
						br_na_mestu--;
						*ispred = KRAJ;
					}
				}
			}
		}
	if (kretanje != STOJI)
	{
		igrac_vektor += KORAK * sf::Vector2f(dx[kretanje], dy[kretanje]);
		if (guranje)
			kutija_gurana += KORAK * sf::Vector2f(dx[kretanje], dy[kretanje]);
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
			ispred = &mapa[igrac.y + dy[kretanje]][igrac.x + dx[kretanje]];
			switch (*ispred)
			{
				case PRAZNO:
					*ispred = KUTIJA;
					break;
				case KRAJ:
					*ispred = NA_MESTU;
					br_na_mestu++;
					break;
			}
		}
		kretanje = STOJI;
		guranje = false;
	}
}

void igra::crtaj()
{
	if (kretanje == GORE || kretanje == DOLE)
		for (int i = 0; i < MAPA_X; i++)
			for (int j = 0; j < MAPA_Y; j++)
			{
				g.crtaj(sf::Vector2f((float)i, (float)j), mapa[j][i]);
				if (guranje && fabsf(kutija_gurana.x - i) < 1.0f && fabsf(kutija_gurana.y - j) < 1.0f)
					g.crtaj(kutija_gurana, KUTIJA);
				if (fabsf(igrac_vektor.x - i) < 1.0f && fabsf(igrac_vektor.y - j) < 1.0f)
					g.crtaj(igrac_vektor, IGRAC);
			}
	else
		for (int j = 0; j < MAPA_Y; j++)
			for (int i = 0; i < MAPA_X; i++)
			{
				g.crtaj(sf::Vector2f((float)i, (float)j), mapa[j][i]);
				if (guranje && fabsf(kutija_gurana.x - i) < 1.0f && fabsf(kutija_gurana.y - j) < 1.0f)
					g.crtaj(kutija_gurana, KUTIJA);
				if (fabsf(igrac_vektor.x - i) < 1.0f && fabsf(igrac_vektor.y - j) < 1.0f)
					g.crtaj(igrac_vektor, IGRAC);
			}
}

bool igra::reseno()
{
	return br_na_mestu == br_kutija;
}
