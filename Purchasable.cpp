#include "Purchasable.h"

simolians Purchasable::getPrice() const
{
	return price;
}
bool Purchasable::setPrice(int _price)
{
	if (_price < 0)
	{
		price = 0;
		return false;
	}
	else
	{
		price = _price;
		return true;
	}
}
Purchasable::Purchasable(const char* _name, simolians _price) : GameItem(_name)
{
	this->price = _price;
}
void Purchasable::toOs(ostream& out) const
{
	out <<"Item price: " << price << std::endl;
}