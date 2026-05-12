#include "MusicPlayerController.h"
#include <iostream>
#include "Song.h"
#include "Validations.h"


MusicPlayerController::MusicPlayerController(
    IMusicPlayer* player,
    IPlaylistManager* manager,
    SongLibrary& library) {

    this->player = player;
    this->manager = manager;
    this->library = library;
}

void MusicPlayerController::run() {
    int choice;

    while (true) {
        std::cout << std::endl << "===== MUSIC PLAYER MENU =====" << std::endl;
        std::cout << "1. Create Playlist" << std::endl;
        std::cout << "2. Remove Playlist" << std::endl;
        std::cout << "3. Show All Playlists" << std::endl;
        std::cout << "4. Open Playlist" << std::endl;
        std::cout << "5. Exit" << std::endl << std::endl;

        choice = validations.isValidChoice(1, 5);
        std::cout << std::endl;
        if (choice == 1) {
            std::string playlistName;
            std::cout << "Enter playlist name: ";
            std::getline(std::cin, playlistName);

            manager->createPlaylist(playlistName);
        }

        else if (choice == 2) {
            std::string playlistName;
            manager->showAllPlaylists();
            std::cout << "Enter playlist name to remove: ";
            std::getline(std::cin, playlistName);

            manager->removePlaylist(playlistName);
        }

        else if (choice == 3) {
            manager->showAllPlaylists();
        }

        else if (choice == 4) {
            std::string playlistName;
            manager->showAllPlaylists();
            std::cout << "Enter playlist name to open: ";
            std::getline(std::cin, playlistName);

            Playlist* playlist = manager->getPlaylist(playlistName);

            if (playlist == nullptr) {
                std::cout << "Playlist not found."<< std::endl;
                continue;
            }

            std::cout << "Playlist Opened Successfully." << std::endl;

            int playlistChoice;

            while (true) {
                std::cout << std::endl << "===== PLAYLIST MENU =====" << std::endl << std::endl;

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

                playlistChoice = validations.isValidChoice(1, 11);
                
                if (playlistChoice == 1) {
                    library.displaySongs();
                    std::string songTitle;
                    std::cout << "Select song title: ";
                    std::getline(std::cin, songTitle);

                    Song* selectedSong = library.getSong(songTitle);

                    if (selectedSong == nullptr) {
                        std::cout << "Invalid song selection." << std::endl;
                    }
                    else {
                        manager->addSongToPlaylist(playlistName, selectedSong);
                    }
                }

                else if (playlistChoice == 2) {
                    manager->displayPlaylist(playlistName);
                    std::string title;
                    std::cout << "Enter song title to remove: ";
                    std::getline(std::cin, title);

                    manager->removeSong(title);
                }

                else if (playlistChoice == 3) {
                    std::string title;
                    std::cout << "Enter song title: ";
                    std::getline(std::cin, title);
                    int position;  
                    position = validations.isPositionValid(playlist->getSongs().size());

                    manager->moveSongUp(playlistName, title, position);
                }

                else if (playlistChoice == 4) {
                    std::string title;
                    std::cout << "Enter song title: ";
                    std::getline(std::cin, title);
                    int position;
                    position = validations.isPositionValid(playlist->getSongs().size());
                    manager->moveSongDown(playlistName, title, position);
                }

                else if (playlistChoice == 5) {
                    manager->displayPlaylist(playlistName);
                }

                else if (playlistChoice == 6) {
                    if (playlist->getSongs().size() == 0){
                        std::cout << "Playlist is empty. Please add songs before playing." << std::endl;
                        continue;
                    }
                    player->setPlaylist(playlist);
                    player->play();
                }

                else if (playlistChoice == 7) {
                    if (playlist->getSongs().size() == 0){
                        std::cout << "Playlist is empty. Please add songs before playing." << std::endl;
                        continue;
                    }
                    player->next();
                }

                else if (playlistChoice == 8) {
                    if (playlist->getSongs().size() == 0){
                        std::cout << "Playlist is empty. Please add songs before playing." << std::endl;
                        continue;
                    }
                    player->previous();
                }

                else if (playlistChoice == 9) {
                    if (playlist->getSongs().size() == 0){
                        std::cout << "Playlist is empty. Please add songs before playing." << std::endl;
                        continue;
                    }
                    player->pause();
                }

                else if (playlistChoice == 10) {
                    if (playlist->getSongs().size() == 0){
                        std::cout << "Playlist is empty. Please add songs before playing." << std::endl;
                        continue;
                    }
                    player->stop();
                }
                else if (playlistChoice == 11) {
                    std::cout<< "Returning to main menu..." << std::endl;
                    break;
                }
                else {
                    std::cout<< "Invalid choice. Please try again."<< std::endl;
                }
            }
        }

        else if (choice == 5) {
            std::cout << "Exiting..."<< std::endl;
            break;
        }
        else {
            std::cout<< "Invalid choice. Please try again."<< std::endl;
        }
    }
}