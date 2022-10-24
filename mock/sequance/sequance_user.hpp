#ifndef __SEQUANCE_USER__
#define __SEQUANCE_USER__
#include "./sequance_interface.hpp"

class SeqUser {
    public:
        SeqUser(SequanceInterface *sc);
        void    counterClockWise(unsigned);
    private:
        SequanceInterface *seqclass;

};
#endif