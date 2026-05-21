#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>
#include "Song.h"

class Playlist {
private:
    std::string name;
    std::vector<Song*> songs;

public:
    Playlist();
    Playlist(const std::string& name);

    bool addSong(Song* song);
    bool removeSong(const std::string& songTitle);

    bool moveSongUp(const std::string& songTitle, int position);
    bool moveSongDown(const std::string& songTitle, int position);

    bool display() const;

    std::vector<Song*> getSongs() const;
    std::string getName() const;

    ~Playlist();
};

#endif