#include "igra.h"

igra::igra(sf::RenderWindow* prozor1)
{
	prozor = prozor1;
	v_ekrana = sf::Vector2i(V_EKR_X0,V_EKR_Y0);
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
	zid.setTexture(tZid);
	kutija.setTexture(tKutija);
	kraj.setTexture(tKraj);
	igrac.setTexture(tIgrac);
	na_mestu.setTexture(tNaMestu);
	pocetak = sf::Vector2f(V_NA_EKRANU,0.f);
	zid.setScale(sf::Vector2f(SKALIRANJE,SKALIRANJE));
	kutija.setScale(sf::Vector2f(SKALIRANJE, SKALIRANJE));
	kraj.setScale(sf::Vector2f(SKALIRANJE, SKALIRANJE));
	igrac.setScale(sf::Vector2f(SKALIRANJE, SKALIRANJE));
	na_mestu.setScale(sf::Vector2f(SKALIRANJE, SKALIRANJE));
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
			std::cout << matrica[j][i] <<" ";
			switch (matrica[j][i])
			{
			case 2:
				kutija_vektor[br_kutija] = sf::Vector2f(float(i),float(j));
				br_kutija++;
				mapa[j][i] = 0;
				break;
			case 5:
				kutija_vektor[br_kutija] = sf::Vector2f(float(i), float(j));
				kutija_na_mestu[br_kutija] = 1;
				br_kutija++;
				mapa[j][i] = 3;
			case 4:
				igrac_vektor = sf::Vector2f(float(i), float(j));
				mapa[j][i] = 0;
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

void igra::ispis_matrice()
{
	for (int i = 0; i < V_FAJLA_X; i++)
	{
		for (int j = 0; j < V_FAJLA_Y; j++)
		{ 
			switch (matrica[j][i])
			{
			default:
				break;
			case ZID:
				zid.setPosition(pocetak + sf::Vector2f(i * V_NA_EKRANU, j * V_NA_EKRANU));
				prozor->draw(zid);
				break;
			case KUTIJA:
				kutija.setPosition(pocetak + sf::Vector2f(i * V_NA_EKRANU, j * V_NA_EKRANU));
				prozor->draw(kutija);
				break;
			case KRAJ:
				kraj.setPosition(pocetak + sf::Vector2f(i * V_NA_EKRANU, j * V_NA_EKRANU));
				prozor->draw(kraj);
				break;
			case IGRAC:
				igrac.setPosition(pocetak + sf::Vector2f(i * V_NA_EKRANU, j * V_NA_EKRANU));
				prozor->draw(igrac);
				break;
			case NA_MESTU:
				na_mestu.setPosition(pocetak + sf::Vector2f(i * V_NA_EKRANU, j * V_NA_EKRANU));
				prozor->draw(na_mestu);
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
	poz.setSize(sf::Vector2f(v_ekrana.x - pozx, v_ekrana.y));
	prozor->draw(poz);
}

void igra::start()
{
	ucitaj_nivo(1);
}
