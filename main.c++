// ------------------------------
// projects/c++/decipher/main.c++
// Copyright (C) 2009
// Glenn P. Downing
// ------------------------------

// To run the tests:
//     g++ -ansi -pedantic -lcppunit -ldl -Wall -DTEST main.c++ -o main.app
//     valgrind main.app

// To run the program:
//     g++ -ansi -pedantic -Wall main.c++ -o main.app
//     valgrind main.app < main.in > main.out

// To configure Doxygen:
//     doxygen -g
// That creates the file Doxyfile.
// Make the following edits:
//     EXTRACT_ALL            = YES
//     EXTRACT_PRIVATE        = YES
//     EXTRACT_STATIC         = YES
//     GENERATE_LATEX         = NO

// To document the program:
//     doxygen Doxyfile

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // cout, endl, ios_base, noskipws
#include <fstream>  // ifstream
#include <string>
#ifdef TEST
    #include "cppunit/TestSuite.h"      // TestSuite
    #include "cppunit/TextTestRunner.h" // TestRunner

    #include "TestDecipher.h"
#endif // TEST

#include "Decipher.h"
void printArray();
// ----
// main
// ----
static char text[5000];
int main (int argc, char* argv[]) {
    using namespace std;
    using namespace Decipher;

    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    #ifdef TEST
        // ----------
        // unit tests
        // ----------

        using namespace CppUnit;

        TextTestRunner tr;
        tr.addTest(TestDecipher::suite());
        tr.run();
    #else
        // -------
        // program
        // -------

        istream* p = &cin;
        ifstream in;
        if (argc > 1) {
            in.open(argv[1]);
            assert(in);
            in >> noskipws;
            // must change so we write into the static char array instead
            p = &in;}
        assert(*p);
        *p >> noskipws;
        assert(*p);
        // rewrite the code below
        
        char* ind = text;
        char c;
        while (*p >> c){
           // cout << c;
        *ind = c; ++ind;
	}
	c = max_frequency(text, ind);
	cout << "THIS IS C: " << c << endl; 
	rotate(text, ind, 'e' - c);
        char* b = text;
        while (b < ind){
            assert(b >= text && b < ind);
            cout<< *(b++);
        }
    #endif // TEST
    in.close();
    return 0;}

void printArray(){
	for(int i=0; i<5000; i++){
	std::cout << text[i];
	}
}

