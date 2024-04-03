#include "database.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QGuiApplication>

Database::Database() {
    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName(db_path);
    if(!this->db.open()) {
        qDebug() << "ERROR: Couldn't open the database! Exiting.";
    }

    QSqlQuery q(this->db);
    q.exec("CREATE TABLE IF NOT EXISTS expenses(id INTEGER PRIMARY KEY AUTOINCREMENT, name text, category text, value double)");
    if(q.executedQuery().isEmpty()) {
        qDebug() << "ERROR: Couldn't create the SQLite database. Exiting. Error: " << q.lastError().text();
        exit(1);
    }
}
