#ifndef PROGETTO_PROGRESSBAR_FILELOADER_H
#define PROGETTO_PROGRESSBAR_FILELOADER_H
#include "Observable.h"
#include <iostream>
#include <filesystem>
#include <chrono>
#include <thread>

namespace fs = std::filesystem;

class FileLoader : public Observable {
private:
    fs::path filePath;
    bool done = false;
public:
    explicit FileLoader (const fs::path& path) : filePath(path) {}

    void load() {
        if (!fs::exists(filePath)) {                                   //verifico se il percorso e' valido
            std::cerr << "Errore: Percorso non valido!\n";
        }
        auto fileSize= fs::file_size(filePath);                //ottengo la dimensione del file in byte

        float msPerKB = 50.0f;                                         //tempo per KB
        float totalTime = (fileSize /1024.0f) * msPerKB;               //calcolo tempo di caricamento proporzionale alla dimensione

        //simulazione caricamento
        for (int i = 0; i <= 100; ++i){
            std::this_thread::sleep_for (std::chrono::milliseconds (static_cast<int>(totalTime/100.0f)));
            notifyObserver(static_cast<float>(i)); //notifico gli observer ma con conversione float siccome progress e' float
        }
        ruturn done = true;
    }
};
#endif