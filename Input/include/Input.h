#ifndef INPUT
#define INPUT

#include <vector>
#include <map>
#include <functional>

struct SDL_KeyboardEvent;


class Input
{
public:
	Input();
	~Input();
	Input(const Input& other) = delete;
	Input(Input&& other) = delete;
	Input& operator=(const Input& other) = delete;
	Input& operator=(Input&& other) = delete;

	void HandleKeyUpEvent(const SDL_KeyboardEvent& key);
	void HandleKeyDownEvent(const SDL_KeyboardEvent& key);

	unsigned int RegisterFunction(std::function<void()> function);
	void MapKeyboardFunction(unsigned int scanCode, unsigned int functionId, bool onKeyUp = true);

private:

	std::vector<std::function<void()>> _registeredFunctions;
	std::map<unsigned int, unsigned int> _keyboardDownMappedFunctions;
	std::map<unsigned int, unsigned int> _keyboardUpMappedFunctions;
};
#endif