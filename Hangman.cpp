#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

void playGame();
string generateWord();

int wins, losses;

int main()
{
    int choice;
    char playAgain = 'y';
    cout << "Welcome to Hangman!" << endl;
    cout << "1. Play" << endl;
    cout << "2. Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    if(choice == 1){
        while(playAgain == 'y'){
            playGame();
            cout << "\nWins: " << wins << " Losses: " << losses;
            cout << "\n\nWould you like to play again? (y/n)";
            cin >> playAgain;
        }
    }
    return 0;
}

void playGame(){
    string word = generateWord();
    int index, lossCount = 0;
    bool lose, win, alreadyGuessed;
    char guess;
    vector<string> wordDisplay;
    vector<char> guessList;
    for(int i = 0; i < word.length(); i++){
        wordDisplay.push_back("_");
    }

    //Enter game loop and display progress
    while(lose != true && win != true){
        int correctGuess = 0, winChecker = 0;
        bool validGuess = true;
        cout << "\n\n";
        for(int i = 0; i <wordDisplay.size(); i++){
            cout << wordDisplay[i];
            cout << " ";
        }
        cout << "Incorrect guesses: " << lossCount << "/6";
        
        //Get guess
        cout << "   Enter your guess: ";
        cin >> guess;
        tolower(guess);

        //Check that it is a letter and has not already been guessed
        if(isalpha(guess)){
            for(int i=0;i<guessList.size();i++){
                if(guess == guessList[i]){
                    cout << "\nYou already guessed that letter!" << endl;
                    cout << "\nLetters Guessed: ";
                    validGuess = false;
                    alreadyGuessed = true;
                    for(int i=0; i<guessList.size();i++){
                        cout << guessList[i];
                    }
                }
            }
        }
        else{
            cout << "\nEnter a letter!" << endl;
            cout << "\nLetters Guessed: ";
            for(int i=0; i<guessList.size();i++){
                cout << guessList[i];
            }
            validGuess = false;
        }
        
        if(alreadyGuessed == false){
            validGuess = true;
        }
        //Once guess is valid execute rest of game
        if(validGuess == true){
            guessList.push_back(guess);
            cout << "\nLetters Guessed: ";
            for(int i=0; i<guessList.size();i++){
                cout << guessList[i];
            }
            for(int i=0; i<word.length();i++){
            if(guess == word[i]){
                wordDisplay[i] = word[i];
                correctGuess += 1;
            }
        }
        
        //Check if player lost
        if(correctGuess == 0){
            lossCount += 1;
        }

        if(lossCount == 6){
            cout << "\n";
            for(int i = 0; i <wordDisplay.size(); i++){
                cout << wordDisplay[i];
                cout << " ";
            }
            cout << "\n\nYou lose";
            losses += 1;
            lose = true;
        }

        //Check if player won
        for(int i = 0; i < word.length(); i++){
            if(wordDisplay[i] != "_"){
                winChecker += 1;
            }
        }
        if(winChecker == wordDisplay.size()){
            cout << "\n";
            for(int i = 0; i <wordDisplay.size(); i++){
                cout << wordDisplay[i];
                cout << " ";
            }
            cout << "\n\nYou win!";
            wins += 1;
            win = true;
        }
        }
    }
    cout << "\nThe word was: " << word << endl;
}

string generateWord(){
    int randomNumber;
    srand (time(NULL));
    randomNumber = rand() % 10 + 1;
    string wordList[10] = {"elephant", "spike", "freedom", "cake", "stapler", "dragon", "caramel", "nightmare", "stuck", "forged"};
    string randomWord = wordList[randomNumber - 1];
    return randomWord;
}
