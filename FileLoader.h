#ifndef PROGETTO_PROGRESSBAR_FILELOADER_H
#define PROGETTO_PROGRESSBAR_FILELOADER_H
#include "Observable.h"
#include <filesystem>

namespace fs = std::filesystem;

class FileLoader : public Observable {
private:
    fs::path filePath;
    bool done = false;
public:
    explicit FileLoader (const fs::path& path);

    void load();
};
#endif