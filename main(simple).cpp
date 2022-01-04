#include <iostream>
#include <time.h>

using namespace std;

int repeat();

int main(int argc, char *argv[])
{

	cout<<"************ WELCOME TO THE GAME ************\n"<<"First lets set up the Game"<<endl;
	int min;
	int max;
	int guess;
	int number;
	int range;
	int userguess;
	int guessamount = 0;
	srand(time(NULL));
	cout << "Please Enter the minimum number, a positive integer: " << endl;
	cin >> min;
	while(min < 1)
	{
		cout << "Please Enter the minimum number, a positive integer: " << endl;
		cin >> min;
	}
	cout << "Please Enter the maximum number, which is greater than the min and less then 1000: " << endl;
	cin >> max;
	while(max > 1000 || max <= min)
	{
		cout << "Please Enter the maximum number, which is greater than the min and less then 1000: " << endl;
		cin >> max;
	}
	cout << "Please Enter the number of guesses allowed(less than 10): " << endl;
	cin >> guess;
	while(guess > 10 || guess < 1)
	{
		cout << "Please Enter the number of guesses allowed(less than 10): " << endl;
		cin >> guess;
	}
	range = max - min + 1;
	number = rand() % range + min;
	//cout << number << endl;

	cout << "I have a number between " << min << " and " << max << " Can you guess my number? Please type your first guess" << endl;
	cin >> userguess;
	guessamount++;



	while(userguess < number)
	{
		cout << "Too Low try agin: " << endl;
		cin >> userguess;
		guessamount++;
//		cout << guessamount<< endl;
//		cout << guess<< endl;
		if(guessamount == guess)
			{


				repeat();

			}

	}
	while(userguess > number)
	{
		cout << "Too High try agin: " << endl;
		cin >> userguess;
		guessamount++;
//		cout << guessamount<< endl;
//		cout << guess<< endl;

		if(guessamount == guess)
			{


				repeat();

			}
	}
	if(guessamount == guess)
	{

		repeat();

	}
	else
	{
		cout << "Excellet you guessed the number" << endl;

		guessamount = guess;
		repeat();
	}

	//repeat();

	return 0;
}

int repeat()
{
	char start;
	cout << "Do you want to play agin? (y/n)" << endl;
	cin >> start;
	if ( start == 'Y' || start == 'y')
	{
		int min;
			int max;
			int guess;
			int number;
			int range;
			int userguess;
			int guessamount = 0;
			srand(time(NULL));
			cout << "Please Enter the minimum number, a positive integer: " << endl;
			cin >> min;
			while(min < 1)
			{
				cout << "Please Enter the minimum number, a positive integer: " << endl;
				cin >> min;
			}
			cout << "Please Enter the maximum number, which is greater than the min and less then 1000: " << endl;
			cin >> max;
			while(max > 1000 || max <= min)
			{
				cout << "Please Enter the maximum number, which is greater than the min and less then 1000: " << endl;
				cin >> max;
			}
			cout << "Please Enter the number of guesses allowed(less than 10): " << endl;
			cin >> guess;
			while(guess > 10 || guess < 1)
			{
				cout << "Please Enter the number of guesses allowed(less than 10): " << endl;
				cin >> guess;
			}
			range = max - min + 1;
			number = rand() % range + min;
			//cout << number << endl;

			cout << "I have a number between " << min << " and " << max << " Can you guess my number? Please type your first guess" << endl;
			cin >> userguess;
			guessamount++;



			while(userguess < number)
				{
					cout << "Too Low try agin: " << endl;
					cin >> userguess;
					guessamount++;
//					cout << guessamount<< endl;
//					cout << guess<< endl;
					if(guessamount == guess)
						{


							repeat();

						}

				}
				while(userguess > number)
				{
					cout << "Too High try agin: " << endl;
					cin >> userguess;
					guessamount++;
//					cout << guessamount<< endl;
//					cout << guess<< endl;

					if(guessamount == guess)
						{

							repeat();

						}
				}
				if(guessamount == guess)
				{
					cout << "Hello"<< endl;

					repeat();

				}
				else
				{
					cout << "Excellet you guessed the number" << endl;

					guessamount = guess;
					repeat();
				}

	}
	else if ( start == 'N' || start == 'n')
	{
		return 0;

	}

	return 0;
}
