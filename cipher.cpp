#include <string>
#include "CipherInterface.h"
#include "DES.h"
#include "AES.h"
#include<iostream>

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

    if(cipherName  == "DES")
    {

      cipher = new DES();

      cipher->setKey((unsigned char*)"0123456789abcdef");
      std::cout << typeof(argv[3]);
      if(argv[3]=="ENC"){
        cipher->encrypt((unsigned char*)"HI");
      }
    }else{
      cipher = new AES();
      cipher->setKey((unsigned char*)"0123456789abcdef");
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
