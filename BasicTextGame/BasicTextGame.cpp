// BasicTextGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

class Player {
public:
	int	health;
	Player(int h) {
		health = h;
	}
	void heal() {
		int healAmount = rand() % 11 + 15;
		health += healAmount;
		cout << "You healed for " << healAmount << "health!" << endl;
	}
	void attack(Enemy& e) {
		int damageOutput = rand() % 11 + 10; // generating a random number between 10 and 20
		e.health -= damageOutput;
		cout << "You attacked the Demon Lord for " << damageOutput << " damage! " << endl;
	}

	
};

class Enemy {
public:
	int health;
	Enemy(int h) {
		health = h;
	}
	
	void attack(Player& p) {
		int damageOutput = rand() % 11 + 20; // generating a random number between 20 and 30
		p.health -= damageOutput;
		cout << "You were just attacked for " << damageOutput << " damage! " << endl;
	}
};

void Fight(Player& player, Enemy& enemy) {

	cout << "..." << endl;
	cout << "You finally arrived to the demon lord's lair..";
	cout << "You set out to put an end to this war with one last fight.";


	while (player.health > 0 && enemy.health > 0) {
		std::cout << "Press 'a' to attack or 'h' to heal: ";
		char input = getchar();
		std::cout << std::endl;

		if (input == 'a') {
			player.attack(enemy);
			std::cout << "Enemy health: " << enemy.health << std::endl;
			if (enemy.health <= 0) {
				std::cout << "Player wins!" << std::endl;
				break;
			}
			enemy.attack(player);
			std::cout << "Player health: " << player.health << std::endl;
			if (player.health <= 0) {
				std::cout << "Enemy wins!" << std::endl;
				break;
			}
		}

		else if (input == 'h') {
			player.heal();
			enemy.attack(player);
			std::cout << "Player health: " << player.health << std::endl;
			if (player.health <= 0) {
				std::cout << "Enemy wins!" << std::endl;
				break;
			}
		}

		else {
			std::cout << "Invalid input. Please try again." << std::endl;
		}
	}
}

int main() {
	srand(time(0));

	Player	player(250);
	Enemy	enemy(500);

	fight(player, enemy);

	return 0
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
