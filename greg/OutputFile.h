#ifndef _OUTPUT_FILE_
#define _OUTPUT_FILE_

#include <string>
#include <fstream>
#include <memory>


class Output
{
public:
	static void SetFilePath(std::string path);
	static void out(std::string);
	static void endFile();
private:
	void setUpFile();
	Output();
	static std::shared_ptr<Output> getInstance();
	static std::shared_ptr<Output> m_instance;
	std::ofstream m_out;
};

#endif
