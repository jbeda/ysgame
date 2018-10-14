#include "numbers.h"
int IsInRange(int number, int center, int range) {
	if (number > (center - (range / 2)) && number < (center + (range / 2)))
		return 1;
	return 0;
}