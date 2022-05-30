#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#define BR_NIVOA 50
#define V_FAJLA_X 19
#define V_FAJLA_Y 16
#define MAX_KUTIJA 35
#define ZID 1
#define KUTIJA 2
#define KRAJ 3
#define IGRAC 4
#define NA_MESTU 5

#define V_EKR_X0 1400
#define V_EKR_Y0 800
#define V_SLIKE 256
#define SKALIRANJE 0.25f
#define V_NA_EKRANU 50.0f

class igra
{
	sf::RenderWindow *prozor;

	int matrica[V_FAJLA_Y][V_FAJLA_X], mapa[V_FAJLA_Y][V_FAJLA_X];
	sf::Vector2f kutija_vektor[MAX_KUTIJA], igrac_vektor;
	bool kutija_na_mestu[MAX_KUTIJA];
	int br_kutija;

	sf::Vector2f pocetak;
	sf::Texture tZid, tKutija, tKraj, tIgrac, tNaMestu;
	sf::Sprite zid, kutija, kraj, igrac, na_mestu;
public:
	sf::Vector2i v_ekrana;
	sf::Color boja[2];
	igra(sf::RenderWindow* prozor1);
	bool ucitaj_nivo(int br);
	void ispis_matrice();
	void ispis_podataka();
	void start();
};
