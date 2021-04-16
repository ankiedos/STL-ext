#pragma once
#include<vector>
#include<type_traits>
#include<defs.hpp>
#include<Char.hpp>

MAIN_NS_BEGIN
namespace Types
{
    template<typename T>
    class Object
    {
    public:
        static std::vector<T> instances;
        static bool typeof(const T& obj) const { return std::is_same_v<decltype(obj), decltype(T); }
        template<typename U>
        bool instanceof() { return std::is_same_v<decltype(this), decltype(U)>; }
        template<typename U>
        bool IsSameType(U obj) { return std::is_same_v<decltype(this), decltype(obj)>; }
        Object() : T() { instances += dynamic_cast<T>(this); }
        ~Object() = default; 
        virtual bool Equal(const T& other) = 0;
        virtual friend bool operator ==(const T& lhs, const T& rhs) = 0;
        virtual char* ToCString() = 0;
        virtual std::string ToStdString() = 0;
        virtual Char ToChar() = 0;
        virtual String ToString() = 0;
        virtual StaticString ToStaticString() = 0;
    };
}
MAIN_NS_END