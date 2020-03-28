#include <iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<iomanip>

using namespace std;

int main()
{

string s {};
deque<char> d;
cout<<"Enter a string to check if it is palindrome:\n";
getline(cin,s);

for(char c:s)
{
	if(isalpha(c))
		d.push_back(c);
}

char c1 {};
char c2 {};

while(d.size() > 1)
{
	c1=d.front();
	c2=d.back();
	d.pop_front();
	d.pop_back();
	if(c1 != c2)
	{
		cout<< "String : \"" << s <<"\" is not a palindrome" <<endl;
		return 0;
	}
}

cout<< "String : \"" << s << "\" is a Plalindrome"<<endl;

return 0;
}

