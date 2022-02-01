#pragma once
#ifndef Header_h
#define Header_h
#include<iostream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для функции time()
#include<string>
using std::cout;
using std::endl;

//class Person
class Person
{
public:
	Person() {};
	Person(const char* nname, const char* ffamily)
		:Name(nname), Family(ffamily) {};
	virtual ~Person() {};
	virtual void Set();
//protected:
	virtual void Show();
private:
	std::string Name;
	std::string Family;
};

void Person::Show()
{
	cout << "Family: " << Family << endl;
	cout << "Name: " << Name << endl;
}
void Person::Set()
{
	cout << "Enter Name: ";
	std::cin >> Name;
	cout << "Enter Family: ";
	std::cin >> Family;
}

//class Gunslinger
class Gunslinger : virtual public Person
{
public:
	Gunslinger() {};
	Gunslinger(const char* nname, const char* ffamily, int notches)
	: Person(nname, ffamily), NumberNotchesRifle(notches), StartToGun(rand() % 100) {};
	~Gunslinger() {};
	double& Draw() { return StartToGun; }
	void Show();
	void Set();
private:
	double StartToGun;
	int NumberNotchesRifle;
};

 void Gunslinger::Show()
{
	Person::Show();
	cout << "Transition time to combat readiness: " << StartToGun << endl;
	cout << "Number of notches on a rifle: " << NumberNotchesRifle << endl;
}
 void Gunslinger::Set()
 {
	 Person::Set();
	 cout << "Enter transition time to combat readiness: ";
	 std::cin >> StartToGun;
	 cout << "Enter number of notches on a rifle: ";
	 std::cin >> NumberNotchesRifle;
 }

 //class Card
 class Card
 {
public:
	Card(int a, int b) { SetSuitRank(a, b); };
	Card(int a) { SetSuitRank(a % 13, a % 4); };
	Card() { rank = "Joker,"; suit = " Joker"; }
	~Card() {};
	std::string& GetSuit() { return suit; }
	std::string& GetRank() { return rank; }
	void SetSuitRank(int a, int b);
	void Show() { cout << "Playing card: " << rank << suit << endl; }
 private:
	std::string suit;
	//enum class Suits {Diamonds, Hearts, Clubs, Spades};
	std::string rank;
	//enum class Ranks { Ace, King, Queen, Jack, ten, nine, eight, seven, six, five, four, three, deuce};
};
 void Card::SetSuitRank(int a, int b)
 {
	 std::string Ranks[13] = { "Ace of ", "King of ", "Queen of ", "Jack of ", "ten of ", "nine of ",
		  "eight of ", "seven of ", "six of ", "five of ", "four of ", "three of ", "deuce of " };
	 std::string Suits[4] = { "Diamonds", "Hearts", "Clubs", "Spades" };
	 rank = Ranks[a];
	 suit = Suits[b];
 }

//class PokerPlayer
class PokerPlayer : virtual public Person
{
public:

	PokerPlayer(const char* nname, const char* ffamily) 
		: Person(nname, ffamily)  {}; 
	PokerPlayer() {};
	~PokerPlayer() {};
	Card Draw() { Card tmp(rand() % 53); return tmp; } 
	void Show();
	void Set();
	Card& GetTrump() { return Trump; }
private:
	Card Trump;
};
void PokerPlayer::Set()
{
	Person::Set();
	Trump = Draw();
}
void PokerPlayer::Show() 
{ 
	Person::Show(); 
	Trump.Show();
}

class BadDude : public Gunslinger, public PokerPlayer
{
public:
	BadDude() {};
	BadDude(const char* nname, const char* ffamily):Person(nname, ffamily) {};
	~BadDude() {};
	void Show();
	double Gdraw();
	Card Cdraw();
	void Set();
private:
};

void BadDude::Set()
{
	Person::Set();
	cout << "Enter transition time to combat readiness: ";
	std::cin >> Gunslinger::Draw();
	PokerPlayer::GetTrump() = Cdraw();
}
void BadDude::Show()
{
	Person::Show();
	cout << "Transition time to combat readiness: " << Gdraw() << endl;
	PokerPlayer::GetTrump().Show();
}
double BadDude::Gdraw()
{
	return Gunslinger::Draw();
}
Card BadDude::Cdraw()
{
	return PokerPlayer::Draw();
}

#endif