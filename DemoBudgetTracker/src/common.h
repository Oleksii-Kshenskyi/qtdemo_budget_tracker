#ifndef COMMON_H
#define COMMON_H

#include <QObject>

enum class OpKind {
    Insert,
};

struct ModificationMarker {
    bool is_new;
    OpKind op_kind;
};

struct Expense {
    ModificationMarker marker;
    QString name;
    QString category;
    double value;
};

#endif // COMMON_H
