#pragma once
#include "GameItem.h"
#include "Date.h"
class Award :
    public GameItem
{
private:
    Date dateAwarded;
public:
    Award(const char* awardTitle);

    Award(const Award& other) = default;
    Award& operator=(const Award& rhs) = default;
    ~Award() override = default;

    void toOs(ostream& out) const override;
};

