#ifndef __ATMACHINE__
#define __ATMACHINE__

#include "./BankServer.hpp"

class   AtmMachine {
    BankServer *bankServer;
    public:
        AtmMachine(BankServer *srv) : bankServer(srv) {}
        bool    withdraw(unsigned account_number, int value) {
            bool res = false;
            bankServer->connect();
            int av_ba = bankServer->getbalance(account_number);
            if (av_ba >= value) {
                res = true;
                bankServer->debit(account_number, value);
            }
            bankServer->disconnect();
            return res;
        }
        void    isreal(unsigned account_number) {
            bankServer->removeAccount(account_number); // this is just for testing
        }
};
#endif

/*
    in order to test withdraw
    connect, getbalance, debit, disconnect called only once

    retunr value of withdraw function should be true
*/