#include "../googletest/googletest/include/gtest/gtest.h"
#include "../ProgressBar.h"
#include "../FileLoader.h"

ProgressBar progressBar(300.f, sf::Color::Black, sf::Color::Green);
TEST(progressBar, updateProgress) {
    ProgressBar bar;
    bar.update(50);
    EXPECT_EQ(bar.getValue(), 50); // controlla che il valore interno sia aggiornato
}
