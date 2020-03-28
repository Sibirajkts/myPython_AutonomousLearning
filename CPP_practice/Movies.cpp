#include "Movies.h"

Movies::Movies()
{
	movies.clear();
}

Movies::~Movies()
{
	movies.clear();
}

bool Movies::add_movie(string name, int rating, int watched)
{
	for(const auto &movie:movies)
	{
		if(movie.get_name() == name)
			return false;
	}
	Movie temp{name,rating,watched};
	movies.push_back(temp);
	return true;
}

bool Movies::increment_watched(string name)
{
	for(const auto &movie:movies)
	{
		if(movie.get_name() == name)
		{
			movie.increment_watched();
			return true;
		}
	}
	return false;
}

void Movies::display_movies()
{
}
