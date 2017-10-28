#ifndef _TYPELETTERS_H_
#define _TYPELETTERS_H_

#include "problem.h"

class typeletters : public problem {
private:
    int numchars;
    string word;
    string allowed_chars;
public:
    typeletters() : problem(12), numchars(30), word(""),
                    allowed_chars("abcdefghijklmnopqrstuvwxyz") {}
    void desc() { 
        cout << "You have " << maxtime << " seconds to type a random string of letters and press enter. " <<
                "Press any key when ready." << endl; }
    void generate() {
        for (int i=0; i<numchars; i++) {
            int picked = rand() % allowed_chars.length();
            word += allowed_chars[picked];
        }
    }
    void print() {
        cout << "Your word is: " << endl << endl << word << endl << endl;
    }
    bool answer() {
        string s;
        cout << "Enter your word below: " << endl;
        cin >> s;
        // evaluate answer and print results
        double totaltime = t.elapsed();
        if (s==word) correct = true;
        
        if (totaltime >= maxtime) cout << "Timeout! " << maxtime << " seconds has passed." << endl;
        else if (!correct) cout << "You typed the string wrong!" << endl;
        else {
            cout << "Your time was " << totaltime << " seconds!" << endl;
        }
        
        int score_awarded = int(scoring(1000,0.20,0.80,0,correct,maxtime,totaltime,0,true,true));
        cout << "Points awarded: " << score_awarded << "." << endl;
        score += score_awarded;
        return correct;
    }
};

#endif