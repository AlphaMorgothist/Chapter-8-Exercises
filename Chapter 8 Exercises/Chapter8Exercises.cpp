// Chapter8Exercises.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

class Critter {
public:
	Critter(string name, int hunger = 0, int boredom = 0);
	void Talk();
	void Eat(int food);
	void Play(int fun);
	int Work(string name, int tools);
	void debug();
private:
	int m_Hunger;
	int m_Boredom;
	int m_Age = 0;
	int GetMood() const;
	void PassTime(int time = 1);
};
class Egg {
public:
	
private:
	const int cost = 100;
	void Hatch();
};

int main()
{
	enum { listen = 1, feed, play, work, market, debug = 10 };
	cout << "\nWelcome to Critter Caretaker! Your first critter is free, here you go!" << endl;
	cout << "\nWhat will you name your first critter?" << endl;
	cout << "\nName :";
	string name;
	getline(cin, name);
	Critter crit(name, 0, 0);
	system("pause");
	int fun = 2;
	int food = 0;
	int money = 10;
	int tools = 0;
	system("CLS");
	
	while (true) {
		cout << "\nMoney: " << money << endl;
		cout << "\nWhat would you like to do?" << endl;
		cout << "\n1: Listen to your critter" << endl;
		cout << "2: Feed your critter" << endl;
		cout << "3: Play with your critter" << endl;
		cout << "4: Send your critter to work" << endl;
		cout << "5: Go to the market" << endl;
		cout << "6: Quit" << endl;

		cout << "Selection :";
		int select;
		cin >> select;
		system("CLS");
		switch (select) {
		case listen: {
			crit.Talk();
			system("pause");
		}break;
		case feed: {
			crit.Eat(food);
		}break;
		case play: {
			crit.Play(fun);
		}break;
		case work: {
			int moneymade = crit.Work(name, tools);
			money += moneymade;
			cout << "\nYour creature says: " << endl;
			if (moneymade > 20) {
				cout << "I made lots today!" << endl;
			}
			else if (moneymade > 10) {
				cout << "I made a decent amount today!" << endl;
			}
			else if (moneymade < 10) {
				cout << "I didn't really make a whole lot..." << endl;
			}

		}break;
		case market: {
			system("CLS");
			cout << "\nWelcome to the Market! Please select an item to buy: " << endl;
			cout << "\n\n1: Food" << endl;
			cout << "2: Toys" << endl;
			cout << "3: Tools" << endl;
			cout << "4: Eggs" << endl;
			enum { groceries = 1, toys, works, eggs };
			cout << "\nSelection: ";
			int choice;
			cin >> choice;
			switch (choice) {
			case groceries: {
				cout << "\nFood market: " << endl;
				cout << "\n1: 10 Food - $10" << endl;
				cout << "\n2: 20 Food - $18" << endl;
				cout << "\n3: 30 Food - $25" << endl;
				cout << "\n\nSelection: ";
				int select;
				cin >> select;
				switch (select) {
				case 1: {
					if (money >= 10) {
						food += 10;
						money -= 10;
					}
					else {
						cout << "\nYou don't have enough money!" << endl;
					}
				}break;
				case 2: {if (money >= 18) {
					food += 20;
					money -= 18;
				}
						else {
							cout << "\nYou don't have enough money!" << endl;
						}

				}break;
				case 3: {
					if (money >= 25) {
						food += 30;
						money -= 25;
					}
					else {
						cout << "\nYou don't have enough money!" << endl;
					}
				}break;
				}
			}break;
			case toys: {
				cout << "\nWelcome to the Toy Store!" << endl;
				cout << "\nWhat would you like to buy?" << endl;
				cout << "\n1: Teddy Bear - $40" << endl;
				cout << "2: Toy Box - $60" << endl;
				cout << "3: Swing Set - $120" << endl;
				cout << "\nSelection: ";
				int toysel;
				cin >> toysel;
				switch (toysel) {
				case 1: {
					if (money >= 40) {
						fun += 4;
						money -= 40;
					}
					else {
						cout << "\nYou don't have enough money!" << endl;
					}
				}break;
				case 2: {
					if (money >= 60) {
						fun += 7;
						money -= 60;
					}
					else {
						cout << "\nYou don't have enough money!" << endl;
					}
				}break;
				case 3: {
					if (money >= 120) {
						fun += 12;
						money -= 120;
					}
					else {
						cout << "\nYou don't have enough money!" << endl;
					}
				}break;
				}
			}break;
			case works: {
				cout << "\nWelcome to the Tool Store" << endl;
				cout << "\nWhat would you like to buy?" << endl;
				cout << "\n1: A Wrench - $20" << endl;
				cout << "2: Tool Box - $100" << endl;
				cout << "3: Workshop of Tools - $250" << endl;
				cout << "\nSelection: ";
				int toolsel;
				cin >> toolsel;
				switch (toolsel) {
				case 1: {
					if (money >= 20) {
						tools += 1;
						money -= 20;
					}
					else {
						cout << "\nYou don't have enough money!" << endl;
					}
				}break;
				case 2: {
					if (money >= 100) {
						tools += 5;
						money -= 100;
					}
					else {
						cout << "\nYou don't have enough money!" << endl;
					}
				}break;
				case 3: {
					if (money >= 250) {
						tools += 12;
						money -= 250;
					}
					else {
						cout << "\nYou don't have enough money!" << endl;
					}
				}break;
				}break;
			}
			}break;
		case debug: {
			crit.debug();
		}break;
		}break;
		case 6: {return 0; }break;
		}
	}
	cin.ignore();
	system("pause");
    return 0;
}

Critter::Critter( string name, int hunger, int boredom):
	m_Hunger(hunger),
	m_Boredom(boredom)
{
	cout << "\nAn egg has hatched!" << endl;
	cout << "\nA new creature, named " << name << ", is born!\n" << endl;
}

void Critter::Talk()
{
	cout << "\nYour creature says: " << endl;
	cout << "I feel ";
	int mood = GetMood();
	if (mood > 15) {
		cout << "angry.";
		if (m_Hunger > 7) {
			cout << "\nMy stomach hurts!" << endl;
		}
		if (m_Boredom > 7) {
			cout << "I am soooo bored." << endl;
		}
	}
	else if (mood > 10) {
		cout << "frustraited ";
		if (m_Hunger > 6) {
			cout << "\nMy stomach hurts!" << endl;
		}
		if (m_Boredom > 6) {
			cout << "I am soooo bored." << endl;
		}
	}
	else if (mood > 5) {
		cout << "alright.. ";
		if (m_Hunger > 3) {
			cout << "\nI'm kind of peckish" << endl;
		}
		if (m_Boredom > 3) {
			cout << "Are there any toys around?" << endl;
		}
	}
	else {
		cout << "happy ";
	}
	if (m_Age <= 1) {
		cout << "\n\nYour critter is a toddler" << endl;
	}
	else if (m_Age > 1) {
		cout << "\n\nYour critter is " << m_Age << " cycles old." << endl;
	}
	PassTime();
}

void Critter::Eat(int food)
{
	if (food > 0) {
		cout << "BLEUGHH.\n";
		m_Hunger -= food;
	}
	if (food <= 0) {
		cout << "\nYou don't have enough food! Go to the market and buy some." << endl;
	}
	if (m_Hunger <= 0) {
		cout << "\nYour creature is full!" << endl;
		m_Hunger = 0;
	}
	PassTime();
}

void Critter::Play(int fun)
{
	if (fun <= 2) {
		cout << "Wee!\nThat was fun! It would be more fun with some toys to play with though." << endl;
	}
	else if (fun >= 4) {
		cout << "Wee!\nThat was fun! Thank you for the toys!" << endl;
	}
	m_Boredom -= fun;
	if (m_Boredom < 0) {
		m_Boredom = 0;
	}
	PassTime();
}

int Critter::Work(string name, int tools)
{
	cout << "Your critter, " << name << ", goes off to work with " << tools << " tools." << endl;
	srand(time(NULL));
	int moneymade = rand() % 20 + (tools * 10);
	cout << "\n" << name << " made " << moneymade << " dollars at work" << endl;
	PassTime();
	return moneymade;
}

void Critter::debug()
{
	cout << "Hunger level: " << m_Hunger << "\nBoredom level: " << m_Boredom << endl;
}

int Critter::GetMood() const
{
	return (m_Hunger + m_Boredom);
}

void Critter::PassTime(int time)
{
	m_Hunger += time;
	m_Boredom += time;
	m_Age += time;
}

void Egg::Hatch()
{
	string name;
	cin >> name;
	Critter crit(name, 0, 0);
}
 