#pragma once
#ifndef _BULLET_H_
#define _BULLET_H_

#include <SFML/Graphics.hpp>

class Tank;

class Bullet
{
public:
	Bullet();
	~Bullet();



	void Init(sf::Vector2f position, sf::Sprite* sprite);
	void SetSprite(sf::Sprite* sprite);

	//sf::RenderWindow Draw(sf::RenderWindow window);
	void SetPosition(sf::Vector2f position);
	const sf::Vector2f GetPosition();
	void Update(float dt, sf::Vector2f position, sf::Vector2f direction);
	const sf::RectangleShape Bullet::Bounds();
	void Bullet::SetBCol();
	void Draw(sf::RenderWindow* window);
	void Launch();

	//States
	enum BState { STATE_NULL, LOADED, INFLIGHT, HIT, EMPTY };
	BState m_bulletstate;
	void StateLoaded(sf::Vector2f position, sf::Vector2f direction);
	void StateInFlight(float dt, sf::Vector2f position, sf::Vector2f direction);
	void StateHit();
	void StateEmpty();



	//

private:
	sf::Vector2f m_position;
	sf::Vector2f m_moveDirection;
	sf::Sprite* m_sprite;
	float m_move;
	sf::RectangleShape m_boundingBox;
	sf::RenderWindow* m_window;
	bool m_inFlight;
	sf::Vector2f m_bulletOrigin;
	sf::Vector2f m_bulletDirection;
	
	
	
	// directional enum

};

#endif