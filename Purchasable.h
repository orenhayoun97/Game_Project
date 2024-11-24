#pragma once
#include "GameItem.h"
#include <iostream>
using std::ostream;

using simolians = unsigned int;//typedef for price. simolians are game shekels.

class Purchasable : public GameItem
{
	simolians price = 100;
public:
	simolians getPrice() const;//no explanation needed
	bool setPrice(int _price);//no explanation needed

	/// <summary>
	/// 2 argument constructor
	/// </summary>
	/// <param name="_name">base class property</param>
	/// <param name="_price">derived class property</param>
	Purchasable(const char* _name, simolians _price);

	//Explicitly defaulting 3 member functions
	Purchasable(const Purchasable& other) = default;
	Purchasable& operator=(const Purchasable& rhs) = default;
	~Purchasable() override = default;

	//derived class override of the toOutputStream virtual method
	void toOs(ostream& out) const override;
};