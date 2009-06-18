// --------------------------------
// projects/c++/decipher/Decipher.h
// Copyright (C) 2009
// Glenn P. Downing
// --------------------------------

#ifndef Decipher_h
#define Decipher_h

// --------
// includes
// --------

#include <cassert> // assert
#include <cctype>  // is_alpha, is_lower, is_upper


// ----------
// namespaces
// ----------

namespace Decipher {


 // -------------
// max_char
// -------------
 
/**
 * @return the most frequently occuring character in the array
 */
char max_char(int alpha[26]){
    int index = 0, max = 0;
    for(int i=0; i < 26; i++){
       if(alpha[i]>max){
        max = alpha[i];
        index = i;
	  }
	}
     return (char)index + (int)'a';
     }
// -------------
// max_frequency
// -------------
 
/**
 * O(1)    in space
 * O(n)    in time
 * @param  b a pointer to the beginning of a cstring (inclusive)
 * @param  e a pointer to the end       of a cstring (exclusive) (b < e)
 * @return the character that occurs the most often in [b, e), in lower case
 * it is guaranteed that only ONE character will occur the most often
 * ignore non-alphabetic characters (numbers, punctuation, whitespace, etc.)
 * case IS NOT significant ('a' IS the same as 'A')
 */
char max_frequency (const char* b, const char* e) {
    assert(b < e);
    char temp ; int index;
    int alpha[26] = {0};
    while (b != e){
    	if (std::isalpha(*b)){
    	temp = std::tolower(*b);
    	index = (int)(temp)-(int)'a';
    	alpha[index]++;
    	}
    b++;
    }
    char max = max_char(alpha);
    return max;}

// ------
// rotate
// ------

/**
 * O(1)    in space
 * O(n)    in time
 * @param  b a pointer to the beginning of a cstring (inclusive)
 * @param  e a pointer to the end       of a cstring (exclusive) (b < e)
 * @param  r the amount to rotate to the right
 * rotate the alphabetic characters of [b, e) through the alphabet
 * by rotation 'r'
 * ignore non-alphabetic characters (numbers, punctuation, whitespace, etc.)
 * case IS significant ('a' IS NOT the same as 'A')
 */
void rotate (char* b, char* e, int r) {
    assert(b < e);
    while(b!=e){
    	char& c = *b;
    	if(std::isalpha(c)){
    	   if(std::isupper(c)){
    	   c = c + r;
    	     if((int)c>'Z') c = c - 26;
    	   }
    	   else if(std::islower(c)){
    	   c = c + r;
    	     if((int)c>'z') c = c - 26;
    	   }
    	}
    b++;
    }
   }

} // Decipher
#endif
