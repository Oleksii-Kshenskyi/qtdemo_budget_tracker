#include <algorithm>

#include <qqml.h>
#include <QAbstractTableModel>
#include "tablemodel.h"

enum ModelDisplayRole {
    Display = 0,
    Filter,
};

Q_INVOKABLE QVariant ExpensesTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (section == 0)
        return "Name";
    else if (section == 1)
        return "Category";
    else if (section == 2)
        return "Value";
    else assert(false && "ExpensesTableModel::headerData(): unreachable: header index out of bounds.");
}

int ExpensesTableModel::rowCount(const QModelIndex &) const
{
    if(this->maybeFilteredExpenses.has_value()) {
        return this->maybeFilteredExpenses->size();
    } else return this->expenses.size();
}

int ExpensesTableModel::columnCount(const QModelIndex &) const
{
    return 3;
}

QVariant ExpensesTableModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();

    switch (role) {
        case Qt::DisplayRole: {
            const Expense* e;
            if(this->maybeFilteredExpenses.has_value()) {
                e = &(this->maybeFilteredExpenses.value()[index.row()]);
            } else {
                e = &(this->expenses[index.row()]);
            }

            switch(index.column()) {
                case 0: return e->name; break;
                case 1: return e->category; break;
                case 2: return e->value; break;
                default: assert(false && "ExpensesTableModel::data(): unreachable!"); break;
            }
            break;
        }
        default:
            break;
    }

    return QVariant();
}

QHash<int, QByteArray> ExpensesTableModel::roleNames() const
{
    return { {Qt::DisplayRole, "display"} };
}

void ExpensesTableModel::addExpense(QString name, QString category, double value) {
    this->beginInsertRows(QModelIndex(), this->expenses.count(), this->expenses.count());
    Expense e { name, category, value };
    this->expenses.append(e);
    this->endInsertRows();
}

void ExpensesTableModel::filterByCategory(const QString& category) {
    this->beginResetModel();
    auto opt_fe = &this->maybeFilteredExpenses;
    auto el = &this->expenses;

    if(category == "<ALL>") {
        *opt_fe = std::nullopt;
    } else {
        *opt_fe = QList<Expense>();
        std::copy_if(el->cbegin(), el->cend(), std::back_inserter(**opt_fe), [&](auto& e) { return e.category == category; });
    }

    this->endResetModel();
}
