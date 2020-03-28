//
// Character Filter
//
// (C) By Autonomous Intelligent Driving GmbH
//
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <deque>
#include <algorithm>
#include <fstream>
#include <sstream>

class AlphaNumericPredicate {
    // Fill implementation here
public:
    bool operator()(char c)
    {
        return (isalnum(c));
    }
};

namespace impl
{
    template < typename T > inline void do_print( const T& v, std::ostream& stm ) { stm << v << ' ' ; }

        template < typename F, typename S > // print pair
            inline void do_print( const std::pair<F,S>& p, std::ostream& stm )
                { stm << '{' << p.first << ',' << p.second << "} " ; } }

                template < typename... ARGS, template < typename... > class SEQ  > // print for standard contaners
                void printV( const SEQ<ARGS...>& seq, std::ostream& stm = std::cout, typename SEQ<ARGS...>::iterator* = 0  )
                { stm << "[ " ; for( const auto& v : seq ) impl::do_print(v,stm) ; stm << "]\n" ; }

/*
template <typename T>
void printV(std::T<char> &v)
{
    std::cout<<"[";
    for(auto &i:v)
        std::cout<<i<<",";
    std::cout<<"]"<<std::endl;
}*/
template<typename InputIterator, typename OutputIterator, typename UnaryPredicate>
OutputIterator filter(InputIterator first, InputIterator last,
                      OutputIterator result,
                      UnaryPredicate predicate,
                      size_t history_size)
{
    std::deque<char> visited;
    result = first;
    visited.clear();
    //std::cout<<"history_size: "<<history_size<<std::endl;
    // Fill implementation here
    while(first != last)
    {
        //std::cout<<"1: "<<(*first)<<std::endl;
        if(predicate((*first)))
        {
            //std::cout<<"2: "<<(*first)<<std::endl;
            auto position_it = find(visited.begin(),visited.end(),(*first));

            if( ( history_size == 0 ) || ( position_it == visited.end() ))
            {
                //std::cout<<"3: "<<(*first)<<std::endl;
                (*result) = (*first);
                ++result;
            }
            visited.push_back(*first);
            //printV(visited);
            if( (visited.size() > history_size) && (history_size > 0) )
            {
                //visited.erase(visited.begin());
                visited.pop_front();
                //printV(visited);
            }
        }
        ++first;
    }
    return result;
}

//
// Filter string. Helper for mapping binary blobs to strings.
//
std::string filter_string(std::string source, size_t history_size)
{
    source.erase(filter(std::begin(source), std::end(source),
                        std::begin(source),
                        AlphaNumericPredicate{}, history_size),
                 std::end(source));
    return source;
}

//
// Main entry point.
//
int main()
{
    std::ifstream fin {"char_filter_input000.txt"};
    size_t history_size = 0;
    std::string source;
    std::string temp_line;
    while (std::getline(fin, temp_line))
    {
        std::stringstream ssm {temp_line};
        if(ssm >> history_size)
        {
            std::getline(ssm, source, '\n');
            std::cout<< " hs: "<<history_size<<" src: "<<source<<std::endl;
            std::cout << filter_string(source, history_size) << std::endl;
        }
    }
    return 0;
}

