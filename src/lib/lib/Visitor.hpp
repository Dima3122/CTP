#include <iostream>
#include "InsertStatement.hpp"
#include "DropTableStatement.hpp"
#include "DeleteStatement.hpp"
#include "SelectStatement.hpp"
#include "CreateTableStatement.hpp"
#include "SqlStatement.hpp"

class Visitor
{
private:
    /* data */
public:
    virtual void visitCreateTableStatement(sql::CreateTableStatement a) = 0;
    virtual void visitSelectTableStatement(sql::SelectStatement a) = 0;
    virtual void visitIntertTableStatement(sql::InsertStatement a) = 0;
    virtual void visitDeleteTableStatement(sql::DeleteStatement a) = 0;
    virtual void visitDropTableStatement(sql::DropTableStatement a) = 0;
    virtual ~Visitor() = default;
};

class executeVisitor : public Visitor
{
private:
    /* data */
public:

    void visitCreateTableStatement(sql::SelectStatement a)
    {
        //......
    }

    void visitSelectTableStatement(sql::SelectStatement a)
    {
        //......
    }
    void visitIntertTableStatement(sql::InsertStatement a)
    {
        //......
    }
    void visitDeleteTableStatement(sql::DeleteStatement a)
    {
        //......
    }
    void visitDropTableStatement(sql::DropTableStatement a)
    {
        //......
    }

    executeVisitor();
    ~executeVisitor() = default;
};