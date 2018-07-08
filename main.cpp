#include <iostream>
#include "pt.h"

class ProduceThread : public ProtoThread {
public:
    ProduceThread(void* args, void* ret): {}
    virtual bool Run() {
        PT_BEGIN();
        PT_END();
    }
};
class NewMessageQueue : public MessageQueue{
public:
    virtual ProtoThread& Schedule() {

    }

protected:
    ProtoThread* s;

};


int main() {
    pair p;
    p.left = 1;
    p.right = 2;
    ProduceThread pthread(add, (void*) &p, (void*) &ret);
    pthread.Run();

    std::cout << ret.sum;

    std::cout << "Destroy the thread" << std::endl;
}