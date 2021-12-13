#include <gtest.h>
#include <iostream>
#include <string>
#include <Lexer.hpp>
#include <Parser.hpp>

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
    // result = ParseCreateTableStatement(lexer, result);
    SqlScript SqlScript = run_parse(sql_inquiry);
	std::string result = SqlScript.Statements[0]->get_TableName();
	ASSERT_STRCASEEQ("gamer", result.c_str()) << "Строки не равны";
}

TEST(testing_parser_create_statement, test_create_statement_2)
{
	std::string sql_inquiry = "CREATE TABLE gamer ( name TEXT, age INT , coin REAL );DROP TABLE users";
    SqlScript SqlScript = run_parse(sql_inquiry);
	std::string result = SqlScript.Statements[1]->get_TableName();
	ASSERT_STRCASEEQ("users", result.c_str()) << "Строки не равны";
}

// TEST(testing_parser_create_statement, test_create_statement_3)
// {
// 	std::string sql_inquiry = "CREATE TABLE gamer ( name TEXT, age INT , coin REAL );DROP TABLE users";
//     SqlScript SqlScript = run_parse(sql_inquiry);
// 	std::vector<sql::ColumnDef> column = SqlScript.Statements[0]->get_colums();
// 	std::string result = column[0].ColumnName;
// 	ASSERT_STRCASEEQ("name", result.c_str()) << "Строки не равны";
// }

// TEST(testing_parser_create_statement, test_create_statement_4)
// {
// 	std::string sql_inquiry = "CREATE TABLE gamer ( name TEXT, age INT , coin REAL );DROP TABLE users";
//     SqlScript SqlScript = run_parse(sql_inquiry);
// 	std::vector<sql::ColumnDef> column = SqlScript.Statements[0]->get_colums();
// 	std::string result = column[0].TypeName;
// 	ASSERT_STRCASEEQ("TEXT", result.c_str()) << "Строки не равны";
// }

// TEST(testing_parser_create_statement, test_create_statement_5)
// {
// 	std::string sql_inquiry = "CREATE TABLE gamer ( name TEXT, age INT , coin REAL );DROP TABLE users";
//     SqlScript SqlScript = run_parse(sql_inquiry);
// 	std::vector<sql::ColumnDef> column = SqlScript.Statements[0]->get_colums();
// 	std::string result = column[1].ColumnName;
// 	ASSERT_STRCASEEQ("age", result.c_str()) << "Строки не равны";
// }

// TEST(testing_parser_create_statement, test_create_statement_6)
// {
// 	std::string sql_inquiry = "CREATE TABLE gamer ( name TEXT, age INT , coin REAL );DROP TABLE users";
//     SqlScript SqlScript = run_parse(sql_inquiry);
// 	std::vector<sql::ColumnDef> column = SqlScript.Statements[0]->get_colums();
// 	std::string result = column[1].TypeName;
// 	ASSERT_STRCASEEQ("INT", result.c_str()) << "Строки не равны";
// }
// //end write test lexer
TEST(testing_parser_select_statement, test_select_statement_1)
{
	std::string sql_inquiry = "SELECT TABLE gamer ( name TEXT name , age INT name );DROP TABLE users";
    SqlScript SqlScript = run_parse(sql_inquiry);
	std::string result = SqlScript.Statements[0]->get_TableName();
	ASSERT_STRCASEEQ("gamer", result.c_str()) << "Строки не равны";
}

TEST(testing_parser_select_statement, test_select_statement_2)
{
	std::string sql_inquiry = "SELECT TABLE gamer ( name TEXT name , age INT name );DROP TABLE users";
    SqlScript SqlScript = run_parse(sql_inquiry);
	std::string result = SqlScript.Statements[1]->get_TableName();
	ASSERT_STRCASEEQ("users", result.c_str()) << "Строки не равны";
}

// TEST(testing_parser_select_statement, test_select_statement_3)
// {
// 	std::string sql_inquiry = "SELECT TABLE gamer2 ( name TEXT, age INT );DROP TABLE users";
//     SqlScript SqlScript = run_parse(sql_inquiry);
// 	std::vector<sql::ColumnDef> column = SqlScript.Statements[0]->get_colums();
// 	std::string result = column[0].ColumnName;
// 	ASSERT_STRCASEEQ("name", result.c_str()) << "Строки не равны";
// }

// TEST(testing_parser_select_statement, test_select_statement_4)
// {
// 	std::string sql_inquiry = "SELECT TABLE gamer2 ( name TEXT, age INT );DROP TABLE users";
//     SqlScript SqlScript = run_parse(sql_inquiry);
// 	std::vector<sql::ColumnDef> column = SqlScript.Statements[0]->get_colums();
// 	std::string result = column[0].TypeName;
// 	ASSERT_STRCASEEQ("TEXT", result.c_str()) << "Строки не равны";
// }

// TEST(testing_parser_select_statement, test_select_statement_5)
// {
// 	std::string sql_inquiry = "SELECT TABLE gamer2 ( name TEXT, age INT );DROP TABLE users";
//     SqlScript SqlScript = run_parse(sql_inquiry);
// 	std::vector<sql::ColumnDef> column = SqlScript.Statements[0]->get_colums();
// 	std::string result = column[1].ColumnName;
// 	ASSERT_STRCASEEQ("age", result.c_str()) << "Строки не равны";
// }

// TEST(testing_parser_select_statement, test_select_statement_6)
// {
// 	std::string sql_inquiry = "SELECT TABLE gamer2 ( name TEXT, age INT );DROP TABLE users";
//     SqlScript SqlScript = run_parse(sql_inquiry);
// 	std::vector<sql::ColumnDef> column = SqlScript.Statements[0]->get_colums();
// 	std::string result = column[1].TypeName;
// 	ASSERT_STRCASEEQ("INT", result.c_str()) << "Строки не равны";
// }
// //end write test lexer
TEST(testing_parser_delete_statement, test_delete_statement_1)
{
	std::string sql_inquiry = "DELETE TABLE gamer3 ( name TEXT name , age INT name );";
    SqlScript SqlScript = run_parse(sql_inquiry);
	std::string result = SqlScript.Statements[0]->get_TableName();
	ASSERT_STRCASEEQ("gamer3", result.c_str()) << "Строки не равны";
}

TEST(testing_parser_delete_statement, test_delete_statement_2)
{
	std::string sql_inquiry = "DELETE TABLE gamer3 ( name TEXT name , age INT name );DROP TABLE users";
    SqlScript SqlScript = run_parse(sql_inquiry);
	std::string result = SqlScript.Statements[1]->get_TableName();
	ASSERT_STRCASEEQ("users", result.c_str()) << "Строки не равны";
}

// TEST(testing_parser_delete_statement, test_delete_statement_3)
// {
// 	std::string sql_inquiry = "DELETE TABLE gamer3 ( name TEXT, age INT );DROP TABLE users";
//     SqlScript SqlScript = run_parse(sql_inquiry);
// 	std::vector<sql::ColumnDef> column = SqlScript.Statements[0]->get_colums();
// 	std::string result = column[0].ColumnName;
// 	ASSERT_STRCASEEQ("name", result.c_str()) << "Строки не равны";
// }

// TEST(testing_parser_delete_statement, test_delete_statement_4)
// {
// 	std::string sql_inquiry = "DELETE TABLE gamer3 ( name TEXT, age INT );DROP TABLE users";
//     SqlScript SqlScript = run_parse(sql_inquiry);
// 	std::vector<sql::ColumnDef> column = SqlScript.Statements[0]->get_colums();
// 	std::string result = column[0].TypeName;
// 	ASSERT_STRCASEEQ("TEXT", result.c_str()) << "Строки не равны";
// }

// TEST(testing_parser_delete_statement, test_delete_statement_5)
// {
// 	std::string sql_inquiry = "DELETE TABLE gamer3 ( name TEXT, age INT );DROP TABLE users";
//     SqlScript SqlScript = run_parse(sql_inquiry);
// 	std::vector<sql::ColumnDef> column = SqlScript.Statements[0]->get_colums();
// 	std::string result = column[1].ColumnName;
// 	ASSERT_STRCASEEQ("age", result.c_str()) << "Строки не равны";
// }

// TEST(testing_parser_delete_statement, test_delete_statement_6)
// {
// 	std::string sql_inquiry = "DELETE TABLE gamer3 ( name TEXT, age INT );DROP TABLE users";
//     SqlScript SqlScript = run_parse(sql_inquiry);
// 	std::vector<sql::ColumnDef> column = SqlScript.Statements[0]->get_colums();
// 	std::string result = column[1].TypeName;
// 	ASSERT_STRCASEEQ("INT", result.c_str()) << "Строки не равны";
// }
// //end write test lexer
TEST(testing_parser_insert_statement, test_insert_statement_1)
{
	std::string sql_inquiry = "INSERT TABLE gamer ( name TEXT, age INT );DROP TABLE users";
    SqlScript SqlScript = run_parse(sql_inquiry);
	std::string result = SqlScript.Statements[0]->get_TableName();
	ASSERT_STRCASEEQ("gamer", result.c_str()) << "Строки не равны";
}

TEST(testing_parser_insert_statement, test_insert_statement_2)
{
	std::string sql_inquiry = "INSERT TABLE gamer ( name TEXT, age INT );DROP TABLE users";
    SqlScript SqlScript = run_parse(sql_inquiry);
	std::string result = SqlScript.Statements[1]->get_TableName();
	ASSERT_STRCASEEQ("users", result.c_str()) << "Строки не равны";
}

// TEST(testing_parser_insert_statement, test_insert_statement_3)
// {
// 	std::string sql_inquiry = "INSERT TABLE gamer ( name TEXT, age INT );DROP TABLE users";
//     SqlScript SqlScript = run_parse(sql_inquiry);
// 	std::vector<sql::ColumnDef> column = SqlScript.Statements[0]->get_colums();
// 	std::string result = column[0].ColumnName;
// 	ASSERT_STRCASEEQ("name", result.c_str()) << "Строки не равны";
// }

// TEST(testing_parser_insert_statement, test_insert_statement_4)
// {
// 	std::string sql_inquiry = "INSERT TABLE gamer ( name TEXT, age INT );DROP TABLE users";
//     SqlScript SqlScript = run_parse(sql_inquiry);
// 	std::vector<sql::ColumnDef> column = SqlScript.Statements[0]->get_colums();
// 	std::string result = column[0].TypeName;
// 	ASSERT_STRCASEEQ("TEXT", result.c_str()) << "Строки не равны";
// }

// TEST(testing_parser_insert_statement, test_insert_statement_5)
// {
// 	std::string sql_inquiry = "INSERT TABLE gamer ( name TEXT, age INT );DROP TABLE users";
//     SqlScript SqlScript = run_parse(sql_inquiry);
// 	std::vector<sql::ColumnDef> column = SqlScript.Statements[0]->get_colums();
// 	std::string result = column[1].ColumnName;
// 	ASSERT_STRCASEEQ("age", result.c_str()) << "Строки не равны";
// }

// TEST(testing_parser_insert_statement, test_insert_statement_6)
// {
// 	std::string sql_inquiry = "INSERT TABLE gamer ( name TEXT, age INT );DROP TABLE users";
//     SqlScript SqlScript = run_parse(sql_inquiry);
// 	std::vector<sql::ColumnDef> column = SqlScript.Statements[0]->get_colums();
// 	std::string result = column[1].TypeName;
// 	ASSERT_STRCASEEQ("INT", result.c_str()) << "Строки не равны";
// }
// //end write test lexer
TEST(testing_parser_drop_statement, test_drop_statement_1)
{
	std::string sql_inquiry = "DROP TABLE users;INSERT TABLE gamer ( name TEXT, age INT );";
    SqlScript SqlScript = run_parse(sql_inquiry);
	std::string result = SqlScript.Statements[0]->get_TableName();
	ASSERT_STRCASEEQ("users", result.c_str()) << "Строки не равны";
}

TEST(testing_parser_drop_statement, test_drop_statement_2)
{
	std::string sql_inquiry = "DROP TABLE users;INSERT TABLE gamer ( name TEXT, age INT );";
    SqlScript SqlScript = run_parse(sql_inquiry);
	std::string result = SqlScript.Statements[1]->get_TableName();
	ASSERT_STRCASEEQ("gamer", result.c_str()) << "Строки не равны";
}