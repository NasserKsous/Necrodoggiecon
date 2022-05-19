#include "Cerberus/Core/UI/CWidget_Button.h"
#include "Cerberus/Core/Components/CSpriteComponent.h"
#include "Cerberus/Core/Components/CTextRenderComponent.h"
#include "Cerberus/Core/UI/CWidget_Canvas.h"

using namespace std;

CWidget_Button::CWidget_Button()
{
	sprite = AddComponent<CSpriteComponent>();
	sprite->ui = true;
	textRenderer = AddComponent<CTextRenderComponent>();
	ButtonPressedBind = nullptr;
	ButtonReleasedBind = nullptr;
	HoverEndBind = nullptr;
	HoverStartBind = nullptr;
}


void CWidget_Button::SetText(std::string TextBody)
{
	textRenderer->SetText(TextBody);

}

void CWidget_Button::SetSize(Vector2 Size)
{
	sprite->SetSpriteSize(DirectX::XMUINT2(Size.x, Size.y));
	
}

void CWidget_Button::SetTexture(std::string filePath)
{
	sprite->LoadTexture(filePath);
}

void CWidget_Button::Update(float deltaTime)
{
}

void CWidget_Button::OnButtonPressed()
{
	sprite->SetTextureOffset(DirectX::XMFLOAT2(0, SpriteSize.y * 1));
	if (ButtonPressedBind != nullptr) 	ButtonPressedBind();
}

void CWidget_Button::OnButtonReleased()
{
	sprite->SetTextureOffset(DirectX::XMFLOAT2(0, SpriteSize.y * 2));
	if (ButtonReleasedBind != nullptr) ButtonReleasedBind();
}

void CWidget_Button::OnButtonHoverStart()
{
	sprite->SetTextureOffset(DirectX::XMFLOAT2(0, SpriteSize.y * 2));
	if (HoverStartBind != nullptr) HoverStartBind();
	
}

void CWidget_Button::OnButtonHoverEnd()
{
	sprite->SetTextureOffset(DirectX::XMFLOAT2(0, 0));
	if (HoverEndBind != nullptr) 	HoverEndBind();
}

void CWidget_Button::IsButtonFocused(Vector2 mPos)
{

	Vector2 Scale = Vector2(sprite->GetSpriteSize().x, sprite->GetSpriteSize().y);
	Vector2 Pos = Vector2(GetPosition().x, GetPosition().y);
	if (!hasFocus)
	{
		if (mPos.x > Pos.x && mPos.x < Scale.x + Pos.x &&
			mPos.y > Pos.y && mPos.y < Scale.y + Pos.y)
		{
			if (!hasFocus)
			{
				OnButtonHoverStart();

			}
			hasFocus = true;
			
			
			

		}

	}
	else
	{
		if (!(mPos.x > Pos.x && mPos.x < Scale.x + Pos.x &&
			mPos.y > Pos.y && mPos.y < Scale.y + Pos.y))
		{

			if (hasFocus)
			{
				OnButtonHoverEnd();

			}
			hasFocus = false;

			

		}
		

	}
}

void CWidget_Button::ButtonPressed(bool buttonPressed)
{
	if (buttonPressed) OnButtonPressed();
	else OnButtonReleased();
	
}
