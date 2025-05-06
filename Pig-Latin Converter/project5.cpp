/********************************************************************************************
* File         : project5.cpp
* Course       : CSC 136 — Spring 2025
* Author       : Shivamani Jadi
* Major        : Computer and Information Sciences
* Section      : 010         
* Creation Date: 05/05/2025
* Due Date     : 05/05/2025  
* Professor    : Yong Zhang       
* Assignment   : Project 5 – Pig-Latin Converter
* Purpose      : Read words from stdin, build a char linked list for each,
*                rotate consonants via rotate(), and print the Pig-Latin form.
********************************************************************************************/

#include <iostream>
#include <string>
#include <cctype>
#include "linkedList.h"

using namespace std;

/*****************************************************************
* Function name: isVowel
* Description  : Determines whether a character is a vowel
*                (a, e, i, o, u, y), case-insensitive.
* Parameters   : c (char) — the character to test.
* Returns      : true if c is a vowel; false otherwise.
*****************************************************************/
bool isVowel(char c)
{
    switch (tolower(static_cast<unsigned char>(c)))
    {
        case 'a': case 'e': case 'i':
        case 'o': case 'u': case 'y':
            return true;
        default:
            return false;
    }
}

/*****************************************************************
* Function name: toPigLatin
* Description  : Converts a single word to Pig-Latin using only
*                linkedListType<char>::rotate().
* Parameters   : word (const string&) — the input word.
* Returns      : The Pig-Latin equivalent string.
*****************************************************************/
string toPigLatin(const string& word)
{
    if (word.empty())
        return "";

    // 1) Build a linked list of the word’s characters
    linkedListType<char> lst;
    for (char ch : word)
        lst.insertLast(ch);

    // 2) Check for any vowel
    bool hasVowel = false;
    for (char ch : word)
        if (isVowel(ch)) { hasVowel = true; break; }

    // Rule 1: no vowels → append "-way"
    if (!hasVowel)
        return word + "-way";

    // Rule 2: begins with vowel → append "-way"
    if (isVowel(word.front()))
        return word + "-way";

    // Rule 3: rotate leading consonant(s) until a vowel is at front
    int     rotations = 0;
    string  rotated   = word;
    const int len     = static_cast<int>(word.length());

    while (!isVowel(rotated.front()) && rotations < len)
    {
        lst.rotate();                               // required by spec
        rotated = rotated.substr(1) + rotated.front();
        ++rotations;
    }

    // Build and return final Pig-Latin form
    return rotated + "-" + word.substr(0, rotations) + "ay";
}

/*****************************************************************
* Function name: main
* Description  : Repeatedly prompts the user, reads a word,
*                converts it to Pig-Latin, and prints it.
* Parameters   : none
* Returns      : 0 on normal termination.
*****************************************************************/
int main()
{
    string word;
    while (true)
    {
        cerr << "Enter a string: ";   // goes to stderr
        if (!(cin >> word))           // EOF reached?
            break;

        cout << toPigLatin(word) << '\n';
    }
    return 0;
}
