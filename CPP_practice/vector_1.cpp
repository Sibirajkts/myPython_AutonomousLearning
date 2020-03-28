#include <iostream>
#include <vector>

using namespace std;

int main()
{
vector <int> test_scores {100,95,99,87,88};

cout<<test_scores[0]<<"\t"<<test_scores.at(0)<<endl;
cout<<test_scores[1]<<"\t"<<test_scores.at(1)<<endl;
cout<<"sizeof test_scores:"<<test_scores.size()<<endl;
//cout<<"Bound check in vector while using at"<<endl;
//cout<<test_scores.at(10)<<endl;
test_scores.push_back(70);
test_scores.push_back(71);
cout<<"sizeof test_scores:"<<test_scores.size()<<endl;
cout<<test_scores[6]<<"\t"<<test_scores.at(6)<<endl;
//-----------------------------------------------------------

vector <int> test_score2 (3,20);
cout<<"\n\nvector intiialized with 20:"<<endl;
cout<<test_score2[0]<<"\t"<<test_score2.at(0)<<endl;
cout<<test_score2[1]<<"\t"<<test_score2.at(1)<<endl;
vector <int> test_score8 {0};
cout<<"\n\nvector intiialized8:"<<endl;
cout<<test_score8.size()<<"\t"<<test_score8[0]<<"\t"<<test_score8.at(0)<<endl;
//cout<<test_score8[1]<<"\t"<<test_score8.at(1)<<endl;

vector <int> test_score3 (3);
cout<<"\n\nvector intiialized with 0:"<<endl;
cout<<test_score3[0]<<"\t"<<test_score3.at(0)<<endl;
cout<<test_score3[1]<<"\t"<<test_score3.at(1)<<endl;
int element1;
cout<<"enter an int"<<endl;
cin >> element1;
test_score3.push_back(element1);
cout<<"sizeof test_scores:"<<test_score3.size()<<endl;

vector <int> test_score4;
cout<<"\n\nsizeof test_scores:"<<test_score4.size()<<endl;

//------------------------------------------------------------
vector <vector<int>> movie_ratings 
{
 {1,2,3,4},
 {1,2,4} // to check out of bound, but compilation allowed
};

movie_ratings.push_back({1,3,4});

cout<<"\n\n2D vectors size:"<<movie_ratings.size()<<" : "<<movie_ratings.size()<<"x"<<movie_ratings.at(0).size()<<endl;
movie_ratings.at(0).at(0) = 8;
cout<<movie_ratings[0][0]<<"\t"<<movie_ratings.at(0).at(0)<<endl;
cout<<movie_ratings[2][3]<<"\t"<<movie_ratings.at(2).at(3)<<endl;//throws bound check exception as there is no column 4 in row 3



//------------------------------------------------------------
return 0;
}
