#include <stdio.h>
#include <string.h>

int main(void)
{
	char key [  ] = {"MaStErSuPeRhYpErKeY"};
	char pass[32] = {0};
	char hash[32] = {"X?'r+zW8PFUs"};

	int idx, ckey;

	for (idx = strlen(hash)-1; idx >= 0; 
		ckey = strlen(key) - (idx % strlen(key)) - 1,
		pass[idx] = ((key[ckey] - '0') ^ (hash[idx] + 100)) - '1', idx--);

	printf("Password: %s\n", pass);

	return 0;
}
