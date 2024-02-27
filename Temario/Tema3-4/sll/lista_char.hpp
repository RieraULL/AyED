#pragma once

#include <iostream>
using namespace std;

#include "sll.hpp"

class lista_char
{
private:

      AyED::sll<char> list_;

public:
      lista_char(void):
            list_() {}

      ~lista_char(void) {}

      bool empty(void)
      {
            return list_.empty();
      }

      void write(ostream& os)
      {
            list_.write(os);
      }

      void insert_head(char c)
      {
            AyED::sll_node<char>* n = new AyED::sll_node<char>(c);
            list_.insert_head(n);
      }

      char extract_head()
      {
            AyED::sll_node<char>* n = list_.extract_head();
            char c = n->get_data();
            delete n;

            return c;
      }
};
