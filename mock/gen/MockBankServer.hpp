#ifndef __MOCK_BANK_SERVER__
#define __MOCK_BANK_SERVER__
#include "./BankServer.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
using ::testing::NiceMock;
using ::testing::StrictMock;


class   MockBankServer : public BankServer {
    public:
        MOCK_METHOD(void, connect, (), (override));
        MOCK_METHOD(void, disconnect, (), (override));
        MOCK_METHOD(void, credit, (unsigned, int), (override));
        MOCK_METHOD(void, debit, (unsigned, int), (override));
        MOCK_METHOD(bool, doubleTransaction, (unsigned, int, int), (override));
        MOCK_METHOD(int, getbalance, (unsigned), (const, override));
        MOCK_METHOD(bool, removeAccount, (unsigned), (override));
};

#endif