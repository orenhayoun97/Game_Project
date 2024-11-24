#include "Award.h"

Award::Award(const char* awardTitle) : GameItem(awardTitle)
{
}
void Award::toOs(ostream& out) const
{
	out << dateAwarded << std::endl;
}
