#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
using namespace std;

vector<string> allresult;
void wordBreakUtil(string str, int size, string result,unordered_set<string> &dict)
   {
    
    //Process all prefixes one by one
    for (int i=1; i<=size; i++)
    {
        //extract substring from 0 to i in prefix
        string prefix = str.substr(0, i);
 
        // if dictionary conatins this prefix, then we check
        // for remaining string. Otherwise we ignore this prefix
        // (there is no else for this if) and try next
        if (dict.find(prefix)!=dict.end())
        {
            // if no more elements are there, print it
            if (i == size)
            {
                // add this element to previous prefix
                result += prefix;
                allresult.push_back(result);
            }
            wordBreakUtil(str.substr(i, size-i), size-i, result+prefix+" ",dict);
        }
    }      //end for
}//end function
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        //last argument is prefix
        string result="";
        wordBreakUtil(s,s.length(),result,dict);
        return allresult;
        
    }
