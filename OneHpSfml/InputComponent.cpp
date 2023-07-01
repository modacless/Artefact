#include "InputComponent.h"

#include <iostream>

InputComponent::InputComponent(KeyInput keys, float timeBeforeConsumeBuffer)
{
	input = keys;
	timeToConsume = timeBeforeConsumeBuffer;
	
}


void InputComponent::Render(sf::RenderWindow& window)
{
}

void InputComponent::Update(float deltaTime)
{
	UpdateInputBuffer(inputBuffer,deltaTime);
}


void InputComponent::UpdateEvent(sf::Event event)
{
	if(event.KeyPressed)
	{
		const auto it = std::find_if(begin(input.mapBufferKeys), end(input.mapBufferKeys), [&event](InputBuffer buffer) { return buffer.key == event.key.code; });
		if(it != input.mapBufferKeys.end())
		{
			AddInputToBuffer(*it);
		}

	}
}

void InputComponent::Debug(float deltaTime)
{
	if(GetInputPressed(sf::Keyboard::Space))
	{
		std::cout << "Space";
	}

}

void InputComponent::AddInputToBuffer(InputBuffer key)
{
	inputBuffer.push_back(key);
}


bool InputComponent::GetInputPressed(sf::Keyboard::Key key)
{
	for (auto it = inputBuffer.begin(); it != inputBuffer.end(); ++it)
	{
			switch (it->inputType)
			{

			case EInputType::Buffer:
				if (it->key == key)
				{
					return true;
				}
				break;

			case EInputType::Coyote:

				break;

			case EInputType::BufferCoyote:
				if(it->key == key)
				{
					return true;
				}

			default:

				break;
			}

	}

	return false;
}

void InputComponent::SetBufferConsumed(sf::Keyboard::Key key)
{
	for (auto it = inputBuffer.begin(); it != inputBuffer.end(); ++it)
	{
		if(it->key == key)
		{
			it->isConsumed = true;
		}

	}

}


void InputComponent::UpdateInputBuffer(std::vector<InputBuffer>& inputBuffer, float deltaTime)
{

	if(!inputBuffer.empty())
	{
		inputBuffer.erase(std::remove_if(inputBuffer.begin(), inputBuffer.end(), [deltaTime](InputBuffer& buffer)
			{
				buffer.bufferTimeCounter -= deltaTime;
				return buffer.bufferTimeCounter < 0 || buffer.isConsumed;
			}), inputBuffer.end());
	}


}
