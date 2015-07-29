#include <stdlib.h>
#include <string.h>
#include "student.h"

T_Student* create_student(T_Student *root, const char* name, float score)
{
	T_Student *student = (T_Student*) malloc(sizeof(T_Student));

	memset((void*) student, 0, sizeof(T_Student));
	strncpy((char*) student->name, name, sizeof(student->name));
	student->score = score;

	if (root)
	{
		T_Student *pstudent = root;

		do
		{
			if (pstudent->score < score) /* É um nó com nota menor */
			{
				if (pstudent->prev) /* O nó não é raíz */
				{
					student->prev = pstudent->prev;
					pstudent->prev->next = student;
				}
				else
				{
					root = student;
				}

				pstudent->prev = student;
				student->next = pstudent;

				break;
			}

			if (!pstudent->next) /* É o último nó */
			{
				student->prev = pstudent;
				pstudent->next = student;
				break;
			}

			pstudent = pstudent->next;
		} while (1);
	}
	else
	{
		root = student;
	}

	return root;
}

void destroy_all_students(T_Student *student)
{
	T_Student *next;

	while (student)
	{
		next = student->next;
		free(student);
		student = next;
	}
}
