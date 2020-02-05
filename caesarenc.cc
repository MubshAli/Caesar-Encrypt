#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

string enc(int x , string code) 
{ 
    string s; 
    int len = code.length();
    // traverse text 
    for (int i=0;i<len;i++) 
    { 
        // apply transformation to each character  
        if (isupper(code[i])){ 
            s += char(int(code[i]+x-'A')%26 +'A'); 
	}
    // Encrypt Lowercase letters 
    else if(islower(code[i])){
        s += char(int(code[i]+x-'a')%26 +'a'); 
    }else{
    	s += code[i];
    }
   	 }
  
    // Return the resulting string 
    return s; 
} 

string dec(int x , string code)
{
    string s;
    int len = code.length();
    // traverse text
    for (int i=0;i<len;i++)
    {
        // apply transformation to each character
        if (islower(code[i])){
            s += char(int(code[i]-x-'z')%26 +'z');
	}
    // Encrypt Lowercase letters
  	  else if(isupper(code[i])){
       		 s += char(int(code[i]-x-'Z')%26 +'Z');
    }
  	 else{
		 s += code[i];
   	}
    }

    // Return the resulting string
    return s;
}
int main(int argc, char* argv[])
{
    int num_args = argc;
    string arg2;
    string str1;
    string str2;
    int x = 3;
    string shift = "right";
    if (num_args == 2) {
        istringstream s(argv[1]);
        s >> x;
    }
    if (num_args == 3) {
        istringstream s(argv[1]);
        s >> x;
        istringstream s2(argv[2]);
        s2 >> shift;
    }
    if (x < 0 || x > 25) {
        cout << "ERROR: Incorrect shift value" << endl;
        return 0;
    }
    if (num_args > 3) {
        cout << "ERROR: program should not be called with more than 2 arguments" << endl;
        return 0;
    }
    if(num_args == 3 &&( shift != "left" &&  shift != "right")){
    	cout << "ERROR: Incorrect direction (only left or right allowed)." << endl;
   	return 0;
       	}
    while (getline(cin, str1)) {
        // First input is for example 
        // str1 == eHelloWorld
        // Next iteration it is
        // str1 == dKhoorZurog and so on
        int strlen = str1.length();
        if (str1[0] == 'q') {
                return 0;
        }
        str2 = str1.substr(1, strlen); // str2 == HelloWorld
       // cout << str2 << endl;
	if (str1[0] == 'e') {
		if(shift == "left"){
                cout <<  dec(x,str2) << endl;
        }else{
		cout<< enc(x,str2) << endl;
	}}
        if (str1[0] == 'd') {
		if(shift == "right"){
			cout << dec(x,str2) << endl;
		}
		else{
                cout << enc(x, str2) << endl;
        }
	
   }
}
}
