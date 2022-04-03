#ifndef H_PRIORUTY_QUEUE_M
#define H_PRIORUTY_QUEUE_M

#include <queue>
#include <functional>

template <typename T, 
          class C = std::vector<T>,
          class Pr = std::less<typename C::value_type>>
class priority_queue_m : public std::priority_queue<T, C, Pr>
{
   public:
   priority_queue_m() = default;

   template <typename T, class C, class Pr>
   priority_queue_m(C _c, Pr _pr) : std::priority_queue(_c, _pr) { }

   /// <summary>
   /// Очищает очередь от элементов
   /// </summary>
   void clear();
   /// <summary>
   /// Выводит все элементы очереди на консоль
   /// </summary>
   void print(std::function<void(T)> pf);
};

#endif // !H_PRIORUTY_QUEUE_M