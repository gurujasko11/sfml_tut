#ifndef SFML_TUT_GAMEH
#define SFML_TUT_GAMEH

#include <chrono>
#include "UserInterface.h"
#include "Stage.h"

class Game {
public:
		UserInterface* userInterface;
		sf::RenderWindow* window;
		std::chrono::time_point<std::chrono::system_clock> time_of_last_tick = std::chrono::system_clock::now();
		Stage* stage;

		Game(sf::RenderWindow* window);
		void play();
		bool can_tick();

};
#endif //SFML_TUT_GAMEH
