#ifndef _PACEMAKER_H_
#define _PACEMAKER_H_

#include "problem.h"
#include "console.h"

class pacemaker : public problem {
private:
    float max_time_amt, min_time_amt, pace_time;
public:
    pacemaker() : problem(100), max_time_amt(15.0), min_time_amt(5.0), pace_time(0) {}
    // due to the nature of this problem we need RNG to happen in desc and not generate.
    void desc() { 
        pace_time = (rand()*1.0/RAND_MAX)*(max_time_amt-min_time_amt) + min_time_amt;
        cout << "Mentally keep time for " << pace_time << " seconds. Press any key ONCE when ready " << 
                    "and press another key after " << pace_time << " seconds." << endl; }
    void generate() {}
    void print() {
        cout << "TIMER STARTS NOW!" << endl;
    }
    bool answer() {
        readkey();
        // evaluate answer and print results
        double totaltime = t.elapsed();
        correct = true;
        
        if (totaltime >= maxtime) cout << "Timeout! " << maxtime << " seconds has passed." << endl;
        else {
            cout << "Your time was " << totaltime << " seconds!" << endl;
        }
        double acc = 1-10*abs(1-totaltime/pace_time);
        if (acc < 0) acc = 0;
        
        int score_awarded = int(scoring(1000,0,0,1,correct,maxtime,totaltime,acc,false,false));
        cout << "Points awarded: " << score_awarded << "." << endl;
        score += score_awarded;
        return correct;
    }
};

#endif