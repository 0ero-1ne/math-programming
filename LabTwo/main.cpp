#include "stdafx.h"
#include "Combi.h"
#include <iomanip>
#include "Boat.h"
#include "Auxil.h"

using namespace auxil;

#define N (sizeof(AA)/2)
#define M 3

#define NN (sizeof(v)/sizeof(int))
#define MM 6

int main()
{
	start();

	setlocale(LC_ALL, "rus");

	char AA[][2] = { "A", "B", "C", "D" };
	
	std::cout << "---Генератор множества всех подмножеств---\n";
	std::cout << "Исходное множество: { ";
	
	for (int i = 0; i < sizeof(AA) / 2; i++)
		std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
	
	std::cout << "}";
	std::cout << std::endl << "Генерация всех подмножеств";
	combi::subset s1(sizeof(AA) / 2);         // создание генератора   
	
	__int64 n = s1.getfirst();                // первое (пустое) подмножество    
	while (n >= 0)                          // пока есть подмножества 
	{
		std::cout << std::endl << "{ ";
		for (int i = 0; i < n; i++)
			std::cout << AA[s1.ntx(i)] << ((i < n - 1) ? ", " : " ");
		std::cout << "}";
		n = s1.getnext();                   // cледующее подмножество 
	};
	
	std::cout << std::endl << "Всего подмножеств: " << s1.count() << std::endl << std::endl;

	//------------------------------------------------------------------------------------------

	std::cout << "---Генератор сочетаний---\n";
	std::cout << "Исходное множество: { ";
	for (int i = 0; i < sizeof(AA) / 2; i++)
		std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
	
	std::cout << "}\n";
	
	std::cout << "Генерация сочетаний";
	combi::xcombination xc(sizeof(AA) / 2, 3);

	std::cout << "из " << xc.n << " по " << xc.m;
	
	n = xc.getfirst();
	while (n >= 0)
	{
		std::cout << std::endl << xc.nc << ": { ";
		
		for (int i = 0; i < n; i++)
			std::cout << AA[xc.ntx(i)] << ((i < n - 1) ? ", " : " ");

		std::cout << "}";
		n = xc.getnext();
	};

	std::cout << std::endl << "Всего сочетаний: " << xc.count() << std::endl << std::endl;

	//------------------------------------------------------------------------------------------

	std::cout << "---Генератор перестановок---\n";
	std::cout << "Исходное множество: { ";

	for (int i = 0; i < sizeof(AA) / 2; i++)
		std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
	
	std::cout << "}\n";
	
	std::cout << "Генерация перестановок";
	combi::permutation p(sizeof(AA) / 2);
	n = p.getfirst();

	while (n >= 0)
	{
		std::cout << std::endl << std::setw(4) << p.np << ": { ";

		for (int i = 0; i < p.n; i++)
			std::cout << AA[p.ntx(i)] << ((i < p.n - 1) ? ", " : " ");

		std::cout << "}";
		n = p.getnext();
	};
	 
	std::cout << std::endl << "Всего перестановок: " << p.count() << std::endl << std::endl;

	//--------------------------------------------------------------------------------------------

	std::cout << std::endl << "---Генератор размещений---";
	std::cout << "Исходное множество: { ";
	
	for (int i = 0; i < N; i++)
		std::cout << AA[i] << ((i < N - 1) ? ", " : " ");
	
	std::cout << "}\n";
	std::cout << "Генерация размещений из " << N << " по " << M;
	combi::accomodation s(N, M);
	n = s.getfirst();
	
	while (n >= 0)
	{
		std::cout << std::endl << std::setw(2) << s.na << ": { ";

		for (int i = 0; i < 3; i++)
			std::cout << AA[s.ntx(i)] << ((i < n - 1) ? ", " : " ");

		std::cout << "}";
		n = s.getnext();
	};

	std::cout << std::endl << "Всего размещений: " << s.count() << std::endl << std::endl;
	
	//--------------------------------------------------------------------------------------------

	int V = 1500,
		v[] = { 100, 200, 300, 400, 500, 150,
				100, 200, 300, 400, 500, 150,
				100, 200, 300, 400, 500, 150,
				100, 200, 300, 400, 500, 150,
				300, 670, 200, 350, 250, 400,
				150, 250, 300, 400, 350},

		c[NN] = { 10, 10, 20, 54, 111, 25,
				  11, 15, 22, 120, 67, 26, 
				  14, 18, 100, 90, 83, 27, 
				  19, 99, 61, 87, 30, 25,
				  50, 79, 20, 25, 15, 30,
				  150, 100, 75, 50, 40};
	short r[MM];

	clock_t t1 = 0, t2 = 0;

	t1 = clock();
	int cc = boat(
		V,   // [in]  максимальный вес груза
		MM,  // [in]  количество мест для контейнеров     
		NN,  // [in]  всего контейнеров  
		v,   // [in]  вес каждого контейнера  
		c,   // [in]  доход от перевозки каждого контейнера     
		r    // [out] результат: индексы выбранных контейнеров  
	);
	t2 = clock();


	std::cout << std::endl << "- Задача о размещении контейнеров на судне";
	std::cout << std::endl << "- общее количество контейнеров    : " << NN;
	std::cout << std::endl << "- количество мест для контейнеров : " << MM;
	std::cout << std::endl << "- ограничение по суммарному весу  : " << V;
	std::cout << std::endl << "- вес контейнеров                 : ";

	for (int i = 0; i < NN; i++)
		std::cout << std::setw(3) << v[i] << " ";
	std::cout << std::endl << "- доход от перевозки              : ";
	
	for (int i = 0; i < NN; i++)
		std::cout << std::setw(3) << c[i] << " ";
	std::cout << std::endl << "- выбраны контейнеры (0,1,...,m-1): ";
	
	for (int i = 0; i < MM; i++)
		std::cout << r[i] << " ";
	std::cout << std::endl << "- доход от перевозки              : " << cc;
	
	std::cout << std::endl << "- общий вес выбранных контейнеров : ";
	
	int sum = 0;
	for (int i = 0; i < MM; i++)
		sum += v[r[i]];
	std::cout << sum;
	
	std::cout << std::endl << "- время расчёта алгоритма : " << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);

	return 0;
}