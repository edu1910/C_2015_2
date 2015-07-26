#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int show_menu(S_Menu* menu)
{
	int op = 0;

	do
	{
		int idx;
		for (idx = 0; idx < menu->numItems; idx++)
		{
			printf("%d - %s\n", idx+1, menu->items[idx].title);
		}

		printf("0 - Sair\n\n");

		printf("Opcao: ");
		scanf("%d", &op);
	} while((op < 0) || (op > menu->numItems));

	return op;
}

S_MenuItem* create_item(S_Menu* menu, char* title, T_Func func)
{
	menu->numItems++;
	menu->items = (S_MenuItem*) realloc((void*) menu->items,
		menu->numItems*sizeof(S_MenuItem));
	menu->items[menu->numItems-1].title = title;
	menu->items[menu->numItems-1].func = func;

	return &menu->items[menu->numItems-1];
}

void destroy_menu(S_Menu *menu)
{
	if (menu->items)
	{
		free((void*) menu->items);
		menu->items = NULL;
		menu->numItems = 0;
	}
}
