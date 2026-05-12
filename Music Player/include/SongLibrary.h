#ifndef SONGLIBRARY_H
#define SONGLIBRARY_H  

#include <vector>
#include "Song.h"   

class SongLibrary {
    private:
        std::vector<Song*> songs;
    public:
        void addSong(Song* song);
        void displaySongs() const;
        Song* getSong(std::string title) const;

        ~SongLibrary();
};
#endif 