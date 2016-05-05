#ifndef _AURAL_H_
#define _AURAL_H_

#include <SFML/Audio.hpp>

class Aural
{
public:
	Aural();
	~Aural();


	void SetMusicMain(sf::Music* music);
	void SetMusicTitle(sf::Music* music);

	//void Song(sf::Music* music);


private:
	sf::Music* m_music;

};

#endif