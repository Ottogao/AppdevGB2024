#include "screen.h"

void pascal_triangle(int rows) {
	int n, k;
	
	clearScreen();
	for (n = 0; n < rows; n++) {
		setFGcolor(RED + n%7);
		gotoXY(n + 1, 40 - n * 3);
		for (k = 0; k <= n; k++) {
			printf("%6d", nchoosek(n, k));
		}
		printf("\n");
	}
	resetColors();
}

int nchoosek(int n, int k) {
	return factor(n) / factor(k) / factor(n - k);
}

int factor(int m) {
	if (m == 0) return 1;		// 0! = 1
	else return m * factor(m - 1);	// recursion
}