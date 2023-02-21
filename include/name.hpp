#ifndef NAME_HPP_INCLUDED
#define NAME_HPP_INCLUDED

#include <string>

class Name {
    private:
    std::string first;
    std::string last;

    public:
    Name();
    Name(const Name&);

    Name& operator = (const Name&);

    std::string getFirst() const;
    std::string getLast() const;

    std::string toString() const;

    void setFirst(const std::string&);
    void setLast(const std::string&);

    bool operator == (const Name&) const;
    bool operator != (const Name&) const;
    bool operator < (const Name&) const;
    bool operator <= (const Name&) const;
    bool operator > (const Name&) const;
    bool operator >= (const Name&) const;

    friend std::ostream& operator << (std::ostream&, const Name&);
    friend std::istream& operator >> (std::istream&, Name&);
};

#endif // NAME_HPP_INCLUDED