import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.12
import QtQuick.Controls
import Models 0.1
import Qt.labs.qmlmodels
import QtQuick.Layouts

Item {
    property var theModel: expensesModel
    property var categoryModel: null

    ColumnLayout {
         anchors.fill: parent
         spacing: 20

         RowLayout {
             Layout.preferredHeight: 50
             Layout.preferredWidth: 400
             spacing: tableView.columnSpacing


             Text {
                font.pointSize: 14
                text: "Filter by Category:"
                Layout.preferredHeight: 50
                Layout.preferredWidth: 200
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignRight
                Layout.rightMargin: 3
             }

             ComboBox {
                 id: categoryFilter
                 model: ["<ALL>"].concat(categoryModel)
                 Layout.preferredHeight: 50
                 Layout.preferredWidth: 200
                 font.pointSize: 12
                 onCurrentTextChanged: {
                    theModel.filterByCategory(categoryFilter.currentText);
                 }
             }
         }

    HorizontalHeaderView {
        id: horizontalHeader
        syncView: tableView
        clip: true
        delegate: Rectangle {
            implicitWidth: 200
            implicitHeight: 50
            color: "#303030"
            Text {
                text: display
                anchors.centerIn: parent
                font.pointSize: 16
                color: "#D0D0D0"
            }
        }
        Layout.preferredHeight: 50
        Layout.fillWidth: true
    }

    TableView {
        id: tableView
        columnSpacing: 5
        rowSpacing: 5
        clip: true
        Layout.fillHeight: true
        Layout.fillWidth: true

        model: ExpensesTableModel {
            id: expensesModel
        }

        delegate: Rectangle {
            border.color: "black"
            border.width: 1
            implicitWidth: 200
            implicitHeight: 50
            color: "#FFE4C4"
            Text {
                text: display
                anchors.centerIn: parent
                font.pointSize: 12
            }
        }
        Rectangle {
            anchors.fill: parent
            color: "darkGray"
        }
    }
    }
}
