#pragma once

#include <iostream>

#include "sll.hpp"

class lista_char
{
public:
      lista_char(void);
      ~lista_char(void);

      bool empty(void) const;
      std::ostream& write(std::ostream &os) const;
      void insert_head(char c);
      char extract_head(void);

private:
      AyED::sll<char> list_;
};

lista_char::lista_char(void) : list_() {}

lista_char::~lista_char(void) {}

bool lista_char::empty(void) const
{
      return list_.empty();
}

std::ostream& lista_char::write(std::ostream &os) const
{
      list_.write(os);
      return os;
}

void lista_char::insert_head(char c)
{
      AyED::sll_node<char> *n = new AyED::sll_node<char>(c);
      list_.insert_head(n);
}

char lista_char::extract_head()
{
      AyED::sll_node<char> *n = list_.extract_head();
      char c = n->get_data();
      delete n;

      return c;
}
