#ifndef _MAXIMIN_H_
#define _MAXIMIN_H_

#include <vector>
#include "problem.h"

using namespace std;

class maximin : public problem {
private:
    int numofints, thresh;
    vector<long> ints;
public:
    maximin() : problem(12), numofints(20), thresh(100), ints() {}
    void generate() {
        ints.clear();
        for (int i=0; i<numofints; i++) {
            int x = rand() % (thresh + 1) - rand() % (thresh + 1);
            ints.push_back(x);
        }
        int offset = rand() % (2*thresh + 1) - rand() % (2*thresh + 1);
        for (int i=0; i<numofints; i++) {
            ints[i] += offset;
        }
    }
    void desc() { cout << "Find the max and min of a bunch of numbers. Press any key when ready." << endl; }
    void print() {
        cout << "Identify the maximum and minimum of the following numbers." <<
                " You have " << maxtime << " seconds." << endl;
        for (int i=0; i<numofints; i++) {
            cout << ints[i] << ' ';
        }
        cout << endl;
    }
    bool answer() {
        long ans1;
        cout << "What is the maximum? ";
        cin >> ans1;
        long ans2;
        cout << "What is the minimum? ";
        cin >> ans2;
        // evaluate answer and print results
        double totaltime = t.elapsed();
        int max = 0;
        int min = 0;
        if (numofints != 0) {
            max = ints[0];
            min = ints[0];
        }
        for (int i=0; i<numofints; i++) {
            if (ints[i] > max) max = ints[i];
            if (ints[i] < min) min = ints[i];
        }
        if ((ans1 == max) && (ans2 == min)) correct = true;
            
        if (totaltime >= maxtime) cout << "Timeout! " << maxtime << " seconds has passed." << endl;
        else if (!correct) cout << "Incorrect! Answer is " << max << ", " << min << endl;
        else cout << "You finished the question in " << totaltime << " seconds!" << endl;
        
        int score_awarded = int(scoring(1000,0.40,0.60,0,correct,maxtime,totaltime,0,true,true));
        cout << "Points awarded: " << score_awarded << "." << endl;
        score += score_awarded;
        return correct;
    }
};

#endif