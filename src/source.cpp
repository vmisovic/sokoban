#include "igra.h"

int main()
{
	sf::RenderWindow prozor(sf::VideoMode(1400, 800), "sokoban", sf::Style::Close);
	prozor.setPosition(sf::Vector2i(100, 0));
	igra sokoban(&prozor);
	sokoban.nivo();


	return 0;
}
