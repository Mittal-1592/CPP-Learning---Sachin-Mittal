#ifndef SONG_H
#define SONG_H

#include <string>

class Song {
private:
    std::string title;
    std::string filePath;

public:
    Song(const std::string& title, const std::string& filePath);

    std::string getTitle() const;
    std::string getFilePath() const;
};

#endif