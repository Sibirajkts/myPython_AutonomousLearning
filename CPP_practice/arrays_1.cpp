#include <iostream>

using namespace std;

int main()
{
    char vowels[] {'a','e','i','o','u'};
    cout<< "\nfirst vowel:"<<vowels[0]<<endl;
    cout<< "last vowel:"<<vowels[4]<<endl;
    int scores [5] {1};
    cout<<scores[0]<<"\t"<<scores[1]<<"\t"<<scores[2]
        <<"\t"<<scores[3]<<"\t"
        <<scores[4]<<endl;
    cout<<"Enter scores[3]:"<<endl;
    cin>>scores[3];
    cout<<"Enter scores[4]:"<<endl;
    cin>>scores[4];
    cout<<scores[0]<<"\t"<<scores[1]<<"\t"<<scores[2]
        <<"\t"<<scores[3]<<"\t"
        <<scores[4]<<endl;
    cout<<scores<<"\t"<<scores+1<<"\t"<<scores+2<<endl;

    int movie_ratings[3][4] { {1},{2},{3,4,5,6} };
    cout<<"0,0:"<<movie_ratings[0][0]<<" 0,1:"<<movie_ratings[0][1]<<endl;
    cout<<"1,0:"<<movie_ratings[1][0]<<" 1,1:"<<movie_ratings[0][1]<<endl;


    return 0;
}
