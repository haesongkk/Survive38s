#include "Header.h"
#include "Framework.h"

#include "Time.h"
#include "Input.h"
#include "Sound.h"
#include "Render.h"
#include "Scene.h"

bool isQuit = false;

void Initialize()
{
	InitInput();
	InitTime();
	InitRender();
	InitSound();
	InitScene();
}

void Loop()
{
	while (!isQuit)
	{
		UpdateInput();
		UpdateTime();
		UpdateSound();
		UpdateRender();
		UpdateScene();
	}
}

void Quit()
{
	isQuit = true;
}


void Finalize()
{
	FinalInput();
	FinalTime();
	FinalSound();
	FinalRender();
	FinalScene();
}

