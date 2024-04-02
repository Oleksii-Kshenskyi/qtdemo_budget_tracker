import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.12
import Models 0.1

Window {
    visible: true
    visibility: Window.Maximized
    color: "darkGray"
    TableView {
        leftMargin: 10
        topMargin: 10
        bottomMargin: 10
        rightMargin: 10
        anchors.left: parent.left
        anchors.right: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        columnSpacing: 3
        rowSpacing: 3
        clip: true

        model: ExpensesTableModel {}

        delegate: Rectangle {
            border.color: "black"
            border.width: 1
            implicitWidth: 120
            implicitHeight: 50
            color: "#FFE4C4"
            Text {
                text: display
                anchors.centerIn: parent
                font.pointSize: 16
            }
        }
        Rectangle {
            anchors.fill: parent
            color: "darkGray"
        }
    }
}
