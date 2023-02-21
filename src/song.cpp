#include "song.hpp"

using namespace std;

Song::Song() { }

Song::Song(const Song& s) : songName(s.songName),
    author(s.author), interpreter(s.interpreter), ranking(s.ranking) { }

Song& Song::operator = (const Song& s) {
    songName = s.songName;
    author = s.author;
    interpreter = s.interpreter;
    ranking = s.ranking;

    return *this;
    }

string Song::getSongName() const {
    return songName;
    }

Name Song::getAuthor() const {
    return author;
    }

Name Song::getInterpreter() const {
    return interpreter;
    }

int Song::getRanking() const {
    return ranking;
    }

string Song::toString() const {
    string result;

    result = to_string(ranking);
    result.resize(3, ' ');
    result += " | ";
    result += songName;
    result.resize(40, ' ');
    result += " | ";
    result += author.toString();
    result.resize(115, ' ');
    result += " | ";
    result += interpreter.toString();

    return result;
    }

string Song::toMp3() const {
    return songName + " - " + interpreter.toString() + ".mp3";
    }

void Song::setSongName(const std::string& n) {
    songName = n;
    }

void Song::setAuthor(const Name& a) {
    author = a;
    }

void Song::setInterpreter(const Name& s) {
    interpreter = s;
    }

void Song::setRanking(const int& r) {
    ranking = r;
    }

bool Song::operator == (const Song& s) const {
    return toString() == s.toString();
    }

bool Song::operator < (const Song& s) const {
    return toString() < s.toString();
    }

bool Song::operator != (const Song& s) const {
    return !(*this == s);
    }

bool Song::operator <= (const Song& s) const {
    return *this < s or *this == s;
    }

bool Song::operator > (const Song& s) const {
    return !(*this <= s);
    }

bool Song::operator >= (const Song& s) const {
    return !(*this < s);
    }