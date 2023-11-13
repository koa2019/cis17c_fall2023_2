/* 
 * File:   Score.h
 * Author: DanYell
 * Created on November 2, 2022, 9:05 PM
 */

#ifndef SCORE_H
#define SCORE_H

struct Score {
    int nPlayrs;
    int maxGmes;
    int ttlGams;
    int ttlRnds;
    Player *player;
    //Choices *choices;
};

#endif /* SCORE_H */

