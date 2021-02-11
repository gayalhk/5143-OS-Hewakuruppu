#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main()
{
  char src[50],dest[50],cmd[100];
  cout<<"\nEnter full path of file to be moved : ";
  gets(src);
  cout<<"Enter full path where file to be moved : ";
  gets(dest);
  strcpy(cmd,"mv ");
  strcat(cmd,src);
  strcat(cmd," ");
  strcat(cmd,dest);
  system(cmd);
  return 0;
}
