#ifndef SYMBOLS_H
#define SYMBOLS_H

 
#include <iostream>
#include <algorithm>
#include <string>
#include <memory>
#include <map>

/*
Procedure and Function (name, signature, location)
Types (names, sizes, layout)
Variables (name, location)
Constants (name, location or value)
*/

enum constantType{
	INT =1,
	STR =2,
	CHAR= 3,
	ID =4,
	BOOL = 5
};



class Symbol
{
public:
	std::string name;
	virtual void print(){std::cout<<"BIG FAT ERROR!!!!!!!!!!!\n";}

};


class Type : public Symbol
{
public:
	int size;
	Type(){};
	Type(std::string na, int sz)
	{
		size = sz;
		name = na;
	};
	Type(std::string na)
	{
		name = na;
	}

	void print()
	{
		std::cout<<"Type: "<<name<<" Size: "<<size<<std::endl;
	};
};

class Array : public Type
{
public:
	int lower;
	int upper;
	std::shared_ptr<Type> type;
	Array(std::string na,int l,int u,std::shared_ptr<Symbol> t)
	{
		name = na;
		type = std::dynamic_pointer_cast<Type> (t);
		lower = l;
		upper = u;
		size = (upper - lower +1)*(std::dynamic_pointer_cast<Type>(t)->size);
	};
	void print()
	{
		std::cout<<"Array: "<<name<<" Size:"<<size<<" Lower: " <<lower<<" Upper: " <<upper;
		type->print();
	};
};






class Variable : public Symbol
{
public:
	std::shared_ptr<Type> type;
	int size;
	int location;

	Variable(std::shared_ptr<Type> t, int loc, std::string n)
	{
		name =n;
		loc = location;
		type = t;
		size = t->size;
	}

	void setType(std::shared_ptr<Type> a)
	{
		type =a;
	}

	void print()
	{
		std::cout<<"Var: "<<name<<" Location: " << location<<" ";
		type->print();
		
	}


};

class Function : public Symbol
{
public:
	std::shared_ptr<Type> returnType;
	std::string location;
	std::string signature;
	std::vector<std::shared_ptr<Variable>> parameters;
	void print()
	{
		if(returnType)
		{
			std::cout<<"Function: "<<name<<" Signature : "<<signature<<" Location: "<<location<<std::endl;
		}
		else
		{
			std::cout<<"Procedure: "<<name<<" Signature : "<<signature<<" Location: "<<location<<std::endl;
		}

	}
};





class Constant : public Symbol
{
public:
	constantType type;
	std::string s_value;
	int i_value;
	char c_value;
	bool b_value;

	

	Constant(int  t)
	{
		type = INT;
		i_value = t;
	}
	
	Constant(std::string t, constantType ty)
	{
		s_value;
		type = ty;
	}

	Constant(char t)
	{
		c_value = t;
		type = CHAR;
	}

	Constant(bool t)
	{
		b_value = t;
		type = BOOL;
	}

	Constant * makeBoolNot()
	{
		if(type == BOOL)
		{
			b_value = !b_value;
			return this;
		}
		std::cout<<"ERROR INVALID USE OF NOT\n";
		exit(-1);
	}

	Constant * makeNegative()
	{
		if(type == INT)
		{
			i_value = -i_value;
			return this;
		}
		std::cout<<"ERROR INVALID USE of Unary MINUS\n";
		exit(-1);
	}

	void print()
	{
		std::cout<<"Constant: "<<name<<" ";
		if(type == INT) std::cout<<"Type: int Value:"<<i_value<<std::endl;
		else if(type == CHAR) std::cout<<"Type: char Value: "<<c_value<<std::endl;
		else if(type == STR) std::cout<<"Type: String Value: "<<s_value<<std::endl;
		else if(type == BOOL) std::cout<<"Type: bool Value: "<<b_value<<std::endl;
	}
};


class Record : public Type
{
public:
	std::map<std::string,std::shared_ptr<Variable>> records;
	Record(){};
	void add(std::shared_ptr<Variable> v)
	{
		records.insert(std::make_pair(v->name,v));
	}

	int getSize()
	{
		int tsize = 0;
		for(auto var : records)
		{
			tsize += var.second->size;
		}
		size = tsize;
		return size;
	}

	void print(){

		std::cout<<"Record: "<<name<<" Size:"<<size<<std::endl;
		std::for_each(records.begin(),records.end(), [](std::pair<std::string,std::shared_ptr<Variable>> cur)
		{

			//std::cout<<<<cur.first<<": ";
			cur.second->print();
		});
	}
};






#endif
