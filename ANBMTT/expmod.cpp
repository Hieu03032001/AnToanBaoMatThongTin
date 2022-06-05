#include <iostream>

using namespace std;

int expMod(int a, int b, int n){
    int p;
    if(b== 0)
        return 1;
    p= expMod(a,b/2,n);
    if(b % 2 == 0)
        return (p *p) % n;
    else
        return (p*p*a)%n;
}
int main()
{ 
    cout<<expMod(2,3,6);

    return 0;
}
