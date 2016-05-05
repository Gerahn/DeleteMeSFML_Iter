#include "Aural.h"


Aural::Aural()
	:m_music(NULL)
{

}

Aural::~Aural()
{

}


void Aural::SetMusicMain(sf::Music* music)
{
	m_music = music;
	if (!m_music->openFromFile("norseng8.ogg"))
	{
		return;
	}
	m_music->stop();
	m_music->setLoop(true);
	m_music->setVolume(30);
	m_music->play();
}

void Aural::SetMusicTitle(sf::Music* music)
{
	m_music = music;
	if (!m_music->openFromFile("OneSummersDay.ogg"))
	{
		return;
	}
	m_music->stop();
	m_music->setLoop(true);
	m_music->setVolume(30);
	m_music->play();
}

/*
 The class has pointers to a music object - it's the scaffolding
 It needs the music object instanced in main (as a pointer) to "fuel" this scaffolding
 */


//void Aural::Song(sf::Music* music)
//{
//	//if (!music.openFromFile("norseng8.ogg"))
//	//{
//	//	return;
//	//}
//
//
//}

