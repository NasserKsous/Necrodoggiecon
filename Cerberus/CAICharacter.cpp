#include "CAICharacter.h"

CAICharacter::CAICharacter()
{
	viewSprite = AddComponent<CSpriteComponent>();
	viewSprite->LoadTexture("Resources\\viewFrustrum.dds");
	viewSprite->SetTint(XMFLOAT4(0.0f, 0.0f, 0.0f, 0));
	viewSprite->SetScale(Vector3{ 1.0f, 1.0f, 1.0f });

	audioEmitter = AddComponent<CAudioEmitterComponent>();
	audioEmitter->Load("Resources/TestAudio.wav");
	audioEmitter->Play();
}

void CAICharacter::Update(float deltaTime)
{
	audioEmitter->SetPosition(this->GetPosition());
}

CAICharacter::~CAICharacter()
{
}
