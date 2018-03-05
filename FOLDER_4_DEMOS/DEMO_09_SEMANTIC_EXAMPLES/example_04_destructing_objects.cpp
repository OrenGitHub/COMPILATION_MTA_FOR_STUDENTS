#include <stdio.h>
struct Tree
{
	int serial;
	
	~Tree(){printf("\n\n>> Destructing T(serial=%d)\n\n",serial);}
};

int main(int argc, char **argv)
{
	if (argc < 5)
	{
		Tree t;
		t.serial = 70;
		if (argc < 3)
		{
			goto LABEL;
		}
		t.serial = 100;
	}
	return 0;
LABEL:
	return 0;
}
