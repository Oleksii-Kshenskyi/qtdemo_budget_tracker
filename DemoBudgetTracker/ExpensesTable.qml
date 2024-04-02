import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.12
import QtQuick.Controls
import Models 0.1
import Qt.labs.qmlmodels

Item {
    HorizontalHeaderView {
        id: horizontalHeader
        anchors.left: tableView.left
        anchors.top: parent.top
        syncView: tableView
        clip: true
        delegate: Rectangle {
            implicitWidth: 120
            implicitHeight: 30
            color: "#303030"
            Text {
                text: display
                anchors.centerIn: parent
                font.pointSize: 16
                color: "#D0D0D0"
            }
        }
    }

    TableView {
        id: tableView
        leftMargin: 30
        topMargin: 30
        bottomMargin: 30
        rightMargin: 30
        anchors.fill: parent
        columnSpacing: 3
        rowSpacing: 3
        clip: true

        model: ExpensesTableModel {
        }

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
