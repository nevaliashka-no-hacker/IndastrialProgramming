#include <gtest/gtest.h>
#include "data_processor.h"

// Пример теста (студенты должны дописать свои тесты)
TEST(ProcessorTest, EmptyLine) {
    ProcessResult res = process_line("");
    EXPECT_EQ(res.word_count, 0);
    EXPECT_EQ(res.char_count, 0);
    EXPECT_TRUE(res.longest_word.empty());
}

// TODO: добавить тесты для строк с одним словом,
// с несколькими словами, с ведущими/конечными пробелами и т.д.

TEST(ProcessorTest, OneWord) {
    ProcessResult res = process_line("WOOOOOOORD");
    EXPECT_EQ(res.word_count, 1);
    EXPECT_EQ(res.char_count, 10);
    EXPECT_EQ(res.longest_word, "WOOOOOOORD");
}

TEST(TestDataProcessor, AnyWord) {
    ProcessResult result = process_line("Hello big world");
    EXPECT_EQ(result.word_count, 3);
    EXPECT_EQ(result.char_count, 15);
    EXPECT_EQ(result.longest_word, "Hello");
}

TEST(TestDataProcessor, FirstProbel) {
    ProcessResult result = process_line("  Probel1 Probel54");
    EXPECT_EQ(result.word_count, 2);
    EXPECT_EQ(result.char_count, 18);
    EXPECT_EQ(result.longest_word, "Probel54");
}

TEST(TestDataProcessor, ProbelEnd) {
    ProcessResult result = process_line("Probel100 Probel3      ");
    EXPECT_EQ(result.word_count, 2);
    EXPECT_EQ(result.char_count, 23);
    EXPECT_EQ(result.longest_word, "Probel100");
}

TEST(TestDataProcessor, Probels) {
    ProcessResult result = process_line("      ");
    EXPECT_EQ(result.word_count, 0);
    EXPECT_EQ(result.char_count, 6);
    EXPECT_EQ(result.longest_word, "");
}

TEST(TestDataProcessor, VeryLongWords256) {
    ProcessResult result = process_line("hhhhheeeeelllllloooooooo pyyyyyyyyythoooooooooooon woooooooooooooorldddddddddddd hiiiiiiiiiiiiii aaaaaaaaaaaaaaaaaaaaa ooooooooooooooooooo 5454545454545454545454545454 proooooooooooograaaaaaaaaaaaaaaaamiiiiiiiiiiiiiiiiinggggggggggggggg oooooooooooooooonnnnnnnnnnnn C++++++++++++++++++++++++++++");
    EXPECT_EQ(result.word_count, 10);
    EXPECT_EQ(result.char_count, 294);
    EXPECT_EQ(result.longest_word, "proooooooooooograaaaaaaaaaaaaaaaamiiiiiiiiiiiiiiiiinggggggggggggggg");
}
