#ifndef _SCORING_H_
#define _SCORING_H_

using namespace std;

double scoring(double maxscore, double corr_prop, double time_prop, double acc_prop, 
            bool is_correct, double max_time, double time_used, double acc,
            bool correct_penalty, bool timeout_penalty) {
    // proportionally allocate score between correctness, time, and accuracy
    double corr_max = corr_prop*maxscore;
    double time_max = time_prop*maxscore;
    double acc_max = acc_prop*maxscore;
    double score_awarded = 0;
    // award scores
    if (is_correct) score_awarded += corr_max;
    if (time_used <= max_time) score_awarded += time_max*(1-time_used/max_time);
    score_awarded += acc*acc_max;
    // apply penalty if necessary
    if ((!is_correct) && (correct_penalty)) score_awarded = 0;
    if ((time_used > max_time) && (timeout_penalty)) score_awarded = 0;
    
    return score_awarded;
}

#endif