#ifndef menu_h
#define menu_h

typedef void (*T_Func)(void*, void*);

typedef struct
{
	char* title;
	T_Func func;
} S_MenuItem;

typedef struct
{
	S_MenuItem* items;
	int numItems;
} S_Menu;

int show_menu(S_Menu* menu);
S_MenuItem* create_item(S_Menu* menu, char* title, T_Func func);
void destroy_menu(S_Menu *menu);

#endif