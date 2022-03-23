
#include "Notebook.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include "Direction.hpp"

using namespace std;
namespace ariel
{
    void Notebook::write( int page,  int row,  int col, Direction d, string const &t)
    {
       
    }
    string Notebook::read( int page,  int row,  int col, Direction d,  int len)
    {
        return "read";
    }
    void Notebook::erase( int page,  int row,  int col, Direction d,  int len)
    {
    }
    void Notebook::show( int page)
    {
    }
}