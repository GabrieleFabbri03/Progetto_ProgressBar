#include "ProgressBar.h"

ProgressBar::ProgressBar(float width, sf::Color bgColor, sf::Color fgColor)
    : width(width), dimension(0.0f) {

    //parte dietro barra con dimensione max fissata a width
    background.setSize(sf::Vector2f(width, 20.0f)); //metodi della lib sfml
    background.setFillColor(bgColor);

    //parte frontale della barra inizializzata a 0
    foreground.setSize(sf::Vector2f(0.0f, 20.0f));   //metodi della lib sfml
    foreground.setFillColor(fgColor);
}
//definizione dei metodi della classe ProgressBar.h
void ProgressBar::setPosition(float x, float y) {
    background.setPosition(x, y);
    foreground.setPosition(x, y);
}
