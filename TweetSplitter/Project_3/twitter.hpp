#ifndef TWITTER_HPP
#define TWITTER_HPP

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

//Tweet Class
class Tweet
{
  protected:
    //declare username, message, and charLength
    string username; 
    int charLength;
    string message; 
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
    virtual void setMessage(string s)
    {
      message = s;
      charLength = message.length();
    }
    
    //getter for message
    string getMessage()
    {
      return message;
    }
    
    //getter for charLength
    int getCharLength()
    {
      return charLength;
    }
    
    //function prototype for display
    virtual void display();
};

// MultiTweet class inherites from Tweet class
class MultiTweet: public Tweet
{
  private:
    //declare size and string array
    string* subMessage = new string[100];
    int size;
    
public:
    //conditional constructor
    MultiTweet(string u, string m)
    {
        size = 0;
        username = u;
        setMessage(m);
    }
    
    //overrides tweet's setMessage function
    void setMessage(string s)
    {
        message = s;
        charLength = message.length();
        splitTweets();
    }
    
    //getter for size
    int getSize()
    {
        return size;
    }
    
    //function prototype for splitTweets, splitCount, lastFound, punctCheck, counterAdder and display
    void splitTweets();
    int splitCount(string s);
    size_t lastFound(string s, string punctArr[]);
    bool punctCheck(string s, string punctArr[]);
    string counterAdder(string s, int splits, int length);
    void display();
};
//TweetStream Class
class TweetStream
{
  private:
    //variables for username, tweets array, and size
    string userName;
    Tweet *tweets[100];
    int size;
  public:
    //conditonal contructor
    TweetStream(string u)
    {
      userName = u;
      size = 0;
    }
    
    //setter for username
    void setUsername(string u)
    {
      userName = u;
    }
    
    //getter for username
    string getUsername()
    {
      return userName;
    }
    
    //getter for size
    int getSize()
    {
      return size;
    }
    
    //function prototypes for addMessage and display
    void addMessage(string m);
    void display();
};
#endif
