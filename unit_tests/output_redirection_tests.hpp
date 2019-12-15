#ifndef __OUTPUT_REDIRECTION_TESTS_HPP__
#define __OUTPUT_REDIRECTION_TESTS_HPP__

#include "../header/base_commands.h"	
#include "../header/commented_commands.h" 
#include "../header/multiple_commands.h" 
#include "../header/single_commands.h"
TEST(Output_Redirection_Tests, TEST1) {
	std::string st = "< inputfile.txt | tr a-z A-Z > outputfile.txt";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Output_Redirection_Tests, TEST2) {
	std::string st = "< inputfile.txt | tr A-Z a-z > outputfile.txt";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Output_Redirection_Tests, TEST3) {
	std::string st = "< inputfile.txt | tr -d l > outputfile.txt";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Output_Redirection_Tests, TEST4) {
	std::string st = "< inputfile.txt | tr you me > outputfile.txt";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}


TEST(Output_Redirection_Tests, TEST5) {
	std::string st = "< inputfile.txt | tr you OK > outputfile.txt";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Output_Redirection_Tests, TEST6) {
	std::string st = "< inputfile.txt | tr a-z A-Z | tr YO yo  > outputfile.txt";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Output_Redirection_Tests, TEST7) {
	std::string st = "< inputfile.txt | tr A-Z a-z | tr yo YO  > outputfile.txt";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}


TEST(Output_Redirection_Tests, TEST8) {
	std::string st = "< inputfile.txt | tr a-z A-Z | tr A-Z a-z  > outputfile.txt";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Output_Redirection_Tests, TEST9) {
	std::string st = "< inputfile.txt | tr -d a  > outputfile.txt";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Output_Redirection_Tests, TEST10) {
	std::string st = "< inputfile.txt | tr A-Z a-z | tr -d b > outputfile.txt";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}


TEST(Output_Redirection_Tests, TEST11) {
	std::string st = "< inputfile.txt | tr a-z A-Z | tr -d B  > outputfile.txt";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Output_Redirection_Tests, TEST12) {
	std::string st = "< inputfile.txt | tr a-z A-Z | tr A b  > outputfile.txt";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}


#endif
