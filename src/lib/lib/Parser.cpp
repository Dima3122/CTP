#include "Parser.hpp"

std::unique_ptr<sql::SqlStatement> ParseDropTableStatement(sql::Lexer &lexer, SqlScript &result)
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
    StatementDelete->set_TableName(token.Lexem);
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

std::unique_ptr<sql::SqlStatement> ParseCreateTableStatement(sql::Lexer &lexer, SqlScript &result)
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
    StatementCreate->set_TableName(token.Lexem);
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
        StatementCreate->set_colomns(columnDef);
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

std::unique_ptr<sql::SqlStatement> ParseSelectTableStatement(sql::Lexer &lexer, SqlScript &result)
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
    StatementSelect->set_TableName(token.Lexem);
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
        StatementSelect->set_colomns(expression);
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

std::unique_ptr<sql::SqlStatement> ParseInsertTableStatement(sql::Lexer &lexer, SqlScript &result)
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
    StatementInsert->set_TableName(token.Lexem);
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
        StatementInsert->set_colomns(columnDef);
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

std::unique_ptr<sql::SqlStatement> ParseDeleteTableStatement(sql::Lexer &lexer, SqlScript &result)
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
    StatementDelete->set_TableName(token.Lexem);
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
        StatementDelete->set_colomns(expression);
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

SqlScript run_parse(std::string str)
{
    SqlScript result;
    sql::Lexer lexer(str);
    sql::Token token;
    Error error;
    do
    {
        token = lexer.PeekToken();
        if (token.Type == sql::TokenType::Keyword && token.Lexem == "CREATE")
        {
            result.Statements.emplace_back(ParseCreateTableStatement(lexer, result));
        }
        else if (token.Type == sql::TokenType::Keyword && token.Lexem == "SELECT")
        {
            result.Statements.emplace_back(ParseSelectTableStatement(lexer, result));
        }
        else if (token.Type == sql::TokenType::Keyword && token.Lexem == "INSERT")
        {
            result.Statements.emplace_back(ParseInsertTableStatement(lexer, result));
        }
        else if (token.Type == sql::TokenType::Keyword && token.Lexem == "DELETE")
        {
            result.Statements.emplace_back(ParseDeleteTableStatement(lexer, result));
        }
        else if (token.Type == sql::TokenType::Keyword && token.Lexem == "DROP")
        {
            result.Statements.emplace_back(ParseDropTableStatement(lexer, result));
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