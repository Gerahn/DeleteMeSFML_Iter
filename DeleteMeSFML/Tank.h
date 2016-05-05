#ifndef _TANK_H_
#define _TANK_H_

#include <SFML/Graphics.hpp>
#include <list>

//tank has a function that shoots the bullet
//bullets have speed, a sprite, a bounding box, has a list of bullets to use
//tank takes a bullet, gives it an origin and a direction


//turrent mouse aiming
//mouse position is a sprite that takes the mouse position

//sprite rotation aims at mouse position


//Random Enemy Generation
//Have an array of textures each element with a different image
//New sprites input the function to automatically assign them a sprite

//AI 
//Different kinds of AI
//Assign different kinds of AI to different enemy types
//Aggressor
//Coward
//Patroller
//Sniper (knows where you are at all times, but bullet and fire rate is slow
//e.g swarm type, starts off randomly flying around & running away from the player till it gathers with X amount of others of it's kind, then goes for the player


//Procedural level generation





class Bullet;

class Tank
{
public:
	// Constructors
	Tank();
	~Tank();

	void Init();
	void SetECol();
	void Update(float dt);

	
	//Movement
	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();


	// Accessors
	sf::Drawable* GetDrawable();
	void Draw(sf::RenderWindow* window);
	void SetSprite(sf::Sprite* sprite);

	//sf::RenderWindow Draw(sf::RenderWindow window);

	void SetPosition(sf::Vector2f position);
	const sf::Vector2f GetPosition();
	const sf::Vector2f GetDirection();
	const sf::RectangleShape TankBounds();
	float GetTankSpeed();

	void EquipBullet(Bullet* bullet);
	void Tank::EquipBulletList(std::list<Bullet*> lbullet, sf::Vector2f position, sf::Sprite* sprite);
	const Bullet* GetBullet();
	void FireCannon();


private:
	// Member variables
	sf::Vector2f m_position;
	sf::Vector2f m_moveDirection;
	sf::Sprite* m_sprite;
	float m_move;
	sf::RectangleShape m_boundingBox;
	sf::RenderWindow* m_window;
	Bullet* m_bullet;
	sf::Vector2f m_lastDirection;
	std::list<Bullet*> m_lBullet;


};

#endif