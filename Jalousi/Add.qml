import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1

Rectangle {
    property bool isAdd: true
    property int  time: 0700
    property bool repeat:  false
    property bool isChisl: false
    property bool open: true
    property int  week: 0000000
    property int  index

    id: rectangle
    width: 600
    height: 800
    color: "#000000"

    ColumnLayout {
        id: columnLayout1
        anchors.rightMargin: 15
        anchors.leftMargin: 15
        anchors.bottomMargin: 15
        anchors.topMargin: row1.height
        anchors.fill: parent

        PickerTime {
            id: pickerTime1
            clip: true
            anchors.horizontalCenter: parent.horizontalCenter
            time: rectangle.time
        }

        Row {
            id: row6
            width: 200
            height: 400
            spacing: 20
            anchors.right: parent.right
            anchors.rightMargin: 0

            Text {
                id: text5
                color: "#ffffff"
                text: qsTr("Повторять еженедельно")
                font.pixelSize: 24
            }

            CheckBox {
                id: checkBoxRepeat
                text: qsTr("")
                checked: rectangle.repeat
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        Row {
            id: row4
            width: 200
            height: 400
            anchors.right: parent.right
            anchors.rightMargin: 0
            spacing: 20

            Text {
                id: text3
                color: "#ffffff"
                text: qsTr("Для четных и нечетных недель")
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 24                
            }

            CheckBox {
                id: checkBox1
                text: qsTr("")
                anchors.verticalCenter: parent.verticalCenter
                enabled: true
                checked: rectangle.isChisl
            }
        }

        Column {
            id: column1
            width: 200
            height: 400
            anchors.horizontalCenter: parent.horizontalCenter

            AddWeek {
                id: addWeek1
                width: columnLayout1.width
                height: columnLayout1.width / 7
                anchors.horizontalCenter: parent.horizontalCenter
                week: rectangle.week
                numweek: 1
            }
            AddWeek {
                id: addWeek2
                width: checkBox1.checked ? columnLayout1.width : 0
                height: checkBox1.checked ? columnLayout1.width / 7 : 0
                anchors.horizontalCenter: parent.horizontalCenter
                week: rectangle.week
                numweek: 2
            }
        }

        Row {
            id: row5
            width: 200
            height: 400
            spacing: 20

            Text {
                id: text4
                color: "#ffffff"
                text: qsTr("Действие для жалюзей:")
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 24
            }

            ComboBox {
                id: comboBox1
                anchors.verticalCenter: parent.verticalCenter
                model: ["Открыть","Опустить"]
                currentIndex: open ? 0 : 1
            }
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
            id: cancel
            width: parent.width / 2
            height: parent.height
            color: "#01486c"
            border.width: 1

            MouseArea {
                id: mouseArea1
                anchors.fill: parent
                onPressed:  parent.color = "#246180"
                onReleased: parent.color = "#01486c"
                onClicked:  stack.pop()
            }

            Row {
                id: row2
                anchors.leftMargin: 15
                spacing: 15
                anchors.fill: parent

                Image {
                    id: image2
                    width:  parent.height / 2
                    height: parent.height / 2
                    anchors.verticalCenter: parent.verticalCenter
                    source: "images/delete.png"
                }

                Text {
                    id: text1
                    color: "#ffffff"
                    text: "Отмена"
                    style: Text.Raised
                    anchors.verticalCenter: parent.verticalCenter
                    font.family: "Times New Roman"
                    font.bold: true
                    font.pixelSize: 35
                }
            }
        }

        Rectangle {
            id: save
            width: parent.width / 2
            height: parent.height
            color: "#01486c"
            border.width: 1

            MouseArea {
                id: mouseArea2
                anchors.fill: parent
                onPressed:  parent.color = "#246180"
                onReleased: parent.color = "#01486c"
                onClicked: {
                    if ((checkBox1.checked && (addWeek1.selectedWeek + addWeek2.selectedWeek != 0))
                            || (!checkBox1.checked && (addWeek1.selectedWeek != 0))) {
                        if (isAdd) {
                            AlarmModel.add(pickerTime1.currentTime,
                                           checkBox1.checked ?
                                               addWeek1.selectedWeek + addWeek2.selectedWeek :
                                               addWeek1.selectedWeek * 3,
                                           checkBoxRepeat.checked,
                                           comboBox1.currentIndex == 0);
                        } else {
                            AlarmModel.setData(AlarmModel.index(index,0),
                                               pickerTime1.currentTime,
                                               AlarmModel.r_time());
                            AlarmModel.setData(AlarmModel.index(index,0),
                                               checkBox1.checked ?
                                                   addWeek1.selectedWeek + addWeek2.selectedWeek :
                                                   addWeek1.selectedWeek * 3,
                                               AlarmModel.r_week());
                            AlarmModel.setData(AlarmModel.index(index,0),
                                               checkBoxRepeat.checked,
                                               AlarmModel.r_repeat());
                            AlarmModel.setData(AlarmModel.index(index,0),
                                               comboBox1.currentIndex == 0,
                                               AlarmModel.r_open());
                            AlarmModel.setData(AlarmModel.index(index,0),
                                               true, AlarmModel.r_isOn());
                            JalousiDevice.file()
                        }
                        stack.pop();
                    }
                }
            }

            Row {
                id: row3
                anchors.rightMargin: 15
                anchors.fill: parent
                spacing: 15
                layoutDirection: Qt.RightToLeft

                Image {
                    id: image1
                    width:  parent.height / 2
                    height: parent.height / 2
                    anchors.verticalCenter: parent.verticalCenter
                    source: "images/save.png"
                }

                Text {
                    id: text2
                    color: "#ffffff"
                    text: "Сохранить"
                    style: Text.Raised
                    anchors.verticalCenter: parent.verticalCenter
                    font.family: "Times New Roman"
                    font.bold: true
                    font.pixelSize: 35
                }
            }

        }
    }

    states: [
        State {
            name: "checkBoxRepeatIsChecked"
            when: !checkBoxRepeat.checked
            PropertyChanges {
                target: checkBox1
                checked: false
                enabled: false
            }
        }
    ]
}
