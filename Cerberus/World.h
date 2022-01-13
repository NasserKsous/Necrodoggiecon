#pragma once

#include <string>
#include <vector>
#include "Tile.h"
#include "CWorldData.h"
#include "DataStorage.h"


class World
{

	World();

	World(int WorldSlot);

	void LoadWorld(int Slot);

	void ReloadWorld();

	void UnloadWorld();

	//A List of all tiles in the scene
	//std::vector<Tile*> tileList;


	



protected:

	void SetWorldSize(Vector3 Scale);



private:





	CWorldData* WorldData;


	//This function should only be used when Loading / Reloading the scene.
	void LoadEntity(CT_EntityData EntityData);


	//This is a list of entities loaded in with the level data. This should not be touched outside of Loading / Reloading
	std::vector<CT_EntityData> storedEntities;


	//List of entities spawned in by this class, used for deconstruction.
	//std::vector<CEntity> entityList;



};

