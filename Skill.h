#pragma once
#include <iostream>
using std::ostream;

class Skill
{
private:
	int type;//should be an enum class, but some groups do not learn this feature
	int skillLevel = 3;//a number between [0-100]. 0 is lowest skill. 100 is highest skill

	static const char* skillTypeStrings[];
public:

	Skill(int type, int level) : type(type), skillLevel(level) {}

	static const char* intType2string(int type);

	const char* getTypeString() const;
	int getType() const;
	void practice();
	void forget();
	friend ostream& operator<<(ostream& out, const Skill& s);
};

