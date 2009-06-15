 // ------------------------------------
// projects/c++/decipher/TestDecipher.h
// Copyright (C) 2009
// Glenn P. Downing
// ------------------------------------

#ifndef TestDecipher_h
#define TestDecipher_h

// --------
// includes
// --------

#include <sstream> // istringtstream, ostringstream
#include <string>  // ==

#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END

#include "Decipher.h"

// ------------
// TestDecipher
// ------------

struct TestDecipher : CppUnit::TestFixture {
    // -------------
    // max_frequency
    // -------------

    void test_max_frequency_1 () {
        const char a[] = "X";
        const int  s   = std::strlen(a);
        CPPUNIT_ASSERT(Decipher::max_frequency(a, a + s) == 'x');}

    void test_max_frequency_2 () {
        const char a[] = "XyYz";
        const int  s   = std::strlen(a);
        CPPUNIT_ASSERT(Decipher::max_frequency(a, a + s) == 'y');}

    // ------
    // rotate
    // ------

    void test_rotate_1 () {
        char      a[] = "xyz";
        const int s   = std::strlen(a);
        Decipher::rotate(a, a + s, 1);
        CPPUNIT_ASSERT(!std::strcmp(a, "yza"));}

    void test_rotate_2 () {
        char      a[] = "xyz";
        const int s   = std::strlen(a);
        Decipher::rotate(a, a + s, -1);
        CPPUNIT_ASSERT(!std::strcmp(a, "wxy"));}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDecipher);
    CPPUNIT_TEST(test_max_frequency_1);
    CPPUNIT_TEST(test_max_frequency_2);
    CPPUNIT_TEST(test_rotate_1);
    CPPUNIT_TEST(test_rotate_2);
    CPPUNIT_TEST_SUITE_END();};

#endif // TestDecipher_h
