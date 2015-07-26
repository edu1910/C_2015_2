#include "calc.h"
#include <string.h>

char to_hex(int num);
int from_hex(char ch);

void soma(void* num1, void* num2)
{
	int* pnum1 = (int*) num1;
	int* pnum2 = (int*) num2;
	*pnum2 = *pnum1 + *pnum2;
}

void subtracao(void*num1, void* num2)
{
	int* pnum1 = (int*) num1;
	int* pnum2 = (int*) num2;
	*pnum2 = *pnum1 - *pnum2;
}

void multiplicacao(void* num1, void* num2)
{
	int* pnum1 = (int*) num1;
	int* pnum2 = (int*) num2;
	*pnum2 = *pnum1 * *pnum2;
}

void divisao(void* num1, void* num2)
{
	int* pnum1 = (int*) num1;
	int* pnum2 = (int*) num2;
	*pnum2 = *pnum2 == 0 ? 0 : *pnum1 / *pnum2;
}

void crypt(void* input, void* output)
{
	char key[] = "EDUARDO";

	char* pinput = (char*) input;
	char* poutput = (char*) output;
	int sinput = strlen(pinput);
	int skey = strlen(key);
	int idx;

	for (idx = 0; idx < sinput; idx++)
	{
		int pos = idx % skey;
		char c = pinput[idx] ^ key[pos];

		poutput[idx*2] = to_hex(c >> 4);
		poutput[idx*2+1] = to_hex(c & 0x0F);
	}
}

void decrypt(void* input, void* output)
{
	char key[] = "EDUARDO";

	char* pinput = (char*) input;
	char* poutput = (char*) output;
	int sinput = strlen(pinput);
	int skey = strlen(key);
	int idx;

	for (idx = 0; idx < sinput/2; idx++)
	{
		int pos = idx % skey;
		poutput[idx] = ((from_hex(pinput[idx*2]) << 4) 
			| from_hex(pinput[idx*2+1])) ^ key[pos];
	}
}

char to_hex(int num)
{
	return num + ((num < 10) ? '0' :  'A' - 10);
}

int from_hex(char ch)
{
	return ch - ((ch >= 'A') ? 10 + 'A' : '0');
}
