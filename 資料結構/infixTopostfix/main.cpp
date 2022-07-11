#include <iostream>
#include "stack.h"
#include <string>
#include <vector>
#include <sstream>
using namespace std;
int W(string a){
 if(a=="+"||a=="-")
    return 10;
 else if(a=="*"||a=="/")
    return 20;
 else if (a=="(")
     return 5;
 else
     return 0;
}
bool isop(string y){

   if (y=="+"){
    return true;
   }
   else if (y=="-"){
    return true;
   }
   else if (y=="*"){
    return true;
   }
   else if (y=="/"){
    return true;
   }
   else if (y=="("){
    return true;
   }
   else if (y==")"){
    return true;
   }
   else
   return false;
}
bool isopn(string t){
   return !isop(t);
}

vector<string> toTokens(string infix){
   vector<string> tokenArray;
   string aToken;
   for(int i=0;i<infix.size();i++){
    char c;
    c=infix[i];
    string sc(1,c);
    if(isop(sc)){
        if(aToken!="")
        {tokenArray.push_back(aToken);}
        tokenArray.push_back(sc);
        aToken="";
       }
    else
      { aToken+=sc;
      }
    }
   if(aToken.size()>0){
     tokenArray.push_back(aToken);
    }
   return tokenArray;
}
int main()
{ string infix="10*(5+3.1)";
  vector<string> tokenArray,postfix;
  tokenArray=toTokens(infix);
  MyStack<string> s1;
  MyStack<double> s2;
  string f="";
  string c="";
  double m=0,e=0,j=0;
 for(int i=0;i<tokenArray.size();i++){
   string t=tokenArray[i];
     if(t=="(")
      {s1.push(t);
       continue;
      }
     if(t==")")
     { while(true)
      {f=s1.top();
       s1.pop();
      if(f!="(")
      {postfix.push_back(f);}
       else
          break;
      }
       continue;
       }
     if(isopn(t))
          {
          postfix.push_back(t);
          continue;
          }
     if(!isop(t))
       {cout<<"¹Bºâ¦¡¿ù»~"<<endl;
        break;
         }
     if(s1.empty())
       {s1.push(t);
        continue;
       }
     if(isop(t)){
       c=s1.top();
       while(W(t)<=W(c) && !s1.empty())
       {postfix.push_back(c);
        s1.pop();
        if(!s1.empty())
        c=s1.top();
       }
       s1.push(t);
      }
     }
     while(!s1.empty())
     {c=s1.top();
      s1.pop();
      postfix.push_back(c);
     }
for(int k=0;k<postfix.size();k++)
{if(isop(postfix[k]))
  { f=postfix[k];
     e=s2.top();
     s2.pop();
     j=s2.top();
     s2.pop();
  if(postfix[k]=="+")
      {m=j+e;
      }
  if(postfix[k]=="-")
      {m=j-e;
      }
  if(postfix[k]=="*")
      {m=j*e;
      }
  if(postfix[k]=="/")
      {m=j/e;
      }
  s2.push(m);
  }
  else
  { double x;
    stringstream ss;
    ss<<postfix[k];
    ss>>x;
    s2.push(x);}
}
cout<<"infix:"<<infix<<endl;
cout<<"postfix:";
for(int i=0;i<postfix.size();i++)
     {cout<<postfix[i];}
     cout<<endl;
cout<<"Ans: "<<s2.top()<<endl;


}


