#include "Parser.hpp"

namespace sql
{
    SqlStatementPtr Parser::ParseDropTableStatement()
    {
        std::unique_ptr<sql::DeleteStatement> StatementDelete = std::make_unique<sql::DeleteStatement>();
        sql::Token token = lexer.GetToken();
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }
        Error error;
        if (!(token.Type == sql::TokenType::Keyword && token.Lexem == "DROP"))
        {
            error.expected = "DROP";
            error.str = "Drop value expected";
            error.type = "Keyword";
            result.Errors.push_back(error);
        }
        token = lexer.GetToken();
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }
        if (!(token.Type == sql::TokenType::Keyword && token.Lexem == "TABLE"))
        {
            error.expected = "TABLE";
            error.str = "Table value expected";
            error.type = "Keyword";
            result.Errors.push_back(error);
        }
        token = lexer.GetToken();
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }
        if (token.Type != sql::TokenType::ID)
        {
            error.expected = "Table name";
            error.str = "Table title expected";
            error.type = "ID";
            result.Errors.push_back(error);
        }
        StatementDelete->Set_TableName(token.Lexem);
        token = lexer.GetToken();
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }
        if (token.Type != sql::TokenType::Semicolon)
        {
            error.expected = ";";
            error.str = "Expected ;";
            error.type = "Semicolon";
            result.Errors.push_back(error);
        }
        return std::unique_ptr<sql::DeleteStatement>(StatementDelete.release());
    }

    SqlStatementPtr Parser::ParseCreateTableStatement()
    {
        std::unique_ptr<sql::CreateTableStatement> StatementCreate = std::make_unique<sql::CreateTableStatement>();
        sql::Token token = lexer.GetToken();
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }
        Error error;
        if (!(token.Type == sql::TokenType::Keyword && token.Lexem == "CREATE"))
        {
            error.expected = "DROP";
            error.str = "Create value expected";
            error.type = "Keyword";
            result.Errors.push_back(error);
        }

        token = lexer.GetToken();
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }
        if (!(token.Type == sql::TokenType::Keyword && token.Lexem == "TABLE"))
        {
            error.expected = "TABLE";
            error.str = "Table value expected";
            error.type = "Keyword";
            result.Errors.push_back(error);
        }

        token = lexer.GetToken();
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }
        if (token.Type != sql::TokenType::ID)
        {
            error.expected = "Table name";
            error.str = "Table title expected";
            error.type = "ID";
            result.Errors.push_back(error);
        }
        StatementCreate->Set_TableName(token.Lexem);
        token = lexer.GetToken();
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }

        if (token.Type != sql::TokenType::Bracket || (token.Type == sql::TokenType::Bracket && token.Lexem != "("))
        {
            error.expected = "(";
            error.str = "Expected (";
            error.type = "Bracket";
            result.Errors.push_back(error);
        }
        token = lexer.GetToken();
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }

        while (token.Type != sql::TokenType::Bracket)
        {
            while (token.Type == sql::TokenType::CommonSeparator)
            {
                token = lexer.GetToken();
            }

            if (token.Type != sql::TokenType::ID)
            {
                error.expected = "Column name";
                error.str = "Expected column name";
                error.type = "ID";
                result.Errors.push_back(error);
            }

            sql::ColumnDef columnDef;
            columnDef.ColumnName = token.Lexem;
            token = lexer.GetToken();
            while (token.Type == sql::TokenType::CommonSeparator)
            {
                token = lexer.GetToken();
            }

            if (token.Type != sql::TokenType::TypeName)
            {
                error.expected = "column type";
                error.str = "Expected column type";
                error.type = "TypeName";
                result.Errors.push_back(error);
            }

            columnDef.TypeName_or_value = token.Lexem;
            token = lexer.GetToken();
            while (token.Type == sql::TokenType::CommonSeparator)
            {
                token = lexer.GetToken();
            }
            while (token.Type == sql::TokenType::Comma)
            {
                token = lexer.GetToken();
            }
            StatementCreate->Set_Colomns(columnDef);
        }
        token = lexer.GetToken();
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }
        if (token.Type != sql::TokenType::Semicolon)
        {
            error.expected = ";";
            error.str = "Expected ;";
            error.type = "Semicolon";
            result.Errors.push_back(error);
        }
        return std::unique_ptr<sql::SqlStatement>(StatementCreate.release());
    }

    SqlStatementPtr Parser::ParseSelectTableStatement()
    {
        std::unique_ptr<sql::SelectStatement> StatementSelect = std::make_unique<sql::SelectStatement>();
        sql::Token token = lexer.GetToken();
        Error error;
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }
        if (!(token.Type == sql::TokenType::Keyword && token.Lexem == "SELECT"))
        {
            error.expected = "SELECT";
            error.str = "SELECT value expected";
            error.type = "Keyword";
            result.Errors.push_back(error);
        }

        token = lexer.GetToken();
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }
        if (!(token.Type == sql::TokenType::Keyword && token.Lexem == "TABLE"))
        {
            error.expected = "TABLE";
            error.str = "Table value expected";
            error.type = "Keyword";
            result.Errors.push_back(error);
        }

        token = lexer.GetToken();
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }
        if (token.Type != sql::TokenType::ID)
        {
            error.expected = "Table name";
            error.str = "Table title expected";
            error.type = "ID";
            result.Errors.push_back(error);
        }
        StatementSelect->Set_TableName(token.Lexem);
        token = lexer.GetToken();
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }

        if (token.Type != sql::TokenType::Bracket || (token.Type == sql::TokenType::Bracket && token.Lexem != "("))
        {
            error.expected = "(";
            error.str = "Expected (";
            error.type = "Bracket";
            result.Errors.push_back(error);
        }
        token = lexer.GetToken();
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }

        while (token.Type != sql::TokenType::Bracket)
        {
            while (token.Type == sql::TokenType::CommonSeparator)
            {
                token = lexer.GetToken();
            }

            if (token.Type != sql::TokenType::ID)
            {
                error.expected = "Column name";
                error.str = "Expected column name";
                error.type = "ID";
                result.Errors.push_back(error);
            }

            sql::Expression expression;
            expression.Operand1 = token.Lexem;
            token = lexer.GetToken();
            while (token.Type == sql::TokenType::CommonSeparator)
            {
                token = lexer.GetToken();
            }

            if (token.Type != sql::TokenType::Operation)
            {
                error.expected = "column type";
                error.str = "Expected column type";
                error.type = "TypeName";
                result.Errors.push_back(error);
            }

            expression.Operation = token.Lexem;
            token = lexer.GetToken();
            while (token.Type == sql::TokenType::CommonSeparator)
            {
                token = lexer.GetToken();
            }
            if (token.Type != sql::TokenType::ID)
            {
                error.expected = "column type";
                error.str = "Expected column type";
                error.type = "TypeName";
                result.Errors.push_back(error);
            }
            expression.Operand2 = token.Lexem;
            token = lexer.GetToken();
            while (token.Type == sql::TokenType::CommonSeparator)
            {
                token = lexer.GetToken();
            }
            while (token.Type == sql::TokenType::Comma)
            {
                token = lexer.GetToken();
            }
            StatementSelect->Set_Colomns(expression);
        }
        token = lexer.GetToken();
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }
        if (token.Type != sql::TokenType::Semicolon)
        {
            error.expected = ";";
            error.str = "Expected ;";
            error.type = "Semicolon";
            result.Errors.push_back(error);
        }
        return std::unique_ptr<sql::SqlStatement>(StatementSelect.release());
    }

    SqlStatementPtr Parser::ParseInsertTableStatement()
    {
        std::unique_ptr<sql::InsertStatement> StatementInsert = std::make_unique<sql::InsertStatement>();
        sql::Token token = lexer.GetToken();
        Error error;
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }
        if (!(token.Type == sql::TokenType::Keyword && token.Lexem == "INSERT"))
        {
            error.expected = "INSERT";
            error.str = "INSERT value expected";
            error.type = "Keyword";
            result.Errors.push_back(error);
        }

        token = lexer.GetToken();
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }
        if (!(token.Type == sql::TokenType::Keyword && token.Lexem == "TABLE"))
        {
            error.expected = "TABLE";
            error.str = "Table value expected";
            error.type = "Keyword";
            result.Errors.push_back(error);
        }

        token = lexer.GetToken();
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }
        if (token.Type != sql::TokenType::ID)
        {
            error.expected = "Table name";
            error.str = "Table title expected";
            error.type = "ID";
            result.Errors.push_back(error);
        }
        StatementInsert->Set_TableName(token.Lexem);
        token = lexer.GetToken();
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }

        if (token.Type != sql::TokenType::Bracket || (token.Type == sql::TokenType::Bracket && token.Lexem != "("))
        {
            error.expected = "(";
            error.str = "Expected (";
            error.type = "Bracket";
            result.Errors.push_back(error);
        }
        token = lexer.GetToken();
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }

        while (token.Type != sql::TokenType::Bracket)
        {
            while (token.Type == sql::TokenType::CommonSeparator)
            {
                token = lexer.GetToken();
            }

            if (token.Type != sql::TokenType::ID)
            {
                error.expected = "Column name";
                error.str = "Expected column name";
                error.type = "ID";
                result.Errors.push_back(error);
            }

            sql::ColumnDef columnDef;
            columnDef.ColumnName = token.Lexem;
            token = lexer.GetToken();
            while (token.Type == sql::TokenType::CommonSeparator)
            {
                token = lexer.GetToken();
            }

            if (token.Type != sql::TokenType::ID)
            {
                error.expected = "column type";
                error.str = "Expected column type";
                error.type = "TypeName";
                result.Errors.push_back(error);
            }

            columnDef.TypeName_or_value = token.Lexem;
            token = lexer.GetToken();
            while (token.Type == sql::TokenType::CommonSeparator)
            {
                token = lexer.GetToken();
            }
            while (token.Type == sql::TokenType::Comma)
            {
                token = lexer.GetToken();
            }
            StatementInsert->Set_Colomns(columnDef);
        }
        token = lexer.GetToken();
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }
        if (token.Type != sql::TokenType::Semicolon)
        {
            error.expected = ";";
            error.str = "Expected ;";
            error.type = "Semicolon";
            result.Errors.push_back(error);
        }
        return std::unique_ptr<sql::InsertStatement>(StatementInsert.release());
    }

    SqlStatementPtr Parser::ParseDeleteTableStatement()
    {
        std::unique_ptr<sql::DeleteStatement> StatementDelete = std::make_unique<sql::DeleteStatement>();
        sql::Token token = lexer.GetToken();
        Error error;
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }
        if (!(token.Type == sql::TokenType::Keyword && token.Lexem == "SELECT"))
        {
            error.expected = "SELECT";
            error.str = "SELECT value expected";
            error.type = "Keyword";
            result.Errors.push_back(error);
        }

        token = lexer.GetToken();
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }
        if (!(token.Type == sql::TokenType::Keyword && token.Lexem == "TABLE"))
        {
            error.expected = "TABLE";
            error.str = "Table value expected";
            error.type = "Keyword";
            result.Errors.push_back(error);
        }

        token = lexer.GetToken();
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }
        if (token.Type != sql::TokenType::ID)
        {
            error.expected = "Table name";
            error.str = "Table title expected";
            error.type = "ID";
            result.Errors.push_back(error);
        }
        StatementDelete->Set_TableName(token.Lexem);
        token = lexer.GetToken();
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }

        if (token.Type != sql::TokenType::Bracket || (token.Type == sql::TokenType::Bracket && token.Lexem != "("))
        {
            error.expected = "(";
            error.str = "Expected (";
            error.type = "Bracket";
            result.Errors.push_back(error);
        }
        token = lexer.GetToken();
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }

        while (token.Type != sql::TokenType::Bracket)
        {
            while (token.Type == sql::TokenType::CommonSeparator)
            {
                token = lexer.GetToken();
            }

            if (token.Type != sql::TokenType::ID)
            {
                error.expected = "Column name";
                error.str = "Expected column name";
                error.type = "ID";
                result.Errors.push_back(error);
            }

            sql::Expression expression;
            expression.Operand1 = token.Lexem;
            token = lexer.GetToken();
            while (token.Type == sql::TokenType::CommonSeparator)
            {
                token = lexer.GetToken();
            }

            if (token.Type != sql::TokenType::Operation)
            {
                error.expected = "column type";
                error.str = "Expected column type";
                error.type = "TypeName";
                result.Errors.push_back(error);
            }

            expression.Operation = token.Lexem;
            token = lexer.GetToken();
            while (token.Type == sql::TokenType::CommonSeparator)
            {
                token = lexer.GetToken();
            }
            if (token.Type != sql::TokenType::ID)
            {
                error.expected = "column type";
                error.str = "Expected column type";
                error.type = "TypeName";
                result.Errors.push_back(error);
            }
            expression.Operand2 = token.Lexem;
            token = lexer.GetToken();
            while (token.Type == sql::TokenType::CommonSeparator)
            {
                token = lexer.GetToken();
            }
            while (token.Type == sql::TokenType::Comma)
            {
                token = lexer.GetToken();
            }
            StatementDelete->Set_Colomns(expression);
        }
        token = lexer.GetToken();
        while (token.Type == sql::TokenType::CommonSeparator)
        {
            token = lexer.GetToken();
        }
        if (token.Type != sql::TokenType::Semicolon)
        {
            error.expected = ";";
            error.str = "Expected ;";
            error.type = "Semicolon";
            result.Errors.push_back(error);
        }
        return std::unique_ptr<sql::DeleteStatement>(StatementDelete.release());
    }

    SqlScript Parse_str(std::string str)
    {
        SqlScript result;
        Lexer lexer(str);
        Parser parser(lexer);
        Token token;
        Error error;
        do
        {
            token = lexer.PeekToken();
            if (token.Type == sql::TokenType::Keyword && token.Lexem == "CREATE")
            {
                result.Statements.emplace_back(parser.ParseCreateTableStatement());
            }
            else if (token.Type == sql::TokenType::Keyword && token.Lexem == "SELECT")
            {
                result.Statements.emplace_back(parser.ParseSelectTableStatement());
            }
            else if (token.Type == sql::TokenType::Keyword && token.Lexem == "INSERT")
            {
                result.Statements.emplace_back(parser.ParseInsertTableStatement());
            }
            else if (token.Type == sql::TokenType::Keyword && token.Lexem == "DELETE")
            {
                result.Statements.emplace_back(parser.ParseDeleteTableStatement());
            }
            else if (token.Type == sql::TokenType::Keyword && token.Lexem == "DROP")
            {
                result.Statements.emplace_back(parser.ParseDropTableStatement());
            }
            else
            {
                error.expected = "STATEMENT";
                error.str = "Any statement expected";
                error.type = "Keyword";
                result.Errors.push_back(error);
            }
        } while (token.Type != sql::TokenType::FinalToken);
        return result;
    }
}
