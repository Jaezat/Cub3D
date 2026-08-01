#include <main.h>

bool	it_power_two(int num)
{
	if (num <= 0)
		return (false);
	if (num == 2)
		return (true);
	while (!(num % 2))
	{
		num /= 2;
		if (num == 2)
			return (true);
	}
	return (false);
}
