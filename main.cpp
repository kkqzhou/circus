#include "console.h"
#include "problem.h"
#include "multiplication.h"
#include "maximin.h"
#include "guessxs.h"
#include "bintodec.h"
#include "mode.h"
#include "pacemaker.h"
#include "typeletters.h"
#include "ihatefractions.h"
#include "missing.h"
#include "memory.h"

using namespace std;

int main(int argc, char **argv)
{
    srand(time(0));
    long score;
    
    cout << "Welcome to KZ's circus of challenges! Thank you for beta testing." << endl;
    cout << "You will be given a number of math and/or speed-based questions." << endl;
    cout << "At the start of each question, you will be given the question type and a time limit." << endl;
    cout << "Press any key once you are ready to solve the question. The timer will begin immediately." << endl;
    cout << "Once you have completed a question, press any key to move on to the next question." << endl;
    cout << "Make sure to maximize your screen window. Press any key to begin." << endl << endl;
    readkey();
    
    for (int i=0; i<10; i++) {
         /* */
        problem* pb;
        int type = rand() % 10;
        bool testmode = false;
        if (!testmode) {
            if (type == 0) pb = new multiplication;
            if (type == 1) pb = new maximin;
            if (type == 2) pb = new guessXs;
            if (type == 3) pb = new binToDec;
            if (type == 4) pb = new mode;
            if (type == 5) pb = new pacemaker;
            if (type == 6) pb = new typeletters;
            if (type == 7) pb = new ihatefractions;
            if (type == 8) pb = new missing;
            if (type == 9) pb = new memory;
        }
        if (testmode) {
            pb = new guessXs;
        }
        clrscr();
        cout << "Question " << i+1 << ": ";
        pb->desc();
        readkey();
        pb->generate();
        pb->print();
        pb->startTimer();
        pb->answer();
        score += pb->getScore();
        cout << "Score: " << score << endl << endl;
        
        delete pb;
        readkey();
    }
    cout << "You finished with a score of " << score << "." << endl;
    return 0;
}
