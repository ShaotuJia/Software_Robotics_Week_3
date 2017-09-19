/**
 * @breif: This program is to extract a new function that returns the position
 * of the beginning of a given string in a given text
 * @author: Shaotu Jia
 */

#include <iostream>
#include <string>

/**
 * @breif: This function is to find the position of given string in a given text
 @ and following the way from code in Problem 9-4.
 * @param text A char array the given text
 * @param array_search A char array we want to find in the given text
 * @return position A integer represent of the position of search char array；
 * if cannot find matched array return -1
 */
 int beg_position_one (const char* text, const int& text_length, const char* array_search, const int& array_search_length) {

     int position = -1; ///< The position of the beginning of array_search in text

     for (int i = 0; i < text_length - array_search_length + 1; i++) {
         bool found = true;  ///< Whether find mathced chars

         for (int j = 0; j < array_search_length; j++) {
             found = (text[i + j] != array_search[j]) ? false : true;
         }

         if (found) {
             position = i;
             break;
         }

     }

     return position;

 }

/**
 * @breif: This function has same target to beg_position_one but accessing by easily way
 * @param text A char array the given text
 * @param array_search A char array we want to find in the given text
 * @return position A integer represent of the position of search char array;
 * if cannot find matched array return -1
 */
 int beg_position_two (const char* text, const char* array_search) {

     std::string str_text = text;    ///< convert char array to std::string
     std::string str_array = array_search;    ///< convert char array to std::string
     std::size_t found = str_text.find(str_array);  ///< find the position of str_array in str_text

     if (found != std::string::npos) {
         return found;
     } else {
         return -1;
     }

 }


 int main() {
     char text[1024] = "1234567890";
     char array_search[4] = "34";
     int text_length = 10;
     int array_search_length = 2;
     auto array_position_one = beg_position_one(text, text_length, array_search, array_search_length);
     std::cout << " The position using beg_position_one function: \n" << array_position_one << "\n";
     auto array_position_two = beg_position_two(text, array_search);
     std::cout << " The position using beg_position_two function: \n" << array_position_two << "\n";

 }
