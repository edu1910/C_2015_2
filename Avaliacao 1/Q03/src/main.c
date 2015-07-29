#include <stdio.h>

int soma_multiplos(int numero, int maximo);

int main(void)
{
	printf("\nSoma dos múltiplos de 3 = %d\n", soma_multiplos(3, 1000));
	printf("\nSoma dos múltiplos de 7 = %d\n\n", soma_multiplos(7, 1000));

	return 0;
}

int soma_multiplos(int numero, int maximo)
{
	int multiplo, soma = 0;

	//printf("\nMultiplos de %d: ", numero); //DEBUG

	for (multiplo = 0; multiplo <= maximo; multiplo += numero)
	{
		//printf("%d ", multiplo); //DEBUG
		soma += multiplo;
	}

	return soma;
}
