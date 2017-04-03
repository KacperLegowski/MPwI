
#include <iostream>

using namespace std;
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

int zwroc(int a, int c, int x, int m)
{
	return (a*x + c) % m;
}
void losuj(float od, float to, int ilosc_losowan, int a, int c, float x, int m)
{
	for (int i = 0; i<ilosc_losowan; i++)
	{
		x = ((zwroc(a, c, x, m) / to)*(to - od)) + od;
		cout << x << endl;
	}

}
int zwroc2(int a, int b, int c, int x, int m)
{
	return (a*x*x + b*x + c) % m;
}
void losuj2(int ilosc_losowan, int *tab, int a, int b, int c, int x, int m)
{
	for (int i = 0; i<ilosc_losowan; i++)
	{
		tab[x]++;
		x = zwroc2(a, b, c, x, m);
	}
	for (int i = 0; i<32; i++)
	{
		cout << tab[i] << endl;
	}
}

int zwroc3(int x)
{
	bool t1, t2;
	for (int i = 0; i<32; i++)
	{
		t2 = CHECK_BIT(x, 4);
		t1 = CHECK_BIT(x, 17);
		if (t1 == t2)
		{
			x = x << 1;
			return x;
		}
		else
		{
			x = x << 1;
			x++;
			return x;
		}
	}
}
void losuj3(int ilosc_losowan, int *tab, int x)
{
	for (int i = 0; i<ilosc_losowan; i++)
	{
		tab[abs(x % 31)]++;
		x = zwroc3(x);
	}
}
void losuj4(float pocz, float kon, int ilosc_losowan, int* tab, int x) {
	int max_int = 2147483647;
	int max = 150;
	for (int i = 0; i < ilosc_losowan; i++) {
		//tab[abs(x % 31)]++;
		x = zwroc3(x);
		double y = ((double)abs(x%max) / max)*(kon - pocz) + pocz;
		cout << y << endl;
	}
}
int main()
{
	int tablica[32];
	for (int i = 0; i<32; i++)
	{
		tablica[i] = 0;
	}
	losuj4(5.0, 5.5, 255, tablica, 5);
	//losuj3(10000, tablica, 15);
	/*for (int i = 0; i<32; i++)
	{
	cout << i << "\t" <<tablica[i] << endl;;
	}*/
	getchar();
	getchar();
	return 0;
}