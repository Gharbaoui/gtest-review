#ifndef __MOCK_SEQUANCE__
#define __MOCK_BANK_SERVER__
#include "./sequance_interface.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>



class MockSequance: public SequanceInterface
{
    MOCK_METHOD(bool, walkUp, (unsigned), (override));
    MOCK_METHOD(bool, walkDown, (unsigned), (override));
    MOCK_METHOD(bool, walkRight, (unsigned), (override));
    MOCK_METHOD(bool, walkLeft, (unsigned), (override));
    MOCK_METHOD(int, report, (), (const,override));
};

#endif