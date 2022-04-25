#include "std_lib_facilities.h"
#include <complex>
#include "Matrix.h"
#include "MatrixIO.h"

// Compile: g++ ch24.cpp -o ch24

using namespace Numeric_lib;

template<typename A> 
void size(const A& a)
{
    cout<<sizeof(a)<< endl;
}

void one_to_three(){
    cout << "sizeof(char) = " << sizeof(char) << endl;
    cout << "sizeof(short) = " << sizeof(short) << endl;
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(long) = " << sizeof(long) << endl;
    cout << "sizeof(float) = " << sizeof(float) << endl;
    cout << "sizeof(double) = " << sizeof(double) << endl;
    cout << "sizeof(int*) = " << sizeof(int*) << endl;
    cout << "sizeof(double*) = " << sizeof(double*) << endl;
    Matrix<int> a(10);
    cout << "sizeof(Matrix<int> a(10)) = " << sizeof(a) << endl;
    Matrix<int> b(100);
    cout << "sizeof(Matrix<int> b(100)) = " << sizeof(b) << endl;
    Matrix<double> c(10);
    cout << "sizeof(Matrix<double> c(10)) = " << sizeof(c) << endl;
    Matrix<int,2> d(10,10);
    cout << "sizeof(Matrix<int,2> d(10,10)) = " << sizeof(d) << endl;
    Matrix<int,3> e(10,10,10);
    cout << "sizeof(Matrix<int,3> e(10,10,10)) = " << sizeof(e) << endl;
    cout << "a.size() = " << a.size() << endl;
    cout << "b.size() = " << b.size() << endl;
    cout << "c.size() = " << c.size() << endl;
    cout << "d.size() = " << d.size() << endl;
    cout << "e.size() = " << e.size() << endl;
}

int main(){

    one_to_three();
    
    int a;
    cin >> a;
    double a_d = sqrt(a);
    int a_i = sqrt(a);
    if (a_d == a_i) cout << sqrt(a);
    else cout << "No square root";
    
    Matrix<double> matrics(10);

    cout<<"\nWrite 10 values:\n";

    float y;
    
    for (int i = 0; i < matrics.size(); i++)
    {
        cin>>y;
        matrics[i]=y;
    }

    cout << "Values:\n";

    for (int i = 0; i < matrics.size(); i++)
    {
        cout << matrics[i] << " ";
    }

    int n;
    cout << "\nn: ";
    cin >> n;
    int m;
    cout << "m: ";
    cin >> m;

    Matrix<int,2> nm(n,m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            nm(i,j)=i*j;
            cout  << nm(i,j)<< "\t";
        }
        cout<<endl;
    }

    Matrix<complex<double>> cm(10);
    complex<double> cd;
    complex<double> sum;
    cout << "Enter 10 values to sum:\n";
    for (int i = 0; i < cm.size(); i++)
    {
        cin>>cd;
        cm[i]=cd;
        sum=sum+cm[i];
    }
    cout << "Sum: " << sum << endl;

    int z;
    Matrix<int,2> mm(2,3);
    cout << "Please input 6 numbers\n";
    for (int i = 0; i < mm.dim1(); i++)
    {
        for (int j = 0; j < mm.dim2(); j++)
        {
            cin>>z;
            mm(i,j)=z;
        }
    }
    cout << "Your numbers:\n";
    for (int i = 0; i < mm.dim1(); i++)
    {
        for (int j = 0; j < mm.dim2(); j++)
        {
            cout  << mm(i,j)<< "\t";
        }
        cout<<endl;
    }
    
    return 0;
}