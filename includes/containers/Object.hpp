#pragma once
#include<vector>
#include<type_traits>
#include<defs.hpp>
#include<Char.hpp>

MAIN_NS_BEGIN
namespace Types
{
    namespace Helpers { struct Reflect {}; }
    template<typename T>
    class Object
    {
    public:
        static std::vector<T> instances;
        static bool typeof(const T& obj) const { return std::is_same_v<decltype(obj), decltype(T); }
        template<typename U>
        bool instanceof() const { return std::is_same_v<decltype(this), decltype(U)>; }
        template<typename U>
        bool IsSameType(U obj) const { return std::is_same_v<decltype(this), decltype(obj)>; }
        Object() : T() { T::instances += dynamic_cast<T>(this); }
        ~Object() = default; 
        ~Object(typename Helpers::Reflect) { T::instances -= dynamic_cast<T>(this); ~Object(); }
        virtual bool Equal(const T& other) const = 0;
        virtual friend bool operator ==(const T& lhs, const T& rhs) const = 0;
        virtual char* ToCString() = 0;
        virtual std::string ToStdString() = 0;
        virtual Char ToChar() = 0;
        virtual String ToString() = 0;
        virtual StaticString ToStaticString() = 0;
    };
}
MAIN_NS_END