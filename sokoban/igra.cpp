#include "igra.h"
igra::igra(sf::RenderWindow* prozor1)
{
    prozor = prozor1;
    if (!(tZid.loadFromFile("resource/kocka.png")))
        exit(1);
    //if (!(tZid.loadFromFile("resource/igrac.png")))
        //exit(1);
    if (!(tKutija.loadFromFile("resource/kutija.png")))
        exit(2);
    if (!(tKraj.loadFromFile("resource/kraj-t256.png")))
        exit(3);
    if (!(tNaMestu.loadFromFile("resource/na_mestu.png")))
        exit(4);
    zid.setTexture(tZid);
    kutija.setTexture(tKutija);
    kraj.setTexture(tKraj);
    na_mestu.setTexture(tNaMestu);
    na_mestu.setScale(sf::Vector2f(0.25f, 0.25f));
    zid.setScale(sf::Vector2f(0.25f,0.25f));
    kutija.setScale(sf::Vector2f(0.25f, 0.25f));
    kraj.setScale(sf::Vector2f(0.25f, 0.25f));
    boja[1] = sf::Color::White;
    boja[2] = sf::Color(0,0,0,200);
    std::ifstream nivo("resource/nivo.txt");
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
    poz.setFillColor(boja[2]);
    poz.setPosition(sf::Vector2f(1000.f, 0.f));
    poz.setSize(sf::Vector2f(400, 800));
    prozor->draw(poz);
}
void igra::nivo()
{
    while (prozor->isOpen())
    {
        sf::Event event;
        while (prozor->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                prozor->close();
        }
        prozor->clear(boja[1]);
        ispis_matrice();
        ispis_podataka();
        prozor->display();
    }
}
