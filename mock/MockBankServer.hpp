#ifndef __MOCK_BANK_SERVER__
#define __MOCK_BANK_SERVER__
#include "./BankServer.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;


class   MockBankServer : public BankServer {
    public:
        MOCK_METHOD(void, connect, (), (override));
        MOCK_METHOD(void, disconnect, (), (override));
        MOCK_METHOD(void, credit, (unsigned, int), (override));
        MOCK_METHOD(void, debit, (unsigned, int), (override));
        MOCK_METHOD(bool, doubleTransaction, (int, int, int), (override));
        MOCK_METHOD(int, getbalance, (int), (const, override));
};

#endif