//overloading operators
#include<iostream>
using namespace std;

class CVector{
    public: 
    int x,y;
    CVector(): x(0), y(0) {}; // default constructor is needed since we define a parametrized one
    CVector(int a, int b): x(a), y(b) {}
    CVector operator + (const CVector&);
};

CVector CVector::operator+ (const CVector& param){ 
    // The parameter expected for a member function overload for operations such as operator+ is 
    // naturally the operand to the right hand side of the operator.
    CVector temp;
    temp.x = x + param.x;
    temp.y = y + param.y;
    return temp;
}

CVector operator- (const CVector& param1, const CVector& param2){ 
    // This overload is Not a member function.
    // parameters are listed and the overload has no affiliation
    CVector temp;
    temp.x = param1.x - param2.x;
    temp.y = param1.y - param2.y;
    return temp;
}

int main(){

    CVector foo (3,1);
    CVector bar (1,2);
    CVector sum, diff;
    sum = foo.operator+(bar);
    diff = operator-(foo, bar);
    cout<<sum.x<<","<<sum.y<< '\n';
    cout<<diff.x<<","<<diff.y<< '\n';
    return 0;
}