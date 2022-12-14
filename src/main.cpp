#include <ncurses.h>

#include "game_engine.hpp"

using namespace std;

int main()
{
	int max_y, max_x;
	unsigned int mistakes;
	unsigned long long duration_time;

	/////////////////////////// FOR TESTING ///////////////////////////////////////
    string str = "   Hello World    this is a testing \n\n\n\n for this  \t\t\t project, this is a testing for writing words on the given board and testing its functionality and so and so and so";
	////////////////////////// END OF TESTING ////////////////////////////////////

	initscr();
	noecho();
	curs_set(0);

	getmaxyx(stdscr, max_y, max_x);

	WINDOW* win = newwin(max_y, max_x, 0, 0);

	box(win, 0, 0);

	game_engine *ptr = new game_engine(win, str);
	mistakes = ptr->start_game();
	duration_time = ptr->get_duration_time_millisec();

	wgetch(win);

	endwin();
	return 0;
}
