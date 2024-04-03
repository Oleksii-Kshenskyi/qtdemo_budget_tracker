import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

// TODO: Better validation of text fields
Item {
    property var theModel: null
    property var categoryModel: ["Subscriptions", "Games", "Groceries", "Technology"]

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
            Layout.row: 1
            Layout.column: 0
        }

        // TODO: Implement filtering table records by category
        ComboBox {
            id: expenseCategory
            font.pointSize: 12
            implicitWidth: 200
            implicitHeight: 50
            topPadding: 5
            Layout.row: 1
            Layout.column: 1
            model: categoryModel
        }

        Text {
            text: "Cost:"
            font.pointSize: 12
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
            validator: RegularExpressionValidator{regularExpression: /^[0-9]+.[0-9]+$/}
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
            onClicked: {
                theModel.addExpense(expenseNameField.text, expenseCategory.currentText, expenseCostField.text);
            }
        }
    }
}

