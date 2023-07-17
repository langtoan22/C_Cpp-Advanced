#include <iostream>
#include <thread>
#include <string>
#include <unistd.h>

using namespace std;

void foo1(){
    int i = 0;
    while (1)
    {
       cout << "Thread uisng function foo1: "<< i << endl;
        usleep(1000000);
        i++;
    }
    
}

void foo2(){
    int i = 0;
    while(1){
        cout << "Thread uisng function foo2: " << i << endl;
        usleep(3000000);
        i++;
    }
}

int main(int argc, char const *argv[])
{
    thread th1(foo1);
    thread th2(foo2);

    th1.join();
    th2.join();

    while(1){

    }

    return 0;
}




