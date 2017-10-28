#ifndef _PROBLEM_H_
#define _PROBLEM_H_

#include "timer.h"
#include "scoring.h"

class problem {
protected:
    bool correct;
    double maxtime;
    long score;
    timer t;
public:
    problem(double m) : correct(false), maxtime(m), score(0), t() {}
    virtual ~problem() {}
    virtual void desc() = 0;
    virtual void generate() = 0;
    virtual void print() = 0;
    void startTimer() { t.start(); }
    virtual bool answer() = 0;
    double getScore() { return score; }
};

#endif