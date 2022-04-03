#ifndef H_STUDENT
#define H_STUDENT

struct student
{
   student(char _name, bool at = false) : name(_name), at_own_lesson(at) { }

   char name;
   bool at_own_lesson;
};

#endif // !H_STUDENT