#include <gtest/gtest.h>

#include "advancedCalculator.hpp"

double out{};

TEST(AdvancedCalculatorTestCalculate, ShouldAdd) {
    ASSERT_EQ(process("-5.5 + -5.5", &out), ErrorCode::OK);
    ASSERT_DOUBLE_EQ(out, -11);
    ASSERT_EQ(process("10.2 + 12.9", &out), ErrorCode::OK);
    ASSERT_DOUBLE_EQ(out, 23.1);
    ASSERT_EQ(process("-99999.999 + -9999999.999", &out), ErrorCode::OK);
    ASSERT_DOUBLE_EQ(out, -10099999.998);
}

TEST(AdvancedCalculatorTestCalculate, ShouldSubtract) {
    ASSERT_EQ(process("-5.5 - -5.5", &out), ErrorCode::OK);
    ASSERT_DOUBLE_EQ(out, 0);
    ASSERT_EQ(process("10.2 - 12.9", &out), ErrorCode::OK);
    ASSERT_DOUBLE_EQ(out, -2.7);
    ASSERT_EQ(process("-99999.999 - -9999999.999", &out), ErrorCode::OK);
    ASSERT_DOUBLE_EQ(out, 9900000);
}

TEST(AdvancedCalculatorTestCalculate, ShouldMultiply) {
    ASSERT_EQ(process("-5.5 * -5.5", &out), ErrorCode::OK);
    ASSERT_DOUBLE_EQ(out, 30.25);
    ASSERT_EQ(process("10.2 * 12.9", &out), ErrorCode::OK);
    ASSERT_DOUBLE_EQ(out, 131.58);
    ASSERT_EQ(process("-99999.999 * -99999.999", &out), ErrorCode::OK);
    ASSERT_DOUBLE_EQ(out, 9999999800.000001);
}

TEST(AdvancedCalculatorTestCalculate, ShouldDivide) {
    ASSERT_EQ(process("-5.5 / -5.5", &out), ErrorCode::OK);
    ASSERT_DOUBLE_EQ(out, 1);
    ASSERT_EQ(process("10.2 / 1.6", &out), ErrorCode::OK);
    ASSERT_DOUBLE_EQ(out, 6.375);
    ASSERT_EQ(process("-99999.999 / -9.999", &out), ErrorCode::OK);
    ASSERT_DOUBLE_EQ(out, 10001);
}

TEST(AdvancedCalculatorTestCalculate, ShouldPower) {
    ASSERT_EQ(process("-5 ^ 3", &out), ErrorCode::OK);
    ASSERT_DOUBLE_EQ(out, -125);
    ASSERT_EQ(process("12.5 ^ -3", &out), ErrorCode::OK);
    ASSERT_DOUBLE_EQ(out, 0.000512);
    ASSERT_EQ(process("99999.999 ^ 0", &out), ErrorCode::OK);
    ASSERT_DOUBLE_EQ(out, 1);
}

TEST(AdvancedCalculatorTestCalculate, ShouldRoot) {
    ASSERT_EQ(process("16 $ 4", &out), ErrorCode::OK);
    ASSERT_DOUBLE_EQ(out, 2);
    ASSERT_EQ(process("128 $ 7", &out), ErrorCode::OK);
    ASSERT_DOUBLE_EQ(out, 2);
    ASSERT_EQ(process("99999.999 $ 1", &out), ErrorCode::OK);
    ASSERT_DOUBLE_EQ(out, 99999.999);
}

TEST(AdvancedCalculatorTestCalculate, ShouldModulo) {
    ASSERT_EQ(process("16 % 4", &out), ErrorCode::OK);
    ASSERT_DOUBLE_EQ(out, 0);
    ASSERT_EQ(process("128 % 7", &out), ErrorCode::OK);
    ASSERT_DOUBLE_EQ(out, 2);
    ASSERT_EQ(process("99999 % 6", &out), ErrorCode::OK);
    ASSERT_DOUBLE_EQ(out, 3);
}

TEST(AdvancedCalculatorTestCalculate, ShouldFactorial) {
    ASSERT_EQ(process("1 !", &out), ErrorCode::OK);
    ASSERT_DOUBLE_EQ(out, 1);
    ASSERT_EQ(process("2 !", &out), ErrorCode::OK);
    ASSERT_DOUBLE_EQ(out, 2);
    ASSERT_EQ(process("8 !", &out), ErrorCode::OK);
    ASSERT_DOUBLE_EQ(out, 40320);
}

TEST(AdvancedCalculatorTestErrors, ShouldReturnBadFormat) {
    ASSERT_EQ(process("+ 1.1", &out), ErrorCode::BadFormat);
    ASSERT_EQ(process("1.1 $", &out), ErrorCode::BadFormat);
    ASSERT_EQ(process("+ 1 1", &out), ErrorCode::BadFormat);
    ASSERT_EQ(process("1 1 *", &out), ErrorCode::BadFormat);
    ASSERT_EQ(process("^ 1 *", &out), ErrorCode::BadFormat);
    ASSERT_EQ(process("- -1 -1", &out), ErrorCode::BadFormat);
    ASSERT_EQ(process("% 1 -1", &out), ErrorCode::BadFormat);
    ASSERT_EQ(process("1 ! 1", &out), ErrorCode::BadFormat);
    ASSERT_EQ(process("1 + 1 - 1", &out), ErrorCode::BadFormat);
}

TEST(AdvancedCalculatorTestErrors, ShouldReturnBadCharacter) {
    ASSERT_EQ(process("a + 1", &out), ErrorCode::BadCharacter);
    ASSERT_EQ(process("1 - abc", &out), ErrorCode::BadCharacter);
    ASSERT_EQ(process("a * a", &out), ErrorCode::BadCharacter);
    ASSERT_EQ(process("ab / cd", &out), ErrorCode::BadCharacter);
    ASSERT_EQ(process("1 ^ a", &out), ErrorCode::BadCharacter);
    ASSERT_EQ(process("a $ b", &out), ErrorCode::BadCharacter);
    ASSERT_EQ(process("1a % 1b", &out), ErrorCode::BadCharacter);
    ASSERT_EQ(process("a1 % 1", &out), ErrorCode::BadCharacter);
    ASSERT_EQ(process("1 % a1", &out), ErrorCode::BadCharacter);
    ASSERT_EQ(process("a1 % a1", &out), ErrorCode::BadCharacter);
    ASSERT_EQ(process("a !", &out), ErrorCode::BadCharacter);
}

TEST(AdvancedCalculatorTestErrors, ShouldReturnDivideBy0) {
    ASSERT_EQ(process("1 / 0", &out), ErrorCode::DivideBy0);
    ASSERT_EQ(process("1 / 0.0", &out), ErrorCode::DivideBy0);
    ASSERT_EQ(process("0.0 / 0", &out), ErrorCode::DivideBy0);
    ASSERT_EQ(process("1.1 % 0", &out), ErrorCode::DivideBy0);
    ASSERT_EQ(process("1.1 $ 0", &out), ErrorCode::DivideBy0);
}

TEST(AdvancedCalculatorTestErrors, ShouldReturnModuleOfNonIntegerValue) {
    ASSERT_EQ(process("1 % 1.1", &out), ErrorCode::ModuleOfNonIntegerValue);
    ASSERT_EQ(process("1.1 % 1", &out), ErrorCode::ModuleOfNonIntegerValue);
    ASSERT_EQ(process("1.1 % 1.1", &out), ErrorCode::ModuleOfNonIntegerValue);
}

TEST(AdvancedCalculatorTestErrors, ShouldReturnSqrtOfNegativeNumber) {
    ASSERT_EQ(process("-1 $ -1", &out), ErrorCode::SqrtOfNegativeNumber);
    ASSERT_EQ(process("-1 $ 1", &out), ErrorCode::SqrtOfNegativeNumber);
    ASSERT_EQ(process("-1.1 $ 1", &out), ErrorCode::SqrtOfNegativeNumber);
}
