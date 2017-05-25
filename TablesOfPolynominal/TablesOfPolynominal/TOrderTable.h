#pragma once;
#include <string>

#define MAX_SIZE 100000

using namespace std;

template <class T>
struct TLine
{
	string nameKey;
	T pValue;
};
template <class T>
class TOrderTable
{
private:
	TLine<T>* line;
	size_t numOfLine;
	size_t countOfLine;
public:
	TOrderTable()
	{
		numOfLine = NULL;
		countOfLine = NULL;
		line = nullptr;
	}
	TOrderTable(size_t _numOfLine)
	{
		if (_numOfLine > MAX_SIZE || _numOfLine < NULL)
			throw _numOfLine;
		numOfLine = _numOfLine;
		line = new TLine<T>[_numOfLine];
		countOfLine = NULL;
	}
	~TOrderTable(){}
	bool IsFull()
	{
		return (countOfLine == numOfLine);
	}
	bool IsEmpty()
	{
		return (countOfLine == NULL);
	}
	int SearchOfLineByName(string _nameKey)
	{
		if (IsEmpty())
			return -1;
		for (size_t i = 0; i < countOfLine; i++)
		{
			if (line[i].nameKey == _nameKey)
				return i;
		}
		return -1;
	}
	int SearchOfLineByValue(T _pValue)
	{
		for (size_t i = 0; i < countOfLine; i++)
		{
			if (line[i].pValue == _pValue)
				return i;
		}
		return -1;
	}
	void AddLine(string _nameKey, T _pValue)
	{
		if (IsFull())
			throw "Is Full";
		TLine<T> temp;
		int pos = 0;
		while (_pValue <= line[pos].pValue)
			pos++;
		temp = line[pos];
		line[pos].nameKey = _nameKey;
		line[pos].pValue = _pValue;
		countOfLine++;
		int flag = 1;
		TLine<T> tmp;
		for (size_t i = pos + 1; i < countOfLine; i++)
		{
			if (flag)
			{
				tmp = line[i];
				line[i] = temp;
				flag--;
			}
			else
			{
				temp = line[i];
				line[i] = tmp;
				flag++;
			}
		}
	}
	void DeleteLine(string _nameKey)
	{
		if (IsEmpty())
			throw "Is Empty";
		int pos = SearchOfLineByName(_nameKey);
		if (pos == -1)
			throw "Is Not Found";
		for (size_t i = pos; i < countOfLine - 1; i++)
		{
			line[i].nameKey = line[i + 1].nameKey;
			line[i].pValue = line[i + 1].pValue;
		}
		line[countOfLine].nameKey = '\0';
		countOfLine--;
	}
	T GetValue(string _nameKey)
	{
		if (IsEmpty())
			throw "Is Empty";
		int pos = SearchOfLineByName(_nameKey);
		if (pos == -1)
			throw "Is Not Found";
		return line[pos].pValue;
	}
};