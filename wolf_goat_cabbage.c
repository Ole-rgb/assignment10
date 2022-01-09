#include "base.h"

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
	switch (position) {
		case RIGHT:	
		if (sl_contains(left, "wolf") && sl_contains(left, "goat")) {
			printf("Wolf eats Goat");
			exit(0);
		}
		else if (sl_contains(left, "goat") && sl_contains(left, "cabbage")) {
			printf("Goat eats Cabbage");
			exit(0);
		}
		case LEFT:
		if (sl_contains(right, "wolf") && sl_contains(right, "goat")) {
			printf("Wolf eats Goat");
			exit(0);
		}
		else if (sl_contains(right, "goat") && sl_contains(right, "cabbage")) {
			printf("Goat eats Cabbage");
			exit(0);
		}
	}

	if (sl_contains(right, "wolf") && sl_contains(right, "cabbage") && sl_contains(right, "goat")) {
		printf("You win!");
		exit(0);
	}
	// todo: implement
}

void evaluate_situation(void) {
	finish();
}

StringOption starts_with(String element, int index, String x) {
	if(s_starts_with(element, x)) {
		return make_string_some(element);
	}
	return make_string_none();
}

bool is_boat_empty(List boat) {
	if(!sl_contains(boat, "goat") && 
	!sl_contains(boat, "cabbage") && 
	!sl_contains(boat, "wolf")) {
		return true;
	}
	return false;
	
}

void play_wolf_goat_cabbage(void) {
	//anfangszustand setzen
	left = sl_of_string("wolf, goat, cabbage");
	right = sl_of_string("");
	boat = sl_of_string("");
	position = LEFT;
	List choice;
	print_situation();
	char ch[8];
	while(!(s_equals(ch, "q"))) {
		scanf("%s", ch);
		String str = s_copy(ch);
		if(s_equals(ch, "l")) {
			position = LEFT;
		}
		else if(s_equals(ch, "r")) {
			position = RIGHT;
		}
		else {
			List auto_completed = sl_choose(left, starts_with, ch);
			//sl_print(auto_completed);
			if(position == LEFT && is_boat_empty(boat)) {
				boat = auto_completed;
			}
		}
		print_situation();
	}
}

int main(void) {
	//report_memory_leaks(true);
	play_wolf_goat_cabbage();
	return 0;
}
