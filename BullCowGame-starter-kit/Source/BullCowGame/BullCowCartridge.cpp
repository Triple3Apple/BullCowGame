// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"


//FString HiddenWord = TEXT("stinky");        // BAD (will make it global!)


void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay(); // needed to make game run
    SetupGame();     // setting up game

    PrintLine(FString::Printf(TEXT("Debug: word is: %s\n"), *HiddenWord));      // for DEBUGGING Purposes
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ProcessGuess(Input);
}

void UBullCowCartridge::SetupGame()
{
    bGameOver = false;
    HiddenWord = TEXT("stinky");        // HiddenWord is declared in the header class and made private
    PlayerLives = HiddenWord.Len();

    // welcoming the player
    PrintLine(TEXT("MOOOOOOOOO! Welcome to Bull Cows!\n"));
    PrintLine(FString::Printf(TEXT("You have %i lives"), PlayerLives));
    PrintLine(FString::Printf(TEXT("Press TAB and guess the %i letter \nword then press enter to continue..."), HiddenWord.Len()));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press ENTER to play again..."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else  // checking player guess
    {
        if (Guess == HiddenWord)
        {
            PrintLine(TEXT("Correct! You win!"));
            EndGame();
            return;     // early return so it does not read the other if statements
        }
        else
        {
            --PlayerLives;
            PrintLine(TEXT("You have lost a life!"));
            if (PlayerLives > 0)
            {
                if (HiddenWord.Len() != Guess.Len())
                {
                    PrintLine(FString::Printf(TEXT("Sorry the hidden word is %i characters \nlong, try guessing again! \nYou have %i lives remaining"),HiddenWord.Len(), PlayerLives));
                    return;
                }
                else if (HiddenWord.Len() == Guess.Len())
                {
                    PrintLine(FString::Printf(TEXT("Correct word length but wrong word, \ntry guessing again! You have %i lives \nremaining"), PlayerLives));
                    return;
                }
            }
            else
            {
                ClearScreen();
                PrintLine(TEXT("GAMEOVER, no more lives remaining!"));
                PrintLine(TEXT("The hidden word was: %s"), *HiddenWord);
                EndGame();
                return;
            }
        }
    }
}