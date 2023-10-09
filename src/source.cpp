#include "igra.h"

int main()
{
	sf::RenderWindow prozor(sf::VideoMode(V_EKR_X0, V_EKR_Y0), "sokoban", sf::Style::Close);
	prozor.setPosition(sf::Vector2i(100, 0));
	prozor.setFramerateLimit(60);
	igra sokoban(prozor);
	int nivo = 1;
	sokoban.ucitaj_nivo(nivo);

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
				if (event.key.code == sf::Keyboard::U)
					sokoban.undo();
				if (event.key.code == sf::Keyboard::R)
					sokoban.ucitaj_nivo(nivo);
				if (event.key.code == sf::Keyboard::B && nivo > 1)
					sokoban.ucitaj_nivo(--nivo);
				if (event.key.code == sf::Keyboard::N && nivo < BR_NIVOA)
					sokoban.ucitaj_nivo(++nivo);
			}
		}
		prozor.clear(sf::Color::White);
		sokoban.igrac_update();
		sokoban.crtaj_mapu();
		if (sokoban.reseno())
			sokoban.ucitaj_nivo(++nivo);
		prozor.display();
	}
	return 0;
}
