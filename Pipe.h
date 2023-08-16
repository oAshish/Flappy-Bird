#pragma once
#include<SFML/Graphics.hpp>

class Pipe
{

public:
	Pipe(int);
	sf::Texture pipeup, pipedown;
	static void loadtexture();
	
};

