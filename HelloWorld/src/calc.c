#include "calc.h"

int soma(int num1, int num2)
{
	return num1+num2;
}

int subtracao(int num1, int num2)
{
	return num1-num2;
}

int multiplicacao(int num1, int num2)
{
	return num1*num2;
}

int divisao(int num1, int num2)
{
	return num2 == 0 ? 0 : num1/num2;
}
