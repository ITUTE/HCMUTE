#include <bits/stdc++.h> 
#include <sstream>
#include <iostream>
using namespace std; 

void RLE(string plainText, string compressedText) 
{ 
	int n = plainText.length(); 
	ostringstream convert;
	for (int i = 0; i < n; i++) 
	{ 
		int count = 1; 
		while (i < n - 1 && plainText[i] == plainText[i + 1]) { 
			count++; 
			i++; 
		} 
		convert<<count;
		compressedText+=convert.str()+plainText[i];
	} 
} 

int main() 
{ 
	string plainText,compressedText;
	fflush(stdin);
	gets(plainText);
	RLE(plainText,compressedText);
	cin.ignore();
	puts(compressedText);
	return 0; 
} 

