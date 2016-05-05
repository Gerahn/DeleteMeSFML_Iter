#include "Input.h"
#include "Tank.h"

Input::Input()
	: m_attachTank(NULL)
{

}

Input::~Input()
{

}




void Input::Update(float dt)
{
	if (m_attachTank == NULL)
	{
		return; //return will escape the entire method
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		//call move right function
		m_attachTank->MoveRight();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		//call move left function
		m_attachTank->MoveLeft();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		//call move left function
		m_attachTank->MoveUp();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		//call move left function
		m_attachTank->MoveDown();
	}

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F))
	//{
	//	//call move left function
	//	//m_attachTank->FireCannon(m_attachTank->GetBullet(), dt);
	//
	//	//tank controls what it has equipped
	//	//has to ask tank - call your fire weapon function
	//	//tank says function, fire equipped weapon
	//	//function says fire attached bullet
	//	//bullet calls it's "movement" function
	//}

}




void Input::AttachTank(Tank* tank)
{
	//could do a fancy message etc here 
	m_attachTank = tank;
}
