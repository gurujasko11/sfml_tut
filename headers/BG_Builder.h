#ifndef BG_BUILDER_H
#define BG_BUILDER_H

#include "Background.h"

class BG_Builder
{
public:
		void add_point(int x, int y);

		BG_Builder();
		BG_Builder(std::list<std::pair<int, int>>& path);

		Background build();
private:
		std::list<std::pair<int,int>> path;
		int cell_size = 32;
		int BG_X = 16;
		int BG_Y = 16;
};

#endif //BG_BUILDER_H
