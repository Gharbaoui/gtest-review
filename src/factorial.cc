#include "factorial.h"

int	fact_rec(int n)
{
	if (n > 0)
		return n * fact(n - 1);
	else
		return 1;
}
int	fact(int n)
{
	if (n < 0)
		return -1;
	return fact_rec(n);
}
