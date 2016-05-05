#ifndef _GAMESTATE_H
#define _GAMESTATE_H

// forward declarations
// Hint to compiler that this is defined elsewhere
// Main reason, decrease compile time - when other 
// files #include this
class Input;

class GameState
{
public:
	//Constructor
	GameState();
	~GameState();

	void Initialise(Input* input);
	void Update(float dt);

	

	



private:
	Input* m_input;



	//Texture

	//Sprites? Does this class need to know about 
	//   sprites or do the tanks need to know about them?
	//   (Who owns sprites)
	// Memory Management and Cleaning

	//Player tank
	//List of enemy tanks






};
















#endif