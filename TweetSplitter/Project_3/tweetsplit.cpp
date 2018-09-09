#include <iostream>
#include <string>
#include "twitter.hpp"

using namespace std;

int main()
{
  // Declare variables for username and message
  string username;
  string message;
  
  //ask for username and message input
  cout << "Please enter your username: ";
  cin >> username;
  cin.ignore();
  cout << "Please input your message: ";
  getline(cin, message);
  
  // Create TweetStream object using contional contructor
  TweetStream stream(username);
  
  // Add the user's message to the TweetStream
  stream.addMessage(message);
  
  // Display tweets in the TweetStream object
  stream.display();
  
  return 0;
}
