#ifndef student_h
#define student_h

typedef struct S_Student
{
	struct S_Student *prev;
	char name[32];
	float score;
	struct S_Student *next;
} T_Student;

T_Student* create_student(T_Student *root, const char* name, float score);
void destroy_all_students(T_Student *student);
void destroy_student(T_Student *student);

#endif
