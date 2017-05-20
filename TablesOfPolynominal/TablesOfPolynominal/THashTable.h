#define MaxSizeOfTable 65

template <class T>
struct THashLine
{
	size_t numOfLine;
	std::string nameOfLine;
	T value;

	THashLine* pNextLine;
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
		return ((int)(_nameOfLine[0]) - 65);
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
		THashLine* p = new THashLine;
		*p = line[hashKey];
		for (size_t i = 0; i < line[hashKey].numOfLine; i++)
		{
			if (p->nameOfLine == _nameOfLine)
				return true;
			p = p->pNextLine;
		}
		return false;
	}
	void AddLine(std::string _nameOfLine, T _polinom)
	{
		if (IsFull())
			throw "Is Full";
		size_t hashKey = Hash(_nameOfLine);
		if (line[hashKey].numOfLine == 0)
		{
			line[hashKey].nameOfLine = _nameOfLine;
			line[countOfLine].value = _polinom;
		}
		else
		{
			THashLine<T>* p = new THashLine<T>;
			*p = line[hashKey];
			for (size_t i = 0; i < line[hashKey].numOfLine; i++)
			{
				p = p->pNextLine;
			}
			p->pNextLine->nameOfLine = _nameOfLine;
			p->pNextLine->value = _polinom;
		}
		line[hashKey].numOfLine++;
		countOfLine++;
	}
	void DeleteLine(string _nameOfLine)
	{
		if (IsEmpty())
			throw "Is Empty";
		if (!IsFound(_nameOfLine))
			throw "Is Not Found";
		size_t count = 0;
		size_t hashKey = Hash(_nameOfLine);
		THashLine<T>* p = new THashLine;
		*p = line[hashKey];
		while (p->nameOfLine != _nameOfLine)
		{
			p = p->pNextLine;
			count++;
		}
		THashLine<T>* pl = new THashLine;
		*pl = line[hashKey];
		for (size_t i = 0; i < count - 1; i++)
		{
			pl = pl->pNextLine;
		}
		pl->pNextLine = p->pNextLine;
		delete p;
		line[hashKey].numOfLine--;
		countOfLine--;
	}
	T GetPolinominal(std::string _nameOfLine)
	{
		size_t hashKey = Hash(_nameOfLine);
		THashLine<T>* p = new THashLine;
		*p = line[hashKey];
		for (size_t i = 0; i < line[hashKey].numOfLine; i++)
		{
			if (p->nameOfLine == _nameOfLine)
				return p->value;
			p = p->pNextLine;
		}
		throw "Is Not Found";
	}
};