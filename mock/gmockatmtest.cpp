#include "./AtmMachine.hpp"
#include "./MockBankServer.hpp"

class AtmMachineFixture : public ::testing::Test
{
    protected:
        AtmMachineFixture () : atm(&bankServer) {}
        MockBankServer bankServer;
        AtmMachine atm;
};

TEST(AtmMachineGroup, basicTestswithoneaccount)
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

TEST(AtmMachineGroup, multipleAccounts)
{
    MockBankServer bankServer;
    AtmMachine atm(&bankServer);
    unsigned account1, account2;
    int value = 90;

    account1 = 89789;
    account2 = 123232;
    
    EXPECT_CALL(bankServer, connect()).Times(2);
    EXPECT_CALL(bankServer, getbalance(_)).Times(2).WillRepeatedly(Return(200));
    EXPECT_CALL(bankServer, debit(_, value)).Times(2);
    EXPECT_CALL(bankServer, disconnect()).Times(2);

    EXPECT_TRUE(atm.withdraw(account1, value));
    EXPECT_TRUE(atm.withdraw(account2, value));
}

TEST_F(AtmMachineFixture, removeAccountTests)
{
    unsigned account1;

    account1 = 90;

    EXPECT_CALL(bankServer, removeAccount(account1)).Times(0);


    atm.isreal(account1);
}