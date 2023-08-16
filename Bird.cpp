#include "Bird.h"
#include "Globals.h"

Bird::Bird() :
	gravity(20),
	h_velocity(350),
	counter(0),	
	switch_bird(0),
	
	shouldfly(true) 
{	//image load of bird
	birdtexture[0].loadFromFile("assets/birdup.png");
	birdtexture[1].loadFromFile("assets/birddown.png");
	

	//to show loaded image
	birdsprite.setTexture(birdtexture[0]);
	
	birdsprite.setScale(scalefactor, scalefactor);

	
}
void Bird::setfly(bool shouldfly)
{
	this->shouldfly = shouldfly;
}
void Bird::update(sf::Time& dt)
{
	if (birdsprite.getGlobalBounds().top < 548&&shouldfly) {
		if (counter == 5) {
			birdsprite.setTexture(birdtexture[switch_bird]);
			if (switch_bird == 1) {
				switch_bird = 0;

			}
			else {
				switch_bird = 1;
			}
			counter = 0;
		}
		counter++;
		v_velocity += gravity * dt.asSeconds();
		birdsprite.move(0, v_velocity);

		if (birdsprite.getGlobalBounds().top < 0) {

			birdsprite.setPosition(100, 0);
		}

	}
	else {
		resetbirdposition();
	}
		
	
    }
float Bird::getrightpoint()
{
	return birdsprite.getGlobalBounds().left + birdsprite.getGlobalBounds().width;
}

void Bird::flapbird(sf::Time&dt)
{
	v_velocity=-h_velocity * dt.asSeconds();
}

void Bird::resetbirdposition()
{
	birdsprite.setPosition(100.f, 100.f);
	v_velocity = 0;
}
