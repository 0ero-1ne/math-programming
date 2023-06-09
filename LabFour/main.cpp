#include "strGenerate.h"
#include "Levenshtein.h"
#include "LCS.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

#define LEN_S1 300
#define LEN_S2 200
#define K (1)
#define LEN_PREFIX_S1 (int)(LEN_S1 * (double)K)
#define LEN_PREFIX_S2 (int)(LEN_S2 * (double)K)

int main()
{
	srand((unsigned)time(NULL));
	setlocale(0, "ru");

	char* S1, *S2;
	
	S1 = strGenerate::strGenerate(LEN_S1);
	S2 = strGenerate::strGenerate(LEN_S2);

	cout << "-----------------------String 1-----------------------" <<endl<< S1 << endl;
	cout << "-----------------------String 2-----------------------" <<endl<< S2 << endl;

	clock_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	
	cout << "\n\n";
	
	cout << "Prefix1: " << prefix(S1, LEN_PREFIX_S1) << endl;
	cout << "Prefix2: " << prefix(S2, LEN_PREFIX_S2) << endl;
	cout << endl;
	
	/*cout << endl << "-- Расстояние Левенштейна -----" << endl;
	cout << endl << "--Длина --- Рекурсия -- Дин.програм. ---"
		<< endl;

	int lev = 0, lev_r = 0;
	int sum = 0, sum_r = 0;
	
	for (int i = 0; i < min(LEN_PREFIX_S1, LEN_PREFIX_S2); i++)
	{
		t1 = clock();
		lev = levenshtein_r(i, prefix(S1, LEN_PREFIX_S1), i, prefix(S2, LEN_PREFIX_S2));
		t2 = clock();

		t3 = clock();
		lev_r = levenshtein(i, prefix(S1, LEN_PREFIX_S1), i, prefix(S2, LEN_PREFIX_S2));
		t4 = clock();
		
		cout << right << setw(2) << i << "/" << setw(2) << i
			<< "        " << left << setw(10) << (t2 - t1)
			<< "   " << setw(10) << (t4 - t3) << endl;
		
		sum_r += t2 - t1;
		sum += t4 - t3;
	}

	cout << lev << endl << lev_r << endl;
	cout << sum_r << "\t" << sum << endl << endl;*/

	char X[] = "ABCDFGI", Y[] = "EATUFI";
	cout << endl << "-- вычисление длины LCS для X и Y(рекурсия)";
	cout << endl << "-- последовательность X: " << X;
	cout << endl << "-- последовательность Y: " << Y;

	t1 = clock();

	int s = lcs(
		sizeof(X) - 1,  // длина   последовательности  X   
		"ABCDFGI",       // последовательность X
		sizeof(Y) - 1,  // длина   последовательности  Y
		"EATUFI"       // последовательность Y
	);

	t2 = clock();

	cout << endl << "-- длина LCS: " << s << " --- Время: " << double(t2 - t1)/CLOCKS_PER_SEC << endl;

	char z[100] = "";

	t3 = clock();
	int l = lcsd(X, Y, z);
	t4 = clock();

	cout << endl
		<< "-- наибольшая общая подпоследовательость - LCS(динамическое"
		<< "программирование)" << endl;

	cout << endl << "последовательость X: " << X;
	cout << endl << "последовательость Y: " << Y;
	cout << endl << "                LCS: " << z;
	cout << endl << "          длина LCS: " << l;
	cout << endl << "              Время: " << double(t4 - t3) / CLOCKS_PER_SEC;
	cout << endl;

	return 0;
}