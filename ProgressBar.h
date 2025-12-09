#ifndef PROGETTO_PROGRESSBAR_PROGRESSBAR_H
#define PROGETTO_PROGRESSBAR_PROGRESSBAR_H

#include "Observer.h"
#include <SFML/Graphics.hpp>

class ProgressBar : public sf::Drawable, public Observer {
private:
    sf::RectangleShape background;
    sf::RectangleShape foreground;
    float width;
    float value;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override; //si trova nella classe protected sf::Drawable della SFML
public:
    ProgressBar(float width, sf::Color bgColor, sf::Color fgColor);//non dichiaro value perch`e inizializzato a 0.0

    void setPosition(float x, float y);
    void updateProgress(float progress) override;
    float getValue() const;

    //aggiunti metodi getter per gtest
    sf::Vector2f getForegroundSize() const;
    sf::Vector2f getBackgroundPosition() const;
    sf::Vector2f getForegroundPosition() const;
};
#endif