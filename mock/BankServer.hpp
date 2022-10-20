#ifndef __BANKSERVER_VIRTUAL__
#define __BANKSERVER_VIRTUAL__

class BankServer {
    public:
        virtual ~BankServer();
        virtual void    connect() = 0;
        virtual void    disconnect() = 0;
        virtual void    credit(unsigned account_number, int value) = 0;
        virtual void    debit(unsigned account_number, int value) = 0;
        virtual bool    doubleTransaction(int account_number, int v1, int v2) = 0;
        virtual int     getbalance(int account_number) const = 0;
};

#endif