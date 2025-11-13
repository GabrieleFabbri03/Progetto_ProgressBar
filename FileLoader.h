#ifndef PROGETTO_PROGRESSBAR_FILELOADER_H
#define PROGETTO_PROGRESSBAR_FILELOADER_H
#include "Observable.h"

class FileLoader : public Observable {
private:
    sf::Path filePath;
    bool done = false;
public:
    FileLoader (const sf::Path& path) : filePath(path) {}

};
#endif