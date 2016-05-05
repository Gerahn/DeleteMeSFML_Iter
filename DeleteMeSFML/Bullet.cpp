#include "Bullet.h"
#include "Tank.h"


#include <stdlib.h>

Bullet::Bullet()
	: m_sprite(NULL)
	, m_position(sf::Vector2f(0, 0))
	, m_move(2000)
	, m_moveDirection(sf::Vector2f(0, -1))
	, m_boundingBox(sf::Vector2f(50, 50))
	, m_inFlight(false)
	, m_bulletOrigin(sf::Vector2f(0, 0))
	, m_bulletDirection(sf::Vector2f(0, 0))
	, m_bulletstate(Bullet::BState::LOADED)
{
	//m_bulletstate = Bullet::BState::LOADED;
}


Bullet::~Bullet()
{
}


void Bullet::SetSprite(sf::Sprite* sprite)
{
	m_sprite = sprite;
}




// Accessors



void Bullet::Draw(sf::RenderWindow* window)
{
	if(m_bulletstate == INFLIGHT)
	{
		window->draw(*m_sprite);
		window->draw(m_boundingBox);
	}
}

//sf::RenderWindow Draw(sf::RenderWindow window)
//{
//	window.draw(m_sprite);
//}


//Create a new function that refers to window.draw
//Why? In main we are having to update the tank delta time and then draw, we could do this in one function



void Bullet::SetPosition(sf::Vector2f position)
{
	m_position = position;
	m_sprite->setPosition(position);
}

const sf::Vector2f Bullet::GetPosition()
{
	return m_position;
}


const sf::RectangleShape Bullet::Bounds()
{
	return m_boundingBox;
}



void Bullet::Init(sf::Vector2f position, sf::Sprite* sprite)
{
	//m_boundingBox.setSize(m_sprite->getGlobalBounds().width, m_sprite->getGlobalBounds().height);
	//m_boundingBox.setPosition(position.x, position.y);

	//sf::Texture bulletTexture;
	//bulletTexture.loadFromFile("bullet.png");
	//sf::Sprite* sprBullet = new sf::Sprite(bulletTexture);
	//Bullet pbullet;
	//pbullet.SetSprite(sprBullet);

	//m_sprite->setPosition(m_position);
	
	m_position = position;
	m_sprite = sprite;
	m_sprite->setPosition(position);
	m_bulletstate = LOADED;
	m_boundingBox.setOrigin(25, 25);
	m_boundingBox.setFillColor(sf::Color::Transparent);
	m_boundingBox.setOutlineColor(sf::Color::Green);
	m_boundingBox.setOutlineThickness(3.0f);
}


//void Bullet::Init(sf::Vector2f position)
//{
//	sf::Texture bullet;
//	bullet.loadFromFile("bullet.png");
//	sf::Sprite sprBullet(bullet);
//	sprBullet.setPosition(position.x, position.y);
//	//m_position += sf::Vector2f(0, -1) * 1000.0f * dt;
//	//if (sprBullet.getPosition().y > 1000)
//	//{
//	//	return;
//	//}
//}




void Bullet::SetBCol()
{
	m_boundingBox.setSize(sf::Vector2f(5, 5));
}



void Bullet::Launch()
{
	if (m_inFlight == false && m_bulletstate == Bullet::LOADED)
	{
		m_bulletOrigin = m_position;
		m_inFlight = true;
		m_bulletstate = Bullet::INFLIGHT;
		//by having everything here it won't keep calling during flight
	}
}


//Switch statement pivoting on enum which calls a function
void Bullet::Update(float dt, sf::Vector2f position, sf::Vector2f direction)
{
	//Have switch statement to call functions from here
	
	switch (m_bulletstate)
	{
		case Bullet::STATE_NULL:
			//Nothing Happens?
			break;
	
		case Bullet::LOADED:
			Bullet::StateLoaded(position, direction);
			//break;
	
		case Bullet::INFLIGHT:
			Bullet::StateInFlight(dt, position, direction);
			//break;
	
		case Bullet::HIT:
			//Explosion Function
			break;
	
		case Bullet::EMPTY:
			//? Empty click sound?
			break;
	}



	// if direction is changed while the bullet is in flight, the direction won't get passed into the next fire (storage or passing problem?)
	

}	

Bullet::BState Bullet::GetBulletState()
{
	return m_bulletstate;
}


//State Functions
void Bullet::StateLoaded(sf::Vector2f position, sf::Vector2f direction)
{
	if (m_inFlight == false)// loaded enum
	{
		m_position = position;
		m_sprite->setPosition(m_position);
		m_boundingBox.setPosition(m_position.x, m_position.y);

		if (direction != sf::Vector2f(0, 0))
		{
			m_bulletDirection = direction;
		}
	}
}



void Bullet::StateInFlight(float dt, sf::Vector2f position, sf::Vector2f direction)
{
	if (m_inFlight == true)
	{
		m_bulletOrigin += m_bulletDirection * m_move * dt;
		m_sprite->setPosition(m_bulletOrigin);
		m_boundingBox.setPosition(m_bulletOrigin);

		if (direction != sf::Vector2f(0, 0))
		{
			m_moveDirection = direction;
		}
	}

	if (m_sprite->getPosition().x > 2000.0f || m_sprite->getPosition().y > 2000.0f || m_sprite->getPosition().x < 0.0f || m_sprite->getPosition().y < 0.0f)
		//could have bounds be window + an amount, then could then lead to enemies who spawn in bounds
	{
		m_position = position;
		m_sprite->setPosition(m_position);

		m_bulletDirection = m_moveDirection;

		m_inFlight = false;
		m_bulletstate = Bullet::LOADED;
	}
}



void Bullet::StateHit()
{


}




void Bullet::StateEmpty()
{


}


//End State Functions



//hit enum


//empty

