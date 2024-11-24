#ifndef __GAME_CLASS_HEADER__
#define __GAME_CLASS_HEADER__

#include <iostream>
using std::ostream;
#include "Sim.h"

class Game {
private:
    Sim** sims = nullptr; // Dynamic array of pointers to Sim objects
    int numSims = 0; // Current number of Sim objects
    int maxSims = 0; // Maximum number of Sim objects allowed

    void printStatus() const;
public:
    Game(int maxSims);

    /// <summary>
    /// appends a new sim to the game.
    /// Simply "moves" the pointer value into the game.
    /// A new sim is not created, the  method only keeps the pointed
    /// object internally.
    /// </summary>
    /// <param name="sim">Pointer to a sim object to save internally(no new sim is constructed)</param>
    /// <returns>True - if the sim is added. False o.w</returns>
    bool addSim(Sim* sim);
    
    /// <summary>
    /// appends a new sim to the game.
    /// creates a new sim object with name "simName".
    /// A new sim is created and appended.
    /// </summary>
    /// <param name="simName">const pointer to a string(a new sim is constructed using this name)</param>
    /// <returns>True - if the sim is added. False o.w.
    ///     if False is returned, no new sim object is created.
    /// </returns>
    bool addSim(const char* simName);
    
    Sim* findSim(const char* name) const;
    bool performAction(const char* name, int action) const;
    void passTime() const;
    bool canAddSims() const;
    friend ostream& operator<<(ostream& out, const Game& g) { g.printStatus(); return out; }

    Game(const Game& other) = delete;
    Game& operator=(const Game& other) = delete;
    static void cleanBuffer();
    ~Game();
};

#endif // !__GAME_CLASS_HEADER__
