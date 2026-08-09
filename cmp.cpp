#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main(){
    int dx=0;
    while(1){
        cout<<++dx<<'\n';
        system("data.exe > in");
        system("bf.exe < in > std");
        system("mine.exe < in > mine");
        if(system("fc mine std")){cout<<"Error";return 0;}
        Sleep(200);
    }
}