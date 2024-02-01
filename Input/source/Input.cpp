#include "Input.h"
#include <SDL.h>

Input::Input()
	:_registeredFunctions{}
	,_keyboardDownMappedFunctions{}
	,_keyboardUpMappedFunctions{}
{
}

Input::~Input()
{
}

void Input::HandleKeyUpEvent(const SDL_KeyboardEvent& key)
{
	auto it = _keyboardUpMappedFunctions.find(key.keysym.scancode);
	if (it != _keyboardUpMappedFunctions.end())
	{
		_registeredFunctions[it->second]();
	}
}
void Input::HandleKeyDownEvent(const SDL_KeyboardEvent& key)
{
	if (key.repeat == 0)
	{
		auto it = _keyboardDownMappedFunctions.find(key.keysym.scancode);
		if (it != _keyboardDownMappedFunctions.end())
		{
			_registeredFunctions[it->second]();
		}
	}
}

unsigned int Input::RegisterFunction(std::function<void()> function)
{
	_registeredFunctions.push_back(function);

	return _registeredFunctions.size() - 1;
}

void Input::MapKeyboardFunction(unsigned int scanCode, unsigned int functionId, bool onKeyUp)
{
	if (onKeyUp)
	{
		_keyboardUpMappedFunctions[scanCode] = functionId;
	}
	else
	{
		_keyboardDownMappedFunctions[scanCode] = functionId;
	}
}
