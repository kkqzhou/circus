#ifndef _MEMORY_H_
#define _MEMORY_H_

#include "problem.h"
#include "console.h"

class memory : public problem {
private:
    int nnums;
    float wait;
    string numbers;
    string allowed_chars;
public:
    memory() : problem(12), nnums(12), wait(0.75), numbers(""), allowed_chars("0123456789") {}
    void desc() {
        cout << "Memorize a sequence of numbers and type the numbers out in one string as quickly as possible." << endl;
        cout << "You have " << maxtime << " seconds. Press any key when ready." << endl; }
    void generate() {
        for (int i=0; i<nnums; i++) {
            int picked = rand() % (allowed_chars.length());
            numbers += allowed_chars[picked];
        }
    }
    void print() {
        int startx = 0;
        int starty = 3;
        cout << "Here are your numbers: " << endl;
        for (unsigned int i=0; i<numbers.length(); i++) {
            setcoords(startx,starty);
            for (unsigned int j=0; j<i; j++) {
                cout << "*";
            }
            cout << numbers[i];
            Sleep(int(wait*1000));
        }
        setcoords(startx,starty);
        for (unsigned int i=0; i<numbers.length(); i++) {
            cout << "*";
        }
        cout << endl;
    }
    bool answer() {
        // clear the buffer to prevent cheating - otherwise you can type in numbers while they are being displayed
        HANDLE hIn;
        hIn = GetStdHandle(STD_INPUT_HANDLE);
        FlushConsoleInputBuffer(hIn);
        string ans;
        cout << "Enter the numbers shown, in one string: ";
        cin >> ans;
        // evaluate answer and print results
        double totaltime = t.elapsed();
        if (ans == numbers) correct = true;
        
        int num_ints_match = 0;
        if (numbers.length() == ans.length()) {
            for (unsigned int i=0; i<numbers.length(); i++) {
                if (numbers[i] == ans[i]) num_ints_match++;
            }
        }
        
        double acc = num_ints_match*1.0/numbers.length();
        
        if (totaltime >= maxtime) cout << "Timeout! " << maxtime << " seconds has passed." << endl;
        else if (!correct) {
            cout << "Incorrect! Answer is " << numbers << endl;
            cout << "You finished the problem in " << totaltime << " seconds!" << endl;
        }
        else {
            cout << "Correct! You finished the problem in " << totaltime << " seconds!" << endl;
        }
        
        int score_awarded = int(scoring(1000,0.20,0.50,0.30,correct,maxtime,totaltime,acc,false,true));
        cout << "Points awarded: " << score_awarded << "." << endl;
        score += score_awarded;
        return correct;
    }
};

#endif