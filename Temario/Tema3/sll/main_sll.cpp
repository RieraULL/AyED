#include <iostream>

#include "sll.hpp"
#include "lista_char.hpp"

#define N_CHARS 26

int main(void)
{
      /*{
            AyED::sll<char> L1;
            AyED::sll<char> L2;

            for (int i = 14; i >= 0; i -= 2)
                  L1.insert_head(new AyED::sll_node<char>('a' + i));

            for (int i = 25; i >= 0; i -= 2)
                  L2.insert_head(new AyED::sll_node<char>('a' + i));

            AyED::sll<char> L;

            L1.write(std::cout);
            std::cout << std::endl;
            L2.write(std::cout);
            std::cout << std::endl;
            L.write(std::cout);
            std::cout << std::endl;

            std::cout << std::endl;

            L.merge1(L1, L2);

            L1.write(std::cout);
            std::cout << std::endl;
            L2.write(std::cout);
            std::cout << std::endl;
            L.write(std::cout);
            std::cout << std::endl;
            std::cout << std::endl;
      }

      {
            AyED::sll<char> L1;
            AyED::sll<char> L2;

            for (int i{0}; i <= 14; i += 2)
                  L1.insert_head(new AyED::sll_node<char>('a' + i));

            for (int i = 1; i <= 25; i += 2)
                  L2.insert_head(new AyED::sll_node<char>('a' + i));

            AyED::sll<char> L;

            L1.write(std::cout);
            std::cout << std::endl;
            L2.write(std::cout);
            std::cout << std::endl;
            L.write(std::cout);
            std::cout << std::endl;

            std::cout << std::endl;

            L.merge2(L1, L2);

            L1.write(std::cout);
            std::cout << std::endl;
            L2.write(std::cout);
            std::cout << std::endl;
            L.write(std::cout);
            std::cout << std::endl;
            std::cout << std::endl;
      }*/

      {
            AyED::sll<char> L1;

            for (int i = 25; i >= 0; i--)
                  L1.insert_head(new AyED::sll_node<char>('a' + i));

            AyED::sll<char> L;

            L1.write(std::cout);
            std::cout << std::endl;
            L.write(std::cout);
            std::cout << std::endl;

            std::cout << std::endl;

            L.invPar(L1);

            L1.write(std::cout);
            std::cout << std::endl;
            L.write(std::cout);
            std::cout << std::endl;
            std::cout << std::endl;
      }

      return 0;
}
