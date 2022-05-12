#include <iostream>
#include<set>
#include<string>
#include<algorithm>

void GetList(const char* Imya, std::set<std::string>& List);
void display(const std::string& s);

int main()
{
    std::set<std::string> MattList, PetList, UnionList;
    GetList("Matt", MattList);
    std::cout << "Matt's friend list:\n";
    std::for_each(MattList.begin(), MattList.end(), display);
    GetList("Patt", PetList);
    std::cout << "Patt's friend list:\n";
    std::for_each(PetList.begin(), PetList.end(), display);
    std::set_union(MattList.begin(), MattList.end(), PetList.begin(), PetList.end(), std::insert_iterator<std::set<std::string>>(UnionList, UnionList.begin()));
    std::cout << "Union list: \n";
    std::for_each(UnionList.begin(), UnionList.end(), display);
    return 0;
}

void GetList(const char* Imya, std::set<std::string>& List)
{
    std::cout << "Enter " << Imya << " list (quit to quit):\n";
    std::string letters;
    while (std::cin >> letters && letters != "quit")
        List.insert(letters);
}
void display(const std::string& s)
{
    std::cout << s << std::endl;
}
