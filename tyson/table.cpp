#include "table.h"
#include <algorithm>
#include <iostream>

std::shared_ptr<Table> Table::m_instance;

Table::Table():
m_mutex(),
m_table()
{
}

std::shared_ptr<Table> Table::getInstance()
{
	if(!m_instance)
	{
		std::shared_ptr<Table> table(new Table());
		m_instance = table;
	}
	return m_instance;
}

void Table::InsertElement(std::string id, Element element)
{
	getInstance()->m_mutex.lock();
	getInstance()->m_table.insert(std::make_pair(id, element));
    getInstance()->m_mutex.unlock();
}

void Table::PrintTable()
{
	getInstance()->m_mutex.lock();
	std::for_each(getInstance()->m_table.begin(), getInstance()->m_table.end(), [](std::pair<std::string,Element> element)
	{
		std::cout << element.first << " " << element.second.name << " " << element.second.location << " " << element.second.value << std::endl;
	});
	getInstance()->m_mutex.unlock();
}