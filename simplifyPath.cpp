#include<iostream>
#include<stack>
#include<deque>
#include<vector>
#include<sstream>
using namespace std;


void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        if(item!="" && item!=" ")
        { 
            elems.push_back(item);
        }
    }
}


string simplifyPath(string path) {
    vector<string> elems;
    split(path, '/', elems);
    string result="";
    deque<string> st;

    for(int i=0;i<elems.size();i++){
        //cout<<elems[i]<<"\n";
        if(elems[i]==".."){
            if(st.empty()==false)
                st.pop_back();
        }else if(elems[i]!="." &&  elems[i]!="/"){
            st.push_back(elems[i]);
            //cout<<elems[i]<<"==>"<<"\n";;
        }
    }

   string slash="/";
   if(st.empty())
       result=slash;

   while(st.empty()==false){
       string top=st.front();
       st.pop_front();
       result=result+slash;
       result=result+top;
   }
   return result;
}


int main()
{
    cout<<simplifyPath("/home/")<<"\n"; // => "/home"
    cout<<simplifyPath("/a/./b/../../c/")<<"\n";//, => "/c"
    cout<<simplifyPath("/home//foo/")<<"\n";
    cout<<simplifyPath("/../")<<"\n"; // =>"/"
    cout<<simplifyPath("/home/foo/.ssh/../.ssh2/authorized_keys/");
}
