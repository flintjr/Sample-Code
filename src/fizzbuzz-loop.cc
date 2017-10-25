/* fizzbuzz-loop.cc
   Counting from  1-100, replace 3=fizz, 5-buzz and 15 with fizzbuzz

   Copyright (C) 2017 Lee Van Dyke

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/
#include <iostream>
using std::cin;using std::cout;using std::endl;
#include <string>
using std::string;

void fizloop1(unsigned int b, const unsigned int e){
  const string f3="fizz", b5="buzz", fb15="fizzbuzz";
  if ((b != e) && (e>b)){ //check range
    for (b; b<=e; ++b){
      if      (!(b%15)){cout<<fb15;cout<<','<<endl;}
      else if (!(b%5)) {cout<<b5;  if (b%e)cout<<',';} //Don't print last comma.
      else if (!(b%3)) {cout<<f3;  if (b%e)cout<<',';}
      else             {cout<<b;   if (b%e)cout<<',';}
    }
    cout<<endl;
  }
  else cout<<"Error:Positive range 2 must be greater than range 1."<<endl;
}

void usage(const char *name){
  string s="Usage: Enter positive ranges for ";
  string s2(" range1 range2, i.e. 1 100. Will replace 3=fizz, 5-buzz and 15 with fizzbuzz");
  cout<<s<<name<<s2<<endl;
}
    
main(int argc, char *argv[]){
  string beg,end;
  if (argc==3)
    for (int i=1; i<argc; ++i){
      if (i==1) beg=argv[i];
      if (i==2) end=argv[i];
    }
  else{
    usage(argv[0]);
    exit(-1);
  }
  unsigned int i=std::stoul(beg), j=std::stoul(end);//convert to int
  fizloop1(i,j);
}
