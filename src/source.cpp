#include "igra.h"

int main()
{
	sf::RenderWindow prozor(sf::VideoMode(V_EKR_X0, V_EKR_Y0), "sokoban", sf::Style::Close);
	prozor.setPosition(sf::Vector2i(100, 0));
	igra sokoban(&prozor);
	sokoban.start();

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
			if (event.type == sf::Event::Resized)
				sokoban.v_ekrana = sf::Vector2i(event.size.width, event.size.height);
		}
		prozor.clear(sokoban.boja[0]);
		sokoban.ispis_matrice();
		sokoban.ispis_podataka();
		prozor.display();
	}
	return 0;
}
