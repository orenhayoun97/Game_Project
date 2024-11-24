#include "Game.h"
#include "Skill.h"
#include <iostream>


Game::Game(int maxSims) : maxSims(maxSims), sims(new Sim* [maxSims])//numSims gets 0 default initialized by the class itself
{}

bool Game::addSim(Sim* sim)
{
	if (!canAddSims() || findSim(sim->getName()))
	{
		return false;
	}
	else
	{
		sims[numSims] = sim;
		numSims++;
		return true;
	}
}

bool Game::addSim(const char* simName)
{
	Sim* toAdd = new Sim(simName);
	if (!addSim(toAdd))
	{
		delete toAdd;
		toAdd = nullptr;
		return false;
	}

	return true;
}

void Game::printStatus() const
{
	for (int i = 0; i < numSims; i++)
	{
		std::cout << *sims[i];
	}
	std::cout << std::endl;
}

Game::~Game() {
	for (int i = 0; i < numSims; i++) {
		delete sims[i];
		sims[i] = nullptr;
	}
	delete[] sims;
	sims = nullptr;
	numSims = 0;
	maxSims = 0;
}

void Game::passTime() const
{
	//for all sims, randomize decrement values and add to properties
	for (int i = 0; i < numSims; i++)
	{
		//we should replace this with object use from <random>,
		//	plus, % operation breaks uniformity of uniform distributions (in random variables)
		int decEnergy = -(std::rand() % 15 + 1);
		int decHunger = -(std::rand() % 15 + 1);
		sims[i]->setEnergy(sims[i]->getEnergy() + decEnergy);
		sims[i]->setHunger(sims[i]->getHunger() + decHunger);
		sims[i]->forget();
	}
}

Sim* Game::findSim(const char* name) const
{
	for (int i = 0; i < numSims; i++)
	{
		if (strcmp(name, sims[i]->getName()) == 0)
			return sims[i];
	}

	return nullptr;
}

bool Game::performAction(const char* name, int action) const
{
	int actionIndex = -1;
	int actionChoice = -1;
	char TempBuffer[100] = { 0 };
	int TempPrice = 0;
	Sim* found = findSim(name);
	if (!found) return false;

	switch (action)//this switch should use enum class but some students did not learn this feature
	{
		//action EAT
	case 0:
		found->eat();
		std::cout << "\"" << found->getName() << "\" ate\n";
		break;
		//action SLEEP
	case 1:
		found->sleep();
		std::cout << "\"" << found->getName() << "\" slept\n";
		break;
		//action AGE_UP
	case 2:
		found->ageUp();
		std::cout << "aged Sim \"" << found->getName() << "\" by 1 year\n";
		break;
		//action PRACTICE
	case 3:
		std::cout << "Enter Skill to practice:\n";
		actionIndex = 0;
		while (Skill::intType2string(actionIndex) != nullptr)
		{
			std::cout << Skill::intType2string(actionIndex) << " -> " << actionIndex << std::endl;
			++actionIndex;
		}
		std::cin >> actionChoice;
		found->practice(actionChoice);
		break;
		// action receive award
	case 4:
		std::cout << "Enter Award Title:" << std::endl;
		cleanBuffer();
		std::cin.getline(TempBuffer, 100);
		found->receiveAward(TempBuffer);
		break;
		// buy Item
	case 5:
		std::cout << "Enter item name:" << std::endl;
		cleanBuffer();
		std::cin.getline(TempBuffer, 100);
		std::cout << "Enter Price of the item:" << std::endl;
		std::cin >> TempPrice;
		found->buyItem(TempBuffer,TempPrice);
		break;
	default:
		return false;
	}

	return true;
}

bool Game::canAddSims() const
{
	return numSims < maxSims;
}
void Game::cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}