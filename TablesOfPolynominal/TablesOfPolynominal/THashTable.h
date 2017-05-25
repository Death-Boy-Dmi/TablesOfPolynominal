#pragma once;
#include "TPolynominal.h"

#define MaxSizeOfTable 36

template <class T>
struct THashLine
{
	size_t numOfLine;
	std::string nameOfLine;
	T /*TPolynominal */value;

	THashLine<T>* pNextLine;
	THashLine()
	{
		numOfLine = NULL;
	}
};
template <class T>
class THashTable
{
	THashLine<T> line[MaxSizeOfTable];
	size_t countOfLine;

	size_t Hash(std::string _nameOfLine)
	{
		return ((int)(_nameOfLine[0]) - 48);
	}
public:
	THashTable()
	{
		countOfLine = NULL;
	}
	bool IsFull()
	{
		return (countOfLine == MaxSizeOfTable);
	}
	bool IsEmpty()
	{
		return (countOfLine == NULL);
	}
	bool IsFound(std::string _nameOfLine)
	{
		size_t hashKey = Hash(_nameOfLine);
		if (line[hashKey].numOfLine == 0) return false;
		if (line[hashKey].nameOfLine == _nameOfLine)
		{
			return true;
		}
		else
		{
			THashLine<T>* p = new THashLine<T>;
			p = line[hashKey].pNextLine;
			for (size_t i = 0; i < line[hashKey].numOfLine - 1; i++)
			{
				if (p->nameOfLine == _nameOfLine)
					return true;
				p = p->pNextLine;
			}
		}
		return false;
	}
	void AddLine(std::string _nameOfLine, T /*TPolynominal */ _polinom)
	{
		if (IsFull())
			throw "Is Full";
		size_t hashKey = Hash(_nameOfLine);
		if (line[hashKey].numOfLine == 0)
		{
			line[hashKey].nameOfLine = _nameOfLine;
			line[hashKey].value = _polinom;
		}
		else
		{
			line[hashKey].pNextLine = new THashLine<T>;
			THashLine<T>* p = new THashLine<T>;
			p = line[hashKey].pNextLine;
			for (size_t i = 0; i < line[hashKey].numOfLine-1; i++)
			{
				p->pNextLine = new THashLine<T>;
				p = p->pNextLine;
			}
			p->nameOfLine = _nameOfLine;
			p->value = _polinom;
		}
		line[hashKey].numOfLine++;
		countOfLine++;

	}
	void DeleteLine(std::string _nameOfLine)
	{
		if (IsEmpty())
			throw "Is Empty";
		if (IsFound(_nameOfLine) == false)
			throw "Is Not Found";
		size_t count = 0;
		size_t hashKey = Hash(_nameOfLine);
		if (line[hashKey].numOfLine == 1)
		{
			T _polinom;
			line[hashKey].nameOfLine = "";
			line[hashKey].value = _polinom;

		}
		else
		{
			THashLine<T>* p = new THashLine<T>;
			p = line[hashKey].pNextLine;
			while (p->nameOfLine != _nameOfLine)
			{
				p = p->pNextLine;
				count++;
			}
			THashLine<T>* pl = new THashLine<T>;
			pl = line[hashKey].pNextLine;
			for (size_t i = 0; i < count - 2; i++)
			{
				pl = pl->pNextLine;
			}
			pl->pNextLine = p->pNextLine;
			delete p;
		}
		line[hashKey].numOfLine--;
		countOfLine--;
	}
	T /*TPolynominal*/ GetPolinominal(std::string _nameOfLine)
	{
		if (IsEmpty())
			throw "Is Empty";
		if (IsFound(_nameOfLine) == false)
			throw "Is Not Found";
		size_t hashKey = Hash(_nameOfLine);
		if (line[hashKey].nameOfLine == _nameOfLine)
		{
			return line[hashKey].value;
		}
		else
		{
			THashLine<T>* p = new THashLine<T>;
			p = line[hashKey].pNextLine;

			for (size_t i = 0; i < line[hashKey].numOfLine-1; i++)
			{
				if (p->nameOfLine == _nameOfLine)
					return p->value;
				p = p->pNextLine;
			}
		}
	}
};