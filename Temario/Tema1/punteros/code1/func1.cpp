#include <iostream>
using namespace std;

namespace AyED
{

   typedef int (*opera_ptr)(int, int);

   int suma(int n1, int n2) { return n1 + n2; }
   int rest(int n1, int n2) { return n1 - n2; }
   int mult(int n1, int n2) { return n1 * n2; }
   int div(int n1, int n2) { return n1 / n2; }

   int opera(int n1, int n2, opera_ptr operador)
   {
      return (*operador)(n1, n2);
   }
}

int main(void)
{
   const int a = 10, b = 5;

   cout << AyED::opera(a, b, AyED::suma) << endl;
   cout << AyED::opera(a, b, AyED::rest) << endl;
   cout << AyED::opera(a, b, AyED::mult) << endl;
   cout << AyED::opera(a, b, AyED::div) << endl;
}
