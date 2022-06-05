#include<iostream>

using namespace std;
// affine : 
//// ma hoa : y = (ax +b )mod n
string encrypt(string text, long a,long b){
	string result = "";
	for (int i = 0 ; i< text.length();i++){
		int temp = (a * (int(text[i])-65) + b)%26 ;
		result += char(65 + temp);
	}
	
	return result;
}

//giai ma : x = a^-1 *(y-b) mod n
//-------------
//tim a^-1 mod n
long Inserve(long a , long n){
	long q,r,y,y0= 0,y1 =1,temp = n;
	while(a>0){
		q = n/a;
		r = n%a;
		if( r == 0)
			break;
		y = y0 - q*y1;
		n = a;
		a= r;
		y0 =y1;
		y1 = y;
	}
	if(y < 0)
		return y + temp;
	else
		return y;
}

//giai ma
string decypt(string text,long a, long b){
	string result = "";
	int decryptKey = Inserve(a,26);
	for(int i = 0 ; i < text.length();i++){
		int temp = 26+ (decryptKey * (int(text[i])-65-b))%26;
		result+= char(65 + temp);
	}
	return result;
}

int main(){
	string s = "TWENTYFIFTEEN";
	string p = "FEKHFMBABFKKH";
	cout<<encrypt(s,17,20)<<"\n";
	cout<<decypt(p,17,20);
	return 0;
}
