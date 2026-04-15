#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include "Skill.h"
#include "Sim.h"
using namespace std;

Sim::Sim() : Sim("Jane Doe")
{}

Sim::Sim(const char* _name)
{
	this->name = _strdup(_name);
}

Sim::Sim(const Sim& other)
{
	*this = other;
}
// sim1 = sim2
Sim& Sim::operator=(const Sim& rhs)
{
	if (this != &rhs)
	{
		this->age = rhs.age;
		this->hunger = rhs.hunger;
		this->energy = rhs.energy;
		delete[] this->name;
		this->name = nullptr;
		this->skills.empty();
		this->item.empty();
		for (int i = 0; i < rhs.item.getSize(); i++)
		{
			GameItem* original = rhs.item[i];
			Purchasable* p = dynamic_cast<Purchasable*>(original);
			if (p) // buy item
			{
				this->item.pushBack(new Purchasable(p->getName() , p->getPrice()));
			}
			else // Award
			{
				this->item.pushBack(new Award(original->getName()));
			}
		}
		this->name = _strdup(rhs.name);
		for (int i = 0; i < rhs.skills.getSize(); i++)
			this->skills.pushBack(new Skill(*rhs.skills[i]));
	}
	return *this;
}
// Destructor
Sim::~Sim() {
	item.empty(); // new
	delete[] name;
	name = nullptr;
}

// Getters
const char* Sim::getName() const {
	return name;
}

int Sim::getAge() const {
	return age;
}

int Sim::getHunger() const {
	return hunger;
}

int Sim::getEnergy() const {
	return energy;
}

// Setters

void Sim::setAge(int age)
{
	if (age < 0) {
		this->age = 0;
	}
	else
	{
		this->age = age;
	}
}


void Sim::setHunger(int hunger) {
	if (hunger < 0) {
		this->hunger = 0;
	}
	else if (hunger > 100) {
		this->hunger = 100;
	}
	else {
		this->hunger = hunger;
	}
}

void Sim::setEnergy(int energy) {
	if (energy < 0) {
		this->energy = 0;
	}
	else if (energy > 100) {
		this->energy = 100;
	}
	else {
		this->energy = energy;
	}
}

// Methods
void Sim::sleep() {
	energy += 15;
	if (energy > 100) {
		energy = 100;
	}
}

void Sim::eat() {
	hunger += 15;
	if (hunger > 100) {
		hunger = 100;
	}
}

void Sim::ageUp() {
	age++;
}

void Sim::printSim() const
{
	cout << getName() << " - Age: " << getAge();
	cout << ", Hunger: " << getHunger();
	cout << ", Energy: " << getEnergy() << ".\n";
	cout << "SKILLS:\n";
	for (int i = 0; i < 6; i++)
	{
		cout << "-";
	}
	cout << '\n';
	for (int i = 0; i < skills.getSize(); i++)
	{
		cout << *skills[i] << endl;
	}

	cout << "ITEMS:\n";
	for (int i = 0; i < 6; i++)
	{
		cout << "-";
	}
	cout << '\n';
	if (item.getSize() == 0)
	{
		cout << "No items yet...\n";
	}
	else
	{
		for (int i = 0; i < item.getSize(); i++)
		{
			cout << i + 1 << ") " << *item[i] << endl;
		}

	}
}

void Sim::practice(int skillType)
{
	if (Skill::intType2string(skillType) == nullptr)
	{
		cout << "cannot practice this skill...\n";
		return;
	}
	//skill not yet started
	if (skills.findSkill(skillType) == -1)
	{
		skills.pushBack(new Skill(skillType, 3));
	}
	else
	{
		skills[skills.findSkill(skillType)]->practice();
	}
}

void Sim::forget() const
{
	for (int i = 0; i < skills.getSize(); i++)
	{
		skills[i]->forget();
	}
}
bool Sim::buyItem(const char* itemName, int price)
{
	item.pushBack(new Purchasable(itemName, price));
	return true;
}
bool Sim::receiveAward(const char* title)
{
	item.pushBack(new Award(title));
	return true;
}
