#ifndef __BANKSERVER_VIRTUAL__
#define __BANKSERVER_VIRTUAL__

class BankServer {
    public:
        virtual         ~BankServer() = default;
        virtual void    connect() = 0;
        virtual void    disconnect() = 0;
        virtual void    credit(unsigned account_number, int value) = 0;
        virtual void    debit(unsigned account_number, int value) = 0;
        virtual bool    doubleTransaction(unsigned account_number, int v1, int v2) = 0;
        virtual int     getbalance(unsigned account_number) const = 0;
        virtual bool    removeAccount(unsigned account_number) = 0;
};

#endif