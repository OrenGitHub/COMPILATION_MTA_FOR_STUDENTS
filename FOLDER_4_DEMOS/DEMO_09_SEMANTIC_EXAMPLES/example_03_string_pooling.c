#include <stdio.h>

int main(int argc, char **argv)
{
	const char *s1 = "table";
	const char *s2 = "table";

	if (s1>s2) printf("s1>s2\n");
	if (s1<s2) printf("s1<s2\n");

	return 0;
}
