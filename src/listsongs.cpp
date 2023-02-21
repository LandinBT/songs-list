#include "listsongs.hpp"

using namespace std;

bool ListSongs::isValidPos(const int& p) {
    return p >= 0 and p <= cont;
    }

void ListSongs::copyAll(const ListSongs& l) {
    int i(0);

    while(i <= l.cont) {
        musicHits[i] = l.musicHits[i];

        i++;
        }

    cont = l.cont;
    }

ListSongs::ListSongs() : cont(-1) { }

ListSongs::ListSongs(const ListSongs& l) {
    copyAll(l);
    }

ListSongs& ListSongs::operator = (const ListSongs& l) {
    copyAll(l);

    return *this;
    }

bool ListSongs::isEmpty() {
    return cont == -1;
    }

bool ListSongs::isFull() {
    return cont == ARRAYSIZE - 1;
    }

void ListSongs::insertSong(const int& p, const Song& s) {
    if(isFull()) {
        throw ListException("Desbordamiento de datos, insertSong");
        return;
        }

    if(p != -1 and !isValidPos(p)) {
        throw ListException("Posicion invalida, insertSong");
        return;
        }

    int i(cont);

    while(i > p) {
        musicHits[i + 1] = musicHits[i];

        i--;
        }

    musicHits[p + 1] = s;

    cont++;
    }

void ListSongs::deleteSong(const int& p) {
    if(!isValidPos(p)) {
        throw ListException("Posicion invalida, deleteSong");
        return;
        }

    int i(p - 1);

    while(i < cont) {
        musicHits[i] = musicHits[i + 1];

        i++;
        }

    cont--;
    }

Song ListSongs::retrieve(const int& p) {
    if(!isValidPos(p)) {
        throw ListException("Posicion invalida, retrieve");
        }

    return musicHits[p];
    }

int ListSongs::getFirstPos() {
    return isEmpty() ? -1 : 0;
    }

int ListSongs::getLastPos() {
    return cont;
    }

int ListSongs::getPrevPos(const int& p) {
    return p == getFirstPos() or !isValidPos(p) ? -1 : p - 1;
    }

int ListSongs::getNextPos(const int& p) {
    return p == getLastPos() or !isValidPos(p) ? -1 : p + 1;
    }

int ListSongs::findSongLinear(const Song& s) {
    int i(0);

    while(i <= cont) {
        if(musicHits[i] == s) {
            return i;
            }

        i++;
        }

    return -1;
    }

int ListSongs::findSongBinary(const Song& s) {
    int i(0), j(cont);
    int half;

    while(i <= j) {
        half = (i + j) / 2;

        if(musicHits[half] == s) {
            return half;
            }

        if(s < musicHits[half]) {
            j = half - 1;
            }
        else {
            i = half + 1;
            }
        }

    return -1;
    }

void ListSongs::deleteAll() {
    cont = -1;
    }

string ListSongs::toString() const {
    string result;
    int i(0);

    while(i <= cont) {
        result += musicHits[i].toString() + "\n";

        i++;
        }

    result += "\n";

    return result;
    }