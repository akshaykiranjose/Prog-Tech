// function template
#include<iostream>
using namespace std;

template <class T>
T getmax(T a, T b)
{
    T result;
    result = (a>b)?a:b;
    return result;
}

int main(){

    int i=5, j=6, k;
    float l = 10.4, m=4.5, n;
    k = getmax<int>(i,j);
    n = getmax<float>(l,m);
    cout<<k<<endl;
    cout<<n<<endl;

}