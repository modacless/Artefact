#pragma once
#include "Component.h"
#include <cassert>


enum class EInputType
{
	Buffer,
	Coyote,
	BufferCoyote,
};

class InputBuffer
{
public:
	sf::Keyboard::Key key;
	EInputType inputType;

	//Time while it can be use
	float coyoteTime;
	float coyoteTimeCounter;

	//Buffer time before destroy
	float bufferTime;
	float bufferTimeCounter;

	//Check if already true
	bool isConsumed = false;

	InputBuffer();
	InputBuffer(sf::Keyboard::Key key, float timeToLive, EInputType typeOfInput = EInputType::Buffer)
	{
		this->key = key;
		this->bufferTimeCounter = timeToLive;
		this->bufferTime = timeToLive;

		inputType = typeOfInput;
	}

};


struct InGameKeys
{
	sf::Keyboard::Key right;
	sf::Keyboard::Key left;
	sf::Keyboard::Key down;
	sf::Keyboard::Key up;

	sf::Keyboard::Key jump;
};

struct KeyInput
{

public:
	std::vector<InputBuffer> mapBufferKeys;

};

struct PlayerInput : KeyInput
{
	InGameKeys keys;
	PlayerInput()
	{
		keys = InGameKeys();
		keys.left = sf::Keyboard::Q;
		keys.right = sf::Keyboard::D;
		keys.up = sf::Keyboard::Z;
		keys.down = sf::Keyboard::S;
		keys.jump = sf::Keyboard::Space;

		mapBufferKeys.emplace_back(InputBuffer(keys.jump,1.f, EInputType::Buffer));
	};
};


class InputComponent : public IComponent
{

public:
	//Base component
	InputComponent(KeyInput keys, float timeBeforeConsumeBuffer);


	void Render(sf::RenderWindow& window) override;
	void Update(float deltaTime) override;

	void UpdateEvent(sf::Event event) override;

	void Debug(float deltaTime) override;

	//Input Buffer Management
	void AddInputToBuffer(InputBuffer key);

	//Get input from buffer
	bool GetInputPressed(sf::Keyboard::Key key); //Can be a bit confusing need to WIP

	void SetBufferConsumed(sf::Keyboard::Key key);

protected:

	KeyInput input;
	std::vector<InputBuffer> inputBuffer;
	float timeToConsume;

	void UpdateInputBuffer(std::vector<InputBuffer>& inputBuffer, float deltaTime);

private:

	float actualTimeToConsume;

	//Buffer Management
	template <typename V>
	void PopFront(V& v)
	{
		assert(!v.empty());
		v.erase(v.begin());
	}

};

