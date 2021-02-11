#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main()
{
  char extension[10],cmd[50];
  cout<<"\nENTER EXTENSION OF FILES : ";
  cin>>extension;
  strcpy(cmd,"rm *.");
  strcat(cmd,extension);
  system(cmd);
  return 0;
}
