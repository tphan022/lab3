#include <iostream>
#include <vector>
#include "Sort.h"

using namespace std;

void S_sort::sort(Container* container) {
    int i, j, first;
    int numLength = container->size();
    for(i = numLength - 1; i > 0; i--) {
       first = 0;
       Base* ival;
       ival = container->at(i);
       for(j= 1; j <= i; j++) {
          Base* jval;
          jval = container->at(j);
          if(jval->evaluate() < ival->evaluate()) {
             first = j;
          }
        }
        container->swap(first,j);
     }
}
