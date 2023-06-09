#include <iostream>
#include <locale>
#include "Auxil.h"

#define CYCLE 2500000

using namespace std;
using namespace auxil;

int fact(int num);

int main()
{
	start();
	cout << dget(1, 100);

	double  av1 = 0, av2 = 0;
	clock_t  t1 = 0, t2 = 0;

	setlocale(LC_ALL, "rus");

	start();                          // старт генерации 
	t1 = clock();                            // фиксация времени 
	for (int i = 0; i < CYCLE; i++)
	{
		av1 += (double)auxil::iget(-100, 100); // сумма случайных чисел 
		av2 += auxil::dget(-100, 100);         // сумма случайных чисел 
	}
	t2 = clock();                            // фиксация времени 


	cout << endl << "количество циклов:         " << CYCLE;
	cout << endl << "среднее значение (int):    " << av1 / CYCLE;
	cout << endl << "среднее значение (double): " << av2 / CYCLE;
	cout << endl << "продолжительность (у.е):   " << (t2 - t1);
	cout << endl << "                  (сек):   "
		<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
	cout << endl;

	start();
	t1 = clock();
	int result = fact(15);
	cout << "Factorial 15: " << result;
	t2 = clock();
	cout << endl << "продолжительность (у.е):   " << (t2 - t1);
	cout << endl << "                  (сек):   "
		<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
	cout << endl;

	return 0;
}

int fact(int num)
{
	if (num < 0)
	{
		return 0;
	}

	if (num == 0)
	{
		return 1;
	}

	return num * fact(num - 1);
}