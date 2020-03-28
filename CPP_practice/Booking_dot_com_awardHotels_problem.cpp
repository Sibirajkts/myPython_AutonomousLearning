#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

//#define DEBUG
#undef DEBUG

/*
 * Complete the 'awardTopKHotels' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING positiveKeywords
 *  2. STRING negativeKeywords
 *  3. INTEGER_ARRAY hotelIds
 *  4. STRING_ARRAY reviews
 *  5. INTEGER k
 */

vector<int> awardTopKHotels(string positiveKeywords, string negativeKeywords, vector<int> hotelIds, vector<string> reviews, int k) {
    multimap<int,string> hotel_and_review;
    //map<int,string> hotel_and_review;
    map<int,int> hotel_and_score;
    auto j = reviews.begin();
    for(auto i=hotelIds.begin();(i!=hotelIds.end())&&(j!=reviews.end());i++,j++)
    {
        #ifdef DEBUG
        cout<<"vector: "<<(*i)<<(*j)<<endl;
        #endif
        hotel_and_review.insert(make_pair((*i),(*j)));
        //hotel_and_review[(*i)] = hotel_and_review[(*i)] + " " + (*j) ;
        hotel_and_score.insert(make_pair((*i),0));
        //hotel_and_score[(*i)] = 0;
    }
    #ifdef DEBUG
    cout<<"HOTEL and ITs review BEFORE: "<<hotel_and_review.size()<<endl;
    for(auto i=hotel_and_review.begin();i!=hotel_and_review.end();i++)
    {
        cout<<i->first<<"\t"<<i->second<<endl;
    }
    cout<<"HOTEL and ITs score BEFORE: "<<hotel_and_score.size()<<endl;
    int count = 0;
    for(auto i=hotel_and_score.begin();((i!=hotel_and_score.end())&&(count<hotel_and_score.size()));i++,count++)
    {
        cout<<i->first<<"\t"<<i->second<<endl;
    }
    #endif
    //return hotelIds;
    vector<string> pos,neg;
    string temp_word {};
    stringstream iss1 (positiveKeywords);
    while(iss1 >> temp_word)
        pos.push_back(temp_word);
    stringstream iss2 (negativeKeywords);
    while(iss2 >> temp_word)
        neg.push_back(temp_word);
    #ifdef DEBUG
    cout<<"Positive Key words:"<<endl;
    for(auto i:pos)
        cout<<i<<endl;
    cout<<"Negative key words:"<<endl;
    for(auto i:neg)
        cout<<i<<endl;
    #endif
    int score = 0;
    //for(auto &review=hotel_and_review.begin();review!=hotel_and_review.end();review++)
    for(auto &review:hotel_and_review)
    {
        score = 0;
        for(auto pword:pos)
        {
            int found = 0;
            do
            {
                found = review.second.find(pword);
                if(found != string::npos)
                {
                    score=score+2;
                    //found=found+pword.length();
                    found=found+1;
                    #ifdef DEBUG
                    cout<<"ID: "<<review.first<<" pword: "<<pword<<" score: "<<score<<endl;
                    #endif
                }
            } while(review.second.find(pword,found)!=string::npos);

            //if(review.second.find(pword) != string::npos)
            //    score=score+2;
        }
        for(auto nword:neg)
        {
            int found = 0;
            do
            {
                found = review.second.find(nword);
                if(found != string::npos)
                {
                    score=score-1;
                    found=found+1;
                    #ifdef DEBUG
                    cout<<"ID: "<<review.first<<" nword: "<<nword<<" score: "<<score<<endl;
                    #endif
                }
            } while(review.second.find(nword,found)!=string::npos);
            //if(review.second.find(nword) != string::npos)
            //    score=score-1;
        }
        hotel_and_score[review.first] += score;
        #ifdef DEBUG
        cout<<"ID: "<<review.first<<" current score: "<<hotel_and_score[review.first]<<endl;
        #endif
    }
#ifdef DEBUG
    {
        cout<<"HOTEL and ITs score AFTER: "<<hotel_and_score.size()<<endl;
        int count = 0;
        for(auto i=hotel_and_score.begin();((i!=hotel_and_score.end())&&(count<hotel_and_score.size()));i++,count++)
        {
            cout<<i->first<<"\t"<<i->second<<endl;
        }
    }
#endif

        vector<pair<int,int>> maptoVec(hotel_and_score.begin(),hotel_and_score.end());
        vector<int> sorted_hotelIds;
        sort(maptoVec.begin(),maptoVec.end(),[](const pair<int,int> &a,const pair<int,int> &b){ return (a.second > b.second); } );
      #ifdef DEBUG
        cout<<"sorted hotel and its score after:"<<maptoVec.size()<<endl;
      #endif
        for (auto &i:maptoVec)
        {
            #ifdef DEBUG
            cout<<"Hotel Id:"<<i.first<<" score: "<<i.second<<endl;
            #endif
            sorted_hotelIds.push_back(i.first);
        }

    #ifdef DEBUG
    cout<<"END"<<endl;
    #endif
    return sorted_hotelIds;
}

int main()
{
    ifstream fin("Booking_input000.txt");

    string positiveKeywords;
    getline(fin, positiveKeywords);

    string negativeKeywords;
    getline(fin, negativeKeywords);

    string hotelIds_count_temp;
    getline(fin, hotelIds_count_temp);

    int hotelIds_count = stoi(ltrim(rtrim(hotelIds_count_temp)));

    vector<int> hotelIds(hotelIds_count);

    for (int i = 0; i < hotelIds_count; i++) {
        string hotelIds_item_temp;
        getline(fin, hotelIds_item_temp);

        int hotelIds_item = stoi(ltrim(rtrim(hotelIds_item_temp)));

        hotelIds[i] = hotelIds_item;
    }

    string reviews_count_temp;
    getline(fin, reviews_count_temp);

    int reviews_count = stoi(ltrim(rtrim(reviews_count_temp)));

    vector<string> reviews(reviews_count);

    for (int i = 0; i < reviews_count; i++) {
        string reviews_item;
        getline(fin, reviews_item);

        reviews[i] = reviews_item;
    }

    string k_temp;
    getline(fin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    vector<int> result = awardTopKHotels(positiveKeywords, negativeKeywords, hotelIds, reviews, k);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    fin.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

