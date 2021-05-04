#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
  //Message presented to the player
  // std::cout << "\n\n______________________________________________________________\n";
  // std::cout << "|             You are a lockpicker in training.              |\n";
  // std::cout << "|   You have to crack various locks to finish your traning.  |\n";
  // std::cout << "|   You need to find the correct combination to continue...  |\n";
  // std::cout << "|____________________________________________________________|\n\n";

  std::cout << "\nYou are a lockpicker in training.\n";
  std::cout << "You have to crack various padlocks to finish your traning.\n";
  std::cout << "You need to find the correct combination on a level " << Difficulty;
  std::cout << " padlock to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
  PrintIntroduction(Difficulty);

  //Declaring our three numbers code
  const int CodeA = rand() % Difficulty + Difficulty;
  const int CodeB = rand() % Difficulty + Difficulty;
  const int CodeC = rand() % Difficulty + Difficulty;

  const int CodeSum = CodeA + CodeB + CodeC;
  const int CodeProduct = CodeA * CodeB * CodeC;

  //Printing CodeSum and CodeProduct
  std::cout << "* There are three numbers in the code.";
  std::cout << "\n* The numbers add-up to: " << CodeSum;
  std::cout << "\n* The numbers multiply to give: " << CodeProduct << std::endl;
  std::cout << "Enter your code guess (number 1 number 2 number 3): ";

  // Storing the player guesses
  int GuessA, GuessB, GuessC;
  std::cin >> GuessA >> GuessB >> GuessC;

  int GuessSum = GuessA + GuessB + GuessC;
  int GuessProduct = GuessA * GuessB * GuessC;

  // Checking if the player guess is correct
  if (GuessSum == CodeSum && GuessProduct == CodeProduct)
  {
    std::cout << "\n*** You cracked the lock! Now you'll be tested with a higher difficulty padlock. ***\n";
    return true;
  }
  else
  {
    std::cout << "\n*** You failed to crack the lock... Try it again! ***\n";
    return false;
  }
}

int main()
{
  srand(time(NULL)); //Create new random sequence based on time of the day

  int LevelDifficulty = 1;
  const int MaxDifficulty = 5;

  while (LevelDifficulty <= MaxDifficulty) //Loop the game untill all levels are completed
  {
    bool bLevelComplete = PlayGame(LevelDifficulty);
    std::cin.clear();  //Clears any errors
    std::cin.ignore(); //Discards the buffer

    if (bLevelComplete)
    {
      // Increase level difficulty
      ++LevelDifficulty;
    }
  }

  std::cout << "\n*** Congratulations! Your training is complete! You are hired! ***";

  return 0;
}