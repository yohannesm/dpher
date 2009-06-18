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

#ifdef TEST
    #include "cppunit/TestSuite.h"      // TestSuite
    #include "cppunit/TextTestRunner.h" // TestRunner

    #include "TestDecipher.h"
#endif // TEST

#include "Decipher.h"

// ----
// main
// ----

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
	static char text[5000];
        istream* p = &cin;
        ifstream in;
        if (argc > 1) {
            in.open(argv[1]); //opening the file from argv[1]
            assert(in);
            in >> noskipws; 
            p = &in;}
        assert(*p);
        *p >> noskipws; //don't skip whitespaces
        assert(*p);
        // rewrite the code below
        char* ind = text;
        char c;
        while (*p >> c){ //read the input either from the keyboard or the file
           // cout << c;
        *ind = c; // copy the input to the text[] 
         ++ind;
	}
	c = max_frequency(text, ind);
	rotate(text, ind, 'e' - c);
        char* t = text;
        //outputting the decyphered file into the standard output
        while (t < ind){
            assert(t >= text && t < ind);
            cout<< *(t++);
        }
        in.close(); //close the file
    #endif // TEST

    return 0;}

