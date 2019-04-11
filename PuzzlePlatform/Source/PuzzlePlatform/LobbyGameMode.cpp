// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"


void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	++NumberOfPlayers;

	if (NumberOfPlayers >= 3)
	{
		UWorld* World = GetWorld();
		if (!ensure(World != nullptr)) { return; }

		bUseSeamlessTravel = true;
		World->ServerTravel("/Game/PuzzlePlatform/Maps/Game?listen");
	}
}

void ALobbyGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);

	--NumberOfPlayers;
}