#ifndef _MULTIPLICATION_H_
#define _MULTIPLICATION_H_

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "problem.h"

using namespace std;

class multiplication : public problem {
private:
    long a,b;
    int digits;
public:
    multiplication() : problem(25), a(0), b(0), digits(2) {}
    void generate() {
        long ubound = pow(10,digits);
        long lbound = pow(10,digits-1);
        a = rand() % (ubound-lbound) + lbound;
        b = rand() % (ubound-lbound) + lbound;
    }
    void desc() { cout << "Find the product of two numbers. Press any key when ready." << endl; }
    void print() {
        cout << "What is " << a << " x " << b << "? You have " << maxtime << " seconds." << endl;
    }
    bool answer() {
        long ans;
        cout << "Please enter your answer: ";
        cin >> ans;
        // evaluate answer and print results
        double totaltime = t.elapsed();
        if (ans == a*b) correct = true;
        if (totaltime >= maxtime) cout << "Timeout! " << maxtime << " seconds has passed." << endl;
        else if (!correct) cout << "Incorrect! Answer is " << a*b << endl;
        else {
            cout << "You finished the question in " << totaltime << " seconds!" << endl;
        }
        int score_awarded = int(scoring(1000,0.25,0.75,0,correct,maxtime,totaltime,0,true,false));
        cout << "Points awarded: " << score_awarded << "." << endl;
        score += score_awarded;
        return correct;
    }
};

#endif