#ifndef TABLE_H
#define TABLE_H
#include <map>
#include <mutex>
#include <memory>

struct Element
{
	int name;
	int location;
	std::string value;
	Element(std::string _value)
	{
		name = 1;
		location = 1;
		value = _value;
	}
};

class Table
{
public:
	static void InsertElement(std::string,Element);
	static void PrintTable();

private:
	Table();
	static std::shared_ptr<Table> getInstance();
	static std::shared_ptr<Table> m_instance;
	std::mutex m_mutex;
	std::map<std::string, Element> m_table;
};

#endif