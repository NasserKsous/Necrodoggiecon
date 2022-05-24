#include "PauseMenu.h"
#include "Cerberus/Core/UI/CWidget_Button.h"
#include "Cerberus/Core/UI/CWidget_Image.h"
#include "Cerberus/Core/Components/CTextRenderComponent.h"
#include "Cerberus/Core/Utility/CWorldManager.h"
#include "CWorld_Game.h"

PauseMenu::PauseMenu()
{
	InitialiseCanvas();
}

void PauseMenu::InitialiseCanvas()
{
	Debug::Log("Pause Canvas Initialised");

	CWidget_Image* Background = CreateImage(Vector2(0, 0), Vector2(.5, .5), -150);
	Background->GetSprite()->LoadTextureWIC("Resources/Game/uiBackground.png");
	Background->GetSprite()->SetRenderRect(XMUINT2(16, 16));
	Background->GetSprite()->SetSpriteSize(XMUINT2(1500, 1000));
	Background->GetSprite()->SetUseTranslucency(true);
	Background->GetSprite()->SetTint(XMFLOAT4(-255, -255, -255, -0.1f));

	std::string ResumeButtonName = "Resume";
	CWidget_Button* Resume = CreateButton(Vector2(0, 128), Vector2(1, 1), ResumeButtonName, -155);
	Resume->Bind_OnButtonPressed(std::bind(&PauseMenu::ResumeGame , this));
	Resume->SetTexture("Resources/UI/UI_ButtonAtlas.dds");
	Resume->SetButtonSize(Vector2(256, 110));

	std::string QuitButtonName = "Quit to Menu";
	CWidget_Button* Exit = CreateButton(Vector2(0, 0), Vector2(1, 1), QuitButtonName, -155);
	Exit->Bind_OnButtonPressed(std::bind(&PauseMenu::QuitToMenu , this));
	Exit->SetTexture("Resources/UI/UI_ButtonAtlas.dds");
	Exit->SetButtonSize(Vector2(256, 110));
	Exit->GetText()->SetScale(1, 1, 1);
	
	std::string FullQuitButtonName = "Quit to Desktop";
	CWidget_Button* ExitFull = CreateButton(Vector2(0, -128), Vector2(1, 1), FullQuitButtonName, -155);
	ExitFull->Bind_OnButtonPressed(std::bind(&PauseMenu::QuitToDesktop , this));
	ExitFull->SetTexture("Resources/UI/UI_ButtonAtlas.dds");
	ExitFull->SetButtonSize(Vector2(256, 110));

	SetVisibility(false);
}

void PauseMenu::PauseGame()
{
	SetVisibility(true);
	Debug::Log("pause");
	isPaused = true;
}

void PauseMenu::ResumeGame()
{
	SetVisibility(false);
	Debug::Log("resume");
	isPaused = false;
}

void PauseMenu::QuitToMenu()
{
	Debug::Log("quit to menu");
	CWorldManager::LoadWorld(new CWorld_Game(0));
}

void PauseMenu::QuitToDesktop()
{
	Debug::Log("quit to desktop");
	PostQuitMessage(1);
}

void PauseMenu::Update(float deltaTime)
{
	CWidget_Canvas::Update(deltaTime);
	if (Inputs::InputManager::IsKeyReleased(Inputs::InputManager::Escape))
	{
		if (isPaused)
		{
			ResumeGame();
		}
		else
		{
			PauseGame();
		}
	}
}
