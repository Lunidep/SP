//                 lexer.h 2021
#ifndef LEXER_H
#define LEXER_H
#include "baselexer.h"
class tLexer :public tBaseLexer {
public:
    //конструктор
    tLexer() :tBaseLexer() {
        //создать автоматы:

        //________________________________________

        // вещественное

        addstr(Adec, 0, "+", 1);
        addstr(Adec, 0, "-", 1);

        addstr(Adec, 1, ".", 2);
        addrange(Adec, 1, '0', '9', 1);

        addrange(Adec, 2, '0', '9', 3);

        addstr(Adec, 3, "e", 4);
        addstr(Adec, 3, "E", 4);
        addrange(Adec, 3, '0', '9', 3);

        addstr(Adec, 4, "+", 5);
        addstr(Adec, 4, "-", 5);
        addrange(Adec, 4, '0', '9', 5);

        addrange(Adec, 5, '0', '9', 5);
        Adec.final(5);

        //________________________________________

        // идентификатор
        
        //0
        addstr(Aid, 0, "!", 1);

        addrange(Aid, 0, 'A', 'Z', 2);
        addrange(Aid, 0, 'a', 'z', 2);

        addstr(Aid, 0, "?", 3);

        //1
        addstr(Aid, 1, "!", 1);

        addrange(Aid, 1, 'A', 'Z', 2);
        addrange(Aid, 1, 'a', 'z', 2);
        addrange(Aid, 1, '0', '9', 2);
        addstr(Aid, 1, "-", 2);


        //2
        addstr(Aid, 2, "!", 1);

        addrange(Aid, 2, 'A', 'Z', 2);
        addrange(Aid, 2, 'a', 'z', 2);
        addrange(Aid, 2, '0', '9', 2);
        addstr(Aid, 2, "-", 2);

        addstr(Aid, 2, "?", 3);


        //3
        addstr(Aid, 3, "!", 2);

        addrange(Aid, 3, 'A', 'Z', 2);
        addrange(Aid, 3, 'a', 'z', 2);
        addrange(Aid, 3, '0', '9', 2);
        addstr(Aid, 3, "-", 2);

        addstr(Aid, 3, "?", 3);

        Aid.final(1);
        Aid.final(2);
        //________________________________________

        // идентификатор предиката
        
        //0
        addrange(Aidq, 0, 'A', 'Z', 1);
        addrange(Aidq, 0, 'a', 'z', 1);
        addstr(Aidq, 0, "!", 1);

        addstr(Aidq, 0, "-", 2);

        addstr(Aidq, 0, "?", 3);

        //1
        addrange(Aidq, 1, 'A', 'Z', 1);
        addrange(Aidq, 1, 'a', 'z', 1);
        addrange(Aidq, 1, '0', '9', 1);
        addstr(Aidq, 1, "!", 1);

        addstr(Aidq, 1, "-", 2);

        addstr(Aidq, 1, "?", 3);

        //2
        addrange(Aidq, 2, 'A', 'Z', 1);
        addrange(Aidq, 2, 'a', 'z', 1);
        addrange(Aidq, 2, '0', '9', 1);
        addstr(Aidq, 2, "!", 1);

        addstr(Aidq, 2, "-", 4);

        addstr(Aidq, 2, "?", 3);

        //3
        addrange(Aidq, 3, 'A', 'Z', 1);
        addrange(Aidq, 3, 'a', 'z', 1);
        addrange(Aidq, 3, '0', '9', 1);
        addstr(Aidq, 3, "!", 1);

        addstr(Aidq, 3, "-", 2);

        addstr(Aidq, 3, "?", 3);

        //4
        addrange(Aidq, 4, 'A', 'Z', 1);
        addrange(Aidq, 4, 'a', 'z', 1);
        addrange(Aidq, 4, '0', '9', 1);
        addstr(Aidq, 4, "!", 1);

        addstr(Aidq, 4, "-", 4);

        Aidq.final(3);
    }
};
#endif

