#include <qqml.h>
#include <QAbstractTableModel>
#include "tablemodel.h"

Q_INVOKABLE QVariant ExpensesTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (section == 0)
        return "name";
    else if (section == 1)
        return "color";
    else return "shrug";
}

int ExpensesTableModel::rowCount(const QModelIndex &) const
{
    return 2;
}

int ExpensesTableModel::columnCount(const QModelIndex &) const
{
    return 2;
}

QVariant ExpensesTableModel::data(const QModelIndex &index, int role) const
{
    switch (role) {
    case Qt::DisplayRole:
        return QString("%1, %2").arg(index.column()).arg(index.row());
    default:
        break;
    }

    return QVariant();
}

QHash<int, QByteArray> ExpensesTableModel::roleNames() const
{
    return { {Qt::DisplayRole, "display"} };
}
