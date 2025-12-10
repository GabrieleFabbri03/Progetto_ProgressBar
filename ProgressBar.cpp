#include "ProgressBar.h"

ProgressBar::ProgressBar(float width, sf::Color bgColor, sf::Color fgColor)
    : width(width), value(0.0) {
    //inizializzo le due parti della barra
    //parte dietro barra con dimensione max fissata a width
    background.setSize(sf::Vector2f(width, 20.0)); //metodi della lib sfml
    background.setFillColor(bgColor);

    //parte frontale della barra inizializzata a 0
    foreground.setSize(sf::Vector2f(0.0, 20.0));   //metodi della lib sfml
    foreground.setFillColor(fgColor);
}
//definizione dei metodi della classe ProgressBar.h
void ProgressBar::setPosition(float x, float y) {
    background.setPosition(x, y);
    foreground.setPosition(x, y);
}
//metodo che mi serve al riempiemento della barra
void ProgressBar::updateProgress(float progress) {
    value = progress;
    float filledWidth = width * (value / 100.0); //calcolo la larghezza della parte riempita
    foreground.setSize(sf::Vector2f(filledWidth, 20.0));
}
float ProgressBar::getValue() const {
    return value;
}

void ProgressBar::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(background, states);
    target.draw(foreground, states);
}
//aggiunti getter per gtest
sf::Vector2f ProgressBar::getForegroundSize() const {
    return foreground.getSize();
};
sf::Vector2f ProgressBar::getForegroundPosition() const {
    return foreground.getPosition();
};
sf::Vector2f ProgressBar::getBackgroundPosition() const {
    return background.getPosition();
};
