import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    GridLayout {
        columns: 2
        rows: 4
        columnSpacing: 5
        rowSpacing: 5

        Text {
            text: "Name of expense:"
            font.pointSize: 12
            Layout.row: 0
            Layout.column: 0
        }

        TextField {
            id: expenseNameField
            font.pointSize: 12
            implicitWidth: 200
            implicitHeight: 40
            topPadding: 5
            Layout.row: 0
            Layout.column: 1
        }

        Text {
            text: "Category:"
            font.pointSize: 12
            // width: 300
            // height: 40
            Layout.row: 1
            Layout.column: 0
        }

        ComboBox {
            id: expenseCategory
            font.pointSize: 12
            implicitWidth: 200
            implicitHeight: 40
            topPadding: 5
            Layout.row: 1
            Layout.column: 1
        }

        Text {
            text: "Cost:"
            font.pointSize: 12
            // width: 300
            // height: 40
            Layout.row: 2
            Layout.column: 0
        }

        TextField {
            id: expenseCostField
            font.pointSize: 12
            implicitWidth: 200
            implicitHeight: 40
            topPadding: 5
            Layout.row: 2
            Layout.column: 1
        }

        Button {
            id: addExpenseButton
            text: "Add Expense"
            implicitWidth: 350
            implicitHeight: 50
            font.pointSize: 12
            Layout.row: 3
            Layout.column: 0
            Layout.columnSpan: 2
        }
    }
}

