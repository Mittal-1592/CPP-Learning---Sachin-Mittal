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

    void addSong(Song* song);
    void removeSong(const std::string& songTitle);

    void moveSongUp(const std::string& songTitle, int position);
    void moveSongDown(const std::string& songTitle, int position);

    void display() const;

    std::vector<Song*> getSongs() const;
    std::string getName() const;

    ~Playlist();
};

#endif