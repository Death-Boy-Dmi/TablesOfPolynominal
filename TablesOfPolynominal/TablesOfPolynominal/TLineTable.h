#include <string>

#define MAX_SIZE 100000

using namespace std;

template <class T>
struct TLine
{
	string nameKey;
	T* pValue;
};
template <class T>
class TLineTable
{
private:
	TLine<T>* line;
	size_t numOfLine;
	size_t countOfLine;
public:
	TLineTable()
	{
		numOfLine = NULL;
		countOfLine = NULL;
		line = nullptr;
		line->nameKey = '\0';
		line->pValue = nullptr;
	}
	TLineTable(size_t _numOfLine)
	{
		if (_numOfLine > MAX_SIZE || _numOfLine < NULL)
			throw _numOfLine;
		numOfLine = _numOfLine;
		line = new TLine<T>[_numOfLine];
		countOfLine = NULL;
	}
	~TLineTable() 
	{
		while (countOfLine != 0)
		{
			delete line[countOfLine];
			countOfLine--;
		}
	}
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
	int SearchOfLineByValue(T* _pValue)
	{
		for (size_t i = 0; i < countOfLine; i++)
		{
			if (line[i].pValue == _pValue)
				return i;
		}
		return -1;
	}
	void AddLine(string _nameKey, T* _pValue)
	{
		if (IsFull())
			return false;
		line[countOfLine].nameKey = _nameKey;
		line[countOfLine].pValue = _pValue;
		countOfLine++;
	}
	void DeleteLine(string _nameKey)
	{
		if (IsEmpty())
			return false;
		int pos = SearchOfLineByName(_nameKey);
		if (pos == -1)
			return false;

		line[pos].nameKey = line[countOfLine].nameKey;
		line[pos].pValue = line[countOfLine].pValue;
		
		line[countOfLine].nameKey = '\0';
		line[countOfLine].pValue = nullptr;
		
		countOfLine--;
	}
	T GetValue(string _nameKey)
	{
		int pos = SearchOfLineByName(_nameKey);
		if (pos == -1)
			return false;
		return line[pos].pValue;
	}
};