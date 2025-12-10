#include "FileLoader.h"
#include <iostream>
#include <chrono>
#include <thread>

FileLoader::FileLoader (const fs::path& path) : filePath(path) {}

void FileLoader::load() {
    try {
        unsigned int fileSize= fs::file_size(filePath);            //ottengo la dimensione del file in byte

        unsigned int stepSize = std::max(static_cast<unsigned int>(1), fileSize / 100);
        float stepMs = (fileSize / 1024)* 10 / 100;  //il 10 `e indice per rendere il caricamento piu' lento e visibile

        bytesLoaded += stepSize;

        if (fileSize == 0) {
            done = true;
            notifyObserver(100.0);
            return;
        }

        if (bytesLoaded >= fileSize) {
            bytesLoaded = fileSize;
            done = true;
        }
        //simulazione caricamento
        float progress = (bytesLoaded / static_cast<float>(fileSize))* 100.0;

        notifyObserver(progress); //aggiorno la barra di progresso
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(stepMs))); //simulo il tempo di caricamento
    }
    catch (const fs::filesystem_error&) {  //eccezione della libreria filesystem
        std::cerr << "Errore: Percorso non valido!\n";
        done = true;
    }
}
