#include<iostream>

using namespace std;
// Vigenere : k =string = lenght(text)
// giaima  yi = (xi+ki)mod 26 
//tao kry dai bang ban ro

string Key(string text,string key){
	int a = text.length();
	int b = key.length();
	string result = "";
	int j =0;
	for(int i =0 ; i < a ; i++){
		result += key[j];
		j++;
		if(j == b)
			j =0;
	}	
	return result;
}
//  ma hoa
string encrypt(string text, string key){
	int a = text.length();
	int b = key.length();
	string result = "";
	if(a != b)
		result = "Khoa sai";
	else{
		for(int i = 0 ; i<a;i++){
			int temp = ( (int(text[i]) - 65) + (int(key[i])-65) )%26;
			result +=char(temp+65);
		}
	}
	return result;	
}


// giai ma : xi = (yi-ki +26)mod 26
string decrypt(string text, string key){
	int a = text.length();
	int b = key.length();
	string result = "";
	if(a != b)
		result = "Khoa sai";
	else{
		for(int i = 0 ; i<a;i++){
			int temp = (( (int(text[i]) - 65) - (int(key[i])-65) )+26)%26;
			result +=char(temp+65);
		}
	}
	return result;	
}


int main(){
	string s = "GEEKSFORGEEKS";
	string key = "AYUSH";
	string p ="GCYCZFMLYLEIM";
	cout<<encrypt(s,Key(s,key)) <<"\n";
	cout<<decrypt(p,Key(s,key));
	return 0;
}
