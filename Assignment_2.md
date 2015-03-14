This page will include a description of the second problem assignment, our implementation and design, and useful things that we've learned.

# Introduction #

Our second programming assignment was to decipher two encrypted files whose characters have all been rotated by some constant.  The most frequently occurring character is used to determine that constant by matching the most frequently occurring character with the letter 'e'.  So the number of rotations would equal the offset between the letter 'e' and the most frequently occurring character.  For example, if the most frequently occurring character is the letter 'j', then the offset would equal 21 or -5.  Afterwards, all the characters in the encrypted file would have to be rotated by 21 or -5.  More information about the assignment can be found at:  http://www.cs.utexas.edu/~downing/projects/c++/decipher/index.html

# Details #

## Input ##

If the command line argument was greater than 1, we knew to read in the characters from a text file, with the name of the file being the first argument.  Otherwise, the input is read from cin.  We made a char array of length 5000 to store the unaltered copy of the text file or the input from the cin. Because it's impossible to go through the keyboard input twice, that is why we store it in an array as the user typing in all the words.  We later used traversed the char array to rotate all the alpha characters by the offset. We think it is necessary to sotre the input in the temporary array anyway even if we just have the input from the text file because I/O is really slow compared to the C++ program itself.

## Computing the most frequently occurring character ##

To compute the most frequently occurring character in the file, we declared an int array of length 26, so each index of the array corresponds to a letter of the alphabet.  The array would store the number of occurrences of each letter.  In addition, our program would ignore case when computing the frequency of each character.

## Rotation of the text ##

The rotation of the text was case sensitive, unlike computing the most frequently occurring character.  However, only alpha characters were rotated, thus leaving alone numbers, symbols, and whitespaces.  We also  guarantee that the rotation would not be out of bounds.

## Output ##
The output will be the deciphered text file into the monitor(cout/standard output). Since our program used a pointer to access the characters in the char array, we dereference the pointer when outputting the rotated characters to the output file while incrementing it at each step.

Through this assignment, we have learned about the operations that can be done on a pointer and I/O from an input file versus cin.