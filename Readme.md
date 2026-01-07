🏰 Dungeon Exploration Game (C++)

A C++ text-based dungeon exploration game featuring graph-based room navigation, turn-based combat, skill progression, and a final boss battle.

📌 Overview

This game simulates a player navigating through a dungeon represented as a graph structure.
The player explores rooms, fights enemies, collects treasures, survives traps, and ultimately defeats the final boss to win.

✨ Features
🎮 Core Gameplay

Dungeon represented using graph (adjacency list)

Multiple room types:

Empty

Enemy

Treasure

Trap

Boss

BFS & DFS used for navigation and reachability

🧑 Player System

Health and damage management

Turn-based combat

Inventory system

Experience and leveling

🌳 Skill Tree

Progressive skill unlocking

Prerequisite-based skills

Attack bonus enhancements

⚙️ Game Mechanics

Room exploration using graph traversal

Reachability checking using BFS

Clear win/lose conditions

🏗️ Code Structure
Main Classes

Room – Represents a dungeon room

Enemy – Enemy attributes (health, attack)

SkillNode – Skill tree node

SkillTree – Manages skill unlocking

Player – Player stats, inventory, experience

DungeonGraph – Graph structure with BFS/DFS

Game – Main game loop and controller

🧠 Algorithms Used

BFS (Breadth-First Search)

Finds all reachable rooms from the current position

DFS (Depth-First Search)

Displays dungeon map structure

Path Validation

Ensures player moves only to valid rooms

🗺️ Dungeon Layout
Room 0 (Entry) → Room 1 (Enemy) → Room 2 (Treasure) → Room 3 (Trap)
                     ↓                               ↓
                 Room 4 (Enemy) ←→ Room 5 (Treasure) → Room 7 (BOSS)
                     ↓
                 Room 6 (Enemy) → Room 7 (BOSS)

🖥️ Compilation
Requirements

C++11 or higher

GCC / Clang / MSVC

Compile Commands

Linux / macOS (GCC)

g++ -std=c++11 -o dungeon_game main.cpp


Windows (MinGW)

g++ -std=c++11 -o dungeon_game.exe main.cpp


Windows (MSVC)

cl /EHsc main.cpp /Fe:dungeon_game.exe

▶️ How to Run

Linux / macOS

./dungeon_game


Windows

dungeon_game.exe

🕹️ Gameplay Instructions
Starting

Game starts in Room 0 (Entry Room)

Menu Options

Move to a room

View skill tree

View dungeon map

Check boss reachability

Quit game

Room Encounters

Enemy Room – Turn-based combat

Treasure Room – Gain items & experience

Trap Room – Take damage

Boss Room – Final battle

Combat System

Turn-based attacks

Damage = Base attack + skill bonuses

Enemies drop experience

Skill Progression

Gain experience from combat and treasure

Level up every 10 XP

Skills unlock automatically

🏆 Win & Lose Conditions

✅ Win: Defeat the final boss

❌ Lose: Player health reaches zero

📈 Example Game Session
========================================
        DUNGEON EXPLORATION GAME
========================================

Objective: Defeat the final boss!
Current Room: 0

Adjacent rooms: 1

Options:
1. Move to a room
2. View skill tree
3. View dungeon map
4. Check if boss is reachable
5. Quit game

🚀 Future Enhancements

Multiple dungeon levels

Save & load system

More enemy types

Player classes

Advanced skill tree

Random dungeon generation

Item usage (potions, weapons)

Mini-boss encounters

📜 License

This project is created for educational purposes, demonstrating:

Graph algorithms

C++ OOP design

Game development fundamentals

👨‍💻 Author

Created as a demonstration of Dungeon Exploration Game Mechanics using C++, Graph Theory, and Object-Oriented Programming.