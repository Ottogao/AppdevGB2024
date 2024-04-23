#include "appdev.h"
#include <stdlib.h>
#include <time.h>

combo minmax() {
	combo ret;
	srand((unsigned)time(NULL));
	ret.min = rand() % 31 - 20;		// random number -20 to 10
	ret.max = rand() % 31 + 15;		// random number 15 to 45
	return ret;
}