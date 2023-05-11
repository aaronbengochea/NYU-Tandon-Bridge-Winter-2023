#include <iostream>
#include <vector>
using namespace std;

class Base {
    public:
    Base() {}
    virtual void f() {
    std::cout << "BASE ";
    }
};
class Derived: public Base {
    public:
    Derived(): Base() {}
    virtual void f() {
    std::cout << "DERIVED ";
    }
};
int main() {
    std::vector<Base> base_objs;
    Base obj1 = Derived();
    Derived obj2 = Derived();
    Base obj3 = Base();
    base_objs.push_back(obj1);
    base_objs.push_back(obj2);
    base_objs.push_back(obj3);

    for (Base base_obj : base_objs) {
        base_obj.f();
    }
    obj1.f();
    obj2.f();
    obj3.f();
 return 0;
}

// BASE BASE BASE BASE DERIVED BASE