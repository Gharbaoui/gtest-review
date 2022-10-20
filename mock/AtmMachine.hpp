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
            if (av_ba > value) {
                res = true;
                bankServer->debit(account_number, value);
            }
            bankServer->disconnect();
            return res;
        }
};
#endif