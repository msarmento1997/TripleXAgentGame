/*Michael Sarmento
Date: 9/28/19
*/

#include <iostream>
#include <ctime>

//function to print the introduction of the game
void PrintIntroduction(int LevelDifficulty)
{
    //Print welcome messages to the terminal
    std::cout << "\nYou are a secret agent breaking " <<LevelDifficulty;
    std::cout << " into a secure server room...\nYou need to enter the correct codes to continue...\n\n" ;

}

//function to play game
bool PlayGame(int LevelDifficulty)
{
    PrintIntroduction(LevelDifficulty);
    //Code numbers 
    const int CodeA = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeB = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeC = rand() % LevelDifficulty + LevelDifficulty;
    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    
    std::cout << "There are 3 numbers in the code\n";
    std::cout << "The codes add up to: " << CodeSum;
    std::cout << "\nThe codes multiply to give: " << CodeProduct << "\n";
    
    //Receiving the users 3 number guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //check if user guessed the code correctly
    if(GuessSum == CodeSum && GuessProduct == CodeProduct){
        std::cout << "\nCongratulations! You guessed the Code correctly.\n";
        return true;
    }else{
        std::cout << "\nSorry, the code you entered was incorrect\n";
        return false;
    }

}



//Main function
int main()
{
    srand(time(NULL)); // create new random sequence based on time of day

    std::cout << std::endl;
    std::cout << "\n  ______     _       __          _  __";
    std::cout << "\n /_  __/____(_)___  / /__       | |/ /";
    std::cout << "\n  / / / ___/ / __ \\/ / _ \\______|   / ";
    std::cout << "\n / / / /  / / /_/ / /  __/_____/   |  ";
    std::cout << "\n/_/ /_/  /_/ .___/_/\\___/     /_/|_|  ";
    std::cout << "\n          /_/                         ";

    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) 
    {

        bool bLevelComplete = PlayGame(LevelDifficulty);
        
        std::cin.clear(); //clears any errors
        std::cin.ignore(); //discards the buffer

        if (bLevelComplete)
        {
            //increase the level difficulty
            ++LevelDifficulty;
        }
        else
        {
            //end game
            std::cout << "Mission Failed! You have been detected by security.\n";
            break;
            
        }
    }

    if(LevelDifficulty == 6){
        std::cout << "\n*** Great work agent! You got all the files! Now get out of there! ***\n";
    }
    
    return 0;
}
