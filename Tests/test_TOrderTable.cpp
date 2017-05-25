#include"../gtest/gtest.h"


#include "../TablesOfPolynominal/TablesOfPolynominal/TOrderTable.h"
#include "../TablesOfPolynominal/TablesOfPolynominal/TPolynominal.h"

TEST(TOrderTable, can_create_table)
{
	ASSERT_NO_THROW(TOrderTable<int> table);
}
TEST(TOrderTable, can_use_IsFull)
{
	TOrderTable<int> table;
	ASSERT_NO_THROW(table.IsFull());
}
TEST(TOrderTable, can_correct_use_IsFull_1)
{
	TOrderTable<int> table(26);
	int _pol = 0;
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
TEST(TOrderTable, can_correct_use_IsFull_2)
{
	TOrderTable<int> table(26);
	EXPECT_FALSE(table.IsFull());
}
TEST(TOrderTable, can_use_IsEmpty)
{
	TOrderTable<int> table;
	ASSERT_NO_THROW(table.IsEmpty());
}
TEST(TOrderTable, can_use_SearchOfLineByName)
{
	TOrderTable<int> table;
	ASSERT_NO_THROW(table.SearchOfLineByName("P"));
}
TEST(TOrderTable, can_correct_use_IsEmpty_1)
{
	TOrderTable<int> table;
	EXPECT_TRUE(table.IsEmpty());
}
TEST(TOrderTable, can_correct_use_IsEmpty_2)
{
	TOrderTable<int> table(1);
	int _pol = 0;
	table.AddLine("A", _pol);
	EXPECT_FALSE(table.IsEmpty());
}
TEST(TOrderTable, can_correct_use_SearchOfLineByName_1)
{
	TOrderTable<int> table(2);
	int _pol = 0;
	table.AddLine("A", _pol);
	table.AddLine("A1", _pol);
	EXPECT_EQ(table.SearchOfLineByName("A"), 0);
}
TEST(TOrderTable, can_correct_use_IsFound_2)
{
	TOrderTable<int> table(2);
	int _pol = 0;
	table.AddLine("A", _pol);
	table.AddLine("A1", _pol);
	EXPECT_EQ(table.SearchOfLineByName("A1"), 1);
}
TEST(TOrderTable, can_correct_use_IsFound_3)
{
	TOrderTable<int> table(2);
	int _pol = 0;
	table.AddLine("A", _pol);
	table.AddLine("A1", _pol);
	EXPECT_EQ(table.SearchOfLineByName("B"), -1);
}
TEST(TOrderTable, can_use_AddLine)
{
	TOrderTable<int> table(1);
	int _pol = 0;
	ASSERT_NO_THROW(table.AddLine("P", _pol));
}
TEST(TOrderTable, can_not_use_AddLine_when_IsFull)
{
	TOrderTable<int> table(26);
	int _pol = 0;
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
TEST(TOrderTable, can_use_DeleteLine)
{
	TOrderTable<int> table(2);
	int _pol = 0;
	table.AddLine("P", _pol);
	ASSERT_NO_THROW(table.DeleteLine("P"));
}
TEST(TOrderTable, can_not_use_DeleteLine_when_IsEmpty)
{
	TOrderTable<int> table;
	ASSERT_ANY_THROW(table.DeleteLine("P"));
}
TEST(TOrderTable, can_use_Get)
{
	TOrderTable<int> table(1);
	int _pol = 0;
	table.AddLine("P", _pol);
	ASSERT_NO_THROW(table.GetValue("P"));
}
TEST(TOrderTable, can_correct_use_Get)
{
	TOrderTable<int> table(1);
	int _pol = 10;
	table.AddLine("P", _pol);
	EXPECT_EQ(table.GetValue("P"), _pol);
}
TEST(TOrderTable, can_correct_use__Get)
{
	TOrderTable<int> table(2);
	int _pol = 10;
	int __pol = 12;
	table.AddLine("P", _pol);
	table.AddLine("P1", __pol);
	EXPECT_EQ(table.GetValue("P1"), __pol);
}
TEST(TOrderTable, can_not_use_Get_when_IsEmpty)
{
	TOrderTable<int> table;
	ASSERT_ANY_THROW(table.GetValue("P"));
}
TEST(TOrderTable, can_correct_use_Add_and_Delete_Line)
{
	TOrderTable<int> table(2);
	int _pol = 0;
	table.AddLine("A", _pol);
	table.DeleteLine("A");
	EXPECT_TRUE(table.IsEmpty());
}