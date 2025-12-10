#include "../googletest/googletest/include/gtest/gtest.h"
#include "../ProgressBar.h"
#include "../FileLoader.h"
#include <fstream>

//testo se la barra inizia da 0
TEST(progressBar, initialValueZero) {
    ProgressBar progressBar(300.0, sf::Color::Black, sf::Color::Green);
    EXPECT_FLOAT_EQ(progressBar.getValue(), 0.0);
}
//testo se la barra si aggiorna correttamente e dimensioni
TEST(progressBar, updateProgress) {
    ProgressBar progressBar(300.0, sf::Color::Black, sf::Color::Green);
    progressBar.updateProgress(50.0);
    EXPECT_FLOAT_EQ(progressBar.getValue(), 50.0);

    sf::Vector2f size = progressBar.getForegroundSize();
    EXPECT_FLOAT_EQ(size.x, 150.0); //50% di 300
    EXPECT_FLOAT_EQ(size.y, 20.0);  //h fissa
}
//verifica che posizione venga settata correttamente
TEST(ProgressBarTest, SetPositionSetsBackgroundAndForeground) {
    ProgressBar bar(100.0, sf::Color::Black, sf::Color::Green);
    bar.setPosition(10.0, 20.0);

    sf::Vector2f bgPos = bar.getBackgroundPosition();
    sf::Vector2f fgPos = bar.getForegroundPosition();

    EXPECT_FLOAT_EQ(bgPos.x, 10.0);
    EXPECT_FLOAT_EQ(bgPos.y, 20.0);
    EXPECT_FLOAT_EQ(fgPos.x, 10.0);
    EXPECT_FLOAT_EQ(fgPos.y, 20.0);
}

//test caricamento di un file inesistente
TEST(FileLoader, LoadNonExistentFile) {
    fs::path invalidPath("non_existent_file.txt");
    FileLoader loader(invalidPath);

    testing::internal::CaptureStderr(); //cattura l'output di errore
    loader.load();
    std::string output = testing::internal::GetCapturedStderr(); //restituisce in output catturato

    EXPECT_NE(output.find("Errore: Percorso non valido!"), std::string::npos); //verifica che il messaggio di errore sia presente
}

//Caricamento file vuoto
TEST(FileLoaderTest, LoadEmptyFile) {
    std::ofstream out("empty_file.txt");
    out.close();

    FileLoader loader("empty_file.txt");

    testing::internal::CaptureStderr();
    loader.load();
    std::string output = testing::internal::GetCapturedStderr();

    EXPECT_EQ(output, "");
    EXPECT_TRUE(loader.isDone());

    std::remove("empty_file.txt");
}

//Caricamento file esistente
TEST(FileLoaderTest, LoadExistingFile) {
    // Creo un file temporaneo
    std::ofstream out("temp_file.txt");
    out << "Hello world";
    out.close();

    FileLoader loader("temp_file.txt");

    // Catturo eventuali messaggi di errore
    testing::internal::CaptureStderr();
    while (!loader.isDone()) {
        loader.load();
    }
    EXPECT_TRUE(loader.isDone());

    std::string output = testing::internal::GetCapturedStderr();

    EXPECT_EQ(output, "");      // nessun errore
    EXPECT_TRUE(loader.isDone()); // done dovrebbe essere true

    std::remove("temp_file.txt"); // pulizia
}
