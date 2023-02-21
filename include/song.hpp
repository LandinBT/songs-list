#ifndef SONG_HPP_INCLUDED
#define SONG_HPP_INCLUDED

#include <string>

#include "name.hpp"

class Song {
 private:
  std::string songName;
  Name author;
  Name interpreter;
  int ranking;

 public:
  Song();
  Song(const Song&);

  Song& operator=(const Song&);

  std::string getSongName() const;
  Name getAuthor() const;
  Name getInterpreter() const;
  int getRanking() const;

  std::string toString() const;
  std::string toMp3() const;

  void setSongName(const std::string&);
  void setAuthor(const Name&);
  void setInterpreter(const Name&);
  void setRanking(const int&);

  bool operator == (const Song&) const;
  bool operator != (const Song&) const;
  bool operator < (const Song&) const;
  bool operator <= (const Song&) const;
  bool operator > (const Song&) const;
  bool operator >= (const Song&) const;

  friend std::ostream& operator << (std::ostream&, const Song&);
  friend std::istream& operator >> (std::istream&, Song&);
};

#endif  // SONG_HPP_INCLUDED