#include<C:\Users\antek\Desktop\informatyka\GITHUB_Projekty\library-plus-plus\defs.hpp>
#include<initializer_list>
template<typename Arg, typename Solution = Arg>
class Equation
{
    protected:
    Solution solution;
    virtual Solution operator ()(Arg arg) = 0;
    virtual std::ostream& operator <<(std::ostream& eq) = 0;
    virtual void Print() = 0;
    private:
    Equation() = default;
};

template<typename Arg, typename Params = Arg>
class Linear : Equation<Arg, Params>
{
private:
    Params a, b;

public:
    Solution operator ()(Arg arg) override { return a * arg + b; }

    Linear() = default;
    Linear(const Params& a_, const Params& b_) : a{a_}, b{b_} {}
    Linear(Params&& a_, Params&& b_) : a{std::move(a_)}, b{std::move(b_)} {}

    Linear(const Linear& other) : a{other.a}, b{other.b} {}
    Linear(Linear&& other) : a{std::move(other.a)}, b{std::move(other.b)} {}

    Linear(const std::initializer_list<Params>& list) : a{list[0]}, b{list[1]} {}
    Linear(std::initalizer_list<Params>&& list) : a{std::move(list[0])}, b{std::move(list[1])} {}

    Linear& operator =(const Params& a_, const Params& b_) { a = a_; b = b_; return *this; }
    Linear& operator =(Params&& a_, Params&& b_) { a = std::move(a_); b = std::move(b_); return *this; }
    Linear& operator =(const Linear& other) { a = other.a; b = other.b; return *this; }
    Linear& operator =(Linear&& other) { a = std::move(other.a); b = std::move(other.b); return *this; }
    Linear& operator =(const std::initalizer_list<Params>& list) { a = list[0]; b = list[1]; return *this; }
    Linear& operator =(std::initalizer_list<Params>&& list) { a = std::move(list[0]); b = std::move(list[1]); return *this; }
    ~Linear() = default;
    std::ostream& operator <<(std::ostream& eq) override
    {
        if(a == 1) eq << "f(x) = x" << (b == 0 ? "" : " + ") << (b == 0 ? "" : b);
        else if(a == -1) eq << "f(x) = -x" << (b == 0 ? "" : " + ") << (b == 0 ? "" : b);
        else if(a == 0) eq << "f(x) = " << (b == 0 ? 0 : b);
        else eq << "f(x) = " << a << "x" << (b == 0 ? "" : " + ") << (b == 0 ? "" : b);
        return eq;
    }
    void Print(const std::string& name)
    {
        if(a == 1) std::cout << name << "(x) = x" << (b == 0 ? "" : " + ") << (b == 0 ? "" : b);
        else if(a == -1) std::cout << name << "(x) = -x" << (b == 0 ? "" : " + ") << (b == 0 ? "" : b);
        else if(a == 0) std::cout << name << "(x) = " << (b == 0 ? 0 : b);
        else std::cout << name << "(x) = " << a << "x" << (b == 0 ? "" : " + ") << (b == 0 ? "" : b);
    }
};

// Example:
// Linear f = Linear(1, 1);
// std::cout << "When x = 0 and " << f.Print("f") << " then f(x) = " f(0) << "\n"; // Prints "When x = 0 and f(x) = 1x + 1 ten f(x) = 1"