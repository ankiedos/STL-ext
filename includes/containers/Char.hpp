#pragma once
#include<string>
#include<type_traits>
#include<exception>
#include<iostream>
#include<initializer_list>
#include<array>
#include<functional>
#include<defs.hpp>
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
        class Char;
        template<typename Dest, typename Src>
        Dest char_cast(Src arg);
        class Char
        {
            char ch;
        public:
            static std::array<char, 128> ASCII;
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
            char& GetCharRef() const { return const_cast<char&>(ch); }
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
                    if(!this->IsAlpha()) throw Exceptions::IsNotAlphaException("Object cannot be lowercase due to it is not alphabetic character!\n");
                    else return (this->GetChar() >= 97 && this->GetChar() <= 122);
                }
                catch(const Exceptions::IsNotAlphaException& e) { std::cerr << e.what(); return false; }
            }
            // LIBXX_TEMPLATE_SFINAE_INTEGRAL(T)
            // friend String operator *(const T& lhs, const Char& rhs)
            // {
            //     static_assert(0 < 2, "stdext::Types::String is not implemented!");
            //     return String(rhs, lhs);
            // }
            // LIBXX_TEMPLATE_SFINAE_INTEGRAL(T)
            // friend String operator *(const Char& lhs, const T& rhs)
            // {
            //     static_assert(0 < 2, "stdext::Types::String is not implemented!");
            //     return String(lhs, rhs);
            // }
            friend Char operator *(const Char& lhs, const Char& rhs)
            {
                return Char(char_cast<char>(char_cast<int>(lhs) * char_cast<int>(rhs) % 128));
                // return Char(static_cast<char>(lhs.GetChar() * rhs.GetChar() % 128));
            }
            friend std::ostream& operator <<(std::ostream& os, const Char& ch)
            {
                os << ch.GetChar();
                return os;
            }
            friend std::istream& operator >>(std::istream& is, Char& ch)
            {
                is >> ch.GetCharRef();
                return is;
            }
            bool operator !()
            {
                return !ch;
            }
            friend Char operator ""__Char(const char ch) { return Char(ch); }
        };

        template<typename Dest, typename Src>
        Dest char_cast(Src arg)
        {
            if constexpr(!std::is_same_v<Dest, Src>)
            {
                if constexpr(std::is_fundamental_v<Dest>)
                {
                    if constexpr(std::is_same_v<Src, Char&>) return static_cast<Dest>(arg.GetChar());
                    else if constexpr(std::is_same_v<Src, char&>) return static_cast<Dest>(arg);
                    else if constexpr(std::is_same_v<Dest, char>)
                    {
                        if constexpr(std::is_same_v<Src, Char&>) return arg.GetChar();
                        else if constexpr(std::is_fundamental_v<Src>) return static_cast<char>(arg);
                    }
                }
                else if constexpr(std::is_same_v<Src, char&> && std::is_same_v<Dest, Char>) return Char(char_cast<char>(arg));
            }
            else return arg;
        }
       
        std::array<char, 128> Char::ASCII = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
        26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58,
        59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91,
        92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
        120, 121, 122, 123, 124, 125, 126, 127};
    }
MAIN_NS_END