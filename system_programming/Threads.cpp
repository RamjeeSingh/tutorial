// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>
#include "Thread.h"


using namespace std;

void ThreadBase::start() {
    cout<<"\n before thread start"<<endl;
    pthread_create(&mthreadData.id, NULL, mthreadData.work, mthreadData.arg);
    cout<<"\n after thread start"<<endl;
}    

ThreadBase::ThreadBase(ThreadBase::ThreadData &data) {    
    ThreadBase::mthreadData = data;
}

