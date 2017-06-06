#ifndef SFML_TUT_GAMEH
#define SFML_TUT_GAMEH

#include <chrono>
#include "UserInterface.h"
#include "Stage.h"
#include "WelcomeBoard.h"

class Game {
public:
		enum game_state{
				INITIAL,
				LEVEL_NOT_STARTED,
				LEVEL_STARTED,
				STAGE_FINISHED
		} state;
		WelcomeBoard* welcomeBoard;
		UserInterface* userInterface;
		sf::RenderWindow* window;
		std::chrono::time_point<std::chrono::system_clock> time_of_last_tick = std::chrono::system_clock::now();
		Stage* stage;
		bool rm_turret(Turret* turret);
		Game(sf::RenderWindow* window);
		void play();
		bool can_tick();

};
#endif //SFML_TUT_GAMEH
