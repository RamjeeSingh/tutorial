// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>
#include "Thread.h"

using namespace std;

void * work(void *arg) {
    cout<<" \n Dummy Worker"<<endl;

}

void waitInf() {
   while(true);
}

int main() {
    Thread th("sample", NULL, work);
    th.start();
    waitInf(); 
    return 0;
}
