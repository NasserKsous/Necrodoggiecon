#include "testClass.h"
#include "Utility/DebugOutput/Debug.h"
#include "../CSpriteComponent.h"

TestClass::TestClass()
{
	Debug::Log("init test class!\n");

	

	//sprite->SetTint(XMFLOAT4(rand() % 2 * .5, rand() % 2 * .5, rand() % 2 * .5, 0));

	
	

	//timeElapsed = rand() / 100;
}

void TestClass::Update(float deltaTime)
{
	//CEntity::Update(deltaTime);

	//timeElapsed += deltaTime;

	//const uint32_t speed = 24;
	//sprite->SetTextureOffset(XMFLOAT2(round(timeElapsed * speed) * 128, (int(round(timeElapsed * speed) / 5) % 2) * 128));
}

TestClass::~TestClass()
{
	Debug::Log("destroy test class!\n");
}
