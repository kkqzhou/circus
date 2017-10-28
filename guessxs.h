#ifndef _GUESSXS_H_
#define _GUESSXS_H_

#include "problem.h"

using namespace std;

class guessXs : public problem {
private:
    int height, width;
    int totalsq;
    vector<vector<char> > xs;
public:
    guessXs() : problem(8), height(20), width(25), totalsq(0), xs() {}
    void desc() { 
        cout << "Guess the number of X's in a " << height << " x " << width << " array." << endl; 
        cout << "You have " << maxtime << " seconds. Press any key when ready." << endl;
    }
    void generate() {
        xs.clear();
        totalsq = height*width;
        int xprob = int(totalsq/10) + (rand() % (totalsq-2*int(totalsq/10)+1));
        for (int i=0; i<height; i++) {
            vector<char> row;
            for (int j=0; j<width; j++) {

                int xrealized = rand() % (totalsq+1);
                if (xrealized >= xprob) row.push_back('X');
                if (xrealized < xprob) row.push_back(' ');
            }
            xs.push_back(row);
        }
    }
    void print() {
        cout << endl;
        for (int i=0; i<height; i++) {
            for (int j=0; j<width; j++) {
                cout << xs[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    bool answer() {
        long ans1;
        cout << "How many X's are there on the board? ";
        cin >> ans1;
        // evaluate answer and print results
        double totaltime = t.elapsed();
        int numofxs = 0;
        for (int i=0; i<height; i++) {
            for (int j=0; j<width; j++) {
                if (xs[i][j] == 'X') numofxs++;
            }
        }
        if (ans1 == numofxs) correct = true;
        
        double acc = 1 - 10*abs((numofxs - ans1)*1.0/totalsq);
        if (acc < 0) acc = 0;
            
        if (totaltime >= maxtime) cout << "Timeout! " << maxtime << " seconds has passed." << endl;
        else cout << "You finished the question in " << totaltime << " seconds!" << endl << 
                "Actual # of squares: " << numofxs << endl;
        int score_awarded = int(scoring(1000,0,0.35,0.65,correct,maxtime,totaltime,acc,false,true));
        cout << "Points awarded: " << score_awarded << "." << endl;
        score += score_awarded;
        return correct;
    }
};

#endif