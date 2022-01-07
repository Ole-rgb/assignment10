#include "base.h"

/**
List of objects on the left river bank.
change made
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
	switch (position) {
		case RIGHT:	
		if (sl_contains(left, "Wolf") && sl_contains(left, "Goat")) {
			printf("Wolf eats Goat");
			exit(0);
		}
		else if (sl_contains(left, "Goat") && sl_contains(left, "Cabbage")) {
			printf("Goat eats Cabbage");
			exit(0);
		}
		case LEFT:
		if (sl_contains(right, "Wolf") && sl_contains(right, "Goat")) {
			printf("Wolf eats Goat");
			exit(0);
		}
		else if (sl_contains(right, "Goat") && sl_contains(right, "Cabbage")) {
			printf("Goat eats Cabbage");
			exit(0);
		}
	}

	if (sl_contains(right, "Wolf") && sl_contains(right, "Cabbage") && sl_contains(right, "Goat")) {
		printf("You win!");
		exit(0);
	}
	// todo: implement
}

void evaluate_situation(void) {
	finish();
}

bool starts_with(String element, int index, String x) {
	return s_starts_with(element, x);
}

void play_wolf_goat_cabbage(void) {
	//anfangszustand setzen
	left = sl_of_string("Wolf, Goat, Cabbage");
	right = sl_of_string("");
	boat = sl_of_string("");
	position = LEFT;
	print_situation();
}

int main(void) {
	//report_memory_leaks(true);
	play_wolf_goat_cabbage();
	return 0;
}
