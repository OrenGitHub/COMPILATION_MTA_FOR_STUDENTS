#include <stdio.h>

int main(int argc, char **argv)
{
	const int i = 4;
	int *p = ((int *) &i);
	*p = 800;
	
	printf("%d\n",i);
	return 0;
}
