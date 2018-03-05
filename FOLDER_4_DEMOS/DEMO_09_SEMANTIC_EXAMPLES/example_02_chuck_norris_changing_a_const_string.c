#include <stdio.h>

int main(int argc, char **argv)
{
	const char *s = "LosPollosHermanos";
	char *p = ((char *) s);
	*p = 'D';
	
	printf("%s\n",p);
	return 0;
}
