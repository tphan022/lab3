#include <iostream>
#include <vector>

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
    Op(double number) { value = 0;}
    double value;
    double evaluate() { return value;}
};

class composite : public Base {
   public:
    Base* left;
    Base* right;
    composite() {};
    virtual double evaluate() = 0;
    virtual void addleft();
    virtual void addright();
};

class Mult : public composite {
   public:
    
};

int main(){
   

return 0;
}
