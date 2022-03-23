#include <iostream>
#include <string>
#include <stdexcept>
#include "Direction.hpp"

using namespace std;

namespace ariel{
    class Notebook
    {
        private:

        public:
            Notebook(){
                return;
            }
        static void write(int page,  int row,  int col, Direction d, string const &t);
        static string read( int page,  int row,  int col, Direction d,  int len);
        static void erase( int page,  int row,  int col, Direction d,  int len);
        void show( int page);
    };
    
}