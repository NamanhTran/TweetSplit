#include "twitter.hpp"
#define CHAR_MAX 280
//**START OF Tweet CLASS FUNCTIONS**
//display function for the class Tweet
void Tweet::display()
{
  //prints the tweet
  cout << "@" << username << ": " << message << endl;
}

//**START OF MultiTweet CLASS FUNCTIONS**
// splitTweets and display
void MultiTweet::splitTweets()
{
  //declare temp string, a counter, splitcount, and the message length
  string temp;
  int counter = 1;
  int messageLen = message.length();
  //declare string punctuation to know where to split
  string punct[7] = {" ", ".", ",", ";", "-", "!", "?"};
  
  //if the message is less than or equal to 280
  if(messageLen <= CHAR_MAX)
  {
    subMessage[size] = message;
    size++;
  }
  else
  {
    //calls the splitCount function so we can use it to put in the counter at the end of the message
    int splits = splitCount(message);
    
    //goes through each char in the message
    for(int i = 0; i < messageLen; i++)
    {
      //if we meet the character limit
      if(counter == (CHAR_MAX - 6)) //-6 for the (x/y) 
      {
        //check if the place we stop is in a middle of a word
        if(isalpha(message[i]) || isdigit(message[i]))
        {
          //check for punction exists in the message
          bool check = punctCheck(temp,punct);
          
          //get the rfind's position
          size_t biggest = lastFound(temp,punct);
          
          //if there is no punct in the message
          if(check)
          {
            //move to loop back to the last letter
            i -= ((CHAR_MAX - 7) - biggest);
            
            //put the string
            temp = temp.substr(0,biggest + 1);
            
            //put the counter into the temp string
            temp = counterAdder(temp, splits, size);
            
            //put the message into the array
            subMessage[size] = temp;
            
            //clear the temp string
            temp.clear();
            
            //increment the splits
            size++;
            
            //reset the counter
            counter = 1;
          }
          
          //if there are punct in the message
          else
          {
            //adds the last letter of the message
            temp += message[i];

            //adds the counter to the end of the string
            temp = counterAdder(temp, splits, size);
              
            //puts the split into the array
            subMessage[size] = temp;
              
            //clears the temp string
            temp.clear();
              
            //increment the splits
            size++;
              
            //reset the counter
            counter = 1;
          }
          //skips the space
          i += 1;
        }
        
        //if we didn't stop in the middle of a word
        else
        {
          //finds what kind of puncuation it was
          for(int j = 0; j < 7; j++)
          {
            //temp char to compare
            string tempC = punct[j];
            
            //compares the non-alphabetical letter
            if(tempC[0] == message[i])
            {
              //adds to the string
              temp += tempC;
              
              //adds the counter to the end of the string
              temp = counterAdder(temp, splits, size);
              
              //store the split into the array
              subMessage[size] = temp;
              
              //clears the temp string
              temp.clear();
              
              //increase the split
              size++;
              
              //reset the counter
              counter = 1;
              break;
            }
          }    
            
          //skips the space
          i += 1;
        }
      }
        
      //adds the character to the string
      temp += message[i];
      
      //increase the counter
      counter++;
        
      //if we meet the end of the message
      if(i == messageLen - 1)
      {
        //adds the counter to the end of the string
        temp = counterAdder(temp, splits, size);
        
        //put the remaining sentence into the string array
        subMessage[size] = temp;
        
        //increment the splits
        size++;
      }
    }
  }
}

int MultiTweet::splitCount(string s)
{
  //calculate the splits needed for the message 
  int splits = ceil(s.length() / ((CHAR_MAX - 6) * 1.0)); // * 1.0 to promote to a double
  return splits;
}

size_t MultiTweet::lastFound(string s, string punctArr[])
{
  //initialize the biggest variable
  size_t biggest = 0;
  
  //loops through the puct array
  for(int i = 0; i < 7; i++)
  {
    //if the rfind returns a value that is bigger than biggest and ignores if rfind returns npos
    if(s.rfind(punctArr[i]) > biggest && s.rfind(punctArr[i]) != string::npos)
    {
      biggest = s.rfind(punctArr[i]);
    }
    
    //if there is no punct in the message
    else if(i == 6 && biggest == 0)
    {
      biggest = -1;
    }
  }
  
  return biggest;
}

string MultiTweet::counterAdder(string s, int splits, int length)
{
  //this will add " (x/y)" to the end of the string
  s+= " (";
  s+= to_string(length + 1);
  s+= "/";
  s+= to_string(splits);
  s+= ")";
  return s;
}

bool MultiTweet::punctCheck(string s, string punctArr[])
{
  //goes through the array looking for a punct
  for(int i = 0; i < 7; i++)
  {
    //if rfind doesn't return npos there is a punct
    if(s.rfind(punctArr[i]) != string::npos)
    {
      return true;
    }
    
    //if at the last index of array there is no punct
    if(i == 6)
    {
      return false;
    }
  }
}

void MultiTweet::display()
{
  //displays messages for MultiTweet class
  for(int i = 0; i < size; i++)
  {
    cout << "@" << username << ": " << subMessage[i] << endl;
  }
}

//**START OF TweetStream CLASS FUNCTIONS**
void TweetStream::addMessage(string m) 
{
  //checks the length of the message to see what object needs to be created
  int mLength = m.length();
  
  //if message length is greater than 280 create a MultiTweet class
  if(mLength > 280)
  {
    tweets[size] = new MultiTweet(userName, m);
    size++;
  }
  
  //if message length if less than or equal to 280 create a tweet object
  else
  {
    tweets[size] = new Tweet(userName, m);
    size++;
  }
}

void TweetStream::display()
{
  //displays messages through polymorphism
  for(int i = 0; i < size; i++)
  {
    tweets[i]->display();
  }
}
