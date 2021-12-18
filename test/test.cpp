#include <gtest.h>
#include <iostream>
#include <string>
#include <lib/Lexer.hpp>
#include <lib/Parser.hpp>

TEST(testing_lexer, test_get_token)
{
	std::string str = "CREATE TABLE";
	sql::Lexer lexer(str);
	sql::Token token = lexer.GetToken();
	token = lexer.GetToken();
	token = lexer.GetToken();
	std::string result(token.Lexem);
	if (token.Type == sql::TokenType::ID)
	{	
		ASSERT_STRCASEEQ("TABLE", result.c_str());
	}
	else
	{
		FAIL();
	}
}

TEST(testing_lexer, test_peek_token)
{
	std::string str = "DELETE TABLE";
	sql::Lexer lexer(str);
	sql::Token token = lexer.PeekToken();
	token = lexer.GetToken();
	std::string result(token.Lexem);
	if (token.Type == sql::TokenType::Keyword)
	{
		ASSERT_STRCASEEQ("DELETE", result.c_str()) << "Строки не равны";
	}
	else
	{
		FAIL();
	}
}

TEST(testing_lexer, test_get_token_type)
{
	std::string str = "DELETE TABLE";
	sql::Lexer lexer(str);
	sql::Token token = lexer.GetToken();
	std::string result = lexer.GetTokenTypeName(token.Type);
	ASSERT_STRCASEEQ("keyword", result.c_str()) << "Строки не равны";
}
//end write test lexer
TEST(testing_parser_create_statement, test_create_statement_1)
{
	std::string sql_inquiry = "CREATE TABLE gamer ( name TEXT, age INT , coin REAL );";
    sql::Lexer lexer(sql_inquiry);
    SqlScript SqlScript = Parse(sql_inquiry);
	std::string result = SqlScript.Statements[0]->Get_TableName();
	ASSERT_STRCASEEQ("gamer", result.c_str()) << "Строки не равны";
}

TEST(testing_parser_create_statement, test_create_statement_2)
{
	std::string sql_inquiry = "CREATE TABLE gamer ( name TEXT, age INT , coin REAL );DROP TABLE users";
    SqlScript SqlScript = Parse(sql_inquiry);
	std::string result = SqlScript.Statements[1]->Get_TableName();
	ASSERT_STRCASEEQ("users", result.c_str()) << "Строки не равны";
}
// //end write test lexer
TEST(testing_parser_select_statement, test_select_statement_1)
{
	std::string sql_inquiry = "SELECT TABLE gamer ( name TEXT name , age INT name );DROP TABLE users";
    SqlScript SqlScript = Parse(sql_inquiry);
	std::string result = SqlScript.Statements[0]->Get_TableName();
	ASSERT_STRCASEEQ("gamer", result.c_str()) << "Строки не равны";
}

TEST(testing_parser_select_statement, test_select_statement_2)
{
	std::string sql_inquiry = "SELECT TABLE gamer ( name TEXT name , age INT name );DROP TABLE users";
    SqlScript SqlScript = Parse(sql_inquiry);
	std::string result = SqlScript.Statements[1]->Get_TableName();
	ASSERT_STRCASEEQ("users", result.c_str()) << "Строки не равны";
}
// //end write test lexer
TEST(testing_parser_delete_statement, test_delete_statement_1)
{
	std::string sql_inquiry = "DELETE TABLE gamer3 ( name TEXT name , age INT name );";
    SqlScript SqlScript = Parse(sql_inquiry);
	std::string result = SqlScript.Statements[0]->Get_TableName();
	ASSERT_STRCASEEQ("gamer3", result.c_str()) << "Строки не равны";
}

TEST(testing_parser_delete_statement, test_delete_statement_2)
{
	std::string sql_inquiry = "DELETE TABLE gamer3 ( name TEXT name , age INT name );DROP TABLE users";
    SqlScript SqlScript = Parse(sql_inquiry);
	std::string result = SqlScript.Statements[1]->Get_TableName();
	ASSERT_STRCASEEQ("users", result.c_str()) << "Строки не равны";
}
// //end write test lexer
TEST(testing_parser_insert_statement, test_insert_statement_1)
{
	std::string sql_inquiry = "INSERT TABLE gamer ( name TEXT, age INT );DROP TABLE users";
    SqlScript SqlScript = Parse(sql_inquiry);
	std::string result = SqlScript.Statements[0]->Get_TableName();
	ASSERT_STRCASEEQ("gamer", result.c_str()) << "Строки не равны";
}

TEST(testing_parser_insert_statement, test_insert_statement_2)
{
	std::string sql_inquiry = "INSERT TABLE gamer ( name TEXT, age INT );DROP TABLE users";
    SqlScript SqlScript = Parse(sql_inquiry);
	std::string result = SqlScript.Statements[1]->Get_TableName();
	ASSERT_STRCASEEQ("users", result.c_str()) << "Строки не равны";
}
//end write test lexer
TEST(testing_parser_drop_statement, test_drop_statement_1)
{
	std::string sql_inquiry = "DROP TABLE users;INSERT TABLE gamer ( name TEXT, age INT );";
    SqlScript SqlScript = Parse(sql_inquiry);
	std::string result = SqlScript.Statements[0]->Get_TableName();
	ASSERT_STRCASEEQ("users", result.c_str()) << "Строки не равны";
}

TEST(testing_parser_drop_statement, test_drop_statement_2)
{
	std::string sql_inquiry = "DROP TABLE users;INSERT TABLE gamer ( name TEXT, age INT );";
    SqlScript SqlScript = Parse(sql_inquiry);
	std::string result = SqlScript.Statements[1]->Get_TableName();
	ASSERT_STRCASEEQ("gamer", result.c_str()) << "Строки не равны";
}