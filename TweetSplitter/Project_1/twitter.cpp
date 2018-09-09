#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
using namespace std;


void splitTweets(string message, string s[], int* splits)
{
 
  //declare temp string, a counter, splitcount, and the message length
  string temp;
  int counter = 1;
  int messageLen = message.length();
  //declare string punctuation to know where to split
  string punct[5] = {" ", ",", ".", "!", "?"};
  if(messageLen < 280)
  {
    s[0] = message;
    (*splits)++;
  }
  else
  {
    //goes through each char in the message
    for(int i = 0; i < messageLen; i++)
    {
      //if we meet the character limit
      if(counter == 280) //-6 for the (x/y) 
      {
        //check if the place we stop is in a middle of a word
        if(isalpha(message[i]) || isdigit(message[i]))
        {
          //goes the punctionation array to see which is the closest
          for(int j = 0; j < 5; j++)
          {
            if(temp.rfind(punct[j]) != string::npos)
            {
              //move back the for loop to the last word
              i -= (279 - temp.rfind(punct[j]));
              
              //find where to split
              temp = temp.substr(0,temp.rfind(punct[j]) + 1);
              
              //puts the split into the array
              s[*splits] = temp;
              
              //clears the temp string
              temp.clear();
              
              //increment the splits
              (*splits)++;
              
              //reset the counter
              counter = 1;
              break;
            }  
          }  
          //skips the space
          i += 1;
        }
        //if we didn't stop in the middle of a word
        else
        {
          //finds what kind of puncuation it was
          for(int j = 0; j < 5; j++)
          {
            //temp char to compare
            string tempC = punct[j];
            
            //compares the non-alphabetical letter
            if(tempC[0] == message[i])
            {
              //adds to the string
              temp += tempC;
              //store the split into the array
              s[*splits] = temp;
              
              //ckears the temp string
              temp.clear();
              
              //increase the split
              (*splits)++;
              
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
        //put the remaining sentence into the string array
        s[*splits] = temp;
        (*splits)++;
      }
    }
  }
}

void displaySplitTweet(string s[], int splits, string username)
{
  //if there are no splits just print the message
  if(splits == 1)
  {
    cout << "@" << username << ": " << s[0] << endl;
  }
  else
  {
    //goes through the string array and prints it
    for(int i = 0; i < splits; i++)
    {
      cout << "@" << username << ": " << s[i] << " (" << i+1 << "/" << splits << ")" << endl; 
    }
  }
}
