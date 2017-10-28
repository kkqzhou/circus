#ifndef _TIMER_H_
#define _TIMER_H_

#include <time.h>

class timer {
private:
    double begTime;
public:
    void start() { begTime = clock(); }
    double elapsed() { return (clock() - begTime) / CLOCKS_PER_SEC; }
};

#endif