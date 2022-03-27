#pragma once
#include "States.h"
#include <iostream>
#include <stdio.h>
#include <map>

class Automata
{
public:
	States state;
	int cash;
	std::map <int, std::string> menu;
	std::map <int, int> prices;
	int choice;
	Automata()
	{
		this->state = OFF;
		this->cash = 0;
		this->choice = -1;
		menu[0] = "�����";
		menu[1] = "��������";
		menu[2] = "��������";
		prices[0] = 50;
		prices[1] = 60;
		prices[2] = 70;
	};
	void on();
	void off();
	void coin();
	void coin(int);
	void etMenu(std::map <int, std::string>, std::map <int, int>);
	void etMenu(std::string, std::string);
	States getState();
	int getCash();
	void choiceuser();
	void choiceuser(int);
	void check();
	void cancel();
	void cook();
	void finish();
};
