#include<iostream>
#include<map>
#include<set>
#include<sstream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;


void display_words(const map<string, int> &words)
{
    cout<<setw(12)<<left<<"\nword"
        <<setw(7)<<right<<"Count"<<endl;
    cout<<"==================================="<<endl;
    for(auto pair:words)
        cout<<setw(12)<<left<<pair.first
            <<setw(7)<<right<<pair.second<<endl;
}

void display_words(const map<string, set<int>> &words)
{
    cout<<setw(12)<<left<<"\nword"
        <<"Occurences"<<endl;
    cout<<"==================================="<<endl;
    for(auto pair: words)
    {
        cout<<setw(12)<<left<<pair.first
            <<left<<"[";
        for(auto i:pair.second)
        {
            cout<<i<<" ";
        }
        cout<<"]"<<endl;
    }
}

void part1()
{
    map<string,int> words;
    string line {};
    string word {};
    ifstream infile {"words.txt"};
    if(infile)
    {
        while(getline(infile,line))
        {
            stringstream ssm {line};
            while(ssm>>word)
            {
                words[word]++;
            }
        }
        infile.close();
        display_words(words);
    }
    else
    {
        cerr<<"Error Opening File"<<endl;
    }
}

void part2()
{
    map<string, set<int>> words;
    string line {};
    string word {};
    int line_no = 0;
    ifstream infile {"words.txt"};
    if(infile)
    {
        while(getline(infile,line))
        {
            line_no++;
            stringstream ssm {line};
            while(ssm >> word)
            {
                words[word].insert(line_no);
            }
        }
        infile.close();
        display_words(words);

    }
    else
    {
        cerr<<"Error Opening File"<<endl;
    }
}


int main()
{
    part1();
    part2();
    return 0;
}
