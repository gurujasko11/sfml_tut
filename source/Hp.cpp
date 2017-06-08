#include "../headers/Hp.h"

Hp* Hp::getInstance(){
	static Hp hp;
	return &hp;
}

