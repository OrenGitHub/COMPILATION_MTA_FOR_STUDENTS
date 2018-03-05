#include <stdio.h>

void CheckPassword(void)
{
	int a = 0x11111111;
	char  buffer[8] = {0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99};
	int b = 0xaaaaaaaa;

	scanf("%s", buffer);

	if ((buffer[0] == 'D') &&
		(buffer[1] == 'r') &&
		(buffer[2] == 'q') &&
		(buffer[3] == '6'))
	{
		printf("inside bank account\n");
	}
}
int main(int argc, char **argv)
{
	int a = 0x11111111;
	int b = 0x22222222;

	CheckPassword();

	system("mspaint");
}