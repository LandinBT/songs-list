#include "userinterface.hpp"

int main() {
    ListSongs myList;

    UserInterface showMenu(&myList);

    showMenu.mainMenu();
    }
