#pragma once
int lcs(
	int lenx,         // длина   последовательности  X   
	const char x[],   // последовательность X
	int leny,         // длина   последовательности  Y
	const char y[]    // последовательность Y
);

int lcsd(
	const char x[],  // последовательность X
	const char y[],  // последовательность  Y
	char z[]         // наибольшая общая подпоследовательность 
);