#ifndef __SIM_CLASS_HW2_
#define __SIM_CLASS_HW2_
#include "Skill.h"
//#include "ResizableSkillArray.h"
#include "ResizableArray.h"
#include "Purchasable.h"
#include "Award.h"


#include <iostream>


class Sim {
private:
    char* name;
    int age = 0;
    int hunger = 50;
    int energy = 50;
   // ResizableSkillArray skills;
    ResizableArray<Skill> skills;
    void printSim() const;
    GameItem* item = nullptr;

public:
    // Constructors
    Sim();
    Sim(const char* name);
    Sim(const Sim& other);
    Sim& operator=(const Sim& rhs);

    // Destructor
    ~Sim();

    // Getters
    const char* getName() const;

    int getAge() const;
    int getHunger() const;
    int getEnergy() const;

    // Setters

    void setAge(int age);
    void setHunger(int hunger);
    void setEnergy(int energy);

    // Other Methods
    void sleep();
    void eat();
    void ageUp();
    void practice(int skillType);
    void forget() const;
    bool buyItem(const char* itemName, int price);
    bool receiveAward(const char* title);
    friend ostream& operator<<(ostream& out, const Sim& s) { s.printSim(); return out; }
};

#endif // !__SIM_CLASS_HW2_