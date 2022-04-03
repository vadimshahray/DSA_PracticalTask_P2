#include <functional>
#include "student.h"
#include "student_comparer.h"
#include "priority_queue_m.h"

template <typename T, class C, class Pr>
void priority_queue_m<T, C, Pr>::clear()
{
   for ( ; !this->empty(); this->pop());
}

template <typename T, class C, class Pr>
void priority_queue_m<T, C, Pr>::print(std::function<void(T)> pf)
{
   T e = NULL;
   priority_queue_m q;

   for ( ; !this->empty(); e = this->top(), q.push(e), this->pop(), pf(e));
   for ( ; !q.empty(); e = q.top(), this->push(e), q.pop());
}

template class priority_queue_m<student, std::vector<student>, student_comparer>;