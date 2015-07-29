#include <stdio.h>
#include "lamp.h"

int main(void)
{
	byte lamps = 0b00000000;
	byte opcao;

	do
	{
		printf("\n=======================\n");
		printf("       LÂMPADAS!       \n");
		printf("=======================\n\n");
		
		printf("1 - Estado das lâmpadas\n");
		printf("2 - Ligar lâmpada\n");
		printf("3 - Apagar lâmpada\n");
		printf("4 - Sair do programa\n\n");
		
		printf("Opção: ");

		scanf("%hu", (short*) &opcao);

		switch (opcao)
		{
			case 1:
			{
				byte idx;

				for (idx = 0; idx < 8; idx++)
				{
					printf("Lâmpada #%d: %s\n", idx+1, 
						(IS_ON(lamps, idx+1)) ? "ON" : "OFF");
				}
			}
			break;
			case 2:
			{
				byte position;

				printf("Posição: ");
				scanf("%hu", (short*) &position);

				TURN_ON(lamps, position);
			}
			break;
			case 3: 
			{
				byte position;

				printf("Posição: ");
				scanf("%hu", (short*) &position);

				TURN_OFF(lamps, position);
			}
			break;
			case 4: break;
			default : printf("\n\nOpção incorreta!");
		}
	} while (opcao != 4);

	return 0;
}