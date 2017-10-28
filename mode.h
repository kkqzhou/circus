#ifndef _MODE_H_
#define _MODE_H_

#include "problem.h"

class mode : public problem {
private:
    int nlim, nnums, freq;
    vector<int> num;
    vector<int> allnums;
public:
    mode() : problem(25), nlim(10), nnums(4), freq(10), num(), allnums() {}
    void desc() { cout << "Find the number which appears most often in a bunch of integers. " << 
                        "There are no ties." << endl; }
    void generate() {
        if (nlim < nnums) { cout << "Warning! mode.h nlim < nnums" << endl; }
        if (freq < 3) { cout << "Warning! mode.h freq < 3" << endl; }
        // randomize the frequency just a little bit
        freq = freq + (rand() % 3) - 1;
        vector<int> randoms;
        for (int i=0; i<nlim; i++) {
            randoms.push_back(i);
        }
        // randoms should contain 0,1,...,nlim-1
        for (int i=0; i<nnums; i++) {
            int n = rand() % randoms.size();
            num.push_back(randoms[n]);
            randoms.erase(randoms.begin()+n);
            // remove the element that was picked
        }
        // now generate the random numbers
        for (int j=0; j<nnums; j++) {
            if (j == 0) {
                for (int i=0; i<freq; i++) {
                    allnums.push_back(num[j]);
                }
            }
            if (j > 0) {
                int truefreq = (rand() % 2) + freq - 2;
                for (int i=0; i<truefreq; i++) {
                    allnums.push_back(num[j]);
                }
            }
        }
    }
    void print() {
        cout << "Find the mode of the following integers." << 
                " You have " << maxtime << " seconds." << endl << endl;
        while (allnums.size() != 0) {
            int picked = rand() % allnums.size();
            cout << allnums[picked] << " ";
            allnums.erase(allnums.begin() + picked);
        }
        cout << endl << endl;
    }
    bool answer() {
        int ans1;
        cout << "Please enter your answer: ";
        cin >> ans1;
        // evaluate answer and print results
        double totaltime = t.elapsed();
        if (ans1 == num[0]) correct = true;
        
        if (totaltime >= maxtime) cout << "Timeout! " << maxtime << " seconds has passed." << endl;
        else if (!correct) cout << "Incorrect! Answer is " << num[0] << endl;
        else {
            cout << "You finished the question in " << totaltime << " seconds!" << endl;
        }
        int score_awarded = int(scoring(1000,0.20,0.80,0,correct,maxtime,totaltime,0,true,true));
        cout << "Points awarded: " << score_awarded << "." << endl;
        score += score_awarded;
        return correct;
    }
};

#endif