#ifndef TWITTER_HPP // This code prevents multiple includes of twitter.hpp
#define TWITTER_HPP

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int splitCount(string s);
string counterAdder(string s, int splits, int length);

class Tweet
{
  private:
    //declare username, message, and charLength
    string username; 
    string message;  
    int charLength;  
  public:
    //default constructor
    Tweet()
    {
      username.clear();
      message.clear();
      charLength = 0;
    }
    
    //condtional constructor
    Tweet(string name, string m)
    {
      username = name; 
      message = m;
      charLength = message.length();
    }
    
    //setter for Username
    void setUsername(string s)
    {
      username = s;
    }
    //getter for username
    string getUsername()
    {
      return username;
    }
    //setter for message
    void setMessage(string s)
    {
      message = s;
      charLength = message.length();
    }
    //getter for message
    string getMessage()
    {
      return message;
    }
    
    int getCharLength()
    {
      return charLength;
    }
    //function prototype for display
    void display();
};

class TwitterManager
{
  private:
    //declare username, message, length, and tweet array pointer
    string username; 
    string message;  
    int length;
    Tweet* tweets;
    
    //function prototype for splitTweets
    void splitTweets();
    
  public:
    //default constructor for TwitterManager
    TwitterManager()
    {
      username.clear();
      message.clear();
      tweets = new Tweet [100];
      length = 0;
    }
    
    //conditional constructor for TwitterManager
    TwitterManager(string name, string m)
    {
      tweets = new Tweet [100];
      length = 0;
      setUsername(name);
      setMessage(m);
    }
    
    //setter for username
    void setUsername(string s)
    {
      username = s;
    }
    //getter for username
    string getUsername()
    {
      return username;
    }
    //getter for length
    int getLength()
    {
      return length;
    }
    //setter for message
    void setMessage(string s)
    {
      message = s;
      splitTweets();
    }
    //function prototype for display, splitCount, and counterAdder
    void display();
    int splitCount(string s);
    string counterAdder(string s, int splits, int length);
};
#endif
