#ifndef _OUTPUT_FILE_
#define _OUTPUT_FILE_

#include <string>
#include <fstream>
#include <memory>
#include <map>

class Output
{
public:
	static void SetFilePath(std::string path);
	static void out(std::string);
	static void comment(std::string);
	static void endFile();
	static int getRegister();
	static void freeRegister(int);
	static std::string addString(std::string);

private:
	void setUpFile();
	bool registers[17];
	std::map<std::string, std::string> strings;

	Output();
	static std::shared_ptr<Output> getInstance();
	static std::shared_ptr<Output> m_instance;
	std::ofstream m_out;

};

#endif