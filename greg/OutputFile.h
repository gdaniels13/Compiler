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
	std::deque<int> ifQueue;
	std::deque<int> endIfQueue;

	static void createEndOfIfStatement();
	static int getEndOfIfStatement();
	static int pushIfQueue();
	static int popIfQueue();;
	static int pushEndIfQueue();
	static int popEndIfQueue();
	static int getEndIfQueue();

	static void SetFilePath(std::string path);
	static void out(std::string);
	static void comment(std::string);
	static void endFile();
	static int getRegister();
	static void freeRegister(int);
	static std::string addString(std::string);

	static std::shared_ptr<Output> getInstance();
private:
	void setUpFile();
	bool registers[17];
	std::map<std::string, std::string> strings;

	Output();
	static std::shared_ptr<Output> m_instance;
	std::ofstream m_out;

};

#endif