#include "TPostfix.h"

TPostfix::TPostfix(string inf)
{
	DeleteSpaces(inf);
	infix = inf;
	CheckInfix();
	ArrVarible();
}

bool TPostfix::CheckChars() // �������� �� ���������� �������
{
	string valval = "()*/-+abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.";
	for (size_t i = 0; i < infix.length(); i++)
	{
		if (valval.find(infix[i]) == std::string::npos)
		{
			throw "An invalid character was found";
		}
	}
	return true;
}

bool TPostfix::CheckAmount() // �������� ������������ ���-�� ���������� ���-�� ��������
{
	string str = " " + infix + " ";
	string arop = "-*/+";
	string var = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	for (size_t i = 0; i < str.length(); i++)
		if (arop.find(str[i]) >= 0 && arop.find(str[i]) <= str.length())
		{
			if ((var.find(str[i - 1]) >= 0 && var.find(str[i - 1]) <= var.length())
				&& (var.find(str[i + 1]) >= 0 && var.find(str[i - 1]) <= var.length())
				|| (str[i + 1] == '(' && str[i - 1] == ')'))
				continue;
			else
				throw "the number of variables does not correspond to the numbers of operations";
		}
	return true;
}

bool TPostfix::CheckBrackets() // �������� ���������� ������
{
	string temp = infix;
	if (temp.find('(') == std::string::npos && temp.find(')') == std::string::npos)
		return true;
	if (temp.find("()") >= 0 && temp.find("()") <= temp.length())
	{
		throw "Detected is ''()''";
	}
	while (temp.find('(') != std::string::npos || temp.find(')') != std::string::npos)
	{
		if (temp.find('(') >= 0 && temp.find('(') <= temp.length())
			if (temp.find(')') == std::string::npos)
			{
				throw "Incorrect number of brackets";
			}
			else
			{
				temp[temp.find('(')] = ' ';
				temp[temp.find(')')] = ' ';
			}
		else throw "Incorrect number of brackets";
	}
	return true;
}

bool TPostfix::CheckInfix() // ����� ��������
{
	CheckChars();
	CheckAmount();
	CheckBrackets();
	if (infix[0] == ')' || infix[0] == '*' || infix[0] == '/' || infix[0] == '-' || infix[0] == '+')
		throw "First character is operations";
	if (infix[infix.length() - 1] == '(' || infix[infix.length() - 1] == '*' || infix[infix.length() - 1] == '/' || infix[infix.length() - 1] == '-' || infix[infix.length() - 1] == '+')
		throw "Last character is operations";
	return true;
}

void TPostfix::ArrVarible() // ��������� �� ������ ���������� � ���������� �� � ������
{
	string inf = infix;
	size_t size = 0;
	CheckInfix();
	inf = inf + "=";
	for (int i = 0; i < inf.size(); i++)
		if (inf[i] == '+' || inf[i] == '-' || inf[i] == '*' || inf[i] == '/' || inf[i] == '=')
			size++;
	variable = new string[size];
	for (int i = 0; i < size; i++)
		variable[i] = "";
	varSize = size;
	int k = 0;
	for (int i = 0; i < inf.length(); i++)
	{
		if (inf[i] == '+' || inf[i] == '-' || inf[i] == '*' || inf[i] == '/' || inf[i] == '=')
			inf[i] = ' ';
	}
	while (inf.find('(') != std::string::npos || inf.find(')') != std::string::npos)
	{
		if (inf.find(')') >= 0 && inf.find(')') <= inf.length())
			inf.erase(inf.find(')'), 1);
		if (inf.find('(') >= 0 && inf.find('(') <= inf.length())
			inf.erase(inf.find('('), 1);
	}
	while (inf.length() != 0)
	{
		if (inf.find(' ') >= 0 && inf.find(' ') <= inf.length())
		{
			size_t pos = inf.find(' ');
			for (int j = 0; j < pos; j++)
			{
				variable[k] += inf[j];
			}
			inf.erase(0, pos + 1);
			k++;
		}
	}
}

void TPostfix::DeleteSpaces(string _str)
{
	for (size_t i = 0; i < _str.length(); i++)
	{
		if (_str[i] == ' ')
			_str.erase(i);
	}
}

string TPostfix::ToPostfix()
{
	string inf = infix;
	postfix = "";
	inf = inf + "=";
	TStack<char> operations(MaxSizeString);
	int i = 0;
	while (inf.length() != 0)
	{
		while (i < varSize)
		{
			if (inf.find(variable[i]) == 0)
			{
				postfix += variable[i] + ' ';
				inf.erase(0, variable[i].length());
				i++;
				break;
			}
			else
				break;
			i++;
		}

		if (inf[0] == '(')
		{
			operations.Put('(');
			inf.erase(0, 1);
		}

		if (inf[0] == functions.func[2] || inf[0] == functions.func[3] || inf[0] == functions.func[4] || inf[0] == functions.func[5])
		{
			while (true)
			{
				if (operations.IsEmpty())
				{
					operations.Put(inf[0]);
					break;
				}
				int i = 2;
				int j = 2;
				while (i < 6)
				{
					if (inf[0] == functions.func[i])
						break;
					else
						i++;
				}
				while (j < 6)
				{
					if (operations.GetValTop() == functions.func[j])
						break;
					else
						j++;
				}
				if (functions.priority[i] <= functions.priority[j])
				{
					postfix += operations.Get();
				}
				else
				{
					operations.Put(inf[0]);
					break;
				}

			}
			inf.erase(0, 1);
		}

		if (inf[0] == ')')
		{
			while (operations.GetValTop() != '(')
				postfix += operations.Get();
			operations.Get();
			inf.erase(0, 1);
		}

		if (inf[0] == '=')
		{
			while (operations.IsEmpty() != true)
				postfix += operations.Get();
			inf.erase(0, 1);
		}
	}
	return postfix;
}

double TPostfix::Calculate() // ���� ����������, ���������� �� ����������� �����
{
	cout << "Enter the arguments:" << endl;
	double* var = new double[varSize];
	for (int i = 0; i < varSize; i++)
	{

		string ce = "0123456789.";
		int j = 0;
		while (j < variable[i].length())
		{
			if (ce.find(variable[i][j]) != std::string::npos)
				j++;
			else
				break;
		}
		if (j == variable[i].length())
		{
			std::stringstream temp(variable[i]);
			temp >> var[i];
		}
		else
		{
			size_t k = 0;
			while (k < i && i != 0)
				if (variable[i] == variable[k])
				{
					var[i] = var[k];
					break;
				}
				else
					k++;
			if (k == i || i == 0)
			{
				cout << variable[i] << " = ";
				cin >> var[i];
				string c = "0123456789.";
				if (c.find(var[i]) != std::string::npos)
					throw "Permission incorrect value";
				cout << endl;
			}
			else
				continue;
		}
	}
	string post = postfix;
	for (int i = 0; i < post.size(); i++)
		if (post[i] == ' ')
			post.erase(i, 1);
	double tempResult = 0;
	double result = 0;
	TStack<double> varStack(varSize);
	int i = 0;
	while (post.length() != 0)
	{
		while (i < varSize)
		{
			if (post.find(variable[i]) == 0)
			{
				varStack.Put(var[i]);
				post.erase(0, variable[i].length());
				i++;
				break;
			}
			else
				break;
		}

		if (post[0] == '*')
		{
			double temp = varStack.Get();
			tempResult = varStack.Get() * temp;
			varStack.Put(tempResult);
			post.erase(0, 1);
		}

		if (post[0] == '/')
		{
			double temp = varStack.Get();
			tempResult = varStack.Get() / temp;
			varStack.Put(tempResult);
			post.erase(0, 1);
		}

		if (post[0] == '+')
		{
			double temp = varStack.Get();
			tempResult = varStack.Get() + temp;
			varStack.Put(tempResult);
			post.erase(0, 1);
		}

		if (post[0] == '-')
		{
			double temp = varStack.Get();
			tempResult = varStack.Get() - temp;
			varStack.Put(tempResult);
			post.erase(0, 1);
		}
	}
	result = varStack.Get();
	return Res = result;
}
TPolynominal TPostfix::CalculatePolynom(THashTable<TPolynominal> TableOfPolynom) // ���� ����������, ���������� �� ����������� �����
{
	THashTable<TPolynominal> var = TableOfPolynom;
	for (int i = 0; i < varSize; i++)
	{

		string ce = "0123456789.";
		int j = 0;
		while (j < variable[i].length())
		{
			if (ce.find(variable[i][j]) != std::string::npos)
				j++;
			else
				break;
		}
		if (j == variable[i].length())
		{
			TPolynominal _p(variable[i]);
			var.GetPolinominal(variable[i]) = _p;
		}
		else
		{
			size_t k = 0;
			while (k < i && i != 0)
				if (variable[i] == variable[k])
				{
					var.GetPolinominal(variable[i]) = var.GetPolinominal(variable[k]);
					break;
				}
				else
					k++;
			if (k == i || i == 0)
			{
				TPolynominal _p(variable[i]);
				var.GetPolinominal(variable[i]) = _p;
			}
			else
				continue;
		}
	}
	string post = postfix;
	for (int i = 0; i < post.size(); i++)
		if (post[i] == ' ')
			post.erase(i, 1);
	TPolynominal tempResult;
	TPolynominal result;
	TStack<TPolynominal> varStack(varSize);
	int i = 0;
	while (post.length() != 0)
	{
		while (i < varSize)
		{
			if (post.find(variable[i]) == 0)
			{
				varStack.Put(var.GetPolinominal(variable[i]));
				post.erase(0, variable[i].length());
				i++;
				break;
			}
			else
				break;
		}

		if (post[0] == '*')
		{
			double * arr = new double[TPolynominal::numVar];
			for (size_t i = 0; i < TPolynominal::numVar; i++)
			{
				arr[i] = 1;
			}
			tempResult = varStack.Get();
			tempResult.SetVar(arr);
			double temp = varStack.Get().Calculate();
			tempResult = tempResult * temp;
			varStack.Put(tempResult);
			post.erase(0, 1);
		}

		if (post[0] == '+')
		{
			TPolynominal temp = varStack.Get();
			tempResult = varStack.Get() + temp;
			varStack.Put(tempResult);
			post.erase(0, 1);
		}

		if (post[0] == '-')
		{
			TPolynominal temp = varStack.Get();
			tempResult = varStack.Get() + temp*(-1);
			varStack.Put(tempResult);
			post.erase(0, 1);
		}
	}
	result = varStack.Get();
	return result;
}

double TPostfix::Calculate(THashTable<TPolynominal> TableOfPolynom)
{
	double* var = new double[varSize];
	for (int i = 0; i < varSize; i++)
	{

		string ce = "0123456789.";
		int j = 0;
		while (j < variable[i].length())
		{
			if (ce.find(variable[i][j]) != std::string::npos)
				j++;
			else
				break;
		}
		if (j == variable[i].length())
		{
			std::stringstream temp(variable[i]);
			temp >> var[i];
		}
		else
		{
			size_t k = 0;
			while (k < i && i != 0)
				if (variable[i] == variable[k])
				{
					var[i] = var[k];
					break;
				}
				else
					k++;
			if (k == i || i == 0)
			{
				//cout << variable[i] << " = ";
				//cin >> var[i];
				var[i] = TableOfPolynom.GetPolinominal(variable[i]).Calculate();
				string c = "0123456789.";
				if (c.find(var[i]) != std::string::npos)
					throw "Permission incorrect value";
				cout << endl;
			}
			else
				continue;
		}
	}
	string post = postfix;
	for (int i = 0; i < post.size(); i++)
		if (post[i] == ' ')
			post.erase(i, 1);
	double tempResult = 0;
	double result = 0;
	TStack<double> varStack(varSize);
	int i = 0;
	while (post.length() != 0)
	{
		while (i < varSize)
		{
			if (post.find(variable[i]) == 0)
			{
				varStack.Put(var[i]);
				post.erase(0, variable[i].length());
				i++;
				break;
			}
			else
				break;
		}

		if (post[0] == '*')
		{
			double temp = varStack.Get();
			tempResult = varStack.Get() * temp;
			varStack.Put(tempResult);
			post.erase(0, 1);
		}

		if (post[0] == '/')
		{
			double temp = varStack.Get();
			tempResult = varStack.Get() / temp;
			varStack.Put(tempResult);
			post.erase(0, 1);
		}

		if (post[0] == '+')
		{
			double temp = varStack.Get();
			tempResult = varStack.Get() + temp;
			varStack.Put(tempResult);
			post.erase(0, 1);
		}

		if (post[0] == '-')
		{
			double temp = varStack.Get();
			tempResult = varStack.Get() - temp;
			varStack.Put(tempResult);
			post.erase(0, 1);
		}
	}
	result = varStack.Get();
	return Res = result;
}

string * TPostfix::GetNameOfPolynominals()
{
	string* arrPol;
	size_t arrSize = GetNumOfVar();
	arrPol = new string[arrSize];
	size_t iter = 0;
	for (size_t i = 0; i < varSize; i++)
	{
		arrPol[iter] = variable[i];
		iter++;
	}
	return arrPol;
}

size_t TPostfix::GetNumOfPolynominals()
{
	size_t arrSize = 0;
	string ce = "0123456789.";
	for (size_t i = 0; i < varSize; i++)
	{
		int j = 0;
		while (j < variable[i].length())
		{
			if (ce.find(variable[i][j]) != std::string::npos)
				j++;
			else
				break;
		}
		if (j != variable[i].length())
			arrSize++;
	}
	return arrSize;
}
