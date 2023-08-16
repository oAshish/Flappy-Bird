#include "Game.h"
#include"Globals.h"
#include"Bird.h"
Game::Game(sf::RenderWindow& window) :
win(window),
is_enter(false),
run_game(true)
{    
	win.setFramerateLimit(60);
	//background
	bg_texture.loadFromFile("assets/bg.png");
	bg_sprite.setTexture(bg_texture);
	bg_sprite.setScale(scalefactor, scalefactor);
	bg_sprite.setPosition(0.f, -250.f);
	 

	//ground1
	ground_texture.loadFromFile("assets/ground.png");
	ground_sprite1.setTexture(ground_texture);
	ground_sprite1.setPosition(0.f, 578.f);
	ground_sprite1.setScale(scalefactor, scalefactor); 

	//ground2
	ground_sprite2.setTexture(ground_texture);
	ground_sprite2.setPosition(ground_sprite1.getGlobalBounds().width, 578.f);
	ground_sprite2.setScale(scalefactor, scalefactor);

}

 void Game::startgameloop() {
	 


	 sf::Clock clock;
	 //game loop
	while (win.isOpen()) {
		sf::Time dt = clock.restart();
		sf::Event event;
		//event loop
		while (win.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {

				win.close();
			}
			if (event.type == sf::Event::KeyPressed&& run_game) {

				if (event.key.code == sf::Keyboard::Enter && !is_enter) {
					is_enter = true;
					bird.setfly(true);

				}
				if (event.key.code == sf::Keyboard::Space && is_enter) {
					bird.flapbird(dt);
				}
				

			}
		}
		draw();
		moveground(dt);
		bird.update(dt);

		//win.clear(sf::Color::Blue);
		//to set the background color.
		
			win.display();

		

	}
	
 

}
 void Game::draw()
 {
	 win.draw(bg_sprite);
	 win.draw(ground_sprite1);
	 win.draw(ground_sprite2);
	 win.draw(bird.birdsprite);
 }
 void Game::moveground(sf::Time &dt)
 {
	 ground_sprite1.move(-move_speed * dt.asSeconds(), 0.f);
	 ground_sprite2.move(-move_speed * dt.asSeconds(), 0.f);
	 if (ground_sprite1.getGlobalBounds().left + ground_sprite1.getGlobalBounds().width < 0) {
		 ground_sprite1.setPosition(ground_sprite2.getGlobalBounds().left + ground_sprite2.getGlobalBounds().width, 578.f);
	 }
	 if (ground_sprite2.getGlobalBounds().left + ground_sprite2.getGlobalBounds().width < 0) {
		 ground_sprite2.setPosition(ground_sprite1.getGlobalBounds().left + ground_sprite1.getGlobalBounds().width, 578.f);
	 }
		 
 }
