#include <iostream>
#include <string> 
#include <cctype> 

bool Bool(std::string& str);

int main() 
{
    std::string Palli;
    std::cout << "Enter your phrase: ";
    std::getline(std::cin, Palli);
    if (Bool(Palli))
        std::cout << "Your phrase is palindrome.\n";
    else
        std::cout << "Your phrase is not palindrome.\n";
    return 0;
}

bool Bool(std::string& str)
{
    std::string tmp("");
    for (auto c : str)
        if (isalpha(c))
            tmp = tmp + (char)tolower(c);
    for (int i = 0; i < tmp.size(); ++i)
        if (tmp[i] != tmp[tmp.size() - i - 1])
            return false;
    return true;
}
