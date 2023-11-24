#include "Bird.h"
#include"Globals.h"
Bird::Bird() :
	gravity(10),
	flap_speed(250),
	anim_counter(0),
	texture_switch(1),
	should_fly(false)
{
	texture[0].loadFromFile("assets/birddown.png");
	texture[1].loadFromFile("assets/birdup.png");

	bird_sprite.setTexture(texture[0]);
	bird_sprite.setScale(scale_factor, scale_factor);
	resetbirdposition();
}
void Bird::update(sf::Time& dt)
{
	if (bird_sprite.getGlobalBounds().top < 538 && should_fly)
	{
		if (anim_counter == 5)
		{
			bird_sprite.setTexture(texture[texture_switch]);
			if (texture_switch)
			{
				texture_switch = 0;
			}
			else
			{
				
				texture_switch = 1;
			}
			anim_counter = 0;
		}
		anim_counter++;
		velocity_y += gravity * dt.asSeconds();
		bird_sprite.move(0, velocity_y);

		if (bird_sprite.getGlobalBounds().top < 0) 
		{
			bird_sprite.setPosition(100, 0);
		}
	}
}
void Bird::flapBird(sf::Time& dt)
{
	velocity_y = -flap_speed * dt.asSeconds();
}
float Bird::getrightbound()
{
	return bird_sprite.getGlobalBounds().left+bird_sprite.getGlobalBounds().width;
}
void Bird::resetbirdposition()
{
	bird_sprite.setPosition(100, 50);
	velocity_y = 0;
}
void Bird::setShouldfly(bool should_fly)
{
	this->should_fly = should_fly;
}
