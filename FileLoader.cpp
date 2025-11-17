#include "FileLoader.h"
#include <iostream>
#include <chrono>
#include <thread>

FileLoader::FileLoader (const fs::path& path) : filePath(path) {}

void FileLoader::load() {
    try {
        auto fileSize= fs::file_size(filePath);            //ottengo la dimensione del file in byte


        size_t stepSize = std::max(static_cast<size_t>(1), fileSize / 100);
        float stepMs = (fileSize / 1024)* 5 / 100;

        bytesLoaded += stepSize;

        if (fileSize == 0) {
            done = true;
            notifyObserver(100.0f);
            return;
        }

        if (bytesLoaded >= fileSize) {
            bytesLoaded = fileSize;
            done = true;
        }
        //simulazione caricamento
        float progress = static_cast<float>(bytesLoaded/fileSize)* 100.0f;

        notifyObserver(progress); //aggiorno la barra di progresso
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(stepMs))); //simulo il tempo di caricamento
    }
    catch (const std::filesystem::filesystem_error&) {                                   //verifico se il percorso e' valido
        std::cerr << "Errore: Percorso non valido!\n";
    }
}
