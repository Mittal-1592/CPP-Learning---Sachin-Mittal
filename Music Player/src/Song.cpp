#include "Song.h"

Song::Song(const std::string& title, const std::string& filePath) {
    this->title = title;
    this->filePath = filePath;
}

std::string Song::getTitle() const {
    return title;
}

std::string Song::getFilePath() const {
    return filePath;
}