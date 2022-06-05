 #include<iostream>
 #include<string>
 using namespace std;
 // ma hoa k 
 string encrypt(string text, int key){
 	if(key >26)
 		key = key%26;
 	string result = "";
 	for(int i = 0 ; i < text.length() ;i++){
 		if(isupper(text[i])){
 			result += char(65 +(int(text[i])-65+key)%26);
		}
		else
			result += char(97 +(int(text[i])-97+key)%26);
	 }
	return result;
 }
 
// giai ma 
 string decrypt(string text, int key){
	string result = "";
	for(int i = 0 ; i < text.length();i++){
		if(isupper(text[i])){
 			result += char( 65 + (int(text[i])-65-key)%26 );
		}
		else
			result += char(97 +(int(text[i])-97-key)%26);
	}
	 return result;	
 }
 int main(){
 	string s = "AbC";
	string p ="OpQ";
	cout<<encrypt(s,40)<<"\n";
	cout<<decrypt(p,40);
 	return 0;
 }
