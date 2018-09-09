#include <iostream>
#include <string>
#include "twitter.hpp"

using namespace std;

int main()
{
  string username;
  string message;
  cout << "Please enter your username: ";
  cin >> username;
  cin.ignore();
  cout << "Please input your message: ";
  getline(cin, message);
  // Insert code here to create a TwitterManager object and calling the
  // second constructor: provide a username and message from user input
  TwitterManager manager(username, message);
  // Insert code here that calls the TwitterManager object's display function.
  manager.display();
  return 0;
}
