#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<iomanip>

using namespace std;

bool is_palindrome(const string &str)
{
    stack<char> s;
    queue<char> q;
    for(char c:str)
    {
        if(isalpha(c))
        {
            s.push(c);
            q.push(c);
        }
    }
    while(q.size() > 1)
    {
        char c1 = toupper(s.top());
        char c2 = toupper(q.front());
        s.pop();
        q.pop();
        if(c1 != c2)
            return false;
    }
    return true;
}

int main()
{
    vector<string> test_strings{
            "a","aaa","aba","aaabaaa","A Santa at NASA","C++","HII","hello"
        };
    cout<<boolalpha;
    cout<<setw(8)<<left<<"Result"<<"String"<<endl;
    for(auto &s:test_strings)
        cout<<setw(8)<<left<<is_palindrome(s)<<s<<endl;

    cout<<endl;
    return 0;
}
