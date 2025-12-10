#include <SFML/Graphics.hpp>
#include "ProgressBar.h"
#include "FileLoader.h"
#include <iostream>

int main() {
    std::string pathInput;
    std::cout<<"Inserire un percorso di un file da caricare: \n> ";
    std::getline(std::cin,pathInput); //uso al posto di std::cin per permettere spazi nel percorso

    fs::path selectedFile (pathInput);

    FileLoader fileLoader(selectedFile);

    sf::RenderWindow window(sf::VideoMode(600, 350), "Esempio Progress Bar");
    window.setFramerateLimit(60); //pr vedere piu' fluidamente la barra che carica e limitare gli fps

    //Font titolo
    sf::Font font;
    font.loadFromFile("16020_FUTURAM.ttf");

    //titolo percorso file, tutti metodi di sf::Text
    sf::Text title;
    fs::path nameFile = selectedFile.filename();
    title.setString("Caricamento file: " + nameFile.string());
    title.setFont(font);
    title.setCharacterSize(18);
    title.setFillColor(sf::Color::Black);
    title.setPosition(150.0, 100.0);

    //pecentuale
    sf::Text percent("0%", font, 18);
    percent.setPosition(290.0, 125.0);
    percent.setFillColor(sf::Color::Black);

    ProgressBar progressBar(300.0, sf::Color::Black, sf::Color::Green);
    progressBar.setPosition(150.0, 150.0);

    FileLoader loader(selectedFile);
    loader.addObserver(&progressBar);  //collegamento loader a progress bar

    //gestione chiusura window
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) //se premo la X della window
                window.close();
        }
        loader.load(); //eseguo uno step di caricamento

        int percentUpdate = static_cast<int>(progressBar.getValue());  //aggiorno percentuale
        percent.setString(std::to_string(percentUpdate) + "%"); //converto in stringa

        window.clear(sf::Color::White);   //pulisce e colora lo sfondo della window
        window.draw(progressBar);
        window.draw(title);
        window.draw(percent);
        window.display();//mostra quello che e' stato disegnato nella window

        if (loader.isDone()) {
            percent.setString("Caricamento compleato");
            window.close();
            return 0;
        }
    }
}