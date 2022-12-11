#include <string>
#include "CipherInterface.h"
#include "DES.h"
#include "AES.h"
#include<iostream>
#include <fstream> 

using namespace std;

#include <string>
#include "CipherInterface.h"
#include "DES.h"
#include "AES.h"
#include<iostream>
#include <fstream> 

using namespace std;

int main(int argc, char** argv)
{
	/**
	 * TODO: Replace the code below	with your code which can SWITCH
	 * between DES and AES and encrypt files. DO NOT FORGET TO PAD
	 * THE LAST BLOCK IF NECESSARY.
	 *
	 * NOTE: due to the incomplete skeleton, the code may crash or
	 * misbehave.
	 */
	
	/* Create an instance of the DES cipher */	
	CipherInterface* cipher = NULL; 
	
	/* Set the encryption key
	 * A valid key comprises 16 hexidecimal
	 * characters. Below is one example.
	 * Your program should take input from
	 * command line.
	 */
   string cipherName = argv[1];
   char* key = argv[2];
   char* temp = 0;
   string encFlag = argv[3];
   string inFile = argv[4];
   string outFile = argv[5];

    if(cipherName == "DES")
    {
      cipher = new DES();

      cipher->setKey((unsigned char*)key);
      
      if(encFlag=="ENC"){
		
		ifstream MyReadFile(inFile);
		ofstream MyFile(outFile);
		unsigned char* newc;
		string s;

		if(MyReadFile && MyFile){
			while (getline (MyReadFile, s)) {
				int n = s.length();
				char array[n + 1];
				strcpy(array, s.c_str());

				newc = cipher->encrypt((unsigned char*)array);
				
				MyFile << newc;
				MyFile << "\n";
			}
			MyFile.close();
			MyReadFile.close();
		}
      }else{

		ifstream MyReadFile(inFile);
		ofstream MyFile(outFile);
		string s;
		unsigned char* newc;

		if(MyReadFile && MyFile){
			while (getline (MyReadFile, s)) {
				int n = s.length();
				char array[n + 1];
				strcpy(array, s.c_str());
				// cout << array << endl;
				newc = cipher->decrypt((unsigned char*)array);

				// cout << newc;
				MyFile << newc;
				MyFile << "\n";
			}
			MyFile.close();
			MyReadFile.close();
		}
	  }
    }else{
      cipher = new AES();
	        
	  if(encFlag=="ENC"){
		char a[3] = "00";
		
		strcat(key,a);
    
		cipher->setKey((unsigned char*)key);
		ifstream MyReadFile(inFile);
		ofstream MyFile(outFile);
		unsigned char* newc;
		string s;

		if(MyReadFile && MyFile){
			while (getline (MyReadFile, s)) {
				int n = s.length();
				char array[n + 1];
				strcpy(array, s.c_str());

				newc = cipher->encrypt((unsigned char*)array);
				
				MyFile << newc;
				MyFile << "\n";
			}
			MyFile.close();
			MyReadFile.close();
		}
	  }else{
		char a[3] = "01";
		
		strcat(key,a);
		
		cipher->setKey((unsigned char*)key);
		ifstream MyReadFile(inFile);
		ofstream MyFile(outFile);
		string s;
		unsigned char* newc;

		if(MyReadFile && MyFile){
			while (getline (MyReadFile, s)) {
				int n = s.length();
				char array[n + 1];
				strcpy(array, s.c_str());
				
				newc = cipher->decrypt((unsigned char*)array);

				MyFile << newc;
				MyFile << "\n";
			}
			MyFile.close();
			MyReadFile.close();
		}
	  }
    }
	/* Error checks */
	if(!cipher)
	{
		fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",	
		__FILE__, __FUNCTION__, __LINE__);
		exit(-1);
	}	
	
	return 0;
}
