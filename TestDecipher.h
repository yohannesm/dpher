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
	void test_max_frequency_3 () {
		const char a[] = "LWEIlkdl kfIOESL 982 34LKSDFaaaaaaa  aaaaaaa (*&^%&^aaaaaaaaaaaaaaaaa";
		const int  s   = std::strlen(a);
		CPPUNIT_ASSERT(Decipher::max_frequency(a, a + s) == 'a');}
	void test_max_frequency_4 () {
		const char a[] = "hshshshsrdkfjsoi9384 o83 lskdfsod8fv 8w98fsdfi rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr";
		const int  s   = std::strlen(a);
		CPPUNIT_ASSERT(Decipher::max_frequency(a, a + s) == 'r');}
	void test_max_frequency_5 () {
		const char a[] = "234203948203413";
		const int  s   = std::strlen(a);
		CPPUNIT_ASSERT(Decipher::max_frequency(a, a + s) == 'a');} 
	void test_max_frequency_6 () {
		const char a[] = "bbCCc";
		const int  s   = std::strlen(a);
		CPPUNIT_ASSERT(Decipher::max_frequency(a, a + s) == 'c');}
	void test_max_frequency_7 () {
		const char a[] = " 	 	 	gggghSD__===__*&^*&LIFGggg";
		const int  s   = std::strlen(a);
		CPPUNIT_ASSERT(Decipher::max_frequency(a, a + s) == 'g');}
	void test_max_frequency_8 () {
		const char a[] = "Hello this is a test case for the max_frequency method";
		const int  s   = std::strlen(a);
		CPPUNIT_ASSERT(Decipher::max_frequency(a, a + s) == 'e');}
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
	CPPUNIT_TEST(test_max_frequency_3);
	CPPUNIT_TEST(test_max_frequency_4);
	CPPUNIT_TEST(test_max_frequency_5);
	CPPUNIT_TEST(test_max_frequency_6);
	CPPUNIT_TEST(test_max_frequency_7);
	CPPUNIT_TEST(test_max_frequency_8);
	CPPUNIT_TEST(test_rotate_1);
	CPPUNIT_TEST(test_rotate_2);
	CPPUNIT_TEST_SUITE_END();};

#endif // TestDecipher_h

