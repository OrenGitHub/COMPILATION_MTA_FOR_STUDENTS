typedef struct {
	int a;
	int b;
	int c;
} Person;

void foo(int a, int b, int c)
{
	int d = 0x44444444;
	int e = 0x55555555;
	Person *p = (Person *) malloc(sizeof(*p));
	int f = 0x66666666;

	a = 0x77777777;
	b = 0x88888888;
	c = 0x99999999;

	d = 0xaaaaaaaa;
	e = 0xbbbbbbbb;
	f = 0xeeeeeeee;

	p->a = 0x15151515;
	p->b = 0x26262626;
	p->c = 0x37373737;
}

int main(int argc, char **argv)
{
	int a = 0x11111111;
	int b = 0x22222222;
	int c = 0x33333333;

	foo(a, b, c);
}