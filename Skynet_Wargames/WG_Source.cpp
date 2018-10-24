//Creator Information:
/*
Name: Hunter Derrick
Professor: Tony Hinton
Wargames Start: 10/20/18  -- Wargames Finish: 10/23/2018
Project Name: Skynet HK-Aerial - Wargames
*/



#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;


int main()
{

	srand(static_cast<unsigned int>(time(0)));  //Seed the Random Number Generator.

	int enemyLocation = rand() % 64 + 1; //Generates Random number between 1-64 and places enemy there.

	int gridMax = 64;  //Max number Grid can be
	int gridMin = 1;   //Min number Grid can be

	int humanPredictions = 1;     //Number of predictions. Start at 1
	int binaryAIPredictions = 1;  //Number of predictions. Start at 1
	int randomAIPredictions = 1;  //Number of predictions. Start at 1
	int linearAIPredictions = 1;   //Number of predictions. Start at 1

	int humanGuess;											 //Will ask Human for input and guess a number.
	int binaryAIGuess = ((gridMax - gridMin) / 2) + gridMin; //Generates a number between min and max. 
	int linearAIGuess = 1;									 //Begin linear Guess at 1. Guess will be incremented at Function.

	bool humanFoundEnemy = false;	  //Bool to determine if Human has found the enemy.
	bool binaryAIFoundEnemy = false;  //Bool to determine if the BinaryAI found the enemy.
	bool randomAIFoundEnemy = false;  //Bool to determine if the RandomAI found the enemy.
	bool linearAIFoundEnemy = false;  //Bool to determine if the LinearAI found the enemy.

	bool playAgain = false; //Bool to determine if Human would like to play again.
	char yesOrNo;  //Setting a Char to YesOrNo for input.


	do
	{


		srand(static_cast<unsigned int>(time(0)));  //Seed the Random Number Generator.

		int enemyLocation = rand() % 64 + 1; //Generates Random number between 1-64 and places enemy there.

		int gridMax = 64;  //Max number Grid can be
		int gridMin = 1;   //Min number Grid can be

		int humanPredictions = 1;     //Number of predictions. Start at 1
		int binaryAIPredictions = 1;  //Number of predictions. Start at 1
		int randomAIPredictions = 1;  //Number of predictions. Start at 1
		int linearAIPredictions = 1;   //Number of predictions. Start at 1

		int humanGuess;											 //Will ask Human for input and guess a number.
		int binaryAIGuess = ((gridMax - gridMin) / 2) + gridMin; //Generates a number between min and max. 
		int linearAIGuess = 1;									 //Begin linear Guess at 1. Guess will be incremented at Function.

		bool humanFoundEnemy = false;	  //Bool to determine if Human has found the enemy.
		bool binaryAIFoundEnemy = false;  //Bool to determine if the BinaryAI found the enemy.
		bool randomAIFoundEnemy = false;  //Bool to determine if the RandomAI found the enemy.
		bool linearAIFoundEnemy = false;  //Bool to determine if the LinearAI found the enemy.



		//****************************************************************-CREATE INTERESTING NARRATIVE-****************************************************************
		//todo: Reword the narrative.
		cout << "\n\t\t\t\t\t Welcome to Skynet, Captain.\n\n";
		cout << "Today, you will be witnessing and challenging our newest A.I UAV's. The 'HK-Aerial'.\n\n";
		cout << "Captain, our Intelligence software stragetically places an enemy randomly within an 8x8 Grid.\nAllowing 1 of 64 random locations to be selected within the grid\n";
		cout << "HK-Aerial, automatically hunts down and tracks the enemy in the correct grid sector within a matter of seconds.\n\n";

		//****************************************************************-CREATE HUMAN INTERACTION-********************************************************************
		do
		{
			cout << "\nHuman...Guess the enemy location between Grid 1 - 64: ";
			cin >> humanGuess;
			cout << "\nHuman, your guess was: " << humanGuess << "\n";

			//If Humans guess was too high...
			if (humanGuess > enemyLocation)
			{
				cout << "\nHuman, The enemy location is not in Grid # " << humanGuess << " your guess was to high.\n\n";
				gridMax = humanGuess;
				humanPredictions++;
			}

			//If Humans guess was too low...
			if (humanGuess < enemyLocation)
			{
				cout << "\nHuman, The enemy location is not in Grid # " << humanGuess << " your guess was to low.\n\n";
				gridMin = humanGuess;
				humanPredictions++;
			}

			//If Human guessed correctly...
			else if (humanGuess == enemyLocation)
			{
				cout << "\nEnemy was located in Grid # " << enemyLocation << " Human, you guessed correctly.\n";
				humanFoundEnemy = true;
			}

		} while (!humanFoundEnemy);

		system("pause");

		//****************************************************************-CREATE BINARY_AI INTERACTION-*****************************************************************
		do
		{
			//Repeat what the BinaryAI's guess was.
			cout << "\BinaryAI, your guess was: " << binaryAIGuess << "\n";

			//If BinaryAI's guess was higher than the Enemy Location...
			if (binaryAIGuess > enemyLocation)
			{
				cout << "\nBinaryAI, The enemy location is not in Grid # " << binaryAIGuess << " guess was to high.";
				gridMax = binaryAIGuess;
				binaryAIGuess = ((gridMax - gridMin) / 2) + gridMin;
				binaryAIPredictions++;
			}

			//If BinaryAI's guess was lower than the Enemy Location...
			if (binaryAIGuess < enemyLocation)
			{
				cout << "\nBinaryAI, The enemy location is not in Grid # " << binaryAIGuess << " your guess was to low.";
				gridMin = binaryAIGuess;
				binaryAIGuess = ((gridMax - gridMin) / 2) + gridMin;
				binaryAIPredictions++;
			}

			//If BinaryAI's guess was correct...
			else if (binaryAIGuess == enemyLocation)
			{
				cout << "\nEnemy was located in Grid # " << enemyLocation << " BinaryAI guessed correctly.\n";
				binaryAIFoundEnemy = true;
			}

		} while (!binaryAIFoundEnemy);

		system("pause");

		//****************************************************************-CREATE RANDOM_AI INTERACTION-*****************************************************************
		//todo: Make Random Enemy Guess. Set random enemy value and loop through new random number until it mataches enemy location.
		do
		{
			int randomAIGuess = rand() % 64 + 1;  //Generates Random number between 1-64 to be initialized every cycle of Do-Loop until matching enemy location.

			cout << "\nRandomAI, your guess was: " << randomAIGuess << "\n\n";

			//If RandomAI guess was too high...
			if (randomAIGuess > enemyLocation)
			{			
				cout << "\nRandomAI, The enemy location is not in Grid # " << randomAIGuess << " your guess was to high.\n\n";
				randomAIPredictions++;
			}

			//If RandomAI guess was too low...
			else if (randomAIGuess < enemyLocation)
			{
				cout << "\nComputer Two, The enemy location is not in Grid # " << randomAIGuess << " your guess was to low.\n\n";
				randomAIPredictions++;
			}

			//If RandomAI guess was correct...
			else if (randomAIGuess == enemyLocation)
			{
				cout << "\nEnemy was located in Grid # " << enemyLocation << " RandomAI guessed correctly.\n";
				randomAIFoundEnemy = true;
			}

		} while (!randomAIFoundEnemy);

		system("pause");

		//****************************************************************-CREATE LINEAR_AI INTERACTION-*****************************************************************
		//todo: Make Linear Enemy guess. Start enemy guess at 1 and increase by 1 per loop.
		do
		{
			
			cout << "LinearAI: Your guess starts at " << linearAIGuess << " and increases by 1 each cycle until you are correct." << endl;
			linearAIGuess++;

			//Only need to do LESS than enemy location since the guess starts at 1 and increments up. Guess will never go higher than the enmy location.
			if (linearAIGuess < enemyLocation)
			{
				cout << "You guessed " << linearAIGuess << ". That is too low. Keep trying. You'll get there eventually." << endl;
				linearAIPredictions++;
			}

			//If Guess is correct...
			else if (linearAIGuess = enemyLocation)
			{
				cout << "Correct! The enemy is located in grid # " << enemyLocation << "! Nice job...Took you long enough..." << endl;
				linearAIFoundEnemy = true;
			}
		} while (!linearAIFoundEnemy);

		system("pause");
		//****************************************************************-CREATE INTERACTION SUMMARY-******************************************************************* 
		cout << "\nIt took you controlling the 'HK-Aerial' " << humanPredictions << " search attempts.\n";
		cout << "\nIt only took BinaryAI controlling the 'HK-Aerial' " << binaryAIPredictions << " search attempts.\n";
		cout << "\nIt only took RandomAI controlling the 'HK-Aerial' " << randomAIPredictions << " search attempts.\n";
		cout << "\nIt only took LinearAI controlling the 'HK-Aerial' " << linearAIPredictions << " search attempts." << endl;

		//****************************************************************-CREATE PLAY AGAIN INTERACTION-****************************************************************
		//todo: Add play again functionality.
		
		system("pause");

		cout << "\nDo you wish to try again? (Y or N)" << endl;
		cin >> yesOrNo;
		if (yesOrNo == 'y' || yesOrNo == 'Y')
		{
			playAgain = true;
		}
		else
		{
			playAgain = false;
		}

	} while (playAgain);

	cout << "\nThanks for playing!" << endl;
	system("pause");

	return(0);
}