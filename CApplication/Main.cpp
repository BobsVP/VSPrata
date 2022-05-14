#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <fstream>

struct Review {
    std::string title;
    int rating;
    double price;
};

bool operator<(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool worseThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool worseThan2(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool FillReview(std::shared_ptr<Review> rr);
void ShowReview(const std::shared_ptr<Review> rr);
int main()
{
    using namespace std;
    vector<std::shared_ptr<Review>> books;
    std::shared_ptr<Review> temp(new Review);
    while (FillReview(temp))
    {
        books.push_back(temp);
        auto p = new Review;
        temp = std::shared_ptr<Review>(p);
    }
    if (books.size() > 0)
    {
        cout << "Thank you. You entered the following "
            << books.size() << " ratings:\n"
            << "Rating\tPrice\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);
        if (cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        char ch;
        std::cout << "Enter q - quit, w - original array, e - sort by title, r - reverse sort by title,\n";
        std::cout << "t - sort by rating, y - reverse sort by rating, u - sort by price, i - reverse sort by price\n";
        while (cin.get(ch) && std::tolower(ch) != 'q')
        {
            while (cin.get() != '\n')
                continue;
            if (!std::isalpha(ch))
            {
                cout << "Enter q, w, e, r, t, y, u or i\n";
                continue;
            }
            switch (ch)
            {
            case 'W':
            case 'w':
                for_each(books.begin(), books.end(), ShowReview);
                break;
            case 'E':
            case 'e':
                sort(books.begin(), books.end());
                cout << "Sorted by title:\nRating\tPrice\tBook\n";
                for_each(books.begin(), books.end(), ShowReview);
                break;
            case 'R':
            case 'r':
                sort(books.begin(), books.end());
                cout << "Sorted by title in reverse order:\nRating\tPrice\tBook\n";
                for_each(books.rbegin(), books.rend(), ShowReview);
                break;
            case 'T':
            case 't':
                sort(books.begin(), books.end(), worseThan);
                cout << "Sorted by rating:\nRating\tPrice\tBook\n";
                for_each(books.begin(), books.end(), ShowReview);
                break;
            case 'Y':
            case 'y':
                sort(books.begin(), books.end(), worseThan);
                cout << "Sorted by rating in reverse order:\nRating\tPrice\tBook\n";
                for_each(books.rbegin(), books.rend(), ShowReview);
                break;
            case 'U':
            case 'u':
                sort(books.begin(), books.end(), worseThan2);
                cout << "Sorted by price:\nRating\tPrice\tBook\n";
                for_each(books.begin(), books.end(), ShowReview);
                break;
            case 'I':
            case 'i':
                sort(books.begin(), books.end(), worseThan2);
                cout << "Sorted by price in reverse order:\nRating\tPrice\tBook\n";
                for_each(books.rbegin(), books.rend(), ShowReview);
                break;
            }
            std::cout << "Enter q - quit, w - original array, e - sort by title, r - reverse sort by title,\n";
            std::cout << "t - sort by rating, y - reverse sort by rating, u - sort by price, i - reverse sort by price\n";
        }
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n";
    return 0;
}

bool operator<(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2)
{
    if (r1->title < r2->title)
        return true;
    else if (r1->title == r2->title && r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool worseThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2)
{
    if (r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool worseThan2(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2)
{
    if (r1->price < r2->price)
        return true;
    else
        return false;
}

bool FillReview(std::shared_ptr<Review> rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin, rr->title);
    if (rr->title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr->rating;
    if (!std::cin)
        return false;
    std::cout << "Enter book price: ";
    std::cin >> rr->price;
    if (!std::cin)
        return false;
    while (std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const std::shared_ptr<Review> rr)
{
    std::cout << rr->rating << "\t" << rr->price << "\t" << rr->title << std::endl;
}
