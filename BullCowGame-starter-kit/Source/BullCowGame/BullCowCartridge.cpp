// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"


//FString HiddenWord = TEXT("stinky");        // BAD (will make it global!)


void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay(); // needed to make game run

    // welcoming the player
    PrintLine(TEXT("MOOOOOOOOO! Welcome to Bull Cows! \n~ made for a little boy\n"));
    PrintLine(TEXT("Please press TAB and guess \nthe 5 letter word then press \nenter..."));        // remove the hardcoded number!

   

    SetupGame();     // setting up game

    // prompt player for guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the play er hits enter
{
    ClearScreen();

    int32 HiddenWordLength = HiddenWord.Len();
    
    // checking player guess
    if (Input == HiddenWord)
    {
        PrintLine(TEXT("Correct!"));
    }
    else
    {
        PrintLine(TEXT("Wrong!"));

        if (HiddenWordLength == Input.Len())
        {
            PrintLine(TEXT("Has the correct number of letters"));
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
    HiddenWord = TEXT("stinky");        // HiddenWord is declared in the header class and made private
    PlayerLives = 4;
}