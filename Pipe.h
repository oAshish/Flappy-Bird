#pragma once
#include<SFML/Graphics.hpp>
class Pipe
{
public:
	Pipe(float);
	sf::Sprite sprite_up, sprite_down;
	static void loadTextures();
	void update(sf::Time&);
	float getRightBound();

private:
	static sf::Texture pipe_up, pipe_down;
	static int pipe_distance, move_speed;


};

