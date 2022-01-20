#pragma once
#include "Engine.h"
#include "Vector3.h"
#include "CTransform.h"

//Fundimental component class
//Can be extended upon to make new components to add to CEntity
class CComponent : public CTransform
{
	
public:
	bool shouldUpdate = true;
	bool shouldDraw = false;

	//Updated automatically every single frame
	virtual void Update(float deltaTime) = 0;
	//Almost the same as Update() but to be used for drawing only.
	virtual void Draw(struct ID3D11DeviceContext* context) = 0;
	virtual ~CComponent() {};
};