#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

class Player {
public:
	virtual int getGuess(int answer) {
		return 0;
	}

	virtual ~Player() {
		cout << "Destroyed Player" << endl;

	}
	void set_max(int aMax) {
		max = aMax;
	}
	void set_min(int aMin) {
		max = aMin;
	}
	int get_Max() {
		return max;
	}
	int get_Min() {
		return min;
	}
	int min = 0;
	int max = 100;
	//void play(Player &player1, Player &player2);
protected:
	int guess;

};

class HumanPlayer: public Player {
public:
	int getGuess(int answer) {
		cout << "Enter a Number: " << endl;
		cin >> guess;
		if (guess < answer) {
			min = guess;
		} else if (guess > answer) {
			max = guess;
		}
		return guess;
	}
	~HumanPlayer() {
		cout << "Destroyed HumanPLyaer" << endl;
	}
private:

};
class ComputerPlayer: public Player {
public:
	int getGuess(int answer) {
		guess = (rand() % (max - min + 1)) + min;
		cout << "The computer Guesses: " << guess << endl;
		if (guess < answer) {
			min = guess + 1;
		} else if (guess > answer) {
			max = guess - 1;
		}
		return guess;
	}
	~ComputerPlayer() {
		cout << "Destroyed ComputerPlayer" << endl;

	}

private:

};
void play(Player &player1, Player &player2);
bool checkForWin(int guess, int answer);
int main(int argc, char *argv[]) {
	/////HUMan vs Computer
	Player player;
	HumanPlayer p1;
	ComputerPlayer p2;
	play(p1, p2);

	///////Human Vs Human
	HumanPlayer p3;
	HumanPlayer p4;
	//player.play(p3, p3);

	//Computer Vs Comuter
	ComputerPlayer p5;
	ComputerPlayer p6;
	//player.play(p5, p6);
	return 0;
}

bool checkForWin(int guess, int answer) {
	if (answer == guess) {
		cout << "You're right! You win!" << endl;
		return true;
	} else if (answer < guess)

		cout << "Your guess is too high." << endl;
	else
		cout << "Your guess is too low." << endl;
	return false;
}
// The play function takes as input two Player objects.
void play(Player &player1, Player &player2) {
	int answer = 0, guess = 0;
	srand(time(NULL));

	answer = rand() % 100;
	bool win = false;

	while (!win) {
		cout << "Player 1's turn to guess." << endl;
		if (player1.min > player2.min) {
			player2.min = player1.min;
		}

		else if (player2.min > player1.min) {
			player1.min = player2.min;
		}

		if (player1.max < player2.max) {
			player2.max = player1.max;
		}

		else if (player2.max < player1.max) {
			player1.max = player2.max;
		}
		guess = player1.getGuess(answer);
		win = checkForWin(guess, answer);
		if (win)
			return;

		cout << "Player 2's turn to guess." << endl;
		if (player1.min > player2.min) {
			player2.min = player1.min;
		}

		else if (player2.min > player1.min) {
			player1.min = player2.min;
		}

		if (player1.max < player2.max) {

			player2.max = player1.max;
		}

		else if (player2.max < player1.max) {
			player1.max = player2.max;
		}
		guess = player2.getGuess(answer);
		win = checkForWin(guess, answer);
	}
}
