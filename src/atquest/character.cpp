#include "actions.h"
#include "character.h"
Action Character::Act()
{
        return Action::Wait;
}

int Character::Str() { return 10; }
int Character::Dex() { return 10; }
int Character::Con() { return 10; }
int Character::Wis() { return 10; }
int Character::AC() { return 10 + (Dex() - 10) / 2; }
