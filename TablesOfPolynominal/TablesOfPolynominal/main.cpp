#include <iostream>
#include "TPolynominal.h"
#include "TPostfix.h"
#include "THashTable.h"
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
	arrVarPol = expression.GetArrVar();
	THashTable<TPolynominal>  tableOfPol;
	cout << "Enter the polynominals:\n\n\t";
	for (size_t i = 0; i < expression.GetNumOfVar(); i++)
	{
		cout << arrVarPol[i] << " = ";
		string strPol/* = "x^2"*/;
		cin >> strPol;
		cout << "\n\t";
		TPolynominal pol(strPol, strVar);
		pol.StreamSetVar();
		tableOfPol.AddLine(arrVarPol[i], pol);
	}

	double result = expression.Calculate(tableOfPol);

	cout << "\tresult = " << result << endl;

	system("PAUSE");
}