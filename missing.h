#ifndef _MISSING_H_
#define _MISSING_H_

#include "problem.h"

class missing : public problem {
private:
    char removed;
    string word;
    string allowed_chars;
public:
    missing() : problem(25), removed(' '), word(""),
                allowed_chars("abcdefghijklmnopqrstuvwxyz") {}
    void desc() { 
        cout << "You are given a length 25 string consisting of all but one of the 26 lowercase letters." << endl;
        cout << "You have " << maxtime << " seconds to determine the missing character. Press any key to begin." << endl;
    }
    void generate() {
        vector<int> positions;
        for (unsigned int i=0; i<allowed_chars.length(); i++) {
            positions.push_back(i);
        }
        int rmv = rand() % allowed_chars.length();
        removed = allowed_chars[positions[rmv]];
        positions.erase(positions.begin() + rmv);
        while (positions.size() != 0) {
            int picked = rand() % positions.size();
            word += allowed_chars[positions[picked]];
            positions.erase(positions.begin() + picked);
        }
    }
    void print() {
        cout << endl << word << endl << endl;
    }
    bool answer() {
        char c;
        cout << "Enter the missing character: ";
        cin >> c;
        // evaluate answer and print results
        double totaltime = t.elapsed();
        
        if (c==removed) correct = true;
        
        if (totaltime >= maxtime) cout << "Timeout! " << maxtime << " seconds has passed." << endl;
        else if (!correct) cout << "Incorrect! Correct answer is " << removed << endl;
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