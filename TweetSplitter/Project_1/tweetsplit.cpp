#include <iostream>
#include <string>
#include "twitter.hpp"
using namespace std;

int main()
{
  //get user input and declare message and name variables
  string message;
  string name;
  cout << "Please enter your username: ";
  cin >> name;
  cin.ignore();
  
  cout << "Please enter your message: ";
  getline(cin,message);
  
  //declear splits and split pointer
  int splits = 0;
  int* pSplits = &splits;
  
  //string array for the splited message
  string splitMessage[100];
  
  //call splitTweets to split the message
  splitTweets(message, splitMessage, &splits);
  
  //displays the messages
  displaySplitTweet(splitMessage, splits, name);
  return 0;
}
