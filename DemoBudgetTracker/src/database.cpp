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

    QSqlQuery qc(this->db);
    qc.exec("CREATE TABLE IF NOT EXISTS expenses(id INTEGER PRIMARY KEY AUTOINCREMENT, name text, category text, value double)");
    if(qc.executedQuery().isEmpty()) {
        qDebug() << "ERROR: Couldn't create the SQLite database. Exiting. Error: " << qc.lastError().text();
        exit(1);
    }

    QSqlQuery qs(this->db);
    qs.exec("SELECT * FROM expenses");
    QList<Expense> le;
    while(qs.next()) {
        Expense e;
        e.name = qs.value(1).toString();
        e.category = qs.value(2).toString();
        e.value = qs.value(3).toDouble();
        le.append(e);
    }
    this->model.setModelData(le);
}

// TODO: Optimize this. This delete all/repopulate all approach is atrocious.
//       For example, track modified records via DB's Primary Key, and here on destruction
//       only update those records that are new/modified.
Database::~Database() {
    QSqlQuery qd(this->db);
    if(!qd.exec("DELETE FROM expenses")) {
        qDebug() << "WARNING: couldn't delete pre-existing records from the DB: " << qd.lastError().text();
    }

    QSqlQuery qi(this->db);
    qi.prepare("INSERT INTO expenses(name, category, value) VALUES (?, ?, ?)");
    QVariantList names;
    QVariantList categories;
    QVariantList values;
    for(auto& e : this->model.getModelData()) {
        names << e.name;
        categories << e.category;
        values << e.value;
    }
    qi.addBindValue(names);
    qi.addBindValue(categories);
    qi.addBindValue(values);

    if(!qi.execBatch()) {
        qDebug() << "ERROR: couldn't populate the database on destruction!";
    }
}
