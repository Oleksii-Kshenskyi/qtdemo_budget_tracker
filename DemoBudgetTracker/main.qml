import QtQuick
import QtQuick.Window

Window {
    visible: true
    visibility: Window.Maximized
    color: "darkGray"

    ExpensesTable {
        id: expensesTable
        visible: true
        anchors.topMargin: 10
        anchors.left: parent.left
        anchors.right: parent.horizontalCenter
        anchors.top: parent.top
        anchors.bottom: parent.bottom
    }

    ExpenseControls {
        id: expenseControls
        theModel: expensesTable.theModel
        visible: true
        anchors.topMargin: 10
        anchors.left: parent.horizontalCenter
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
    }
}
