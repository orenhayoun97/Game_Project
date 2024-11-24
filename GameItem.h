#pragma once
#include <iostream>
using std::ostream;

class GameItem
{
	char* name = nullptr;

public:
	GameItem(const char* _name);
	GameItem(const GameItem& other);
	GameItem& operator=(const GameItem& rhs);
	virtual ~GameItem();

	virtual void toOs(ostream& out) const = 0;
	char* getName() const;
	
	friend ostream& operator<<(ostream& out, const GameItem& gi)
	{
		out << "Item Name: " << gi.name << std::endl;
		gi.toOs(out);
		return out;
	}
};

