#include "doctest.h"
#include "Direction.hpp"
#include "Notebook.hpp"
#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;
using namespace ariel;


TEST_CASE("Good input")
{
	Notebook n, n1, n2;
    
	n1.write(3,3,1,Direction::Horizontal,"Hello");
    CHECK(n1.read(3,3,0,Direction::Horizontal, 7) == "_hello_");
    
	n1.erase(3,3,2,Direction::Horizontal, 1);
    CHECK(n1.read(3,3,0,Direction::Horizontal, 7) == "_h~llo_");
    
	n1.erase(3,3,1,Direction::Horizontal, 5);
    CHECK(n1.read(3,3,0,Direction::Horizontal, 7) == "_~~~~~_");

    n2.write(0,0,0,Direction::Vertical, "world");
    CHECK(n2.read(0,0,0,Direction::Vertical, 6) == "world_");
    
	n2.erase(0,0,0,Direction::Vertical, 1);
    CHECK(n2.read(0,0,0,Direction::Vertical, 6) == "~orld_");
    
	n2.erase(0,0,0,Direction::Vertical, 5);
    CHECK(n2.read(0,0,0,Direction::Vertical, 5) == "~~~~~");

	CHECK_NOTHROW(n.write(0, 1, 99, Direction::Horizontal, "b"));
	CHECK_NOTHROW(n.read(0,0,99,Direction:: Horizontal,1)); 
    CHECK_NOTHROW(n.erase(0,0,0,Direction:: Horizontal,100));
	
}
	

TEST_CASE("bad input")
{
	Notebook n;

	CHECK_THROWS(n.erase(0, 0, 0, Direction::Horizontal, 101)); 
	CHECK_THROWS(n.read(0, 0, 0, Direction::Horizontal, 101)); 

    CHECK_THROWS(n.write(1,7,-1,Direction::Horizontal,"hello"));  
    CHECK_THROWS(n.write(1,7,-1,Direction::Vertical,"world"));  

    CHECK_THROWS(n.write(1,-1,7,Direction::Horizontal,"hello"));  
    CHECK_THROWS(n.write(1,-1,7,Direction::Vertical,"world"));  

    CHECK_THROWS(n.write(-1,7,1,Direction::Horizontal,"hello"));  
    CHECK_THROWS(n.write(-1,7,1,Direction::Vertical,"world"));  

	string text;
	for(int i = 0 ; i <= 100; i++){
        text+='e';
    }
    CHECK_THROWS(n.write(0,0,0,Direction:: Horizontal,text));

}

TEST_CASE("rewriting"){
  
    Notebook n1;
    n1.write(1, 3, 5, Direction::Horizontal, "hello");
    CHECK_THROWS(n1.write(1,3,8,Direction::Horizontal,"world")); 
	CHECK_THROWS(n1.write(1,3,12,Direction::Horizontal,"eb"));
	n1.erase(1,3,13,Direction::Horizontal,2);
    CHECK_THROWS(n1.write(1,3,13,Direction::Horizontal,"eb"));
    CHECK_NOTHROW(n1.erase(1,3,13,Direction::Horizontal,2));
	
}
