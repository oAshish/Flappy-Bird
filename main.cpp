#include<SFML/Graphics.hpp>
#include"Globals.h"
#include"Game.h"
int main() {

	sf::RenderWindow win(sf::VideoMode(Win_width, Win_height), "Flappy Bird");
	Game game(win);
	game.startgameloop();


		return 0;
}
