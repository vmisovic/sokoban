#include "igra.h"

int main()
{
	sf::RenderWindow prozor(sf::VideoMode(V_EKR_X0, V_EKR_Y0), "sokoban", sf::Style::Close);
	prozor.setPosition(sf::Vector2i(100, 0));
	prozor.setFramerateLimit(60);
	igra sokoban(&prozor);
	sokoban.ucitaj_nivo(1);

	while (prozor.isOpen())
	{
		sf::Event event;
		while (prozor.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				prozor.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Q || event.key.code == sf::Keyboard::Escape)
					prozor.close();
			}
		}
		prozor.clear(sf::Color::White);
		sokoban.igrac_update();
		sokoban.ispis_matrice();
		prozor.display();
	}
	return 0;
}
