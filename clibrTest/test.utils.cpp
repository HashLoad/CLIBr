#include "../clibr/commands/core/clibr.utils.hpp"
#include <gtest/gtest.h>

using namespace clibr;

TEST(UtilsTest, GetSizeFileTest) {
    std::string filePath = "./clibrTest.exe";
    std::string size = Utils::getSizeFile(filePath);
    ASSERT_NE("Error while opening the file", size);
    ASSERT_NE("Error while getting the file size", size);
}

TEST(UtilsTest, ToLowerCaseTest) {
    std::string input = "HelloWorld";
    std::string output = Utils::toLowerCase(input);
    ASSERT_EQ("helloworld", output);
}

TEST(UtilsTest, ToUpperCaseTest) {
    std::string input = "HelloWorld";
    std::string output = Utils::toUpperCase(input);
    ASSERT_EQ("HELLOWORLD", output);
}

TEST(UtilsTest, RegexReplaceAllTest) {
    std::string input = "Hello, world!";
    std::string pattern = ",";
    std::string replacement = "";
    std::string output = Utils::regexReplaceAll(input, pattern, replacement);
    ASSERT_EQ("Hello world!", output);
}

TEST(UtilsTest, SplitTest) {
	std::string input = "Hello,world,test";
	char delimiter = ' ';
	std::vector<std::string> result = Utils::split(input, delimiter);

	ASSERT_EQ(1, result.size());
	ASSERT_EQ("Hello,world,test", result[0]);
}

TEST(UtilsTest, JoinTest) {
	std::vector<std::string> input = { "Hello", "world", "test" };
	char delimiter = ' ';
	std::string result = Utils::join(input, delimiter);

	ASSERT_EQ("Hello world test", result);
}

TEST(UtilsTest, ReadFromFileTest) {
	std::string filePath = "./clibrTest.exe";
	std::string content = Utils::readFromFile(filePath);
	ASSERT_NE("", content);
}

TEST(UtilsTest, VersionTest) {
	std::string version = Utils::version();
	ASSERT_NE("", version);
}

TEST(UtilsTest, ReplaceStringTest) {
    std::string input = "Hello, world!";
	std::string pattern = ",";
	std::string replacement = "";
	std::string output = Utils::replaceString(input, pattern, replacement);
	ASSERT_EQ("Hello world!", output);
}