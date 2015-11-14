import QtQuick 2.4
import QtQuick.Dialogs 1.2

Rectangle {
    property int  m_time
    property bool m_repeat
    property bool m_open
    property bool m_on
    property int  m_week
    property int  m_index

    function f_isChisl(week) {                       // числительно-знаменательная система?
        var a = false;
        var i,b;
        for (i = 10; i <= 10000000 && !a; i = i * 10) {
            b = ((week - (week % (i / 10))) % i) / (i/10);
            if ( b === 1 || b === 2) {
                a = true;
            }
        }
        return a;
    }

    function timeToString(time) {
        var hour = (time - time % 100) / 100;
        var minute = time % 100;
        return (hour < 10 ? "0" : "") + hour + ":" + (minute < 10 ? "0" : "") + minute;
    }

    Component {
        id: set

        Add {
            isAdd: false
            time: m_time
            repeat: m_repeat
            open: m_open
            week: m_week
            isChisl: f_isChisl(m_week)
            index: m_index
        }
    }

    id: rectangle1
    width: 700
    height: 100
    gradient: Gradient {
        GradientStop {
            id: gradientStop2
            position: 0
            color: "#3460f9"
        }

        GradientStop {
            id: gradientStop1
            position: 1
            color: "#1be2fb"
        }
    }

    Row {
        id: row1
        spacing: 15
        anchors.leftMargin: 15
        anchors.fill: parent



        Text {
            id: time
            color: "#ffffff"
            text: timeToString(m_time)
            anchors.verticalCenter: parent.verticalCenter
            style: Text.Outline
            font.family: "Times New Roman"
            font.bold: true
            font.pixelSize: parent.height / 2.5
        }

        Item {
            id: item1
            width: 100
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0

            Row {
                id: row2
                width: parent.height / 4
                height: parent.height / 4
                spacing: 10
                anchors.verticalCenterOffset: - height / 1.5
                anchors.verticalCenter: parent.verticalCenter

                Image {
                    id: image1
                    width:  m_repeat ? parent.height : 0
                    height: m_repeat ? parent.height : 0
                    source: "images/Repeat.png"
                }

                Text {
                    id: text2
                    color: "#ffffff"
                    text: m_open ? qsTr("Поднять") : qsTr("Опустить")
                    style: Text.Raised
                    font.family: "Arial"
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: parent.height * 0.9
                }
            }

            Week {
                id: week1
                numweek: 1
                week: m_week
                enable: !f_isChisl(m_week)
                width:  parent.height / 4
                height: parent.height / 4
                visible: true
                anchors.verticalCenterOffset: height / 1.5
                anchors.verticalCenter: parent.verticalCenter
            }

            Column {
                id: week2
                width:  parent.height / 5
                height: parent.height / 5
                anchors.verticalCenterOffset: height / 1.5
                anchors.verticalCenter: parent.verticalCenter

                Week {
                    id: week21
                    numweek: 1
                    week: m_week
                    enable: f_isChisl(m_week)
                    width: parent.height
                    height: parent.height
                }
                Week {
                    id: week22
                    week: m_week
                    numweek: 2
                    enable: f_isChisl(m_week)
                    width: parent.height
                    height: parent.height
                }
            }
        }
    }

    Image {
        id: switchon
        width: parent.height * 0.7
        height: parent.height * 0.7
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 15
        source: m_on ? "images/alarm-on.png" : "images/alarm-off.png"

        MouseArea {
            id: mouseArea1
            anchors.fill: parent
            onClicked: {
                AlarmModel.setData(AlarmModel.index(index,0),
                                          !m_on, AlarmModel.r_isOn())
                JalousiDevice.file()
            }
        }
    }

    MouseArea {
        id: mouseArea2
        z: -1
        anchors.fill: parent
        onClicked: stack.push(set);
        onPressAndHold: messageDialog.show()
    }    

    MessageDialog {
        id: messageDialog
        title: qsTr("Удалить?")
        text: "Удалить будильник на " + time.text
        icon: StandardIcon.Question
        standardButtons: StandardButton.Yes | StandardButton.No
        onNo: close()
        onYes: AlarmModel.remove(m_index)

        function show() { messageDialog.open(); }
    }

    states: [
        State {
            name: "Press"
            when: mouseArea2.pressed

            PropertyChanges {
                target: gradientStop2
                color: "#0140be"
            }
            PropertyChanges {
                target: gradientStop1
                color: "#02a0b4"
            }
        }
    ]
}

