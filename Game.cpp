#include "Game.h"
#include"Globals.h"
#include<sstream>
Game::Game(sf::RenderWindow& window): win(window),is_enter_pressed(false),run_game(true),pipe_counter(71),
pipe_spawn_time(70),score(0),start_monitoring(false)
{
	win.setFramerateLimit(60);
	bg_texture.loadFromFile("assets/bg.png");
	bg_sprite.setTexture(bg_texture);
	bg_sprite.setScale(scale_factor, scale_factor);
	bg_sprite.setPosition(0.f, -250.f);


	ground_texture.loadFromFile("assets/ground.png");
	ground_sprite1.setTexture(ground_texture);
	ground_sprite2.setTexture(ground_texture);


	ground_sprite1.setScale(scale_factor, scale_factor);
	ground_sprite2.setScale(scale_factor, scale_factor);

	ground_sprite1.setPosition(0, 568);
	ground_sprite2.setPosition(ground_sprite1.getGlobalBounds().width, 568);

	font.loadFromFile("assets/arial.ttf");
	restart_text.setFont(font);
	restart_text.setCharacterSize(35);
	restart_text.setFillColor(sf::Color::Black);
	restart_text.setPosition(230, 650);
	restart_text.setString("Play Again");

	
	score_text.setFont(font);
	score_text.setCharacterSize(35);
	score_text.setFillColor(sf::Color::Black);
	score_text.setPosition(10, 10);
	score_text.setString("Score : 0");

	Pipe::loadTextures();
}

void Game::doProcessing(sf::Time& dt)
{
	if (is_enter_pressed)
	{
		moveGround(dt);

		if (pipe_counter > pipe_spawn_time)
		{
			pipes.push_back(Pipe(dist(rd)));
			pipe_counter = 0;
		}
		pipe_counter++;

		for (int i = 0; i < pipes.size(); i++)
		{
			pipes[i].update(dt);
			if (pipes[i].getRightBound() < 0) {

				pipes.erase(pipes.begin() + i);
			}
		}

		checkcollisions();
	    check_scores();


	}
	
	bird.update(dt);
	//moveGround(dt);
}
void Game::startgameloop()
{
	sf::Clock clock;
	while (win.isOpen()) {

		sf::Time dt = clock.restart();
		sf::Event event;
		while (win.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
			{
				win.close();
			}
			if (event.type == sf::Event::KeyPressed && run_game)
			{
				if (event.key.code == sf::Keyboard::Enter && !is_enter_pressed)
				{
					is_enter_pressed = true;
					bird.setShouldfly(true);
				}
				if (event.key.code == sf::Keyboard::Space && is_enter_pressed)
				{
					bird.flapBird(dt);

				}
			}
		
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !run_game)
			{

				if (restart_text.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				{
					restart_game();

				}
				
			}


		}


	
		doProcessing(dt);
		draw();
		win.display();
	}
}
void Game::checkcollisions()
{
	if (pipes.size() > 0)
	{
		if (pipes[0].sprite_down.getGlobalBounds().intersects(bird.bird_sprite.getGlobalBounds()) ||
			pipes[0].sprite_up.getGlobalBounds().intersects(bird.bird_sprite.getGlobalBounds()) ||
			bird.bird_sprite.getGlobalBounds().top >= 530)
		{
			is_enter_pressed = false;
			run_game = false;
		}
	}
}
void Game::draw()

{
	win.draw(bg_sprite);
	for (Pipe& pipe : pipes)
	{
		win.draw(pipe.sprite_down);
		win.draw(pipe.sprite_up);

	}
	win.draw(ground_sprite1);
	win.draw(ground_sprite2);
	win.draw(bird.bird_sprite);
	win.draw(score_text);

	if (!run_game)
	{

		win.draw(restart_text);
	}
}
void Game::moveGround(sf::Time& dt)
{
	ground_sprite1.move(-move_speed * dt.asSeconds(), 0.f);
	ground_sprite2.move(-move_speed * dt.asSeconds(), 0.f);

	if (ground_sprite1.getGlobalBounds().left + ground_sprite1.getGlobalBounds().width < 0)
	{
		ground_sprite1.setPosition(ground_sprite2.getGlobalBounds().left + ground_sprite2.getGlobalBounds().width, 568);
	}


	if (ground_sprite2.getGlobalBounds().left + ground_sprite2.getGlobalBounds().width < 0)
	{
		ground_sprite2.setPosition(ground_sprite1.getGlobalBounds().left + ground_sprite1.getGlobalBounds().width, 568);
	}
}
void Game::restart_game()
{
	bird.resetbirdposition();
	bird.setShouldfly(false);
	run_game = true;
	is_enter_pressed = false;
	pipe_counter = 71;
	pipes.clear();
	score = 0;
	score_text.setString("Score : 0");

}
void Game::check_scores()
{
	if (pipes.size() > 0)
	{
		if (!start_monitoring)
		{
			if (bird.bird_sprite.getGlobalBounds().left > pipes[0].sprite_down.getGlobalBounds().left && bird.getrightbound())
			{
				start_monitoring = true;
			}
		}
		else
		{
			if (bird.bird_sprite.getGlobalBounds().left > pipes[0].getRightBound())
			{
				score++;
				score_text.setString("Score : "+ int_to_string(score/8));
				start_monitoring = false;
			}
		}
	}
}
std::string Game::int_to_string(int num )
{
	std::stringstream ss;
	ss << num;
	return (ss.str());
}
