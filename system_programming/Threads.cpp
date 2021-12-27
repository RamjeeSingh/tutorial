// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>


using namespace std;


class Thread {
    string name;
    pthread_t id;
    pthread_attr_t attr_t;
    void *arg;
    void * (*work) (void *);
    
    public:
        Thread(string name, void *arg, void*(*work ) (void *)) {
            this->name = name;
            this->work = work;
            this->arg = arg;           
        }
        void start() {
            cout<<"\n before thread start"<<endl;
            pthread_create(&id, NULL, work, arg);
            cout<<"\n after thread start"<<endl;
        }
         
};


void * work(void * arg) {
    sleep(5) ;
    cout << "\n Hey in Work\n"<< endl;
    return NULL;
}

int main() {
    // Write C++ code here
    std::cout << "Hello world!";
    Thread th("sample", NULL, work);
    th.start();
 while(true);
    return 0;
}
