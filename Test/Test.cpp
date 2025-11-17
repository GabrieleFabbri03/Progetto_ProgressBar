#include "../googletest/googletest/include/gtest/gtest.h"
#include "../ProgressBar.h"
#include "../FileLoader.h"


//testo se la barra inizia da 0
TEST(progressBar, initialValueZero) {
    ProgressBar progressBar(300.f, sf::Color::Black, sf::Color::Green);
    EXPECT_FLOAT_EQ(progressBar.getValue(), 0.0f);
}
//testo se la barra si aggiorna correttamente
TEST(progressBar, updateProgress) {
    ProgressBar progressBar(300.f, sf::Color::Black, sf::Color::Green);
    progressBar.updateProgress(50.0f);
    EXPECT_FLOAT_EQ(progressBar.getValue(), 50.0f);

    sf::Vector2f size = progressBar.getForegroundSize();
    EXPECT_FLOAT_EQ(size.x, 150.0f); //50% di 300
    EXPECT_FLOAT_EQ(size.y, 20.0f);  //h fissa
}
TEST(ProgressBarTest, SetPositionSetsBackgroundAndForeground) {
    ProgressBar bar(100.0f, sf::Color::Black, sf::Color::Green);
    bar.setPosition(10.0f, 20.0f);

    sf::Vector2f bgPos = bar.getBackgroundPosition();
    sf::Vector2f fgPos = bar.getForegroundPosition();

    EXPECT_FLOAT_EQ(bgPos.x, 10.0f);
    EXPECT_FLOAT_EQ(bgPos.y, 20.0f);
    EXPECT_FLOAT_EQ(fgPos.x, 10.0f);
    EXPECT_FLOAT_EQ(fgPos.y, 20.0f);
}