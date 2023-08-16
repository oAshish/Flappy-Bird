#pragma once
#include<SFML/Graphics.hpp>
class Bird
{
public:
	//sf::Texture birdtexture;
	sf::Sprite birdsprite;
	sf::Texture birdtexture[2];
	Bird();
	void setfly(bool);
	void flapbird(sf::Time &dt);
	void resetbirdposition();
	void update(sf::Time& dt);
	float getrightpoint();
	

private:
	
	const int gravity;
	const int h_velocity;
	float v_velocity;
	int counter, switch_bird;
	bool shouldfly;
	

};

