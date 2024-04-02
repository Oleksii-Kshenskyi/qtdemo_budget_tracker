#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QObject>
#include <QQmlEngine>

#include <qqml.h>
#include <QAbstractTableModel>

class ExpensesTableModel : public QAbstractTableModel
{
    Q_OBJECT
    QML_ELEMENT
    QML_ADDED_IN_VERSION(1, 1)

public:
    int rowCount(const QModelIndex & = QModelIndex()) const override;
    int columnCount(const QModelIndex & = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
};

#endif // TABLEVIEW_H
