#include "FileLoader.h"
#include <iostream>
#include <chrono>
#include <thread>

FileLoader::FileLoader (const fs::path& path) : filePath(path) {}

void FileLoader::load() {
    if (!fs::exists(filePath)) {                                   //verifico se il percorso e' valido
        std::cerr << "Errore: Percorso non valido!\n";
    }
    auto fileSize= fs::file_size(filePath);                //ottengo la dimensione del file in byte

    float msPerKB = 50.0f;                                         //tempo per KB
    float totalTime = (fileSize /1024.0f) * msPerKB;               //calcolo tempo di caricamento proporzionale alla dimensione

    //simulazione caricamento
    progress++;
    if (progress > 100) {
        progress = 100;
        done = true;
    }
    notifyObserver(static_cast<float>(progress)); //aggiorno la barra di progresso
    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(totalTime / 100))); //simulo il tempo di caricamento
}
