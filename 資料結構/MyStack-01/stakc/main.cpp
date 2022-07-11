#include <iostream>
#include <stack>
#include <string>
using namespace std;
int W(char a){
 if(a=='+'||a=='-')
    return 10;
 else if(a=='*'||a=='/')
    return 20;
 else if (a=='(')
     return 5;
 else
     return 0;
}
bool isopn(char t){
   if(t>='0'&&t<='9')
   {
       return true;
   }
     return false;
}
bool isop(char y){
   switch(y){
   case '+':
   case '-':
   case '*':
   case '/':
   case ')':
   case '(':
          return true;
   }
   return false;
}
int main()
{stack <char>s1;
 stack <double>s2;
 char c='0',f='0';
 char t='0';
 double e=0,j=0,m=0;
 string infix="(((1+(2*3))+(4/5))*3)-4+3";
 string postfix;
 for(int i=0;i<(int)infix.length();i++)
 {t=infix[i];
  if(t=='(')
  {s1.push(t);
   continue;
  }
  if(t==')')
  { while(true)
    { f=s1.top();
     s1.pop();
     if(f!='(')
     {postfix+=f;}
     else
        break;
    }
   continue;
  }
  if(isopn(t))
  {postfix+=t;
   continue;
  }
  if(!isop(t))
  {cout<<"運算式錯誤"<<endl;
    break;
  }
  if(s1.empty())
     {s1.push(t);
      continue;
     }
  if(isop(t)){
    c=s1.top();
    while(W(t)<=W(c) && !s1.empty())
    {postfix+=c;
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
 postfix+=c;
}
for(int k=0;k<(int)postfix.length();k++)
{if(isop(postfix[k]))
  {f=postfix[k];
    e=s2.top();
    s2.pop();
    j=s2.top();
    s2.pop();
  switch(f){
  case '+':
      m=j+e;
      break;
  case '-':
      m=j-e;
      break;
  case '*':
      m=j*e;
      break;
  case '/':
      m=j/e;
      break;
  }
  s2.push(m);
  }
  else
 {s2.push((double)postfix[k]-48);}
}
cout<<"infix: "<<infix<<endl;
cout<<"postfix: "<<postfix<<endl;
cout<<"Ans: "<<s2.top()<<endl;
return 0;
}

