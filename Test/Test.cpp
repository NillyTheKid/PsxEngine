#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "Engine.h"
#include "Rendering.h"
#include "Input.h"
#include "ECS.h"
#pragma warning(disable:26451)
#include <SDL.h>
#include <functional>
#include "Window.h"

#include "Scene.h"
#include "Entity.h"
#include "PrintComponent.h"
#include "TestComponent.h"
#include "TestSystem.h"

#include <iostream>

namespace
{
	bool toolTest = false;

	void PrintSpace()
	{
		std::cout << "Space\n";
	}

	void PrintStartLeft()
	{
		std::cout << "Start Left\n";
	}

	void PrintStopLeft()
	{
		std::cout << "Stop Left\n";
	}
}

int main(int argc, char* argv[])
{
	//Have this in separate scope so all destructors are called before dumping memory leaks
	{
		Engine engine{};
		Rendering* rendering = engine.CreateRenderer(!toolTest);
		Input* input = engine.CreateInput();
		ECS* ecs = engine.CreateEcs();

		//Register input
		{
			auto spaceFuncId = input->RegisterFunction(std::bind(&PrintSpace));
			auto startLeftFuncId = input->RegisterFunction(std::bind(&PrintStartLeft));
			auto stopLeftFuncId = input->RegisterFunction(std::bind(&PrintStopLeft));

			input->MapKeyboardFunction(SDL_SCANCODE_SPACE, spaceFuncId);
			input->MapKeyboardFunction(SDL_SCANCODE_A, startLeftFuncId, false);
			input->MapKeyboardFunction(SDL_SCANCODE_LEFT, startLeftFuncId, false);
			input->MapKeyboardFunction(SDL_SCANCODE_A, stopLeftFuncId, true);
			input->MapKeyboardFunction(SDL_SCANCODE_LEFT, stopLeftFuncId, true);
		}

		auto testWindow = rendering->createWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_OPENGL);
		testWindow->setBackgroundColour(Colour(0.0f, 0.0f, 0.0f, 1.0f));
		rendering->RegisterWindowCallback(testWindow, std::bind(&Engine::Quit, &engine));

		rendering->createGlContext(testWindow);

		if (toolTest)
		{
			auto testWindow2 = rendering->createWindow("Test but small", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 200, 500, SDL_WINDOW_OPENGL);
			testWindow2->setBackgroundColour(Colour(1.0f, 0.0f, 0.0f, 1.0f));
			rendering->RegisterWindowCallback(testWindow2, std::bind(&Window::CloseWindow, testWindow2));
		}

		TestSystem* testSystem = ecs->CreateSystem<TestSystem>();

		Scene testScene{};
		Entity* testEntity = testScene.CreateEntity();
		TestComponent* testComp = testEntity->CreateComponent<TestComponent>();
		testComp->SetData(5);
		testEntity->CreateComponent<PrintComponent>(); //Shouldnt have to temp store the comp if it doesnt require any interactions

		Scene testScene2{};
		auto ent2 = testScene2.CreateEntity();
		auto comp2 = ent2->CreateComponent<TestComponent>();
		testScene2.CreateEntity();

		auto testSceneId = ecs->LoadScene(testScene);
		auto testScene2Id = ecs->LoadScene(testScene2);

		ecs->UnloadScene(testScene2Id);

		ecs->LoadScene(testScene2);

		engine.Run();
	}

	_CrtDumpMemoryLeaks();

	return 0;
}