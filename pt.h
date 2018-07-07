#ifndef __PT_H__
#define __PT_H__

class ProtoThread {
public:
    ProtoThread() : ptLine(0) {}

    void Restart() {ptLine = 0;}

    void Stop() { ptLine = LineNumberInvalid;}

    bool isRunning() {
        return ptLine != LineNumberInvalid;
    }

    virtual bool Run() = 0;

protected:
    typedef int LineNumber;
    static const LineNumber LineNumberInvalid = (LineNumber)(-1);
    LineNumber ptLine;

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
#define PT_YIELD() \
    ptYielded = false; \
    ptLine = __LINE__; \
    case __LINE__: {\
        if (!ptYielded) \
            return true; \
        }

// Yield protothread until given condition is true.
#define PT_YIELD_UNTIL(condition) \
    ptYielded = false; \
    ptLine = __LINE__; \
    case __LINE__: {\
        if (!ptYielded || !(condition)) \
            return true; \
        }
#endif