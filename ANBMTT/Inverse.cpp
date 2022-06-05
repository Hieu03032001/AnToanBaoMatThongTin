#include<iostream>

using namespace std;
// a^-1 mob b
int inverse(long a , long b){
	long q,r,y,y0=0,y1 =1,temp = b;
	while(a>0){
		q = b/a;
		r = b%a;
		if(r == 0)
			break;
		y = y0 - y1*q;
		b = a;
		a = r;
		y0 =y1;
		y1 = y;
	}
	if(y < 0)
		return y + temp;
	else
		return y;
}

int main(){
	cout<<inverse(30,101);
	return 0;
}
