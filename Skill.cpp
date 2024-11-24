#include "Skill.h"

const char* Skill::skillTypeStrings[] = { "painting", "chess", "dancing", "reading", "cooking"};

/// <summary>
/// All skill object hold a property "type" as int.
///		This method translates the int type to a c-style string via the static array
///		skillTypeStrings[]. in other words, there is a 1-1 matching between field "type" and
///		and a corresponding string
/// </summary>
/// <returns>The appropriate string from the static array</returns>
const char* Skill::getTypeString() const
{
	return Skill::skillTypeStrings[this->type];
}

/// <summary>
/// a public static method, returning the matched string to type "type".
/// </summary>
/// <param name="type">an integer representing a type of skill</param>
/// <returns>the matching string for that skill type, OR nullptr if type is out
///		of array bounds</returns>
const char* Skill::intType2string(int type)
{
	//sizeof is ok here because skillTypeStrings is defined
	//	in the global scope therfor available to sizeof at compile time
	if (type < 0 || type >= sizeof(Skill::skillTypeStrings) / sizeof(const char*))
		return nullptr;
	else return Skill::skillTypeStrings[type];
}

/// <summary>
/// prints the skill object to an ostream (usually cout in our case)
/// </summary>
/// <param name="out">an ostream</param>
/// <param name="s">the skill object to print</param>
/// <returns>a reference to the output ostream</returns>
ostream& operator<<(ostream& out, const Skill& s)
{
	out << "Skill type: " << s.getTypeString() << std::endl;
	out << "Skill level: " << s.skillLevel << "%" << std::endl;
	return out;
}

/// <summary>
/// an action method that increases the skill level randomly by [1-5] points
/// </summary>
void Skill::practice()
{
	this->skillLevel += std::rand() % 6 + 1;
	if (skillLevel > 100)
		skillLevel = 100;
}

/// <summary>
/// an action method that decreases the skill level randomly by [1-5] points
/// </summary>
void Skill::forget()
{
	this->skillLevel -= std::rand() % 6 + 1;
	if (skillLevel < 0)
		skillLevel = 0;
}

/// <summary>
/// simple field public getter
/// </summary>
/// <returns>the calling skill objects' integer type</returns>
int Skill::getType() const
{
	return type;
}