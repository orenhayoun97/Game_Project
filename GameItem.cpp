#include "GameItem.h"

void GameItem::toOs(ostream& out) const
{
}
/// <summary>
/// c'tor of GameItem
/// </summary>
/// <param name="_name"></param>
GameItem::GameItem(const char* _name)
{
	this->name = _strdup(_name);
}
/// <summary>
/// copy c'tor of GameItem
/// </summary>
/// <param name="other"></param>
GameItem::GameItem(const GameItem& other)
{
	this->name = _strdup(other.name);
}

GameItem& GameItem::operator=(const GameItem& rhs)
{
	if (this != &rhs)
	{
		delete[] this->name;
		this->name = _strdup(rhs.name);
	}

	return *this;
}

GameItem::~GameItem()
{
	delete[] this->name;
	this->name = nullptr;
}
char* GameItem::getName() const
{
	return name;
}