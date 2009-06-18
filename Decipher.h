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
 * @param alpha is the array that we are searching for the max
 * @return the most frequently occuring character in the array
 * it will just return 'a' if there is no alphabetical character in the text
*/
char max_char(int alpha[26]){
    int index = 0, max = 0;
    for(int i=0; i < 26; i++){
       if(alpha[i]>max){
        max = alpha[i];
        index = i;
	  }
	}
     assert(index<26 && index>=0);
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
    int alpha[26] = {0}; // array to represent all the 26 letters of alphabet
    while (b != e){
    	if (std::isalpha(*b)){
    	temp = std::tolower(*b);
    	index = (int)(temp)-(int)'a'; //add the count of the char into the corresponding index at the array
    	alpha[index]++; //increment the value inside the array
    	}
    b++; //move the ptr forward
    }
    char max = max_char(alpha);
    assert(max >='a' && max <= 'z');
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
    r = r % 26; //truncate r so  r < 26
    assert(b < e);
    while(b!=e){
    	char& c = *b;  // use c as an alias of b
    	if(std::isalpha(c)){ //check if it's an alphabetical character
    	   if(std::isupper(c)){
    	   c = c + r;
    	     if((int)c>'Z') c = c - 26;  //check if it's out of bound and then restore it
             else if((int)c<'A') c = c +26;
    	   }
    	   else if(std::islower(c)){
    	   c = c + r;
    	     if((int)c>'z') c = c - 26;
	     else if((int)c<'a') c = c + 26;
    	   }
    	}
    b++; //incrementing the pointer
    }
   }

} // Decipher
#endif
