#include "./sequanceMock.hpp"
#include "./sequance_user.hpp"

class SeqUnIntrestedFixture: public ::testing::Test {
    protected:
        SeqUnIntrestedFixture() : sq(&mockSeq) {}
        NiceMock<MockSequance> mockSeq;
        SeqUser sq;
};

TEST_F(SeqUnIntrestedFixture, counterClockWiseRotation)
{
    Sequence s1;
    unsigned stps;

    stps = 90;
    // i want right before left for example

    EXPECT_CALL(mockSeq, walkLeft(stps)).Times(1).InSequence(s1);
    EXPECT_CALL(mockSeq, walkRight(stps)).Times(1).InSequence(s1);

    sq.counterClockWise(stps);

}

TEST_F(SeqUnIntrestedFixture, OtherWayForOrder)
{
    unsigned stps;

    stps = 89;
    Expectation right = EXPECT_CALL(mockSeq, walkRight(stps)).Times(1);
    EXPECT_CALL(mockSeq, walkLeft(stps)).Times(1).After(right);

    sq.counterClockWise(stps);
}