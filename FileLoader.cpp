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
    size_t stepSize = fileSize / 100;
    float stepMs = (fileSize / 1024)* 5 / 100;

    bytesLoaded += stepSize;
    if (bytesLoaded >= fileSize) {
        bytesLoaded = fileSize;
        done = true;
    }
    //simulazione caricamento
    float progress = static_cast<float>(bytesLoaded/fileSize)* 100.0f;

    notifyObserver(progress); //aggiorno la barra di progresso
    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(stepMs))); //simulo il tempo di caricamento
}
