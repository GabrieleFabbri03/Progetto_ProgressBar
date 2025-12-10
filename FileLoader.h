#ifndef PROGETTO_PROGRESSBAR_FILELOADER_H
#define PROGETTO_PROGRESSBAR_FILELOADER_H
#include "Observable.h"
#include <filesystem>

namespace fs = std::filesystem;

class FileLoader : public Observable {
private:
    int progress = 0;
    float bytesLoaded = 0.0;
    fs::path filePath;
    bool done = false;
public:
    FileLoader (const fs::path& path);

    void load();

    bool isDone() const { return done; }
};
#endif