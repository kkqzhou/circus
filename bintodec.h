#ifndef _BINTODEC_H_
#define _BINTODEC_H_

#include "problem.h"

class binToDec : public problem {
private:
    int number, thresh;
public:
    binToDec() : problem(25), number(0), thresh(256) {}
    void generate() { number = thresh + (rand() % (thresh*7)); }
    void desc() { cout << "Convert from binary to decimal. Press any key when ready." << endl; }
    void print() {
        cout << "Convert the following binary number into decimal." << 
                " You have " << maxtime << " seconds." << endl << endl;
        int num = number;
        vector<int> bin;
        while (num > 1) {
            if (num % 2 == 0) bin.insert(bin.begin(),0);
            if (num % 2 == 1) bin.insert(bin.begin(),1);
            num /= 2;
        }
        if (num == 0) bin.insert(bin.begin(),0);
        if (num == 1) bin.insert(bin.begin(),1);
        for (vector<int>::const_iterator i=bin.begin(); i!=bin.end(); i++) {
            cout << *i;
        }
        cout << endl << endl;
    }
    bool answer() {
        long ans1;
        cout << "Please enter your answer: ";
        cin >> ans1;
        // evaluate answer and print results
        double totaltime = t.elapsed();
        if (ans1 == number) correct = true;
        
        if (totaltime >= maxtime) cout << "Timeout! " << maxtime << " seconds has passed." << endl;
        else if (!correct) cout << "Incorrect! Answer is " << number << endl;
        else cout << "You finished the question in " << totaltime << " seconds!" << endl;

        int score_awarded = int(scoring(1000,0.25,0.75,0,correct,maxtime,totaltime,0,true,true));
        cout << "Points awarded: " << score_awarded << "." << endl;
        score += score_awarded;
        return correct;
    }
};

#endif