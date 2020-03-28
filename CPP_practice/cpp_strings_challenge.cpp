#include <iostream>
#include <string>
using namespace std;
int main()
{
	string alphabet {" }abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	string key      {"{ XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
	string input_message {};
	string encrypted_msg {};
	string decrypted_msg {};
	cout<<"Enter your secret message: ";	
	getline(cin,input_message);
	for(auto a : input_message)
	{
		size_t letter_pos = alphabet.find(a);
		if(letter_pos != string::npos)
		{
			encrypted_msg += key.at(letter_pos);
		}
		else
		{
			encrypted_msg += a;
		}
	}
	cout<<"\nEncrypted Message: "<<encrypted_msg<<endl;
	
	
	for(auto a : encrypted_msg)
	{
		size_t letter_pos = key.find(a);
		if(letter_pos != string::npos)
		{
			decrypted_msg += alphabet.at(letter_pos);
		}
		else
		{
			decrypted_msg += a;
		}
	}

	cout<<"\nDecrypted Message: "<<decrypted_msg<<endl;
	cout<<endl;
	return 0;
}
