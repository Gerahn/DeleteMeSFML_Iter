#include "Tank.h"
#include "Bullet.h"

Tank::Tank()
	: m_sprite(NULL)
	, m_position(sf::Vector2f(0, 0))
	, m_move(500)
	, m_moveDirection(sf::Vector2f(0, 0))
	, m_lastDirection(sf::Vector2f(0, 0))
	, m_boundingBox(sf::Vector2f(50, 50))
	, m_bullet(NULL)
	, m_lBullet(20, NULL)
{

}
Tank::~Tank()
{

}

float Tank::GetTankSpeed()
{
	return m_move;
}


void Tank::Update(float dt)
{
	m_position += m_moveDirection * m_move * dt;
	m_sprite->setPosition(m_position);
	m_lastDirection = m_moveDirection;
	m_moveDirection = sf::Vector2f(0, 0);
	m_boundingBox.setPosition(m_position.x, m_position.y);
}


// Accessors
sf::Drawable* Tank::GetDrawable()
{
	return m_sprite;
}


void Tank::Draw(sf::RenderWindow* window)
{
	window->draw(*m_sprite);
	window->draw(m_boundingBox);
}

//sf::RenderWindow Draw(sf::RenderWindow window)
//{
//	window.draw(m_sprite);
//}


//Create a new function that refers to window.draw
//Why? In main we are having to update the tank delta time and then draw, we could do this in one function


void Tank::SetSprite(sf::Sprite* sprite)
{
	m_sprite = sprite;
}

void Tank::SetPosition(sf::Vector2f position)
{
	m_position = position;
}

const sf::Vector2f Tank::GetPosition()
{
	return m_position;
}

const sf::Vector2f Tank::GetDirection()
{
	return m_lastDirection;
}

const sf::RectangleShape Tank::TankBounds()
{
	return m_boundingBox;
}



void Tank::Init()
{
	//m_boundingBox.setSize(m_sprite->getGlobalBounds().width, m_sprite->getGlobalBounds().height);
	m_boundingBox.setPosition(m_position.x, m_position.y);
	m_boundingBox.setOrigin(25, 25);
	m_boundingBox.setFillColor(sf::Color::Transparent);
	m_boundingBox.setOutlineColor(sf::Color::Green);
	m_boundingBox.setOutlineThickness(3.0f);
}

void Tank::SetECol()
{
	m_boundingBox.setSize(sf::Vector2f(20, 20));
}


//Movement
void Tank::MoveRight()
{
	m_moveDirection = sf::Vector2f(1, 0);
	m_sprite->setRotation(-90);
}

void Tank::MoveLeft()
{
	m_moveDirection = sf::Vector2f(-1, 0);
	m_sprite->setRotation(90);
}

void Tank::MoveUp()
{
	m_moveDirection = sf::Vector2f(0, -1);
	m_sprite->setRotation(180);
}


void Tank::MoveDown()
{
	m_moveDirection = sf::Vector2f(0, 1);
	m_sprite->setRotation(0);
}



void Tank::EquipBullet(Bullet* bullet)
{
	//call attached bullet's "move"
	m_bullet = bullet;
}

void Tank::EquipBulletList(std::list<Bullet*> lbullet, sf::Vector2f position, sf::Sprite* sprite)
{
	m_lBullet = lbullet;

	std::list<Bullet*>::iterator iter = m_lBullet.begin();
	for (iter; iter != m_lBullet.end(); ++iter)
	{
		(*iter)->Init(position, sprite);
	}
}

const Bullet* Tank::GetBullet()
{
	return m_bullet;
}

void Tank::FireCannon()
{
	std::list<Bullet*>::iterator iter = m_lBullet.begin();

	for (iter; iter != m_lBullet.end(); ++iter)
	{
		if ((*iter)->GetBulletState() == Bullet::INFLIGHT)
		{
			continue;
		}
		//if already in flight, will go back to the start


		if ((*iter)->GetBulletState() == Bullet::LOADED)
		{
			(*iter)->Launch();
		}
	}
	
	//As an expansion the tank's cannon could have it's own eject velocity added to the projectile, whereas the projectile could just have weight, and base damage
}