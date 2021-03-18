#include<string>
#include<type_traits>
#include<exception>
#include<iostream>
#include<initializer_list>
#include<C:\Users\antek\Desktop\informatyka\GITHUB_Projekty\library-plus-plus\defs.hpp>
MAIN_NS_BEGIN
    namespace Types
    {
        namespace Exceptions
        {
            class IsNotAlphaException : std::exception
            {
                const char* msg;
            public:
                IsNotAlphaException(const char* msg_) : msg{msg_} {}
                const char* what() const noexcept override { return msg; }
            };
        }
        class Char
        {
            char ch;
            char DereferenceInitList(const std::initializer_list<char>& list) { return const_cast<char*>(list.begin())[0]; }
            char DereferenceInitList(std::initializer_list<char>&& list) { return const_cast<char*>(std::move(list.begin()))[0]; }
        public:
            Char() = default;
            Char(const char& c) : ch{c} {}
            Char(char&& c) : ch{std::move(c)} {}

            Char(const Char& other) : ch{other.ch} {}
            Char(Char&& other) : ch{std::move(other.ch)} {}

            Char(const std::initializer_list<char>& list) : ch{DereferenceInitList(list)} {}
            Char(std::initializer_list<char>&& list) : ch{DereferenceInitList(std::move(list))} {}
            ~Char() = default;

            Char& operator =(const char& c) { this->ch = c; return *this; }
            Char& operator =(char&& c) { this->ch = std::move(c); return *this; }
            Char& operator =(const Char& other) { this->ch = other.ch; return *this; }
            Char& operator =(Char&& other) { this->ch = std::move(other.ch); return *this; }
            Char& operator =(const std::initializer_list<char>& list) { ch = DereferenceInitList(list); return *this; }
            Char& operator =(std::initializer_list<char>&& list) { ch = DereferenceInitList(std::move(list)); return *this; }

            char GetChar() const { return ch; }
            Char SetChar(char c) { this->ch = c; return *this; }

            char* ToCString() { return const_cast<char*>(this->GetChar() + "\0"); }
            std::string ToString() { return std::string(this->ToCString()); }

            bool IsNumeric() const { return (this->GetChar() >= 48 && this->GetChar() <= 57); }
            bool IsAlpha() const { return ((this->GetChar() >= 65 && this->GetChar() <= 90) || (this->GetChar() >= 97 && this->GetChar() <= 122)); }
            bool IsAlphaNumeric() const { return (this->IsAlpha() || this->IsNumeric()); }
            bool IsCapital() const
            {
                try
                {
                    if(!this->IsAlpha()) throw Exceptions::IsNotAlphaException("Object cannot be capital due to it is not alphabetic character!\n");
                    else return (this->GetChar() >= 65 && this->GetChar() <= 90);
                }
                catch(const Exceptions::IsNotAlphaException& e) { std::cerr << e.what(); return false; }
            }
            bool IsLowercase() const
            {
                try
                {
                    if(!this->IsAlpha()) throw Exceptions::IsNotAlphaException("Object cannot be lowercase due to it is not alphabetic caracter!\n");
                    else return (this->GetChar() >= 97 && this->GetChar() <= 122);
                }
                catch(const Exceptions::IsNotAlphaException& e) { std::cerr << e.what(); return false; }
            }
        };
        Char char_cast(char arg) { return Char(arg); }
        char char_cast(Char arg) { return arg.GetChar(); }
    }
MAIN_NS_END