// this short program will show the endianness of the computer
#include <stdio.h>
union myUnion {
	int x;
	float f;
	char a[4];
};

int main(void) {
	union myUnion m;
	m.x = 0x0000000D;
	printf("%d\n", 0123);
	printf("%d\n", 0b1010011);
	printf("%d\n", 0x53);
	printf("%d\n", 'S');
	printf("%d\n", m.x);
	if (m.a[0] == 0x0A) printf("big endian\n");
	if (m.a[0] == 0x0D) printf("little endian\n");
	m.f = 0.15625;
	for (int i = 0; i < 4; i++) printf("%02x", m.a[i]);
	printf("\n");
}