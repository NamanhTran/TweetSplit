#include "twitter.hpp"
#define CHAR_MAX 280
// The splitTweet function
void TwitterManager::splitTweets()
{
  //declare temp string, a counter, splitcount, and the message length
  string temp;
  int counter = 1;
  int messageLen = message.length();
  
  //declare string punctuation to know where to split
  string punct[4] = {" ", ".", "!", "?"};
  
  //if the message is less than or equal to 280
  if(messageLen <= CHAR_MAX)
  {
    tweets[length] = Tweet(username, message);
    length++;
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
        if(isalpha(message[i]) || isdigit(message[i]) || message[i] == ',')
        {
          //goes the punctionation array to see which is the closest
          for(int j = 0; j < 4; j++)
          {
            if(temp.rfind(punct[j]) != string::npos)
            {
              //move back the for loop to the last word
              i -= ((CHAR_MAX - 7) - temp.rfind(punct[j])); //-1 to account for array starting 0
              
              //find where to split
              temp = temp.substr(0,temp.rfind(punct[j]) + 1);
              
              //adds the counter to the end of the string
              temp = counterAdder(temp, splits, length);
              
              //puts the split into the array
              tweets[length] = Tweet(username, temp);
              
              //clears the temp string
              temp.clear();
              
              //increment the splits
              length++;
              
              //reset the counter
              counter = 1;
              break;
            }
            
            //if there are no punct.
            else if(j == 3)
            {
              //adds the last letter of the message
              temp += message[i];
              
              //adds the counter to the end of the string
              temp = counterAdder(temp, splits, length);
              
              //puts the split into the array
              tweets[length] = Tweet(username, temp);
              
              //clears the temp string
              temp.clear();
              
              //increment the splits
              length++;
              
              //reset the counter
              counter = 1;
            }
          }  
          //skips the space
          i += 1;
        }
        
        //if we didn't stop in the middle of a word
        else
        {
          //finds what kind of puncuation it was
          for(int j = 0; j < 4; j++)
          {
            //temp char to compare
            string tempC = punct[j];
            
            //compares the non-alphabetical letter
            if(tempC[0] == message[i])
            {
              //adds to the string
              temp += tempC;
              
              //adds the counter to the end of the string
              temp = counterAdder(temp, splits, length);
              
              //store the split into the array
              tweets[length] = Tweet(username, temp);
              
              //ckears the temp string
              temp.clear();
              
              //increase the split
              length++;
              
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
        temp = counterAdder(temp, splits, length);
        
        //put the remaining sentence into the string array
        tweets[length] = Tweet(username, temp);
        
        //increment the splits
        length++;
      }
    }
  }
}

//display function for the class Tweet
void Tweet::display()
{
  //prints the tweet
  cout << "@" << username << ": " << message << endl;
}

//display function for the class TwitterManager
void TwitterManager::display()
{
  //calls the display function of the Tweet class (length) amount of times
  for(int i = 0; i < length; i++)
  {
    tweets[i].display();
  }
}

int TwitterManager::splitCount(string s)
{
  //calculate the splits needed for the message 
  int splits = ceil(s.length() / ((CHAR_MAX - 6) * 1.0)); // * 1.0 to promote to a double
  return splits;
}

string TwitterManager::counterAdder(string s, int splits, int length)
{
  //this will add " (x/y)" to the end of the string
  s+= " (";
  s+= to_string(length + 1);
  s+= "/";
  s+= to_string(splits);
  s+= ")";
  return s;
}
