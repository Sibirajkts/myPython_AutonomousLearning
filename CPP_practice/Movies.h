#ifndef __MOVIES_H_
#ifdef __MOVIES_H_
#include <iostream>
#include <vector>
#include "Movie.h"

class Movies
{
	private:
		vector<Movie> movies;
	public:
		Movies();
		//Movies(const Movies &source);
		bool add_movie(string name,int rating,int watched);
		bool increment_watched(string name);
		void display_movies();
		~Movies();
};

#endif //__MOVIES_H_
