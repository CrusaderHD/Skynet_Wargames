//Creator Information:
/*
Name: Hunter Derrick
Professor: Tony Hinton
Wargames Start: 10/20/18  -- Wargames Finish: 10/20/2018
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

	int enemyLocation = rand() % 64 + 1; //Random number between 1 and 64.
	int gridMaxAiOne = 64;
	int gridMaxAiTwo = 64;
	int gridMaxHuman = 64;
	int gridMinAiOne = 1;
	int gridMinAiTwo = 1;
	int gridMinHuman = 1;
	int predictionsAiOne = 1;
	int predictionsAiTwo = 1;
	int predictionsHuman = 1;
	int aiOneGuess = rand() % 64 + 1; //Random number between 1 and 64.
	//int aiTwoGuess = rand() % 64 + 1; //Random number between 1 and 64.
	int humanGuess;
	bool aiFoundEnemy = false;
	bool playerFoundEnemy = false;

	cout << "\n\t\t\t\t\t Welcome to Skynet, Captain.\n\n";
	cout << "Today, you will be witnessing our newest A.I UAV. The 'HK-Aerial'.\n\n";
	cout << "HK-Aerial Software Initalizing...\n\n";
	cout << "Captain, our Intelligence software stragetically places an enemy randomly within an 8x8 Grid.\nAllowing 1 of 64 random locations to be selected within the grid\n";
	cout << "HK-Aerial, automatically hunts down and tracks the enemy in the correct grid sector within a matter of seconds.\n\n";


	//Create the search loop (do) function.
	do
	{
		cout << "\nHuman...Guess the enemy location between Grid 1 - 64: ";
		cin >> humanGuess;
		cout << "\nHuman, your guess was: " << humanGuess  << "\n";
		cout << "\Computer One, your guess was: " << aiOneGuess << "\n";
		//cout << "\nComputer Two, your guess was: " << aiTwoGuess << "\n\n";


		if (aiOneGuess > enemyLocation)
		{
			cout << "\nComputer One, The enemy location is not in Grid # " << aiOneGuess << " guess was to high.";
			gridMaxAiOne = aiOneGuess;
			aiOneGuess = ((gridMaxAiOne - gridMinAiOne) / 2) + gridMinAiOne;
			predictionsAiOne++;
		}

		/*if (aiTwoGuess > enemyLocation)
		{
			cout << "\nComputer Two, The enemy location is not in Grid # " << aiTwoGuess << " your guess was to high.\n\n";
			gridMaxAiTwo = aiTwoGuess;
			aiTwoGuess = ((gridMaxAiTwo - gridMinAiTwo) / 2) + gridMinAiTwo;
			predictionsAiOne++;
		}*/

		if (humanGuess > enemyLocation)
		{
			cout << "\nHuman, The enemy location is not in Grid # " << humanGuess << " your guess was to high.\n\n";
			gridMaxHuman = humanGuess;
			predictionsHuman++;
		}

		if (aiOneGuess < enemyLocation)
		{
			cout << "\nComputer One, The enemy location is not in Grid # " << aiOneGuess << " your guess was to low.";
			gridMinAiOne = aiOneGuess;
			aiOneGuess = ((gridMaxAiOne - gridMinAiOne) / 2) + gridMinAiOne;
			predictionsAiOne++;
		}

		/*else if (aiTwoGuess < enemyLocation)
		{
			cout << "\nComputer Two, The enemy location is not in Grid # " << aiTwoGuess << " your guess was to low.\n\n";
			gridMinAiTwo = aiTwoGuess;
			aiTwoGuess = ((gridMaxAiTwo - gridMinAiTwo) / 2) + gridMinAiTwo;
			predictionsAiTwo++;
		}*/

		if (humanGuess < enemyLocation)
		{
			cout << "\nHuman, The enemy location is not in Grid # " << humanGuess << " your guess was to low.\n\n";
			gridMinHuman = humanGuess;
			predictionsHuman++;
		}

		else if (aiOneGuess == enemyLocation)
		{
			cout << "\nEnemy was located in Grid # " << enemyLocation << " Computer One guessed correctly.\n";
			cout << "\nIt only took aiOne controlling the 'HK-Aerial " << predictionsAiOne << " search attempts.\n\n";
			aiFoundEnemy = true;
		}

		/*else if (aiTwoGuess == enemyLocation)
		{
			cout << "\nEnemy was located in Grid # " << enemyLocation << " Computer Two guessed correctly.\n";
			cout << "\nIt only took aiTwo controlling the 'HK-Aerial " << predictionsAiTwo << " search attempts.\n\n";
			enemyFound = true;
		}*/

		else if (humanGuess == enemyLocation)
		{
			cout << "\nEnemy was located in Grid # " << enemyLocation << " Human, you guessed correctly.\n";
			cout << "\nIt only took you controlling the 'HK-Aerial " << predictionsHuman << " search attempts.\n\n";
			playerFoundEnemy = true;
		}

	} while (enemyLocation != aiOneGuess && humanGuess);

	if (aiFoundEnemy)
	{
		cout << "\n\tThe AI found the enemy.";
	}
	if (playerFoundEnemy)
	{
		cout << "\n\tThe player found the enemy.";
	}

	if (playerFoundEnemy && aiFoundEnemy)
	{
		cout << "All parties found enemies." << endl;
	}
	

	system("pause");

	return(0);
}