#include <locale.h>
#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <chrono>
#include <conio.h>

typedef unsigned long long int  U;
typedef long double D;
using namespace std;
using namespace chrono;


void input(U *n)
{
   printf_s("Введите число членов ряда: ");
   scanf_s("%d", n);

   return;
};

D procc(U n, U i)
{
   D res = 0;
   for (i; i <= n; res += 4. * pow(-1, i) / (2 * i + 1), i++);

   return res;
}

int main()
{
   setlocale(0, "");
   U i = 0, n = 0;
   input(&n);
   system_clock::time_point start = system_clock::now();
   D res = procc(n, i);
   system_clock::time_point end = system_clock::now();
   printf_s("Результат: %Lf \n", res);
   //auto t1 = std::chrono::high_resolution_clock::now();
   //D res = procc(n, i);
   //auto t2 = std::chrono::high_resolution_clock::now();
   auto sec = duration_cast<duration<double>>(end - start);
   printf_s("Время выполнения: %lf ms.\n", sec.count()) /*std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count())*/;

   return _getch();
}
