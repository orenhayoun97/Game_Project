# SIM-LIFE Simulator
A character simulator based on advanced object oriented programming (OOP) principles in C++.
The Project simulates a character management system, witch allows for tracking personal metrics,
skill development, and managing items and rewards.

## Cure Features
* Full character menagement: Create and manage Sims with real time tracking of age, hunger and energy levels.
* Polymorphic Progression System: Develop skills such as painting, chess and dancing, with proficiency levels.
* Polymorphic Item Handling: Utilizes inhgeritance to manage different game items.
* Custom Generic Container: Features a hand-coded `ResizableArray<T>` template to handle dynamic memory and object pointers efficiently.

## Architecture and Class Structure

### Core Logic
* `Sim` : The central entity managing persona data, a `ResizableArray` of skills, and a pointer of a `GameItem`.
* `Skill`: Represents specific abilities with methods like `practice()` to increase level and `forget()` to decrease it.
* `ResizableArray<T>`: A template class for dynamic arrays that handles automatic resizing and ensures deep copies of objects.

### Inheritance and Polymorphhism
* `GameItme`: The abstract base class for all items.
* `Purchasable`: A derived class representing items with a specific price in "Simolians".
* `Award`: A derived class representing honorary titles or achievements given to a Sim.

## Technical Highlights
* Manual Memory Management: Implements destructor, copy constructor and assignment operator to prevent memory leaks.
* Friend Functions: Overloaded `operator<<` for clean, formatted console output of complex objects.

## Gameplay Options
* Add Sim: Register a new character into the game world.
* Pass Time: Advance the game clock, Which updates physical stats like hunger and energy.
* Perform Action: Order a Sim to eat, sleep, practice a skill, or acquire items.
* Print Status: View a detailed report of all Sims and thier current progress
