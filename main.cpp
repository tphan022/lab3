#include <iostream>
#include <vector>
#include <list>


using namespace std;

class Base {
   public:
    // Constructors
    Base() {};
    virtual double evaluate() = 0;
};

// Leaf
class Op : public Base {
   public:
    Op() {};
    Op(double number) { value = number;}
    double value;
    double evaluate() { return value;}
};

class composite : public Base {
   public:
    Base* left;
    Base* right;
    composite() {};
    virtual double evaluate() = 0;
    virtual void addleft() {}
    virtual void addright() {}
};

class Mult : public composite {
   public:
    Base* left;
    Base* right;
    Mult() {};
    double evaluate() {return left->evaluate() * right->evaluate();}
    void addleft(Base* l) {left = l;}
    void addright(Base* r) {right = r;}
};

class Div : public composite {
   public:
    Base* left;
    Base* right;
    Div() {};
    double evaluate() {return left->evaluate() / right->evaluate();}
    void addleft(Base* l) {left = l;}
    void addright(Base* r) {right = r;}
};

class Add : public composite {
   public:
    Base* left;
    Base* right;
    Add() {};
    double evaluate() {return left->evaluate() + right->evaluate();}
    void addleft(Base* l) {left = l;}
    void addright(Base* r) {right = r;}
};

class Sub : public composite {
   public:
    Base* left;
    Base* right;
    Sub() {};
    double evaluate() {return left->evaluate() - right->evaluate();}
    void addleft(Base* l) {left = l;}
    void addright(Base* r) {right = r;}
};

class Sqr : public composite {
   public:
    Base* left;
    Sqr() {};
    double evaluate() {return left->evaluate() * left->evaluate();}
    void addleft(Base* l) {left = l;}
    void addright(Base* r) {left = r;}
};

class Sort;

class Container {
   protected:
    Sort* sort_function;
   public:
    Container() : sort_function(NULL){};
    Container(Sort* function) : sort_function(function) {};
    void set_sort_function(Sort* sort_function);
    virtual void add_element(Base* element) = 0;
    virtual void print() = 0;
    virtual void sort() = 0;
    virtual void swap(int i, int j) = 0;
    virtual Base* at(int i) = 0;
    virtual int size() = 0;
};

class Vector_C : public Container {
    protected:
     vector<Base*> b;
     Sort* sort_function;
    public:
     Vector_C() : sort_function(NULL){};
     Vector_C(Sort* function) : sort_function(function) {};
     void set_sort_function(Sort* sort_function) {this->sort_function
           = sort_function;}
     void add_element(Base* element) {
         b.push_back(element);
     }
     void print() {
         for(unsigned int i = 0; i < b.size(); i++) {
              cout <<  b.at(i)->evaluate() << " " ;
         }
         cout << endl;
     }
     void sort();
     void swap(int i, int j) {
         Base* tmp = b.at(i);
         b.at(i) = b.at(j);
         b.at(j) = tmp;
     }
     Base* at(int i) {
         return b.at(i);
     }
     int size() {
         return b.size();
     }
};

class List_C : public Container {
    protected:
     list<Base*> b;
     Sort* sort_function;
    public:
     List_C() : sort_function(NULL) {};
     List_C(Sort* function) : sort_function(function) {};
     void set_sort_function(Sort* sort_function) {this->sort_function
           = sort_function;}
     void add_element(Base* element) {
       b.push_back(element);
     }
     void print() {
       for(list<Base*>::iterator i = b.begin(); i != b.end(); i++) {
           cout << (*i)->evaluate() << " " ;
       }
       cout << endl;
     }
     void sort();
     void swap(int i, int j) {
        list<Base*>::iterator itI = b.begin();
        list<Base*>::iterator itJ = b.begin();
        Base* temp;
        for(int i1 = 0; i1 < i; i1++) {
          itI++;
        }
        for(int j1 = 0; j1 < j; j1++) {
          itJ++;
        }
        temp = *itJ;
        *itJ = *itI;
        *itI = temp;
     }
     Base* at(int i) {
        list<Base*>::iterator W = b.begin();
        for(int j = 0; j < i; j++) {
           W++;
        }
        return *W;
     }
     int size() {
        return b.size();
     }
};


class Sort {
   public:
    Sort() {}
    virtual void sort(Container* container) = 0;
};

class Ssort : public Sort { // this is the selection sort class
   public:
    Ssort() {}
    void sort(Container* container) {
      int i, j, first;
      for(i = container->size() - 1; i > 0; i--) {
         first = 0;
         for (j = 1; j <= i; j++) {
            if(container->at(j)->evaluate() < container->at(first)->evaluate()) {
               first = j;
            }
         }
         container->swap(first,i);
      }
    }

};

class Bsort : public Sort { // this is the bubble sort class
   public:
    Bsort() {}
    void sort(Container* container) {
      int i, j, flag = 1;
      for(i = 1; (i <= container->size()) && flag; i++) {
        flag = 0;
        for (j = 0; j < (container->size() - 1); j++) {
          if(container->at(j+1)->evaluate() > container->at(j)->evaluate()) {
             container->swap(j,j+1);
             flag = 1;
          }
        }
      }
    }
};

void Vector_C::sort() {
    sort_function->sort(this);
}

void List_C::sort() {
    sort_function->sort(this);
}

int main(){
   Op two(2.0);
   Base* n2 = &two;
   Op one1(1.0);
   Base* n11 = &one1;
   Op one2(14.0);
   Base* n12 = &one2;
   Op three(3.0);
   Op seven(7.0);
   Base* n7 = &seven;
   Op four(4.0);
   Op six(6.0);
   Base* n6 = &six;
   Base* n4 = &four;
   Sqr Root;
   Div divide;
   Base* di = &divide;
   Add addition;
   Base* ad = &addition;
   Mult multi;
   Base* mu = &multi;
   Sub subtr;
   Base* su = &subtr;
  // Root.addright(n2);

   Root.addleft(mu);
   addition.addleft(n11);
   addition.addright(n12);
   divide.addleft(n6);
   divide.addright(su);
   subtr.addleft(n4);
   subtr.addright(n2);
   multi.addleft(ad);
   multi.addright(di);
   cout << Root.evaluate() << endl;

cout << "Vector test with selection sort: " << endl;
Vector_C vcontainer;
Ssort selectionS;
vcontainer.add_element(n6);
vcontainer.add_element(di);
vcontainer.add_element(mu);
vcontainer.add_element(n11);
vcontainer.add_element(n7);
vcontainer.add_element(ad);
vcontainer.set_sort_function(&selectionS);
vcontainer.sort();
vcontainer.print();

cout << "Vector test with bubble sort: " << endl;
Vector_C vcontainer2;
Bsort BubbleS;
vcontainer2.add_element(n6);
vcontainer2.add_element(di);
vcontainer2.add_element(mu);
vcontainer2.add_element(n11);
vcontainer2.add_element(n7);
vcontainer2.add_element(ad);
vcontainer2.set_sort_function(&BubbleS);
vcontainer2.sort();
vcontainer2.print();

cout << "List test with selection sort: " << endl;
List_C lcontainer;

lcontainer.add_element(n6);
lcontainer.add_element(di);
lcontainer.add_element(n12);
lcontainer.add_element(n11);
lcontainer.add_element(n7);
lcontainer.add_element(ad);
lcontainer.set_sort_function(&selectionS);
lcontainer.sort();
lcontainer.print();

cout << "List test with bubble sort: " << endl;
List_C lcontainer2;

lcontainer2.add_element(n6);
lcontainer2.add_element(di);
lcontainer2.add_element(n12);
lcontainer2.add_element(n11);
lcontainer2.add_element(n7);
lcontainer2.add_element(ad);
lcontainer2.set_sort_function(&BubbleS);
lcontainer2.sort();
lcontainer2.print();


return 0;
}
