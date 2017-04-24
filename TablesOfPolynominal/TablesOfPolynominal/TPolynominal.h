#pragma once

#include <iostream>
#include <string>

using namespace std;

struct TMonom
{
	double coef;
	int degree;
};
struct TLink
{
	TMonom monom;
	TLink *pNext;
	TLink()
	{
		monom.coef = 0;
		monom.degree = -1;
	}
};
class TPolynominal
{
	TLink *pHead;
	void CreateHead()
	{
		pHead = new TLink;
		pHead->monom.coef = 0;
		pHead->monom.degree = -1;
	}
	

public:
	static double* arrArg;
	static unsigned int Power;
	static unsigned int numVar;		// количество переменных
	static string* arrVar;		// массив объявленных переменных

	TPolynominal(string strPol, string strVar);
	TPolynominal();
	
	double* GetArrArg() { return arrArg; }
	void ToArrVar(string strVar);		// перевод в массив объявленных переменных
	void StreamSetVar();
	void SetVar(double* arr);

	TPolynominal operator + (const TPolynominal &polynom);
	TPolynominal operator * (double const c);
	string ToString(); 
	double Calculate();
};