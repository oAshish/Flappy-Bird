#pragma once
#include<SFML/Graphics.hpp>
class Bird
{
private:
	sf::Texture texture[2];
	const int gravity ;
	const int flap_speed ;
	float velocity_y;
	int anim_counter, texture_switch;
	bool should_fly;

public:
	sf::Sprite bird_sprite;
	Bird();
	void setShouldfly(bool);
	void flapBird(sf::Time &dt);
	void resetbirdposition();
	void update(sf::Time&);
	float getrightbound();



};

