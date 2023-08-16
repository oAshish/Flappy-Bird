#include <SFML/Graphics.hpp>

#include"Globals.h"
#include"Game.h"
#include"Bird.h"



int main(){

sf::RenderWindow window(sf::VideoMode(win_width, win_height),"Flappy BIrd");
//Render window is a class in sfml where we created a window object which take arguement.....
//Render window is a class in sfml where we created a window object which take arguement.....

Game  game(window);
game.startgameloop();



    return 0;
}