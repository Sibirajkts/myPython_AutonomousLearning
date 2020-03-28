#ifndef __MOVIE_H_
#ifdef __MOVIE_H_
#include <iostream>
#include <string>

using namespace std;

class Movie
{
	private:
		string name;
		int watched;
		int rating;
	public:
		Movie(string name,int watched, int rating);
		Movie();
		Movie(const Movie &source);
		void set_name(const string &name);
		{
			this->name = name;
		}
		string get_name const()
		{
			return name;
		}
		int set_rating(const int &rating)
		{
			this->rating = rating;
		}
		int get_rating const()
		{
			return rating;
		}
		int set_watched(const int watched)
		{
			this->watched = watched;
		}
		int get_watched const()
		{
			return watched;
		}
		~Movie();
		void display_movie const();
		void increment_watched();
};

#endif //__MOVIE_H_
