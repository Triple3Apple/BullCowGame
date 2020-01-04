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
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else  // checking player guess
    {
        if (Input == HiddenWord)
        {
            PrintLine(TEXT("Correct!"));
            EndGame();
        }
        else
        {
            if (HiddenWord.Len() != Input.Len())
            {
                PrintLine(FString::Printf(TEXT("The hidden word is %i characters long, \nyou have lost!"), HiddenWord.Len()));
                EndGame();
            }
        }
    }

    
    

    // check if isogram
    // check if it has the right number of characters

    // decrement a life

    // check if lives > 0
    // if yes: guess again
    //  - show lives left
    // if no: show gameover and hiddenword then prompt to play again

}

void UBullCowCartridge::SetupGame()
{
    bGameOver = false;
    HiddenWord = TEXT("stinky");        // HiddenWord is declared in the header class and made private
    PlayerLives = 4;

    // welcoming the player
    PrintLine(TEXT("MOOOOOOOOO! Welcome to Bull Cows!\n"));
    PrintLine(FString::Printf(TEXT("Press TAB and guess the %i letter \nword then press enter to continue..."), HiddenWord.Len()));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press ENTER to play again..."));
}