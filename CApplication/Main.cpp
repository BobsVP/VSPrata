#include <iostream>
#include <string> 

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
    for (int i = 0; i < str.size(); ++i)
        if (str[i] != str[str.size() - i - 1])
            return false;
    return true;
}
