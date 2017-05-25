#include <iostream>
#include "TPolynominal.h"
#include "TPostfix.h"
#include "THashTable.h"
#include "TLineTable.h"
//#include "TOrderTable.h"
using namespace std;
void main()
{
	string strVar;
	string infixStr;
	string* arrVarPol;
	//double argPol[1] = { 2 };
	cout << "Enter the names of variabels as a priority (through a space):\n\n\t";
	getline(cin, strVar);
	//strVar = "x";
	cout << "\n";

	cout << "Enter the max power:\n\n\t";
	cin >> TPolynominal::Power/* = 10*/;
	cout << "\n";

	cout << "Enter the expression:\n\n\t";
	cin >> infixStr /*= "P+Q"*/;
	cout << "\n";

	TPostfix expression(infixStr);
	expression.ToPostfix();
	arrVarPol = expression.GetNameOfPolynominals();
	THashTable<TPolynominal>  tableOfPol;
	cout << "Enter the polynominals:\n\n\t";
	for (size_t i = 0; i < expression.GetNumOfVar(); i++)
	{
		string ce = "0123456789.";
		int j = 0;
		while (j < arrVarPol[i].length())
		{
			if (ce.find(arrVarPol[i][j]) != std::string::npos)
				j++;
			else
				break;
		}
		if (j == arrVarPol[i].length())
		{
			TPolynominal _p(arrVarPol[i]);
			tableOfPol.AddLine(arrVarPol[i], _p);
		}
		else
		{
			cout << arrVarPol[i] << " = ";
			string strPol/* = "x^2"*/;
			cin >> strPol;
			cout << "\n\t";
			TPolynominal pol(strPol, strVar);
			tableOfPol.AddLine(arrVarPol[i], pol);
		}
	}

	TPolynominal result = expression.CalculatePolynom(tableOfPol);

	cout << "\tresult = " << result.ToString() << endl;

	system("PAUSE");
}