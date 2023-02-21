#include "name.hpp"

using namespace std;

Name::Name() {}

Name::Name(const Name& n) : last(n.last), first(n.first) {}

Name& Name::operator = (const Name& n) {
  last = n.last;
  first = n.first;

  return *this;
}

string Name::getFirst() const { return first; }

string Name::getLast() const { return last; }

string Name::toString() const { return first + ", " + last; }

void Name::setFirst(const std::string& f) { first = f; }

void Name::setLast(const std::string& l) { last = l; }

bool Name::operator == (const Name& n) const { return last == n.last; }

bool Name::operator < (const Name& n) const { return last < n.last; }

bool Name::operator != (const Name& n) const { return !(*this == n); }

bool Name::operator <= (const Name& n) const { return *this < n or *this == n; }

bool Name::operator > (const Name& n) const { return !(*this <= n); }

bool Name::operator >= (const Name& n) const { return !(*this < n); }