#ifndef H_STUDENT_COMPARER
#define H_STUDENT_COMPARER

#include "student.h"

struct student_comparer
{
   inline bool operator()(const student &a, const student &b)
   {
      return a.at_own_lesson && b.at_own_lesson || !a.at_own_lesson && !b.at_own_lesson 
             ? a.name > b.name
             : b.at_own_lesson;
   }
};

#endif // !H_STUDENT_COMPARER