#include "./sequance_user.hpp"

SeqUser::SeqUser(SequanceInterface *sc) : seqclass(sc) {}

void    SeqUser::counterClockWise(unsigned stp) {
    seqclass->walkRight(stp);
    seqclass->walkDown(stp);
    seqclass->walkLeft(stp);
    seqclass->walkUp(stp);
};