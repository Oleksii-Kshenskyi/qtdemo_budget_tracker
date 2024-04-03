#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <optional>

#include <QObject>
#include <QQmlEngine>

#include <qqml.h>
#include <QAbstractTableModel>

struct Expense {
    QString name;
    QString category;
    double value;
};

class ExpensesTableModel : public QAbstractTableModel
{
    Q_OBJECT
    QML_ELEMENT
    QML_ADDED_IN_VERSION(1, 1)

public:
    Q_INVOKABLE virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex & = QModelIndex()) const override;
    int columnCount(const QModelIndex & = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

public slots:
    void addExpense(QString name, QString category, double value);
    void filterByCategory(const QString& category);

private:
    // TODO: Implement saving/loading model's contents to/from a SQLite DB.
    QList<Expense> expenses;
    std::optional<QList<Expense>> maybeFilteredExpenses = QList<Expense>();
};

#endif // TABLEVIEW_H
