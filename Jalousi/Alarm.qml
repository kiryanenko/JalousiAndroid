import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    id: item1
    width: 500
    height: 700

    Component {
        id: add
        Add {
            isAdd: true
        }
    }

    Row {
        id: row1
        height: 100
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0

        Rectangle {
            id: rectangle1
            width: parent.width / 2
            height: parent.height
            color: "#01486c"
            border.width: 1

            MouseArea {
                id: mouseArea1
                anchors.fill: parent
                onPressed:  parent.color = "#246180"
                onReleased: parent.color = "#01486c"
                onClicked:  JalousiDevice.discover();
            }

            Row {
                id: row2
                anchors.leftMargin: 15
                spacing: 15
                anchors.fill: parent

                Image {
                    id: image2
                    width: item1.width == 0 ? 0 : parent.height / 2
                    height: item1.width == 0 ? 0 : parent.height / 2
                    anchors.verticalCenter: parent.verticalCenter
                    source: "images/refresh.png"
                }

                Text {
                    id: text1
                    color: "#ffffff"
                    text: item1.width == 0 ? "" : qsTr("Обновить")
                    style: Text.Raised
                    anchors.verticalCenter: parent.verticalCenter
                    font.family: "Times New Roman"
                    font.bold: true
                    font.pixelSize: 35
                }
            }
        }

        Rectangle {
            id: addbutton
            width: parent.width / 2
            height: parent.height
            color: "#01486c"
            border.width: 1

            MouseArea {
                id: mouseArea2
                anchors.fill: parent
                onPressed:  parent.color = "#246180"
                onReleased: parent.color = "#01486c"
                onClicked:  stack.push(add)
            }

            Row {
                id: row3
                anchors.rightMargin: 15
                anchors.fill: parent
                spacing: 15
                layoutDirection: Qt.RightToLeft

                Image {
                    id: image1
                    width: item1.width == 0 ? 0 : parent.height / 2
                    height: item1.width == 0 ? 0 : parent.height / 2
                    anchors.verticalCenter: parent.verticalCenter
                    source: "images/add.png"
                }

                Text {
                    id: text2
                    color: "#ffffff"
                    text: item1.width == 0 ? "" : qsTr("Добавить")
                    style: Text.Raised
                    anchors.verticalCenter: parent.verticalCenter
                    font.family: "Times New Roman"
                    font.bold: true
                    font.pixelSize: 35
                }
            }
        }
    }

    ListView {
        id: view
        z: -1
        anchors.topMargin: row1.height
        anchors.fill: parent
        model: AlarmModel
        delegate: ElModel {
            width: view.width
            height: 150
            m_time: time
            m_repeat: repeat
            m_open: open
            m_on:   isOn
            m_week: week
            m_index: model.index
        }
    }
}

