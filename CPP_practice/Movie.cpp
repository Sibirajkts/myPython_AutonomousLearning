#include "Movie.h"

Movie::Movie():Movie{"None",0,0}
{
	
}

Movie::Movie(string name,int watched, int rating)
 :name{name},watched{watched},rating{rating}
{
}

Movie::Movie(const Movie &source)
 :name{source.name},watched{source.watched},rating{source.rating}
{
}

Movie::~Movie()
{

}

Movie::display_movie const()
{
	cout<<name<<" "<<rating<<" "<<watched;
}

Movie::increment_watched()
{
	++watched;
}
