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
	zid.setTexture(tZid);
	kutija.setTexture(tKutija);
	kraj.setTexture(tKraj);
	igrac.setTexture(tIgrac);
	na_mestu.setTexture(tNaMestu);
	zid.setScale(sf::Vector2f(0.25f,0.25f));
	kutija.setScale(sf::Vector2f(0.25f, 0.25f));
	kraj.setScale(sf::Vector2f(0.25f, 0.25f));
	igrac.setScale(sf::Vector2f(0.25f, 0.25f));
	na_mestu.setScale(sf::Vector2f(0.25f, 0.25f));
	boja[0] = sf::Color::White;
	boja[1] = sf::Color(0,0,0,200);
	br_kutija = 0;
}
bool igra::ucitaj_nivo(int br)
{
	if (br < 1 || br>50)return false;
	br_kutija = 0;
	std::stringstream naziv;
	naziv << "resource/nivoi/nivo";
	if (br < 10) naziv << "0";
	naziv << br << "\0";
	std::ifstream ulaz(naziv.str());
	std::cout << "Otvaram fajl: " << naziv.str() << "\n";
	for (int j = 0; j < 16; j++)
	{
		for (int i = 0; i < 19; i++)
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
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 16; j++)
		{ 
			switch (matrica[j][i])
			{
			default:
				break;
			case ZID:
				zid.setPosition(sf::Vector2f(i * 50.0f, j * 50.0f));
				prozor->draw(zid);
				break;
			case KUTIJA:
				kutija.setPosition(sf::Vector2f(i * 50.0f, j * 50.0f));
				prozor->draw(kutija);
				break;
			case KRAJ:
				kraj.setPosition(sf::Vector2f(i * 50.0f, j * 50.0f));
				prozor->draw(kraj);
				break;
			case IGRAC:
				igrac.setPosition(sf::Vector2f(i * 50.0f, j * 50.0f));
				prozor->draw(igrac);
				break;
			case NA_MESTU:
				na_mestu.setPosition(sf::Vector2f(i * 50.0f, j * 50.0f));
				prozor->draw(na_mestu);
				break;
			}	 
		}
	}
}
void igra::ispis_podataka()
{
	sf::RectangleShape poz;
	poz.setFillColor(boja[1]);
	poz.setPosition(sf::Vector2f(1000.f, 0.f));
	poz.setSize(sf::Vector2f(400, 800));
	prozor->draw(poz);
}
void igra::nivo()
{
	ucitaj_nivo(1);
	while (prozor->isOpen())
	{
		sf::Event event;
		while (prozor->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				prozor->close();
		}
		prozor->clear(boja[0]);
		ispis_matrice();
		ispis_podataka();
		prozor->display();
	}
}
