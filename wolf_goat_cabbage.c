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
List normal;
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
	if(position == RIGHT) {
		if (sl_contains(left, "wolf") && sl_contains(left, "goat")) {
			printf("i am right Wolf eats Goat\n");
			exit(0);
		}
		else if (sl_contains(left, "goat") && sl_contains(left, "cabbage")) {
			printf("i am right Goat eats Cabbage\n");
			exit(0);
		}
	}
	if(position == LEFT) {
		if (sl_contains(right, "wolf") && sl_contains(right, "goat")) {
			printf("Wolf eats Goat\n");
			exit(0);
		}
		else if (sl_contains(right, "goat") && sl_contains(right, "cabbage")) {
			printf("Goat eats Cabbage\n");
			exit(0);
		}
	}

	if (sl_contains(right, "wolf") && sl_contains(right, "cabbage") && sl_contains(right, "goat")) {
		printf("You win!\n");
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

bool is_it_empty(List it) {
	if(!sl_contains(it, "goat") && 
	!sl_contains(it, "cabbage") && 
	!sl_contains(it, "wolf")) {
		return true;
	}
	return false;
	
}

void play_wolf_goat_cabbage(void) {
	//anfangszustand setzen
	normal = sl_of_string("wolf, goat, cabbage");
	left = sl_of_string("wolf, goat, cabbage");
	right = sl_of_string("");
	boat = sl_of_string("");
	position = LEFT;
	print_situation();
	char ch[8];
	int index;
	String ac_str;
	List auto_completed;
	while(!(s_equals(ch, "q"))) {
		scanf("%s", ch);
		if(s_equals(ch, "l")) {
			position = LEFT;
		}
		else if(s_equals(ch, "r")) {
			position = RIGHT;
		}
		else {
			auto_completed = sl_choose(normal, starts_with, ch);
			ac_str = sl_get(auto_completed, 0);
			//sl_print(auto_completed);
			if(position == LEFT && is_it_empty(boat) && !is_it_empty(left)) {
				if((index = sl_index(left, ac_str)) > -1) {
					sl_remove(left, index);
					boat = auto_completed;
				}
			}
			
			else if(position == LEFT && !is_it_empty(boat)) {
				//String ac_str = sl_get(auto_completed, 0);
				if((index = sl_index(boat, ac_str)) > -1) {
					sl_remove(boat, index);
					sl_append(left, sl_get(auto_completed, 0));				
				}
			}

			else if(position == RIGHT && is_it_empty(boat)) {
				if((index = sl_index(right, ac_str)) > -1) {
					sl_remove(right, index);
					sl_append(boat, ac_str);
				}
			}
			
			else if(position == RIGHT && !is_it_empty(boat)) {
				if((index = sl_index(boat, ac_str)) > -1) {
					sl_remove(boat, index);
					sl_append(right, ac_str);
				}
			}
			
		}
		print_situation();
		evaluate_situation();
	}
}

int main(void) {
	//report_memory_leaks(true);
	play_wolf_goat_cabbage();
	return 0;
}
