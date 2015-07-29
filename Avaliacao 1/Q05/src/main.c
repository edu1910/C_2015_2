#include <stdio.h>
#include "student.h"

void print_students(T_Student *root);
float calculate_average(T_Student *root);

int main(void)
{
	int nstudents, idx;
	T_Student *students = NULL;

	printf("Quantidade de alunos: ");
	scanf("%d", &nstudents);

	for (idx = 0; idx < nstudents; idx++)
	{
		char name[32] = {0};
		float score;

		printf("\n--------------------\n");
		printf("ALUNO: %d/%d", idx+1, nstudents);
		printf("\n--------------------\n");

		printf("Nome: ");
		scanf("%s", name);

		printf("Nota: ");
		scanf("%f", &score);

		students = create_student(students, name, score);
	}

	print_students(students);
	printf("\nMÉDIA: %0.2f\n", calculate_average(students));

	destroy_all_students(students);

	return 0;
}

void print_students(T_Student *root)
{
	int idx = 1;

	printf("\n--------------------\n");
	printf("LISTA DE ALUNOS");
	printf("\n--------------------\n");

	while (root)
	{
		printf("%02d - Nome: %s\n", idx, root->name);
		printf("     Nota: %0.2f\n", root->score);

		root = root->next;
		idx++;
	}
}

float calculate_average(T_Student *root)
{
	float sum;
	int nstudents = 0;

	while (root)
	{
		nstudents++;
		sum += root->score;
		root = root->next;
	}

	return nstudents ? sum/nstudents : 0;
}
