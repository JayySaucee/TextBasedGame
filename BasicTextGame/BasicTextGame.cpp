// BasicTextGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;
class Enemy; // forward declaration of the Enemy class

class Player {
public:
    int health;
    Player(int h) {
        health = h;
    }

    void heal() {
        int amount = rand() % 11 + 15; // generates a random number between 15 and 25
        health += amount;
        std::cout << "Player heals for " << amount << " health!" << std::endl;
    }

    void attack(Enemy& e); // declare the function, but don't define it
};

class Enemy {
public:
    int health;
    Enemy(int h) {
        health = h;
    }

    void attack(Player& p) {
        int damage = rand() % 11 + 10; // generates a random number between 10 and 20
        p.health -= damage;
        std::cout << "Enemy attacks Player for " << damage << " damage!" << std::endl;
    }
};

void Player::attack(Enemy& e) {
    int damage = rand() % 11 + 10; // generates a random number between 10 and 20
    e.health -= damage;
    std::cout << "Player attacks Enemy for " << damage << " damage!" << std::endl;
}

void fight(Player& player, Enemy& enemy) {
    while (player.health > 0 && enemy.health > 0) {
        std::cout << "Press 'a' to attack or 'h' to heal: ";
        char input = getchar();
        std::cout << std::endl;
        if (input == 'a') {
            player.attack(enemy);
            std::cout << "Enemy health: " << enemy.health << std::endl << endl << endl;
            if (enemy.health <= 0) {
                std::cout << "Player wins!" << std::endl;
                break;
            }
            enemy.attack(player);
            std::cout << "Player health: " << player.health << std::endl << endl << endl;
            if (player.health <= 0) {
                std::cout << "Enemy wins!" << std::endl;
                break;
            }
        }
        else if (input == 'h') {
            player.heal();
            enemy.attack(player);
            std::cout << "Player health: " << player.health << std::endl << endl;
            if (player.health <= 0) {
                std::cout << "Enemy wins!" << std::endl << endl;
                break;
            }
        }
        
    }
}

void introduce() {
    std::cout << "This is a turn based fighting mini game." << endl;
    std::cout<< "You are about to fight an opponent who has 300HP, and you only have 250HP" << endl;
    std::cout << "Try to strategize by either healing or attacking when it is your turn." << endl;
    cout << "Your opponent does more damage on average than you." << endl << endl;
}

int main() {
    srand(time(0)); // seed the random number generator with the current time

    Player player(250);
    Enemy enemy(300);

    introduce();
    fight(player, enemy);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
