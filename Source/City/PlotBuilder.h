// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "HouseBuilder.h"
#include "BaseLibrary.h"
#include "PlotBuilder.generated.h"

USTRUCT(BlueprintType)
struct FSidewalkInfo {
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FMeshInfo> staticMeshes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FMeshInfo> instancedMeshes;
};


UCLASS()
class CITY_API APlotBuilder : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	APlotBuilder();

	UFUNCTION(BlueprintCallable, Category = "Generation")
	static TArray<FHousePolygon> generateAllHousePolygons(TArray<FPlotPolygon> p, TArray<FPolygon> others, int maxFloors, int minFloors);


	UFUNCTION(BlueprintCallable, Category = "Generation")
	static TArray<FHousePolygon> generateHousePolygons(FPlotPolygon p, TArray<FPolygon> others, int minFloors, int maxFloors);

	UFUNCTION(BlueprintCallable, Category = "Generation")
	static FPolygon generateSidewalkPolygon(FPlotPolygon p, float offsetSize);

	
	UFUNCTION(BlueprintCallable, Category = "Generation")
	static FSidewalkInfo getSideWalkInfo(FPolygon sidewalk);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//virtual void BeginDestroy() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
