#ifndef _IHATEFRACTIONS_H_
#define _IHATEFRACTIONS_H_

#include "problem.h"

class ihatefractions : public problem {
    // inspired by a similar game in "The Hardest Game 2 by OrangeSense"
private:
    int numfracs;
    vector<int> numerators;
    vector<int> denominators;
public:
    ihatefractions() : problem(16), numfracs(8), numerators(), denominators() {}
    void desc() { 
        cout << "You have " << maxtime << " seconds to compare " << numfracs << " fractions. Type in a " << numfracs << " character string" <<
                " of <, >, ? " << endl << "indicating whether the left-hand side is less than, greater than, or equal to the right hand side." 
                << endl;
        cout << "Press any key when ready. I recommend holding down shift when ready so you can answer faster." << endl; }
    void generate() {
        for (int i=0; i<numfracs; i++) {
            int num1 = 1 + (rand() % 9);
            int denom1 = 1 + (rand() % 9);
            int num2 = 1 + (rand() % 9);
            int denom2 = 1 + (rand() % 9);
            numerators.push_back(num1);
            denominators.push_back(denom1);
            numerators.push_back(num2);
            denominators.push_back(denom2);
        }
    }
    void print() {
        cout << endl;
        for (int i=0; i<numfracs; i++) {
            cout << "  " << numerators[2*i] << "    " << numerators[2*i+1] << "  |";
        }
        cout << endl;
        for (int i=0; i<numfracs; i++) {
            cout << " ---  --- |";
        }
        cout << endl;
        for (int i=0; i<numfracs; i++) {
            cout << "  " << denominators[2*i] << "    " << denominators[2*i+1] << "  |";
        }
        cout << endl << endl;
    }
    bool answer() {
        string s;
        cout << "Enter your answer (as a string of <, >, ?): ";
        cin >> s;
        // evaluate answer and print results
        double totaltime = t.elapsed();
        string correct_ans = "";
        for (int i=0; i<numfracs; i++) {
            if (numerators[2*i]*denominators[2*i+1] < numerators[2*i+1]*denominators[2*i]) correct_ans += '<';
            if (numerators[2*i]*denominators[2*i+1] > numerators[2*i+1]*denominators[2*i]) correct_ans += '>';
            if (numerators[2*i]*denominators[2*i+1] == numerators[2*i+1]*denominators[2*i]) correct_ans += '?';
        }
        
        if (s==correct_ans) correct = true;
        
        if (totaltime >= maxtime) cout << "Timeout! " << maxtime << " seconds has passed." << endl;
        else if (!correct) cout << "Incorrect! Correct answer is " << correct_ans << endl;
        else {
            cout << "Your time was " << totaltime << " seconds!" << endl;
        }
        
        int score_awarded = int(scoring(1000,0.30,0.70,0,correct,maxtime,totaltime,0,true,true));
        cout << "Points awarded: " << score_awarded << "." << endl;
        score += score_awarded;
        return correct;
    }
};

#endif