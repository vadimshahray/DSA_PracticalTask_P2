#ifndef H_ITEM
#define H_ITEM

template <typename T>
struct item
{
   item(T _value, int _priority) : value(_value), priority(_priority) {}
   
   T value;
   int priority;
};
#endif // !H_ITEM