#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#define ZID 1
#define KUTIJA 2
#define KRAJ 3
#define IGRAC 4
#define NA_MESTU 5
class igra
{
    sf::RenderWindow *prozor;
    sf::Texture tZid, tKutija, tKraj, tIgrac, tNaMestu;
    sf::Sprite zid, kutija, kraj, igrac, na_mestu;
    sf::Color boja[2];
    int matrica[16][19], mapa[16][19];
public:
    igra(sf::RenderWindow* prozor1);
    void ucitaj_nivo(int br);
    void ispis_matrice();
    void ispis_podataka();
	void nivo();
};