#include <string>
#include "CipherInterface.h"
#include "DES.h"
#include "AES.h"
#include<iostream>
#include <fstream> 
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define MAX_READ_SIZE 4096

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
		
		unsigned char* newc;

		// The input and output file descriptors
		int inFd = -1, outFd = -1;
		
		// To keep track of the number of bytes read/written
		int bytesRead = -1, bytesWritten = -1;
		
		// The buffer to hold the data read from the file
		char buff[MAX_READ_SIZE]={'\0'};
		
		// Open the source file for reading (O_RDONLY)
		inFd = open(argv[4], O_RDONLY);
		
		// Sanity check
		if(inFd < 0)
		{
			perror("open");
			exit(1);
		}
		
		// Open the destination file for writing (O_WRONLY)
		// If does not exist, create it (O_CREAT)
		// If exists, delete its contents (O_TRUNC)
		// Use permissions 0600
		outFd = open(argv[5], O_WRONLY | O_CREAT | O_TRUNC, 0600);
		
		// Sanity checks
		if(outFd < 0)
		{
			perror("open");
			exit(1);
		}
		
		// Keep reading until we reach the end of file
		while(bytesRead != 0)
		{
			// Read at most MAX_READ_SIZE.
			// Will return how many bytes were actually
			// read (could be less than MAX_READ_SIZE).
			// Will return 0 if the end of file was reached
			bytesRead = read(inFd, buff, MAX_READ_SIZE);
			
			// Sanity check
			if(bytesRead < 0)
			{
				perror("read");
				exit(1);
			}
			// Not at the end of the source file?
			// Write the data to the destination file
			else if(bytesRead != 0)
			{
				// Write the bytes to the destination file.
				// will return the number of bytes read
				// cout<< buff <<endl;
				// cout << bytesRead << endl;
				for(int i=0; i< bytesRead;){
				string newp="";
				int j=0;
				for(j=0;j<8;j++){
					newp+=buff[i];
					i++;
				}
				char* c = const_cast<char*>(newp.c_str());
				newc = cipher->encrypt((unsigned char*)c);
				int n = newp.length();
				bytesWritten = write(outFd, newc, n);
				}
				// Sanity checks
				if(bytesWritten < 0)
				{
					perror("write");
					exit(1);
				}
			}
			
		}
		
		// Close both files
		close(inFd);
		close(outFd);
      }else{

		unsigned char* newc;

		// The input and output file descriptors
		int inFd = -1, outFd = -1;
		
		// To keep track of the number of bytes read/written
		int bytesRead = -1, bytesWritten = -1;
		
		// The buffer to hold the data read from the file
		char buff[MAX_READ_SIZE];
		
		// Open the source file for reading (O_RDONLY)
		inFd = open(argv[4], O_RDONLY);
		
		// Sanity check
		if(inFd < 0)
		{
			perror("open");
			exit(1);
		}
		
		outFd = open(argv[5], O_WRONLY | O_CREAT | O_TRUNC, 0600);
		
		if(outFd < 0)
		{
			perror("open");
			exit(1);
		}
		
		// Keep reading until we reach the end of file
		while(bytesRead != 0)
		{
			// Read at most MAX_READ_SIZE.
			// Will return how many bytes were actually
			// read (could be less than MAX_READ_SIZE).
			// Will return 0 if the end of file was reached
			bytesRead = read(inFd, buff, MAX_READ_SIZE);
			// Sanity check
			if(bytesRead < 0)
			{
				perror("read");
				exit(1);
			}
			// Not at the end of the source file?
			// Write the data to the destination file
			else if(bytesRead != 0)
			{
				// Write the bytes to the destination file.
				// will return the number of bytes read
				for(int i=0; i< bytesRead;){
				
				string newp="";
				int j=0;
				for(j=0;j<8;j++){
					newp+=buff[i];
					i++;
				}
				char* c = const_cast<char*>(newp.c_str());
    			
				newc = cipher->decrypt((unsigned char*)c);
				bytesWritten = write(outFd, newc, newp.length());
				}
				// Sanity checks
				if(bytesWritten < 0)
				{
					perror("write");
					exit(1);
				}
			}
			}
			// Close both files
		close(inFd);
		close(outFd);
		}
    }else{
      cipher = new AES();
	        
	  if(encFlag=="ENC"){
		char a[3] = "00";
		
		strcat(key,a);
    
		cipher->setKey((unsigned char*)key);
		
		unsigned char* newc;

		// The input and output file descriptors
		int inFd = -1, outFd = -1;
		
		// To keep track of the number of bytes read/written
		int bytesRead = -1, bytesWritten = -1;
		
		// The buffer to hold the data read from the file
		char buff[MAX_READ_SIZE]={'\0'};
		
		// Open the source file for reading (O_RDONLY)
		inFd = open(argv[4], O_RDONLY);
		
		// Sanity check
		if(inFd < 0)
		{
			perror("open");
			exit(1);
		}
		
		// Open the destination file for writing (O_WRONLY)
		// If does not exist, create it (O_CREAT)
		// If exists, delete its contents (O_TRUNC)
		// Use permissions 0600
		outFd = open(argv[5], O_WRONLY | O_CREAT | O_TRUNC, 0600);
		
		// Sanity checks
		if(outFd < 0)
		{
			perror("open");
			exit(1);
		}
		
		// Keep reading until we reach the end of file
		while(bytesRead != 0)
		{
			// Read at most MAX_READ_SIZE.
			// Will return how many bytes were actually
			// read (could be less than MAX_READ_SIZE).
			// Will return 0 if the end of file was reached
			bytesRead = read(inFd, buff, MAX_READ_SIZE);
			
			// Sanity check
			if(bytesRead < 0)
			{
				perror("read");
				exit(1);
			}
			// Not at the end of the source file?
			// Write the data to the destination file
			else if(bytesRead != 0)
			{
				// Write the bytes to the destination file.
				// will return the number of bytes read
				// cout<< buff <<endl;
				// cout << bytesRead << endl;
				for(int i=0; i< bytesRead;){
				string newp="";
				int j=0;
				for(j=0;j<16;j++){
					newp+=buff[i];
					i++;
				}
				char* c = const_cast<char*>(newp.c_str());
				newc = cipher->encrypt((unsigned char*)c);
				int n = newp.length();
				bytesWritten = write(outFd, newc, n);
				}
				// Sanity checks
				if(bytesWritten < 0)
				{
					perror("write");
					exit(1);
				}
			}
			
		}
		
		// Close both files
		close(inFd);
		close(outFd);
	  }else{
		char a[3] = "01";
		
		strcat(key,a);
		
		cipher->setKey((unsigned char*)key);
		unsigned char* newc;

		// The input and output file descriptors
		int inFd = -1, outFd = -1;
		
		// To keep track of the number of bytes read/written
		int bytesRead = -1, bytesWritten = -1;
		
		// The buffer to hold the data read from the file
		char buff[MAX_READ_SIZE];
		
		// Open the source file for reading (O_RDONLY)
		inFd = open(argv[4], O_RDONLY);
		
		// Sanity check
		if(inFd < 0)
		{
			perror("open");
			exit(1);
		}
		
		outFd = open(argv[5], O_WRONLY | O_CREAT | O_TRUNC, 0600);
		
		if(outFd < 0)
		{
			perror("open");
			exit(1);
		}
		
		// Keep reading until we reach the end of file
		while(bytesRead != 0)
		{
			// Read at most MAX_READ_SIZE.
			// Will return how many bytes were actually
			// read (could be less than MAX_READ_SIZE).
			// Will return 0 if the end of file was reached
			bytesRead = read(inFd, buff, MAX_READ_SIZE);
			// Sanity check
			if(bytesRead < 0)
			{
				perror("read");
				exit(1);
			}
			// Not at the end of the source file?
			// Write the data to the destination file
			else if(bytesRead != 0)
			{
				// Write the bytes to the destination file.
				// will return the number of bytes read
				for(int i=0; i< bytesRead;){
				
				string newp="";
				int j=0;
				for(j=0;j<16;j++){
					newp+=buff[i];
					i++;
				}
				char* c = const_cast<char*>(newp.c_str());
    			
				newc = cipher->decrypt((unsigned char*)c);
				bytesWritten = write(outFd, newc, newp.length());
				}
				// Sanity checks
				if(bytesWritten < 0)
				{
					perror("write");
					exit(1);
				}
			}
			}
			// Close both files
		close(inFd);
		close(outFd);
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
