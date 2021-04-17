#include<../../includes/containers/Char.hpp>
#include<vector>
#include<string>
#if defined(_WIN32) || defined(_WIN64)
#define CLEAR system("cls")
#define EXIT system("exit")
#else
#define CLEAR system("clear")
#define EXIT system("logout")
#endif

bool IsAlphaNumeric(const char& ch) { return stdext::Types::Char::Char(ch).IsAlphaNumeric(); }
bool IsAtLeastOneNonAlphaNumeric(const std::string& str)
{
    for(auto& i : str)
    {
        if(!IsAlphaNumeric(i)) return true;
    }
    return false;
}
int main()
{
    // stdext::Types::Char answer = '\0';
    std::string answer{};
    bool alphanum = false;
    std::cout << "Please give an answer\n> ";
    // while(!answer)
    // {
        std::cin >> answer;
    // }
    for(auto& i : answer)
    {
        if(!IsAlphaNumeric(i)) alphanum = false;
        else alphanum = true;
    }
    if(alphanum) std::cout << "Thank you for your answer!\n";
    else
    {
        std::cout << "Why are you speaking so rude to me?!?!\n";
        while(true)
        {
            std::cout << "What I do what made you so angry?\n> ";
            std::cin >> answer;
            do
            {
                std::cout << "Could you repeat, please?\n> ";
                std::cin >> answer;
                if(answer == "cls" || answer == "clear")
                {
                    CLEAR;
                    std::cout << "You wanted to clear this session???\nOh, YOU ARE A LOSER!!!!!!\n";
                    while(true) std::cout << "LOSER ";
                }
                else if(answer == "^C")
                {
                    std::cout << "You wanted me to shut down????!!!!\n";
                    std::cout << "In response, I will shut down your device!!!\nHua, hua, hua, hua!!!!\n";
                    EXIT;
                }
            } while(IsAtLeastOneNonAlphaNumeric(answer));
        }
    }
    return 0;
}