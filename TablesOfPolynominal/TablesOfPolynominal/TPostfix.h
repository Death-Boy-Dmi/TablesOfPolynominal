#include <string>
#include <iostream>
#include <sstream>

#include "TStack.h"

using namespace std;

#define MaxSizeString 1000

struct TablFunc
{
	char func[7];
	int priority[7];
	int amount;
	TablFunc()
	{
		func[0] = ')';	amount = 2;
		func[1] = '(';	priority[1] = 0;
		func[2] = '+';	priority[2] = 1;
		func[3] = '-';	priority[3] = 1;
		func[4] = '*';	priority[4] = 2;
		func[5] = '/';	priority[5] = 2;
		func[6] = '=';	priority[6] = 0;
	}
};

class TPostfix
{
	string infix;
	string postfix;
	string* variable;
	size_t varSize;
	TablFunc functions;
	double Res;

	bool CheckChars(); // �������� �� ���������� �������
	bool CheckAmount(); // �������� ������������ ���-�� ���������� ���-�� ��������
	bool CheckBrackets(); // �������� ���������� ������
	bool CheckInfix(); // ����� ��������
	void ArrVarible(); // ��������� �� ������ ���������� � ���������� �� � ������

public:
	TPostfix(string inf);
		
	string ToPostfix();
	double Calculate(); // ���� ����������, ���������� �� ����������� �����
	string GetInfix() { return infix; }
	string GetPostfix() { return postfix; }
	string* GetArrVar() { return variable; }
};