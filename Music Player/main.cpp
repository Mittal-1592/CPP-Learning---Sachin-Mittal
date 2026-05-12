#include "include/IMusicPlayer.h"
#include "include/MusicPlayer.h"
#include "PlaylistManager.h"
#include "MusicPlayerController.h"
#include "SongLibrary.h"

int main() {
    SongLibrary library;
    library.addSong(new Song("Breeze Air", "songs/Breeze Air.wav"));
    library.addSong(new Song("Cloud Nine", "songs/Cloud Nine.wav"));
    library.addSong(new Song("Broom Game", "songs/Broom Game.wav"));
    library.addSong(new Song("Flute Nace", "songs/Flute Nace.wav"));

    MusicPlayer player;
    PlaylistManager manager;

    MusicPlayerController controller(&player, &manager, library);

    controller.run();

    return 0;
}