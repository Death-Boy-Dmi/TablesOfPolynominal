#include"../gtest/gtest.h"

#include "../TablesOfPolynominal/TablesOfPolynominal/TLineTable.h"
#include "../TablesOfPolynominal/TablesOfPolynominal/TPolynominal.h"

TEST(TLineTable, can_create_table)
{
	ASSERT_NO_THROW(TLineTable<TPolynominal> table);
}
TEST(TLineTable, can_use_IsFull)
{
	TLineTable<TPolynominal> table;
	ASSERT_NO_THROW(table.IsFull());
}
TEST(TLineTable, can_correct_use_IsFull_1)
{
	TLineTable<TPolynominal> table(26);
	TPolynominal _pol("x^2", "x");
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
TEST(TLineTable, can_correct_use_IsFull_2)
{
	TLineTable<TPolynominal> table(26);
	EXPECT_FALSE(table.IsFull());
}
TEST(TLineTable, can_use_IsEmpty)
{
	TLineTable<TPolynominal> table;
	ASSERT_NO_THROW(table.IsEmpty());
}
TEST(TLineTable, can_use_SearchOfLineByName)
{
	TLineTable<TPolynominal> table;
	ASSERT_NO_THROW(table.SearchOfLineByName("P"));
}
TEST(TLineTable, can_correct_use_IsEmpty_1)
{
	TLineTable<TPolynominal> table;
	EXPECT_TRUE(table.IsEmpty());
}
TEST(TLineTable, can_correct_use_IsEmpty_2)
{
	TLineTable<TPolynominal> table(1);
	TPolynominal _pol;
	table.AddLine("A", _pol);
	EXPECT_FALSE(table.IsEmpty());
}
TEST(TLineTable, can_correct_use_SearchOfLineByName_1)
{
	TLineTable<TPolynominal> table(2);
	TPolynominal _pol;
	table.AddLine("A", _pol);
	table.AddLine("A1", _pol);
	EXPECT_EQ(table.SearchOfLineByName("A"), 0);
}
TEST(TLineTable, can_correct_use_IsFound_2)
{
	TLineTable<TPolynominal> table(2);	
	TPolynominal _pol;
	table.AddLine("A", _pol);
	table.AddLine("A1", _pol);
	EXPECT_EQ(table.SearchOfLineByName("A1"), 1);
}
TEST(TLineTable, can_correct_use_IsFound_3)
{
	TLineTable<TPolynominal> table(2);
	TPolynominal _pol;
	table.AddLine("A", _pol);
	table.AddLine("A1", _pol);
	EXPECT_EQ(table.SearchOfLineByName("B"), -1);
}
TEST(TLineTable, can_use_AddLine)
{
	TLineTable<TPolynominal> table(1);
	TPolynominal _pol;
	ASSERT_NO_THROW(table.AddLine("P", _pol));
}
TEST(TLineTable, can_not_use_AddLine_when_IsFull)
{
	TLineTable<TPolynominal> table(26);
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
TEST(TLineTable, can_use_DeleteLine)
{
	TLineTable<TPolynominal> table(1);
	TPolynominal _pol;
	table.AddLine("P", _pol);
	ASSERT_NO_THROW(table.DeleteLine("P"));
}
TEST(TLineTable, can_not_use_DeleteLine_when_IsEmpty)
{
	TLineTable<TPolynominal> table;
	ASSERT_ANY_THROW(table.DeleteLine("P"));
}
TEST(TLineTable, can_use_Get)
{
	TLineTable<TPolynominal> table(1);
	TPolynominal _pol;
	table.AddLine("P", _pol);
	ASSERT_NO_THROW(table.GetValue("P"));
}
TEST(TLineTable, can_correct_use_Get)
{
	TLineTable<int> table(1);
	int _pol = 10;
	table.AddLine("P", _pol);
	EXPECT_EQ(table.GetValue("P"), _pol);
}
TEST(TLineTable, can_correct_use__Get)
{
	TLineTable<int> table(2);
	int _pol = 10;
	int __pol = 12;
	table.AddLine("P", _pol);
	table.AddLine("P1", __pol);
	EXPECT_EQ(table.GetValue("P1"), __pol);
}
TEST(TLineTable, can_not_use_Get_when_IsEmpty)
{
	TLineTable<TPolynominal> table;
	ASSERT_ANY_THROW(table.GetValue("P"));
}
TEST(TLineTable, can_correct_use_Add_and_Delete_Line)
{
	TLineTable<TPolynominal> table(2);
	TPolynominal _pol;
	table.AddLine("A", _pol);
	table.DeleteLine("A");
	EXPECT_TRUE(table.IsEmpty());
}