#ifndef VALIDATIONS_H
#define VALIDATIONS_H

#include <string>

class Validations {
    public:
        int isValidChoice(int min, int max);
        int isPositionValid(int size);
        bool validatePlaylistName(const std::string& playlistName);
        std::string getValidPlaylistName();
};
#endif