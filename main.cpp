#include <iostream>
#include <vector>
#include "Sort.h"

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
     virtual void add_element(Base* element) {
         b.push_back(element);
         sort();
     }
     void print() {
         for(unsigned int i = 0; i < b.size(); i++) {
              cout << b.at(i);
         }
         cout << endl;
     }
     void sort() {
         sort_function->sort(this);
     }
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




int main(){
   Op two(2.0);
   Base* n2 = &two;
   Op one1(1.0);
   Base* n11 = &one1;
   Op one2(1.0);
   Base* n12 = &one2;
   Op three(3.0);
   Op seven(7.0);
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

return 0;
}
