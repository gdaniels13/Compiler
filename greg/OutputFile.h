#ifndef _OUTPUT_FILE_
#define _OUTPUT_FILE_

#include <string>
#include <fstream>
#include <memory>
#include <map>
#include <deque>

class Output
{
public:
	int ifCount;
	int EndIfStatement;
	int whileCount;
	int repeatCount;
	int forCount;

	std::deque<int> ifQueue;
	std::deque<int> endIfQueue;
	std::deque<int> whileQueue;
	std::deque<int> repeatQueue;
	std::deque<int> forQueue;
	static void createEndOfIfStatement();
	static int getEndOfIfStatement();
	static int pushIfQueue();
	static int popIfQueue();;
	static int pushEndIfQueue();
	static int popEndIfQueue();
	static int getEndIfQueue();

	static int pushWhile();
	static int popWhile();
	static int getWhile();

	static int pushRepeat();
	static int popRepeat();
	static int getRepeat();

	static int pushFor();
	static int popFor();
	static int getFor();


	static void SetFilePath(std::string path);
	static void out(std::string);
	static void comment(std::string);
	static void endFile();
	static int getRegister();
	static void freeRegister(int);
	static std::string addString(std::string);

	static std::shared_ptr<Output> getInstance();

	static void setCurFunction(std::string);
	static std::string getCurFunction();

private:
	std::string currentFunction;
	void setUpFile();
	bool registers[17];
	std::map<std::string, std::string> strings;

	Output();
	static std::shared_ptr<Output> m_instance;
	std::ofstream m_out;

};

#endif