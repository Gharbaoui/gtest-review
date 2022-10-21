#include "./AtmMachine.hpp"
#include "./MockBankServer.hpp"

TEST(AtmMachine, basicTests)
{
    unsigned account_number = 6790;
    int value = 1000;
    MockBankServer bankServer;

    EXPECT_CALL(bankServer, connect()).Times(1);
    EXPECT_CALL(bankServer, getbalance(account_number)).Times(1).WillRepeatedly(Return(2000));
    EXPECT_CALL(bankServer, debit(account_number, value)).Times(1);
    EXPECT_CALL(bankServer, disconnect()).Times(1);

    AtmMachine atm(&bankServer);
    bool res = atm.withdraw(account_number, value);
    EXPECT_TRUE(res);
}