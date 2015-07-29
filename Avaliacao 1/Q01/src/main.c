#include <stdio.h>
#include <string.h>

char* normalize(char* str);

int main(void)
{
	char frase[] = "Essa questão de programação é fácil";

	printf("\nNormalize: %s\n\n", normalize(frase));

	return 0;
}

char* normalize(char* str)
{
	if (str)
	{
		char from[] = "áàãêÁÀÃÂéêÉÊíÍóõôÓÕÔúÚçÇ";
		char   to[] = "aaaaAAAAeeEEiIoooOOOuUcC";

		int   idx;
		char* chr = NULL;

		for (idx = 0; idx < strlen(str); idx++)
		{
			if ((chr = strchr(from, str[idx])))
			{
				str[idx] = to[chr - from];
			}
		}
	}

	return str;
}
