#include <string>

#define MAX_SIZE 216000

using namespace std;
 
template <class T>
struct THashLine
{
	size_t countOfLink;
	string nameKey;
	size_t hashKey;
	T* pValue;
	THashLine<T>* pNext;
};
template <class T>
class THashTable
{
private:
	THashLine<T>* line;
	size_t numOfLine;
	size_t countOfLine;
	size_t Hash(string _nameKey)
	{
		return ((int)(_nameKey[0]) - 65);
	}
public:
	THashTable()
	{
		numOfLine = NULL;
		countOfLine = NULL;
		line = nullptr;
		line->nameKey = '\0';
		line->pValue = nullptr;
	}
	THashTable(size_t _numOfLine)
	{
		if (_numOfLine > MAX_SIZE || _numOfLine < NULL)
			throw _numOfLine;
		numOfLine = _numOfLine;
		line = new THashLine<T>[MAX_SIZE];
		countOfLine = NULL;
	}
	~THashTable()
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
	bool SearchOfLine(string _nameKey)
	{
		if (IsEmpty())
			return false;
		THashLine<T>* p = line[Hash(_nameKey)];
		for (size_t i = 0; i < line[Hash(_nameKey)].countOfLink; i++)
		{
			if (p->nameKey == _nameKey)
				return true;
			p = p->pNext;
		}
		return false;
	}
	void AddLine(string _nameKey, T* _pValue)
	{
		if (IsFull())
			return false;
		if (line[Hash(_nameKey)]->countOfLink == 0)
		{
			line[Hash(_nameKey)].hashKey = Hash(_nameKey);
			line[Hash(_nameKey)].nameKey = _nameKey;
			line[countOfLine].pValue = _pValue;
			line[Hash(_nameKey)]->countOfLink++;
		}
		else
		{
			THashLine<T>* p = line[Hash(_nameKey)];
			for (size_t i = 0; i < line[Hash(_nameKey)].countOfLink; i++)
			{
				p = p->pNext;
			}
			p->pNext->hashKey = Hash(_nameKey);
			p->pNext->nameKey = _nameKey;
			p->pNext->pValue = _pValue;
			line[Hash(_nameKey)]->countOfLink++;
		}
		countOfLine++;

	}
	void DeleteLine(string _nameKey)
	{
		if (IsEmpty())
			return false;
		if (!SearchOfLine(_nameKey))
			return false;
		size_t count = 0;
		THashLine<T>* p = line[Hash(_nameKey)];
		while (p->nameKey != _nameKey)
		{
			p = p->pNext;
			count++;
		}
		THashLine<T>* pl = line[Hash(_nameKey)];
		for (size_t i = 0; i < count - 1; i++)
		{
			pl = pl->pNext;
		}
		pl->pNext = p->pNext;
		delete p;
		line[Hash(_nameKey)]->countOfLink--;
		countOfLine--;
	}
	T GetValue(string _nameKey)
	{
		if (!SearchOfLine())
			return false;
		THashLine<T>* p = line[Hash(_nameKey)];
		while (p->nameKey != _nameKey)
		{
			p = p->pNext;
		}
		return p->pValue;
	}
};