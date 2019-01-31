#include<stdio.h>
#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ifstream in;
    char a;
    in.open("test.txt");
    while(in.peek()!=EOF)
    {
        in.get(a);
        cout<<a;
    }
    //printf("¡X¡X¡X¡X¡X¡X¡X\n");
    //printf("¡X¡X¡X¡X¡X¡X¡X\n");
    return 0;
}
