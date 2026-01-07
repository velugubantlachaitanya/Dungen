#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

enum RoomType {
    EMPTY,
    ENEMY,
    TREASURE,
    TRAP,
    BOSS
};

struct Room {
    int id;
    RoomType type;
    bool visited;

    Room(int i = 0, RoomType t = EMPTY) {
        id = i;
        type = t;
        visited = false;
    }
};

class Enemy {
public:
    string name;
    int health;
    int attack;

    Enemy(string n = "Goblin", int h = 30, int a = 5) {
        name = n;
        health = h;
        attack = a;
    }
};

class SkillNode {
public:
    string skillName;
    int bonusAttack;
    vector<SkillNode*> children;
    bool unlocked;

    SkillNode(string name, int bonus) {
        skillName = name;
        bonusAttack = bonus;
        unlocked = false;
    }
};

class SkillTree {
private:
    SkillNode* root;

public:
    SkillTree() {
        root = new SkillNode("Base Skill", 0);
        SkillNode* s1 = new SkillNode("Sword Mastery", 5);
        SkillNode* s2 = new SkillNode("Fire Strike", 10);
        SkillNode* s3 = new SkillNode("Berserk", 15);

        root->children.push_back(s1);
        s1->children.push_back(s2);
        s2->children.push_back(s3);

        root->unlocked = true;
    }

    void unlockSkill() {
        SkillNode* curr = root;
        while (!curr->children.empty()) {
            SkillNode* next = curr->children[0];
            if (!next->unlocked) {
                next->unlocked = true;
                cout << "Skill Unlocked: " << next->skillName << endl;
                return;
            }
            curr = next;
        }
        cout << "All skills already unlocked." << endl;
    }

    int getAttackBonus() {
        int bonus = 0;
        SkillNode* curr = root;
        while (curr != nullptr) {
            if (curr->unlocked)
                bonus += curr->bonusAttack;
            if (curr->children.empty()) break;
            curr = curr->children[0];
        }
        return bonus;
    }
};

class Player {
public:
    int health;
    int baseAttack;
    vector<string> inventory;
    SkillTree skills;

    Player() {
        health = 100;
        baseAttack = 10;
    }

    int totalAttack() {
        return baseAttack + skills.getAttackBonus();
    }

    void addItem(string item) {
        inventory.push_back(item);
        cout << "Collected item: " << item << endl;
    }

    bool isAlive() {
        return health > 0;
    }
};

class DungeonGraph {
private:
    map<int, vector<int>> adj;
    map<int, Room> rooms;

public:
    void addRoom(int id, RoomType type) {
        rooms[id] = Room(id, type);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> getNeighbors(int id) {
        return adj[id];
    }

    Room& getRoom(int id) {
        return rooms[id];
    }

    bool allRoomsCleared() {
        for (auto &r : rooms) {
            if (!r.second.visited && r.second.type != EMPTY)
                return false;
        }
        return true;
    }
};

class Game {
private:
    DungeonGraph dungeon;
    Player player;
    int currentRoom;
    int bossRoom;

public:
    Game() {
        srand(time(0));
        buildDungeon();
        currentRoom = 0;
        bossRoom = 6;
    }

    void buildDungeon() {
        dungeon.addRoom(0, EMPTY);
        dungeon.addRoom(1, ENEMY);
        dungeon.addRoom(2, TREASURE);
        dungeon.addRoom(3, TRAP);
        dungeon.addRoom(4, ENEMY);
        dungeon.addRoom(5, TREASURE);
        dungeon.addRoom(6, BOSS);

        dungeon.addEdge(0,1);
        dungeon.addEdge(1,2);
        dungeon.addEdge(2,3);
        dungeon.addEdge(3,4);
        dungeon.addEdge(4,5);
        dungeon.addEdge(5,6);
        dungeon.addEdge(1,4);
    }

    void combat(Enemy enemy) {
        cout << "Encountered Enemy: " << enemy.name << endl;
        while (enemy.health > 0 && player.isAlive()) {
            enemy.health -= player.totalAttack();
            cout << "You attacked enemy. Enemy health: " << enemy.health << endl;
            if (enemy.health <= 0) break;
            player.health -= enemy.attack;
            cout << "Enemy attacked you. Your health: " << player.health << endl;
        }
        if (player.isAlive()) {
            cout << "Enemy defeated!" << endl;
            player.skills.unlockSkill();
        }
    }

    void enterRoom(int roomId) {
        Room &room = dungeon.getRoom(roomId);
        if (room.visited) {
            cout << "Room already visited." << endl;
            return;
        }

        room.visited = true;

        if (room.type == ENEMY) {
            combat(Enemy());
        }
        else if (room.type == TREASURE) {
            player.addItem("Gold");
        }
        else if (room.type == TRAP) {
            player.health -= 15;
            cout << "Trap triggered! Health now: " << player.health << endl;
        }
        else if (room.type == BOSS) {
            cout << "Final Boss Encounter!" << endl;
            combat(Enemy("Dragon", 80, 15));
        }
        else {
            cout << "Empty room." << endl;
        }
    }

    void showOptions() {
        vector<int> neighbors = dungeon.getNeighbors(currentRoom);
        cout << "You can move to rooms: ";
        for (int n : neighbors)
            cout << n << " ";
        cout << endl;
    }

    void play() {
        cout << "Dungeon Exploration Game Started!" << endl;

        while (player.isAlive()) {
            cout << "\nCurrent Room: " << currentRoom << endl;
            enterRoom(currentRoom);

            if (!player.isAlive()) {
                cout << "You died. Game Over." << endl;
                return;
            }

            if (currentRoom == bossRoom && dungeon.allRoomsCleared()) {
                cout << "You cleared the dungeon and defeated the boss!" << endl;
                return;
            }

            showOptions();
            int next;
            cout << "Enter next room: ";
            cin >> next;

            currentRoom = next;
        }
    }
};

int main() {
    Game game;
    game.play();
    return 0;
}
