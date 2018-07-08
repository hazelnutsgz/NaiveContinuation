#ifndef __PT_H__
#define __PT_H__

#include <unordered_set>
#include <unordered_map>
#include <set>

template <typename T>
class Message {
    int senderPid;
    MessageQueue receiverMessageQueue;
    T message;
};

class MessageQueue : public 

template <typename T>
class PriorityQueue{
public:
    virtual T Next() = 0;
    virtual Add() = 0;
    virtual void Remove(Message& targetMessage, bool removeAll) = 0;
    void HasFree() {
        return (size < capacity);
    }
    void IsEmpty() {
        return size == 0;
    }
    size_t size;
    size_t capacity;
};



class ProtoThread {
public:
    ProtoThread() : ptLine(0) {}

    void Restart() {ptLine = 0;}

    void Stop() { ptLine = LineNumberInvalid;}

    bool isRunning() {
        return ptLine != LineNumberInvalid;
    }

    virtual bool Run() = 0;

    void Register(MessageManager& manager) {
        manager.Add(this);
    }
    void UnRegister(MessageManager& manager) {
        manager.Remove(this);
    }

protected:
    typedef int LineNumber;
    static const LineNumber LineNumberInvalid = (LineNumber)(-1);
    LineNumber ptLine;
    int pid;
};

class Context {
public:
    Context() {}
    virtual ProtoThread& Schedule(){

    }
    void Add(ProtoThread& protoThread) {
        threadSet.insert(protoThread);
    }

    void Remove(ProtoThread& protoThread) {
        threadSet.erase(protoThread);
    }

protected:
    MessageManager& messageManager;
    set<protoThread&> threadSet;
};

class MessageManager : public ProtoThread {
public:
    MessageManager(int capacity=100) : queueCapacity(capacity), queueSize(0){}
    void Add(ProtoThread& protoThread) {
        if (registeredProtoThreads.count(protoThread)){
            std::count << "The thread has been registered before" << std::endl;
            return;
        }else {
            registeredProtoThreads.insert(protoThread);
            std::count << "Successfully inserted" << std::endl;
        }
    }

    virtual void Run() {
        while(true) {
            if(currentMessage) {
                Dispatch(currentMessage);
                PT_YIELD("Successfully dispatch message");
            }else {
                PT_YIELD("No message found yet");
            }
        }
    }

    void Remove(ProtoThread& protoThread) {
        if (registeredProtoThreads.count(protoThread)){
            regiterProtoThreads.erase(protoThread);
            std::count << "The thread has been registered before" << std::endl;
            return;
        }else {
            std::count << "The thread do not exist" << std::endl;
        }
    }
    void Add(Message& message, bool allowDuplicated = false) {
        if(HasFree() && (!messageIdentifiers.count(message) || allowDuplicated) ) {
            messageIdentifiers.insert(message);
            messagePool.insert(message);
            queueCapacity += 1;
        }else{
            std::count << "The message should be discarded because of duplication" << std::endl;
        }
    }

    void Remove(Message& message, bool removeAll = true) {
        if(!isEmpty() && messageIdentifiers.count(message)){
            messageIdentifiers.erase(message);
            messagePool.Remove(removeAll);
        }else {
            std::count << "The message should be discarded because of duplication" << std::endl;
        }
    }


    virtual void Dispatch(Message& message) {
        message.receiverPid;
        PriorityQueue& messagePool = topicPool.find();
        MessagemessagePool.Next();
    }
    virtual ProtoThread& Schedule() = 0; //The schedule policy of the message queue


protected:
    unordered_set<ProtoThread&> registerProtoThreads;
    set<Message&> messageIdentifiers;
    PriorityQueue<> & topicPool;
    Message& currentMessage;
};



#define PT_BEGIN() bool ptYielded = true; (void) ptYielded; switch (ptLine) { case 0:

// Stop protothread and end it (use at end of Run() implementation).
#define PT_END() default: ; } Stop(); return false;

// Cause protothread to wait until given condition is true.
#define PT_WAIT_UNTIL(condition) \
    do { ptLine = __LINE__; case __LINE__: \
    if (!(condition)) return true; } while (0)

// Cause protothread to wait while given condition is true.
#define PT_WAIT_WHILE(condition) PT_WAIT_UNTIL(!(condition))

// Cause protothread to wait until given child protothread completes.
#define PT_WAIT_THREAD(child) PT_WAIT_WHILE((child).Run())

// Restart and spawn given child protothread and wait until it completes.
#define PT_SPAWN(child) \
    do { (child).Restart(); PT_WAIT_THREAD(child); } while (0)

// Restart protothread's execution at its PT_BEGIN.
#define PT_RESTART() do { Restart(); return true; } while (0)

// Stop and exit from protothread.
#define PT_EXIT() do { Stop(); return false; } while (0)

// Yield protothread till next call to its Run().
#define PT_YIELD(returnValue) \
    ptYielded = false; \
    ptLine = __LINE__; \
    case __LINE__: {\
        if (!ptYielded) \
            return returnValue; \
        }

#endif