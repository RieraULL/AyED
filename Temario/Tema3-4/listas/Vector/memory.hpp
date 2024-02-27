#pragma once

#include "vector.hpp"
#include "sll_node.hpp"

#define MAX_SZ 100

#define FREE -2

namespace AyED {
    
    template <class T>
    class memory 
    {
        private:
            vector<AyED::sll_node<T> > mem_;
            
        public:
            memory(int max_sz = MAX_SZ):
            mem_(max_sz)
            {
                for(int i = 0; i < mem_.size(); i++)
                    mem_[i].set_next(FREE);
            }
            
            int New(const T& data) {
                
                int i;
                
                for(i = 0; (i < mem_.size()) && (mem_[i].get_next() != FREE); i++);
                
                if (i < mem_.size()) {
                    mem_[i].set_data(data);
                    mem_[i].set_next(NULL_PTR);
                
                    return i;
                } else return NULL_PTR;
            }
            
            void Delete(int inx) {
                
                mem_[inx].set_next(FREE);
            }
            
            sll_node<T>& operator[](int i)
            {
                return mem_[i];
            }
            
            const sll_node<T>& operator[](int i) const
            {
                return mem_[i];
            }
    };
    
}