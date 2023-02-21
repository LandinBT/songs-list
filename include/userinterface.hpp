#ifndef USERINTERFACE_HPP_INCLUDED
#define USERINTERFACE_HPP_INCLUDED

#include <iostream>

#include "listsongs.hpp"

class UserInterface {
    private:
    ListSongs* listRef;

    public:
    UserInterface(ListSongs*);

    void mainMenu();
    void addSong();
    void deleteSong();
    void deleteAllSongs();
    void findSong();
};

#endif // USERINTERFACE_HPP_INCLUDED