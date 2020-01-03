// Fill out your copyright notice in the Description page of Project Settings.


#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay(); // needed to make game run
    PrintLine("Hi there!");
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{

}