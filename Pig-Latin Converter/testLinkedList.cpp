#include "linkedList.h"
#include <iostream>

using namespace std;

int main()
{

  cout << "Create an integer list:\n";
  
  //create an integer list
  linkedListType<int> intList;
  for (int i = 1; i <= 7; i++)
    intList.insertLast(i);
  intList.print();

  //testing rotate()
  cout << "After rotating once:\n";
  intList.rotate();
  intList.print();

  
  //testing deleteKthNode()
  cout << "Delete the third node:\n";
  intList.deleteKthNode(3);
  intList.print();
  
  cout << "\n";

  //create a char list
  linkedListType<char> charList;
  string s = "abcdefgh";

  //insert into list
  for (int i = 0; i < s.length(); i++) 
    charList.insertLast(s[i]);

  //testing rotate()
  cout << "Create a character list:\n";
  charList.print();

  for (int i = 0; i < 3; i++)
    charList.rotate();
  cout << "After rotating three times:\n";
  charList.print();  

  
  //testing deleteKthNode()
  cout << "Delete the first node:\n";
  charList.deleteKthNode(1);
  charList.print();
  
  cout << "Delete the last node:\n";
  charList.deleteKthNode(7);
  charList.print();
  
}
