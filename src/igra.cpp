#include "igra.h"

igra::igra(sf::RenderWindow* prozor1)
{
	prozor = prozor1;
	if (!(tZid.loadFromFile("resource/kocka.png")))
		exit(1);
	if (!(tKutija.loadFromFile("resource/kutija.png")))
		exit(2);
	if (!(tKraj.loadFromFile("resource/kraj-t256.png")))
		exit(3);
	if (!(tIgrac.loadFromFile("resource/igrac.png")))
		exit(4);
	if (!(tNaMestu.loadFromFile("resource/na_mestu.png")))
		exit(5);
	sZid.setTexture(tZid);
	sKutija.setTexture(tKutija);
	sKraj.setTexture(tKraj);
	sIgrac.setTexture(tIgrac);
	sNaMestu.setTexture(tNaMestu);
	kretanje = STOJI;
	br_poteza = 0;
	resize_update(V_EKR_X0,V_EKR_Y0);
	boja[0] = sf::Color::White;
	boja[1] = sf::Color(0,0,0,200);
	br_kutija = 0;
}

bool igra::ucitaj_nivo(int br)
{
	if (br < 1 || br > BR_NIVOA) return false;
	br_kutija = 0;
	std::stringstream naziv;
	naziv << "resource/nivoi/nivo";
	if (br < 10) naziv << "0";
	naziv << br << "\0";
	std::ifstream ulaz(naziv.str());
	std::cout << "Otvaram fajl: " << naziv.str() << "\n";
	for (int j = 0; j < V_FAJLA_Y; j++)
	{
		for (int i = 0; i < V_FAJLA_X; i++)
		{
			ulaz >> matrica[j][i];
			std::cout << matrica[j][i] << " ";
			switch (matrica[j][i])
			{
			case 2:
				kutija_vektor[br_kutija] = sf::Vector2f((float)i, (float)j);
				br_kutija++;
				mapa[j][i] = 0;
				break;
			case 5:
				kutija_vektor[br_kutija] = sf::Vector2f((float)i, (float)j);
				kutija_na_mestu[br_kutija] = 1;
				br_kutija++;
				mapa[j][i] = 3;
				break;
			case 4:
				igrac = sf::Vector2i(i, j);
				igrac_vektor = sf::Vector2f((float)i, (float)j);
				mapa[j][i] = 0;
				break;
			default:
				mapa[j][i] = matrica[j][i];
				break;
			}
		}
		std::cout << "\n";
	}
	ulaz.close();
	return true;
}

void igra::resize_update(int x, int y)
{
	v_ekrana = sf::Vector2i(x, y);

	pocetak = sf::Vector2f(V_NA_EKRANU, 0.f);
	sZid.setScale(sf::Vector2f(SKALIRANJE,SKALIRANJE));
	sKutija.setScale(sf::Vector2f(SKALIRANJE, SKALIRANJE));
	sKraj.setScale(sf::Vector2f(SKALIRANJE, SKALIRANJE));
	sIgrac.setScale(sf::Vector2f(SKALIRANJE, SKALIRANJE));
	sNaMestu.setScale(sf::Vector2f(SKALIRANJE, SKALIRANJE));
}

void igra::igrac_update()
{
	float pomeraj = 0.065;
	sf::Keyboard::Key strelice[4] = {
		sf::Keyboard::Left,
		sf::Keyboard::Up,
		sf::Keyboard::Right,
		sf::Keyboard::Down
	};
	int dx[4] = {-1, 0, +1, 0};
	int dy[4] = {0, -1, 0, +1};
	int suprotno[4] = {DESNO, DOLE, LEVO, GORE};

	for(int i = 0; i < 4; i++)
		if((kretanje == STOJI || kretanje == i || kretanje == suprotno[i]) &&
		  sf::Keyboard::isKeyPressed(strelice[i]) &&
		  mapa[igrac.y + dy[i]][igrac.x + dx[i]] != ZID)
			kretanje = i;
	if(kretanje != STOJI)
		igrac_vektor += sf::Vector2f(dx[kretanje] * pomeraj, dy[kretanje] * pomeraj);

	if(fabsf(igrac_vektor.x - (float)igrac.x) >= 1.f || fabsf(igrac_vektor.y - (float)igrac.y) >= 1.f)
	{
		br_poteza++;
		igrac.x += dx[kretanje];
		igrac.y += dy[kretanje];
		kretanje = STOJI;
	}
}

void igra::undo()
{

}

void igra::ispis_matrice()
{
	for (int j = 0; j < V_FAJLA_Y; j++)
	{
		for (int i = 0; i < V_FAJLA_X; i++)
		{ 
			switch (matrica[j][i])
			{
			case ZID:
				sZid.setPosition(pocetak + sf::Vector2f(i * V_NA_EKRANU, j * V_NA_EKRANU));
				prozor->draw(sZid);
				break;
			case KUTIJA:
				sKutija.setPosition(pocetak + sf::Vector2f(i * V_NA_EKRANU, j * V_NA_EKRANU));
				prozor->draw(sKutija);
				break;
			case KRAJ:
				sKraj.setPosition(pocetak + sf::Vector2f(i * V_NA_EKRANU, j * V_NA_EKRANU));
				prozor->draw(sKraj);
				break;
			case IGRAC:
				sIgrac.setPosition(pocetak + igrac_vektor * V_NA_EKRANU);
				prozor->draw(sIgrac);
				break;
			case NA_MESTU:
				sNaMestu.setPosition(pocetak + sf::Vector2f(i * V_NA_EKRANU, j * V_NA_EKRANU));
				prozor->draw(sNaMestu);
				break;
			default:
				break;
			}	 
		}
	}
}

void igra::ispis_podataka()
{
	int pozx = 2 * pocetak.x + V_FAJLA_X * V_NA_EKRANU;
	sf::RectangleShape poz;
	poz.setFillColor(boja[1]);
	poz.setPosition(sf::Vector2f(pozx, 0.f));
	poz.setSize(sf::Vector2f((v_ekrana.x > pozx) * (v_ekrana.x - pozx), v_ekrana.y));
	prozor->draw(poz);
}
