#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setFramerateLimit(60);


    sf::CircleShape ball(50.f);
    ball.setFillColor(sf::Color::Red);

    int x = 0,y = 0;
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.key.code == sf::Keyboard::Space)
            {
                while (ball.getPosition().y > 400)
                {
                    if (y > 0) y = 0;
                    ball.move(0, y--);
                    window.clear(sf::Color::Yellow);
                    window.draw(ball);
                    window.display();
                }
            }
            else if (event.key.code == sf::Keyboard::D)
            {
                if (x < 0) x = 0;
                if (ball.getPosition().x+100 > 800) {}
                else ball.move(x++, 0);
            }
            else if (event.key.code == sf::Keyboard::A)
            {
                if (x > 0)x = 0;
                if (ball.getPosition().x < 0) {}
                else ball.move(x--, 0);
            }
        }
        if (ball.getPosition().y+100 < 600) ball.move(0, y++);
        else
        {
            y = 0;
            ball.setPosition(ball.getPosition().x, 500);
        }

        window.clear(sf::Color::Yellow);
        window.draw(ball);
        window.display();
    }

    return 0;
}