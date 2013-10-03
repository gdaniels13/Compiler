#include "table.h"

int main()
{
	
	Element e;
	e.name = 1;
	e.location = 2;
	e.value = 3;
	Table::InsertElement("element", e);
	Table::PrintTable();
	return 0;
}