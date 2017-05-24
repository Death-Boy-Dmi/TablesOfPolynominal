#include <conio.h>

#include"../gtest/gtest.h"

#include "../TablesOfPolynominal/TablesOfPolynominal/THashTable.h"
#include "../TablesOfPolynominal/TablesOfPolynominal/TPolynominal.h"

TEST(THashTable, can_create_table)
{
	ASSERT_NO_THROW(THashTable<TPolynominal> table);
}
TEST(THashTable, can_use_IsFull)
{
	THashTable<TPolynominal> table;
	ASSERT_NO_THROW(table.IsFull());
}
TEST(THashTable, can_correct_use_IsFull_1)
{
	THashTable<TPolynominal> table;
	TPolynominal _pol("x^2","x");
	for (size_t i = 65; i < 91; i++)
	{
		char* _ch = new char[2];
		_ch[0] = (char)(i);
		_ch[1] = '\0';
		std::string sstr(_ch);
		table.AddLine(sstr, _pol);
	}
	EXPECT_TRUE(table.IsFull());
}
TEST(THashTable, can_correct_use_IsFull_2)
{
	THashTable<TPolynominal> table;
	EXPECT_FALSE(table.IsFull());
}
TEST(THashTable, can_use_IsEmpty)
{
	THashTable<TPolynominal> table;
	ASSERT_NO_THROW(table.IsEmpty());
}
TEST(THashTable, can_use_IsFound)
{
	THashTable<TPolynominal> table;
	ASSERT_NO_THROW(table.IsFound("P"));
}
TEST(THashTable, can_correct_use_IsEmpty_1)
{
	THashTable<TPolynominal> table;
	EXPECT_TRUE(table.IsEmpty());
}
TEST(THashTable, can_correct_use_IsEmpty_2)
{
	THashTable<TPolynominal> table;
	TPolynominal _pol;
	table.AddLine("A",_pol);
	EXPECT_FALSE(table.IsEmpty());
}
TEST(THashTable, can_correct_use_IsFound_1)
{
	THashTable<TPolynominal> table;
	TPolynominal _pol;
	table.AddLine("A", _pol);
	table.AddLine("A1", _pol);
	EXPECT_TRUE(table.IsFound("A"));
}
TEST(THashTable, can_correct_use_IsFound_2)
{
	THashTable<TPolynominal> table;
	TPolynominal _pol;
	table.AddLine("A", _pol);
	table.AddLine("A1", _pol);
	EXPECT_TRUE(table.IsFound("A1"));
}
TEST(THashTable, can_correct_use_IsFound_3)
{
	THashTable<TPolynominal> table;
	TPolynominal _pol;
	table.AddLine("A", _pol);
	table.AddLine("A1", _pol);
	EXPECT_FALSE(table.IsFound("B"));
}
TEST(THashTable, can_use_AddLine)
{
	THashTable<TPolynominal> table;
	TPolynominal _pol;
	ASSERT_NO_THROW(table.AddLine("P", _pol));
}
TEST(THashTable, can_not_use_AddLine_when_IsFull)
{
	THashTable<TPolynominal> table;
	TPolynominal _pol;
	for (size_t i = 65; i < 91; i++)
	{
		char* _ch = new char[2];
		_ch[0] = (char)(i);
		_ch[1] = '\0';
		std::string sstr(_ch);
		table.AddLine(sstr, _pol);
	}
	ASSERT_ANY_THROW(table.AddLine("P", _pol));
}
TEST(THashTable, can_use_DeleteLine)
{
	THashTable<TPolynominal> table;
	TPolynominal _pol;
	table.AddLine("P", _pol);
	ASSERT_NO_THROW(table.DeleteLine("P"));
}
TEST(THashTable, can_not_use_DeleteLine_when_IsEmpty)
{
	THashTable<TPolynominal> table;
	ASSERT_ANY_THROW(table.DeleteLine("P"));
}
TEST(THashTable, can_use_Get)
{
	THashTable<TPolynominal> table;
	TPolynominal _pol;
	table.AddLine("P", _pol);
	ASSERT_NO_THROW(table.GetPolinominal("P"));
}
TEST(THashTable, can_correct_use_Get)
{
	THashTable<int> table;
	int _pol = 10;
	table.AddLine("P", _pol);
	EXPECT_EQ(table.GetPolinominal("P"),_pol);
}
TEST(THashTable, can_correct_use__Get)
{
	THashTable<int> table;
	int _pol = 10;
	int __pol = 12;
	table.AddLine("P", _pol);
	table.AddLine("P1", __pol);
	EXPECT_EQ(table.GetPolinominal("P1"), __pol);
}
TEST(THashTable, can_not_use_Get_when_IsEmpty)
{
	THashTable<TPolynominal> table;
	ASSERT_ANY_THROW(table.GetPolinominal("P"));
}
TEST(THashTable, can_correct_use_Add_and_Delete_Line)
{
	THashTable<TPolynominal> table;
	TPolynominal _pol;
	table.AddLine("A", _pol);
	table.DeleteLine("A");
	EXPECT_TRUE(table.IsEmpty());
}