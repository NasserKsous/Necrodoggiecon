#pragma once
#include "Cerberus/Core/UI/CWidget_Canvas.h"
class MainMenu :
    public CWidget_Canvas
{


    virtual void InitialiseCanvas();


public:
    MainMenu();

    void TestButtonPressed();

};

