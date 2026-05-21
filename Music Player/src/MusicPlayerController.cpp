#include "MusicPlayerController.h"
#include <iostream>
#include "Song.h"
#include "Validations.h"


MusicPlayerController::MusicPlayerController(
    IMusicPlayer* player,
    IPlaylistManager* manager,
    SongLibrary& library, Validations &validations):library(library){
    this->player = player;
    this->manager = manager;
    this->validations = validations;
}

void MusicPlayerController::run() {
    while (true) {
        std::cout << std::endl;
        std::cout << "===== MUSIC PLAYER MENU ====="
                  << std::endl;

        std::cout << "1. Create Playlist" << std::endl;
        std::cout << "2. Remove Playlist" << std::endl;
        std::cout << "3. Show All Playlists" << std::endl;
        std::cout << "4. Open Playlist" << std::endl;
        std::cout << "5. Exit" << std::endl;

        int choice =
            validations.isValidChoice(1, 5);

        if (choice == 5) {
            std::cout << "Application closed !!"<< std::endl;
            break;
        }

        handleMainMenuChoice(choice);
    }
}

void MusicPlayerController::handleMainMenuChoice(
    int choice) {
    if (choice == 1) {

        std::string playlistName;

        std::cout << "Enter playlist name: ";

        playlistName = validations.getValidPlaylistName();

        manager->createPlaylist(playlistName);
    }

    else if (choice == 2) {

        if (!manager->showAllPlaylists()) {
            return;
        }

        std::string playlistName;

        std::cout<< "Enter playlist name to remove: ";

        playlistName = validations.getValidPlaylistName();

        manager->removePlaylist(playlistName);
    }

    else if (choice == 3) {

        manager->showAllPlaylists();
    }

    else if (choice == 4) {

        openPlaylist();
    }
}

void MusicPlayerController::openPlaylist() {

    if (!manager->showAllPlaylists()) {
        return;
    }

    std::string playlistName;

    std::cout << "Enter playlist name to open: ";

    playlistName =
        validations.getValidPlaylistName();

    Playlist* playlist =
        manager->getPlaylist(playlistName);

    if (playlist == nullptr) {

        std::cout << "Playlist not found."
                  << std::endl;

        return;
    }

    std::cout
        << "Playlist Opened Successfully."
        << std::endl;

    handlePlaylistMenu(
        playlist,
        playlistName);
}

void MusicPlayerController::handlePlaylistMenu(
    Playlist* playlist,
    const std::string& playlistName) {

    while (true) {

        std::cout << std::endl;
        std::cout << "===== PLAYLIST MENU ====="
                  << std::endl;

        std::cout << "1. Add Song" << std::endl;
        std::cout << "2. Remove Song" << std::endl;
        std::cout << "3. Move Song Up" << std::endl;
        std::cout << "4. Move Song Down" << std::endl;
        std::cout << "5. Display Playlist" << std::endl;
        std::cout << "6. Play Playlist" << std::endl;
        std::cout << "7. Next Song" << std::endl;
        std::cout << "8. Previous Song" << std::endl;
        std::cout << "9. Pause Song" << std::endl;
        std::cout << "10. Stop Song" << std::endl;
        std::cout << "11. Back" << std::endl;

        int choice =
            validations.isValidChoice(1, 11);

        if (choice == 11) {

            std::cout
                << "Returning to main menu..."
                << std::endl;

            break;
        }

        handlePlaylistChoice(
            choice,
            playlist,
            playlistName);
    }
}

void MusicPlayerController::handlePlaylistChoice(
    int choice,
    Playlist* playlist,
    const std::string& playlistName) {

    if (choice == 1) {

        handleAddSong(playlistName);
    }

    else if (choice == 2) {

        handleRemoveSong(
            playlist,
            playlistName);
    }

    else if (choice == 3) {

        handleMoveSongUp(
            playlist,
            playlistName);
    }

    else if (choice == 4) {

        handleMoveSongDown(
            playlist,
            playlistName);
    }

    else if (choice == 5) {

        manager->displayPlaylist(playlistName);
    }

    else if (choice == 6) {

        handlePlayPlaylist(playlist);
    }

    else if (choice == 7) {

        handleNextSong(playlist);
    }

    else if (choice == 8) {

        handlePreviousSong(playlist);
    }

    else if (choice == 9) {

        handlePauseSong(playlist);
    }

    else if (choice == 10) {

        handleStopSong(playlist);
    }
}

void MusicPlayerController::handleAddSong(
    const std::string& playlistName) {

    std::cout << std::endl;

    library.displaySongs();

    std::string songTitle;

    std::cout << "Select song title: ";

    std::getline(std::cin, songTitle);

    Song* selectedSong =
        library.getSong(songTitle);

    if (selectedSong == nullptr) {

        std::cout
            << "Invalid song selection."
            << std::endl;

        return;
    }

    manager->addSongToPlaylist(
        playlistName,
        selectedSong);
}

void MusicPlayerController::handleRemoveSong(
    Playlist* playlist,
    const std::string& playlistName) {

    manager->displayPlaylist(playlistName);

    if (playlist->getSongs().empty()) {

        std::cout
            << "Playlist is empty. No songs to remove."
            << std::endl;

        return;
    }

    std::string title;

    std::cout
        << "Enter song title to remove: ";

    std::getline(std::cin, title);

    manager->removeSong(title);
}

void MusicPlayerController::handleMoveSongUp(
    Playlist* playlist,
    const std::string& playlistName) {

    if (playlist->getSongs().empty()) {

        std::cout
            << "Playlist is empty. No songs to move."
            << std::endl;

        return;
    }

    std::string title;

    std::cout << "Enter song title: ";

    std::getline(std::cin, title);

    int position =
        validations.isPositionValid(
            playlist->getSongs().size());

    manager->moveSongUp(
        playlistName,
        title,
        position);
}

void MusicPlayerController::handleMoveSongDown(
    Playlist* playlist,
    const std::string& playlistName) {

    if (playlist->getSongs().empty()) {

        std::cout
            << "Playlist is empty. No songs to move."
            << std::endl;

        return;
    }

    std::string title;

    std::cout << "Enter song title: ";

    std::getline(std::cin, title);

    int position =
        validations.isPositionValid(
            playlist->getSongs().size());

    manager->moveSongDown(
        playlistName,
        title,
        position);
}

void MusicPlayerController::handlePlayPlaylist(
    Playlist* playlist) {

    if (playlist->getSongs().empty()) {

        std::cout
            << "Playlist is empty. Please add songs before playing."
            << std::endl;

        return;
    }

    player->setPlaylist(playlist);

    player->play();
}

void MusicPlayerController::handleNextSong(
    Playlist* playlist) {

    if (playlist->getSongs().empty()) {

        std::cout
            << "Playlist is empty. Please add songs before playing."
            << std::endl;

        return;
    }

    player->next();
}

void MusicPlayerController::handlePreviousSong(
    Playlist* playlist) {

    if (playlist->getSongs().empty()) {

        std::cout
            << "Playlist is empty. Please add songs before playing."
            << std::endl;

        return;
    }

    player->previous();
}

void MusicPlayerController::handlePauseSong(
    Playlist* playlist) {

    if (playlist->getSongs().empty()) {

        std::cout
            << "Playlist is empty. Please add songs before playing."
            << std::endl;

        return;
    }

    player->pause();
}

void MusicPlayerController::handleStopSong(
    Playlist* playlist) {

    if (playlist->getSongs().empty()) {

        std::cout
            << "Playlist is empty. Please add songs before playing."
            << std::endl;

        return;
    }

    player->stop();
}