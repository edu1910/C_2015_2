#include <stdio.h>
#include <string.h>
#include "calc.h"
#include "menu.h"

void read_int(char* title, int* value);

int main(void)
{
	int op;
	S_Menu menu;

	memset(&menu, 0, sizeof(S_Menu));

	create_item(&menu, "Soma", soma);
	create_item(&menu, "Subtracao", subtracao);
	create_item(&menu, "Divisao", divisao);
	create_item(&menu, "Multiplicacao", multiplicacao);
	create_item(&menu, "Crypt", crypt);
	create_item(&menu, "Decrypt", decrypt);

	do
	{
		op = show_menu(&menu);

		if (op != 0)
		{
			if (op < 4)
			{
				int num1, num2;

				read_int("Primeiro numero: ", &num1);
				read_int("Segundo numero: ", &num2);

				menu.items[op-1].func(&num1, &num2);

				printf("Resultado: %d\n", num2);
			}
			else
			{
				char input[64], output[128] = {0};

				printf("String: ");
				scanf("%s", input);

				menu.items[op-1].func(input, output);

				printf("Resultado: %s\n", output);
			}
		}
	} while (op != 0);

	destroy_menu(&menu);

	return 0;
}

void read_int(char* title, int* value)
{
	printf(title);
	scanf("%d", value);
}
