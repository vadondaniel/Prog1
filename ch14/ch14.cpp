#include "std_lib_facilities.h"

class P{
public:
    virtual void pvf() = 0;
};

class B1 : public P {
public:
    virtual void vf() {
        cout << "B1::vf" << endl;
        }
    void f() {
        cout << "B1::f" << endl;
        }
    void pvf() {
        cout << "B1::pvf" << endl;
        }
};

class D1 : public B1 {
public:
    void vf() override {
        cout << "D1::vf" << endl;
        }
    void f(){
        cout << "D1::f" << endl;
        }
};

class D2 : public D1 {
public:
    void pvf() override {
        cout << "D2::pvf" << endl;
        }
};

class B2{
public:
    virtual void pvf() = 0;
};

class D21 : public B2{
    string s = "this is D21";
    void pvf() override {
        cout << s << endl;
        }
};

class D22 : public B2{
    int x = 2222;
    void pvf() override {
        cout << x << endl;
        }
};

void f(B2& b){
    b.pvf();
};

int main() {
    
    B1 object;
    object.vf();
    object.f();
    object.pvf();

    D1 object_d;
    object_d.vf();
    object_d.f();
    object_d.pvf();

    B1& object_b_ref=object_d;
    object_b_ref.vf();
    object_b_ref.f();
    object_b_ref.pvf();

    D2 object_d2;
    object_d2.vf();
    object_d2.f();
    object_d2.pvf();

    D21 object_d21;
    f(object_d21);

    D22 object_d22;
    f(object_d22);

    return 0;
}