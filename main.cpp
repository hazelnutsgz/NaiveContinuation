#include <iostream>
#include "pt.h"

class ProduceThread : public ProtoThread {
public:
    virtual bool Run() {
        PT_BEGIN();
        static int a = 5;
        while(a > 0) {
            a -= 1;
            PT_WAIT_UNTIL(a < 0);
            std::cout << a << std::endl;
        }
        PT_END();
    }
};

class ConsumeThread : public ProtoThread {
public:
    virtual bool Run() {
        PT_BEGIN();
        static int a = 5;
        while(a > 0) {
            a -= 1;
            PT_WAIT_UNTIL(a < 0);
            std::cout << a << std::endl;
        }
        PT_END();
    }
};


int main() {
    ProduceThread pthread;
    ConsumeThread cthread;

    while(pthread.Run() || cthread.Run());

    std::cout << "Destroy the two threads" << std::endl;
}