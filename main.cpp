#include <SFML/Graphics.hpp>
#include "ProgressBar.h"
#include "FileLoader.h"
#include <iostream>

int main() {
    std::string pathInput;
    std::cout<<"Inserire un percorso di un file da caricare: \n> ";
    std::cin >> pathInput;

    fs::path selectedFile (pathInput);

    FileLoader fileLoader(selectedFile);

    sf::RenderWindow window(sf::VideoMode(600, 350), "Esempio Progress Bar");
    window.setFramerateLimit(60); //pr vedere piu' fluidamente la barra che carica

    ProgressBar progressBar(300.f, sf::Color::Black, sf::Color::Green);
    progressBar.setPosition(150.0f, 150.0f);

    FileLoader loader(selectedFile);
    loader.addObserver(&progressBar);  //collegamento loader a progress bar

    //gestione chiusura window
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        loader.load(); //eseguo un piccolo step di caricamento

         //aggiorno percentuale
        window.clear(sf::Color::White);   //pulisce e colora lo sfondo della window
        window.draw(progressBar);
        window.display();                 //mostra quello che e' stato disegnato nella window
    }
    return 0;
}
