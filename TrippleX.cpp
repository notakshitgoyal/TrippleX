#include <iostream>
#include<ctime>

void PrintIntroduction(int Difficulty){
    //print welcome messages 
    std::cout <<"\n\n\n YOU ARE A SECREAT AGENT BREAKING INTO A LEVEL " << Difficulty;
    std::cout << std::endl;
    std::cout <<"SECURE SERVER ROOM YOU NEED TO ENTER CORRECT CODE TO ENTER......";
    std::cout << std::endl;

}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    // declare 3 number code
    const int CodeA = rand() % Difficulty + 1;
    const int CodeB = rand() % Difficulty + 1;
    const int CodeC = rand() % Difficulty + 1;
    
    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;
    int PlayersGuess;

    std::cout << std::endl;
    std::cout << "+ there are 3 numbers in the code";

    std::cout << std::endl;
    std::cout << "+ the codes add up to: " << CodeSum;

    std::cout << std::endl;
    std::cout << "+ the code multiply to give: " << CodeProduct;
    std::cout << std::endl;

    int GuessA, GuessB, GuessC;
    // store player guess
     std::cin >> GuessA;
     std::cin >> GuessB;
     std::cin >> GuessC;
     std::cout << "you entered: " << GuessA << GuessB << GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // check if players guess is correct 
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "You win!";
        return true;
    }
    else
    {
        std::cout << "You lose!";
        return false;
    }
}
int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;
    while(LevelDifficulty <= MaxDifficulty)
    {
    bool bLevelComplete = PlayGame(LevelDifficulty);    
    std::cin.clear();
    std::cin.ignore();

    if (bLevelComplete){
        //increase difficulte
        ++LevelDifficulty;

    }
    std::cout << "\n great work agent! you got all the files! now get lost lol...\n";
    }
    return 0;
}