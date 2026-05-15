// struct dez6
// {
// 	long a;
// 	long b;
// }

#include <termios.h>
#include <stdio.h>

int main()
{
	// sizeof(struct dez6);


	long b[2];

	b[0] = 0x1B4A325B1B485B1B;
	b[1] = 0x20756C25004A335B;

	printf("%s", (char *)b);
	return 0;
}
