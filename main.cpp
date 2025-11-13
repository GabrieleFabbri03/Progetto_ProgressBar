#include <SFML/Graphics.hpp>
#include "ProgressBar.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 200), "Esempio Progress Bar");
    window.setFramerateLimit(60); //pr vedere piu' fluidamente la barra che carica

    ProgressBar progressBar(300.f, sf::Color::Black, sf::Color::Green);
    progressBar.setPosition(50.0f, 50.0f);

    //gestione chiusura window
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);   //pulisce e colora lo sfondo della window
        window.draw(progressBar);
        window.display();                 //mostra quello che e' stato disegnato nella window
    }
    return 0;
}
