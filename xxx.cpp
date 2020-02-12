#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{

//The message that the player will see
    std::cout << "\n  LOCK " << Difficulty << "\n";
    std::cout << "\nYou Wake Up And Have A Weird Brace Around Your Neck.. You Hear A Voice Coming Out Of A Speaker Nearby Explaining: \"The Device You Are Currently Wearing Is A Mechanism I Designed Myself. If You Notice The Chamber In The Front Is Currently Housing A Small .22 Revolver. If You Want To Get Out Alive Then You Must Unlock ALL FIVE Locks To Release The Collar And Escape To Freedom\"\n";
    std::cout << "\"Have Fun!!! HAHAHA\"\n\n";

}

bool PlayGame(int Difficulty)

{
    PrintIntroduction(Difficulty);

    // The Combination
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    //The Sum and Product of the combination numbers
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //show sum, product, and text on terminal
    std::cout << "-The Lock Requires A Three Digit Code" << std::endl;
    std::cout << "-The Numbers Add Up To " << CodeSum <<std::endl;
    std::cout << "-The Numbers Multiplied Equal " <<CodeProduct <<std::endl;

    int GuessA, GuessB, GuessC;

    //Store Player Guess
    std::cout << "Enter The Combination Using Spaces Between Each Digit:  ";
    std::cin >> GuessA >> GuessB >> GuessC;

    //Declaring
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Checks the players guess
    if (GuessSum == CodeSum && CodeSum == GuessSum)
    {
        std::cout << "\n The Lock Opens Up\n";
        return true;
    }
    else
    {
        std::cout << "\n\nYou Failed To Remove The Device...\n\n";
        std::cout << "YOU DIE!!!!!!" << std::endl;
        return false;
    }
    
}

int main()
{
    srand(time(NULL));  //creates new random sequence based on the time of day
    int LevelDifficulty = 1;
    const int MaxLevel = 5;
    while (LevelDifficulty <= MaxLevel) //loops game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //clears ayn errors
        std::cin.ignore(); //discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }

    std::cout << "You Remove The Device And Escape!!!";
    return 0;
}
