#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>


using namespace std;


class ThreadBase {    
public:
    class ThreadData {
    public:
        string name;
        pthread_t id;
        pthread_attr_t *attr;
        void *arg;
        void * (*work) (void *);
        ThreadData(string name = NULL, pthread_attr_t *attr = NULL, void* (*work) (void *) = NULL, void *arg = NULL) {
	    this->name = name;
	    this->attr = attr;
            this->arg = arg;
            this->work = work;
        }
    };
    ThreadData mthreadData;
    ThreadBase(ThreadData &mthreadData);
    ThreadBase(string name = NULL, pthread_attr_t *attr = NULL, void* (*work) (void *) = NULL, void *arg = NULL) {

    }
    void start();
};



