#include<bits/stdc++.h>
#include<iostream>
#include<sys/stat.h>
#include<sys/types.h>

using namespace std;

int main() {
    
    if(mkdir("newDirectory", 0777)) {
        cerr << "Error occurred" << strerr
    }
    else {
        cout << "Directory created";
    }
}
