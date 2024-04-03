#ifndef DATABASE_H
#define DATABASE_H

#include "common.h"

#include <QObject>
#include <QQmlEngine>
#include <QtSql/QSqlDatabase>

static constexpr char db_path[] = "expenses.db" ;

// What does this guy need to do?
// - Check if DB already exists and the table's already created
//   - If doesn't exist, create table and file
//   - If exists:
//     - on construction, fetch all expenses data into a QList<Expenses>
//     - on destruction, overwrite the existing database with the current contents of the TableModel.
class Database: public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    Database();

private:
    QList<Expense> stored_expenses = QList<Expense>();
    QSqlDatabase db;
};

#endif // DATABASE_H
