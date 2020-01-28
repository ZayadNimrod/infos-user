#ifndef CHARACTER_H
#define CHARACTER_H
#include "actions.h"


class Character{
    public:
        int x;
        int y;
        char symbol;
        Action Act();

        int Str();
        int Dex();
        int Con();
        int Wis();
        int AC();

};
#endif /* CHARACTER_H */