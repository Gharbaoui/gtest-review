#ifndef __SEQUANCE__
#define __SEQUANCE__

class   SequanceInterface {
    public:
        virtual ~SequanceInterface() = default;
        virtual bool    walkUp(unsigned stp) = 0;
        virtual bool    walkDown(unsigned stp) = 0;
        virtual bool    walkRight(unsigned stp) = 0;
        virtual bool    walkLeft(unsigned stp) = 0;
        virtual int     report() const = 0;
};

#endif