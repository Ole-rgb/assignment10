#include "base.h"


//Ist dieser edit gepushed???


/**
List of objects on the left river bank.
*/
List left;

/**
List of objects on the right river bank.
*/
List right;

/**
List of objects in the boat. The boat has a capacity of one object only.
*/
List boat;

/**
The boat may either be at the left or right river bank. We don't care for the transition (boat crossing the river).
*/
enum Position {
	LEFT, RIGHT
};

/**
Current boat position.
*/
enum Position position;

void print_situation(void) {
	sl_print(left);
	if (position == RIGHT) prints("     ");
	sl_print(boat);
	if (position == LEFT)  prints("     ");
	sl_println(right);	
}

void finish(void) {
	exit(0);
	// todo: implement
}

void evaluate_situation(void) {
	// todo: implement
}

bool starts_with(String element, int index, String x) {
	return s_starts_with(element, x);
}

void play_wolf_goat_cabbage(void) {
	// todo: implement
}

int main(void) {
	report_memory_leaks(true);
	play_wolf_goat_cabbage();
	return 0;
}
