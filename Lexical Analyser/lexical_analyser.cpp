#include<iostream>
#include<set>
#include<fstream>
#include<algorithm>
#include<ctype.h>

using namespace std;

int main()
{
//ifstream infile;
//infile.open("program",ios::in);
string keywords[]={"for","while","int","char","double","return","main","scanf","printf","if"};
char symbols[]={'&','*','^','%',';'};
set<string>key_found;
set<char>symbol_found;
set<string>identifier;
set<string>str_literals;
set<char>::iterator itr;

      ifstream inFile;
      inFile.open("program.txt");
string words;
char ch,word;

//int p=0;

while((!inFile.eof()))
{//cout<<"before::"<< inFile.tellg();

inFile.get(ch);
cout<<ch;
}
inFile.seekg(0);
cout<<"tellg =="<<inFile.tellg();
while((!inFile.eof()))
{//cout<<"before::"<< inFile.tellg();

inFile.get(ch);
//cout<<ch;

if(!isalnum(ch)&&ch!='"')
symbol_found.insert(ch);

else if(isalpha(ch))
{//cout<<"           ch ="<<ch<<endl;
    //inFile.seekg(inFile.tellg()-1);
string s;
  //cout<<"after::"<< inFile.tellg();
  //inFile.get(ch);
  while(ch!=' ' && ch!='=' && !inFile.eof() &&ch!=';' && ch!='(' && ch!=')' && ch!='%')
    {s+=ch;
    inFile.get(ch);
    }
    int flag=0;
    for(int i=0;i<10;i++)
    if(keywords[i]==s)
        flag=1;
    if(flag==1)
    {
        //cout<<"inside checking keywords :"<<*find(keywords,keywords+8,s)<<endl;
        key_found.insert(s);
    }

    else
    {
       //cout<<"inside else";
        identifier.insert(s);
    }
}
else if(ch=='"')
{

    string s;
    //s+=ch;
    inFile.get(ch);
    while(ch!='"')
    {

        s+=ch;
        inFile.get(ch);
    }
    str_literals.insert(s);
   // cout<<"\n:Identifier :"<<s;
}
}
cout<<endl;
/*
cout<<"Identifiers:-\n";
for(int i=0;i<identifier.size();i++)
//cout<<identifier[i]<<" ";

cout<<"Keywords Found:-\n";
for(int i=0;i<key_found.size();i++)
//cout<<key_found[i]<<" ";
*/



set<string>::iterator it;

cout<<"keywords found:-\n";
for(it=key_found.begin();it!=key_found.end();it++)
cout<<*it<<"\n";
cout<<endl<<endl;


cout<<"Strings found:-\n";
for(it=str_literals.begin();it!=str_literals.end();it++)
cout<<*it<<"\n";
cout<<endl<<endl;


cout<<"Identifiers found:-\n";
for(it=identifier.begin();it!=identifier.end();it++)
cout<<*it<<"\n";
cout<<endl<<endl;

cout<<"Symbols found:-\n";
for(itr=symbol_found.begin();itr!=symbol_found.end();itr++)
cout<<*itr<<"\n";
cout<<endl<<endl;


return 0;
}
