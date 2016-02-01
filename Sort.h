#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>

class Container;

class Sort {
   public:
    Sort();
    virtual void sort(Container* container) = 0;

};

class S_sort : public Sort {
   public:
    S_sort();
    void sort(Container* container);

};











#endif
