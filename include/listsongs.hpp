#ifndef LISTSONGS_HPP_INCLUDED
#define LISTSONGS_HPP_INCLUDED

#include <exception>
#include <string>

#include "song.hpp"

#define ARRAYSIZE 1024

/******************************************************************************/

class ListException : public std::exception {
    private:
        std::string msg;

    public:
        ListException() noexcept : msg("Error indefinido") { }

        ListException(const ListException& ex) noexcept : msg(ex.msg) { }

        ListException(const std::string& m) : msg(m) { }

        ListException& operator = (const ListException& ex) noexcept {
            msg = ex.msg;

            return *this;
            }

        virtual ~ListException() { }

        virtual const char* what() const noexcept {
            return msg.c_str();
            }
    };

/******************************************************************************/

class ListSongs {
    private:
        Song musicHits[ARRAYSIZE];
        int cont;

        bool isValidPos(const int&); /// pos

        void copyAll(const ListSongs&);

    public:
        ListSongs();
        ListSongs(const ListSongs&);

        ListSongs& operator = (const ListSongs&);

        bool isEmpty();
        bool isFull();

        void insertSong(const int&, const Song&); /// pos, song
        void deleteSong(const int&); /// pos

        Song retrieve(const int&); /// pos

        int getFirstPos();
        int getLastPos();
        int getPrevPos(const int&); /// pos
        int getNextPos(const int&); /// pos

        int findSongLinear(const Song&);
        int findSongBinary(const Song&);

        void deleteAll();

        std::string toString() const;
    };

#endif // LISTSONGS_HPP_INCLUDED