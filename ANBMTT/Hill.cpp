#include<iostream>
using namespace std;
// nhap mang  khoa k
void nhapKhoa(int Key[2][2]){
	for(int i = 0 ; i<2 ; i++){
		for(int j = 0; j< 2 ;j++){
			cout<<"key["<<i<<"]["<<j<<"]:";
			cin>>Key[i][j];
		}
	}
}
// tim det ^-1
long Inverse(long a , long b){
	long q , r, y, y0=0, y1=1, temp = b;
	while(a>0){
		q = b/a;
		r = b%a;
		if( r == 0)
			break;
		y= y0- q*y1;
		b = a;
		a = r;
		y0 = y1;
		y1 = y;
	}
	if( y < 0)
		return y + temp;
	else 	
		return y;
}
// tim khoa k^-1
void createKeyDecry(int key[2][2],int KeyDecry[2][2]){
	int det = key[0][0] * key[1][1] - key[1][0]* key[0][1];
	long detKey = Inverse(det,26);
	KeyDecry[0][0] = (key[1][1] * detKey)%26;
	
	KeyDecry[1][1] = (key[0][0] * detKey)%26;
	KeyDecry[1][0] = (-key[1][0] * detKey)%26;
	if(KeyDecry[1][0] < 0)
		KeyDecry[1][0]  = KeyDecry[1][0] +26;
	KeyDecry[0][1] = (-key[0][1] * detKey)%26;
	if(KeyDecry[0][1] < 0)
		KeyDecry[0][1]  = KeyDecry[0][1] +26;
}
 
// xuat key giai ma
void OuputKey(int Key[2][2]){
	for(int i = 0 ; i< 2 ;i++){
		for(int j = 0 ; j<2;j++)
			cout<<Key[i][j]<<"\t";
		cout<<"\n";
	}
}

//=================cau 2======================

// nhap xau ki tu
void InputText(string &text1,string &text2){
	cout<<"Nhap chuoi1: ";
	cin>>text1;
	cout<<"Nhap chuoi2: ";
	cin>>text2;
}


//Kiem tra do dai chuoi
int CheckDoDaiChuoi(string text1, string text2){
	if(text1.length() != text2.length())
		return -1;
	else
		return 1;
}

// ma hoa chuoi:
void Encrypt(string text1,int key[2][2],string &result){
	result ="";
	int temp1,temp2;
	for(int k =0 ; k < text1.length();k=k+2){
		temp1 =  (int(text1[k]-65) * key[0][0] + int(text1[k+1]-65) * key[1][0])%26;
		temp2= (int(text1[k]-65) * key[0][1] + int(text1[k+1]-65) * key[1][1])%26;
		result+= char(temp1 +65);
		result+= char(temp2+65);		
	}

}
int main(){
	// cau1 -----------------------------------------
	int key[2][2];
	nhapKhoa(key);
	cout<<"\n";
	OuputKey(key);
	int keyDecry[2][2];
	createKeyDecry(key,keyDecry);
	OuputKey(keyDecry);
	
	//cau2-------------------------------------------
	cout<<"\n =========cau 2==============\n";
	string text1 ,text2;
	InputText(text1,text2); 
	if(CheckDoDaiChuoi(text1,text2) == -1)
		cout<<"Ban da nhap sai";
	else{
		string result ="";
		Encrypt(text1,key,result);
		if(result == text2)
			cout<<"true";
		else
			cout<<"false";
	}
	return 0;
}
