#include "Automata.h"
#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <thread>
#include <chrono>
void Automata::on()
{
	if (this->state == OFF)
	{
		this->state = WAIT;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}
void Automata::off()
{
	this->state = OFF;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void Automata::coin()
{
	if (this->state != OFF)
	{
		int money = 0;
		std::cout << "������� �����: ";
		std::cin >> money;
		this->coin(money);
	}
}
void Automata::coin(int money)
{
	if (this->state != OFF)
	if (money < 0)
		this->cash += -money;
	else
		this->cash += money;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void Automata::etMenu(std::map<int, std::string> menu, std::map <int, int> prices)
{
	this->menu.clear();
	this->prices.clear();
	for (int i = 0; i < menu.size(); i++)
	{
		this->menu[i] = menu[i];
	}
	for (int i = 0; i < prices.size(); i++)
		this->prices[i] = prices[i];
	if (this->prices.size() < this->menu.size())
		for (int i = 0; i < this->menu.size() - this->prices.size(); i++)
		{
			this->prices[this->prices.size()] = 50;
		}
}
void Automata::etMenu(std::string pathmenu, std::string pathprices)
{
	std::ifstream fin;
	fin.open(pathmenu);
	this->menu.clear();
	this->prices.clear();
	if (!fin.is_open())
	{
		std::cout << "������ �������� �����\n";
	}
	else
	{
		std::string bufferstring = "";
		while (!fin.eof())
		{
			bufferstring = "";
			std::getline(fin, bufferstring);
			if (!(bufferstring._Equal("") || bufferstring._Equal("\n")))
			{
				this->menu[this->menu.size()] = bufferstring;
			}
		}
	}
	fin.close();
	fin.open(pathprices);
	if (!fin.is_open())
	{
		std::cout << "������ �������� �����\n";
	}
	else
	{
		std::string bufferstring = "";
		while (!fin.eof())
		{
			bufferstring = "";
			std::getline(fin, bufferstring);
			if (!(bufferstring._Equal("") || bufferstring._Equal("\n")))
			{
				this->prices[this->prices.size()] = std::stoi(bufferstring);
			}
		}
	}
	if (this->prices.size() < this->menu.size())
		for (int i = 0; i < this->menu.size() - this->prices.size(); i++)
		{
			this->prices[this->prices.size()] = 50;
		}
}
States Automata::getState()
{
	return this->state;
}
int Automata::getCash()
{
	return this->cash;
}
void Automata::choiceuser()
{
	int choice = 0;
	std::cin >> choice;
	this->choiceuser(choice);
}
void Automata::choiceuser(int choice)
{
	if (this->state != OFF)
	{
		if (choice<0 || choice>this->menu.size())
		{
			this->state = WAIT;
		}
		this->choice = choice;
		this->state = CHOSEN;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}
void Automata::check()
{
	if (this->state == CHOSEN)
	{
		if (this->cash < this->prices[this->choice])
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			this->state = WAIT;
		}
		else
		{
			this->cash -= this->prices[this->choice];
			this->state = MAKING;
		}
	}
	else
	{
		this->state = WAIT;
	}
}
void Automata::cancel()
{
	if (this->state != OFF)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		this->state = WAIT;
	}
}
void Automata::cook()
{ 
	if (this->state == MAKING)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(4000));
		this->state = READY;
	}
}
void Automata::finish()
{
	this->state = WAIT;
}