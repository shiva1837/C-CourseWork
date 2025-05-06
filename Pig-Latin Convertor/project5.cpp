/********************************************************************************************
* File         : project5.cpp
* Course       : CSC 136 — Spring 2025
* Section      : 020
* Author       : Shivamani Jadi
* Date         : 05/05/2025
* Professor    : Zhang
* Assignment   : Project 5 – Pig-Latin Converter
* Purpose      : Read words from stdin, build a char linked list,
*                call rotate() to find split point, and print
*                both the original and Pig-Latin strings.
********************************************************************************************/

#include <iostream>
#include <string>
#include <cctype>
#include "linkedList.h"

using namespace std;

// Return true if c is a vowel (a, e, i, o, u, y), case-insensitive
bool isVowel(char c)
{
    c = tolower(static_cast<unsigned char>(c));
    return (c=='a' || c=='e' || c=='i' ||
            c=='o' || c=='u' || c=='y');
}

// Convert a word to Pig Latin using only linkedListType<char>::rotate()
string toPigLatin(const string& word)
{
    if (word.empty())
        return "";

    // Build a character list of the word
    linkedListType<char> lst;
    for (char ch : word)
        lst.insertLast(ch);

    // Check if any vowel exists
    bool hasVowel = false;
    for (char ch : word)
        if (isVowel(ch)) { hasVowel = true; break; }

    // No vowels => append "-way"
    if (!hasVowel)
        return word + "-way";

    // Starts with vowel => append "-way"
    if (isVowel(word.front()))
        return word + "-way";

    // Otherwise, rotate until a vowel is at the front
    int len = word.size();
    int moves = 0;
    while (moves < len && !isVowel(lst.front()))
    {
        lst.rotate();
        ++moves;
    }

    // Build Pig-Latin: tail part + "-" + head part + "ay"
    string tail = word.substr(moves);
    string head = word.substr(0, moves);
    return tail + "-" + head + "ay";
}

int main()
{
    string word;
    // Read each word; print prompt and results only when input succeeds
    while (cin >> word)
    {
        cerr << "Enter a string:\n";
        string pig = toPigLatin(word);
        cout << "The string you entered is: " << word << '\n';
        cout << "The pig Latin form of the string: " << pig << "\n\n";
    }
    return 0;
}
