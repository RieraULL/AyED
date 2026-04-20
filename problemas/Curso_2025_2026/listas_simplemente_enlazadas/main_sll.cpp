#include <iostream>

#include "sll.hpp"

#define N_CHARS 26

int main(void)
{

      AyED::sll<char> L1;

      for (int i = 0; i < N_CHARS; i++)
      {
            L1.insert_head(new AyED::sll_node<char>('a' + i));
      }

      L1.write(std::cout);
      std::cout << std::endl;

      AyED::sll<char> L2;

      // for (int i = 0; i < N_CHARS; i++)
      // {
      //       L2.insert_tail(new AyED::sll_node<char>('a' + i));
      // }

      L2.write(std::cout);
      std::cout << std::endl;

      std::cout << "\n=== Ejemplo concat ===" << std::endl;

      // AyED::sll<int> C1;
      // AyED::sll<int> C2;
      // AyED::sll<int> C3;

      // C1.insert_tail(new AyED::sll_node<int>(1));
      // C1.insert_tail(new AyED::sll_node<int>(3));
      // C1.insert_tail(new AyED::sll_node<int>(5));

      // C2.insert_tail(new AyED::sll_node<int>(2));
      // C2.insert_tail(new AyED::sll_node<int>(4));
      // C2.insert_tail(new AyED::sll_node<int>(6));

      // std::cout << "C1: ";
      // C1.write(std::cout);
      // std::cout << std::endl;

      // std::cout << "C2: ";
      // C2.write(std::cout);
      // std::cout << std::endl;

      // C3.concat(C1, C2);
      // std::cout << "C3 = concat(C1, C2): ";
      // C3.write(std::cout);
      // std::cout << std::endl;

      std::cout << "\n=== Ejemplo ordered_merge ===" << std::endl;

      // AyED::sll<int> M1;
      // AyED::sll<int> M2;
      // AyED::sll<int> M3;

      // M1.insert_tail(new AyED::sll_node<int>(1));
      // M1.insert_tail(new AyED::sll_node<int>(3));
      // M1.insert_tail(new AyED::sll_node<int>(5));

      // M2.insert_tail(new AyED::sll_node<int>(2));
      // M2.insert_tail(new AyED::sll_node<int>(4));
      // M2.insert_tail(new AyED::sll_node<int>(6));

      // std::cout << "M1: ";
      // M1.write(std::cout);
      // std::cout << std::endl;

      // std::cout << "M2: ";
      // M2.write(std::cout);
      // std::cout << std::endl;

      // M3.ordered_merge(M1, M2);
      // std::cout << "M3 = ordered_merge(M1, M2): ";
      // M3.write(std::cout);
      // std::cout << std::endl;

      return 0;
}
