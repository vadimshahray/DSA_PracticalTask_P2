#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "student.h"
#include "student_comparer.h"
#include "priority_queue_m.h"

enum COMMAND
{
   PUSH,    // Добавить элемент в очередь
   POP,     // Вытолкнуть элемент из очереди
   CLEAR,   // Очистить очередь
   PRINT,   // Вывести содержимое очереди на консоль
   EMPTY,   // Проверить, пуста ли очередь
   COUNT,   // Количество элементов в очереди
   EXIT     // Завершение работы программы
};

int main()
{
   UINT inCp = GetConsoleCP(), outCp = GetConsoleOutputCP();
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);
   
   char cmd, c, name;
   bool is_repeat = true;

   auto print_item = [](student item) { printf_s("%c ", item.name); };

   priority_queue_m<student, std::vector<student>, student_comparer> q;
   do
   {
      printf_s("Выберите команду:\n"
               "[%d] Добавить студента в очередь;\n"
               "[%d] Вытолкнуть студента из очереди;\n"
               "[%d] Очистить очередь;\n"
               "[%d] Вывести содержимое очереди;\n"
               "[%d] Проверить, пуста ли очередь;\n"
               "[%d] Вывести количество студентов в очереди;\n"
               "[%d] Завершить прием студентов.\n"
               "Команда: ", PUSH, POP, CLEAR, PRINT, EMPTY, COUNT, EXIT);
      scanf_s("\n%c", &cmd, 1);
      printf_s("\n");

      switch (cmd - '0')
      {
         case PUSH:
            printf_s("Введите имя студента: ");
            scanf_s("\n%c", &name, 1);
            printf_s("Находится ли он на своей паре (да <1> / нет <0>): ");
            scanf_s("\n%c", &c, 1); 

            q.push(student(name, c == '1'));
            printf_s("Студент успешно добавлен."); break;
         case POP:
            if (q.empty())
               printf_s("Не удалось вытолкнуть студента: очередь пуста.");
            else
            {
               printf_s("Вытолкнутый студент: %c.", q.top().name);
               q.pop();
            } break;
         case CLEAR:
            q.clear();
            printf_s("Очередь очищена."); break;
         case PRINT:
            printf_s("Студенты в очереди:\n");
            q.print(print_item); break;
         case EMPTY:
            printf_s(q.empty() ? "Очередь пуста." : "Очередь не пуста."); break;
         case COUNT:
            printf_s("Количество студентов в очереди: %zu", q.size()); break;
         case EXIT: 
            is_repeat = false; break;
         default: 
            printf_s("Неверный номер команды."); break;
      }
      printf_s("\n\n");
   } while (is_repeat);

   SetConsoleCP(inCp);
   SetConsoleOutputCP(outCp);

   return 0 * _getch();
}