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
   string encFlag = argv[3];
   string inFile = argv[4];
   string outFile = argv[5];
   std::cout << inFile <<endl;
   std::cout << outFile << endl;
   std::cout << encFlag << endl;
   string final="";
    if(cipherName == "DES")
    {
      cipher = new DES();

      cipher->setKey((unsigned char*)key);
      ofstream MyFile;
      if(encFlag=="ENC"){
		string s;
		unsigned char* newc;
		// Read from the text file
		ifstream MyReadFile(inFile);

		// Use a while loop together with the getline() function to read the file line by line
		while (getline (MyReadFile, s)) {
		// Output the text from the file
			// cout << s;
			int n = s.length();
		
			// declaring character array
			char char_array[n + 1];
		
			// copying the contents of the
			// string to char array
			strcpy(char_array, s.c_str());

			newc = cipher->encrypt((unsigned char*)char_array);
			
			// final+=(string)newc;
			// cout << char_array;
		
			//TODO Write to a file
			// Create and open a text file
			// ofstream outfile;
			MyFile.open("temp.txt", ios::app);

			// // Write to the file
			// cout << newc;
			MyFile << newc;
			cout << endl << "Printed" << endl;

			// Close the file
			
		}
		// newc = cipher->encrypt((unsigned char*)char_array);
		// Close the file
		MyReadFile.close(); 
		MyFile.close();
        
      }else{
		string s;
		unsigned char* newc;

		ifstream MyReadFile(inFile);

		// Use a while loop together with the getline() function to read the file line by line
		while (getline (MyReadFile, s)) {
		// Output the text from the file
			// cout << s;
			int n = s.length();
		
			// declaring character array
			char char_array[n + 1];
		
			// copying the contents of the
			// string to char array
			strcpy(char_array, s.c_str());

			newc = cipher->decrypt((unsigned char*)char_array);
			
			
		}
		cout << newc;
		// MyReadFile.close(); 

		// //TODO Write to a file
		// // Create and open a text file
		// ofstream MyFile(outFile);

		// // Write to the file
		
		// MyFile << newc;

		// // Close the file
		// MyFile.close();
		
	  }
    }else{
      cipher = new AES();
	  std::cout << "DEcryption" << endl;
      cipher->setKey((unsigned char*)"0123456789abcdef");
	  if(encFlag=="ENC"){
		}else{
		}
    }
	/* Error checks */
	if(!cipher)
	{
		fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",	
		__FILE__, __FUNCTION__, __LINE__);
		exit(-1);
	}
	/* Perform encryption */
	// string cipherText = cipher->encrypt("hello world");
	
	/* Perform decryption */
	//cipher->decrypt(cipherText);	
	
	return 0;
}
