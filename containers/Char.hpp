#include<string>
#include<type_traits>
class Char
{
    char ch;
    public:
    Char(char c) : ch{c} {}
    Char() = default;
    Char(const Char& other) : ch{other.ch} {}
    Char(Char&& other) : Char{std::move(other)} {}
    Char(char&& c) : ch{std::move(c)} {}
    ~Char() = default;
    Char operator =(char c) { this->ch = c; return *this; }
    Char operator =(const Char& other) { this->ch = other.ch; return *this; }
    Char operator =(Char&& other) { this->ch = std::move(other).ch; return *this; }
    Char operator =(char&& c) { this->ch = std::move(c); return *this; }
    char* ToCString() { return (char*)(this->ch); }
    std::string ToString() { return std::string(this->ToCString()); }
};