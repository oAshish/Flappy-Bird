#pragma once
#include<SFML/Graphics.hpp>
#include"Bird.h"
class Game
{
public:
	Game(sf::RenderWindow& window);//creating a contructor which takes parameter .......
	sf::RenderWindow& win;         //Its like declaring a win variable of type sf::RenderWindow&
	void startgameloop();   //member function of game.
private:
	sf::Texture bg_texture, ground_texture;
	sf:: Sprite bg_sprite,ground_sprite1,ground_sprite2;
	void draw();
	Bird bird;
	bool is_enter,run_game;
    const int move_speed = 250;
	void moveground(sf::Time &dt);
};

