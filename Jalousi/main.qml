import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: applicationWindow1
    title: qsTr("Управление жалюзи")
    width: 640
    height: 480
    visible: true

    StackView {
        id: stack
        anchors.fill: parent
        initialItem: main

        Component {
            id: main

            MainForm {
                anchors.fill: parent
            }
        }
        focus: true
        Keys.onBackPressed: depth > 1 ? pop() : event.accepted = false;
    }

    ///////////////// Уведомления //////////////////////
    Rectangle {
        id: massageBox
        y: 400
        height: 50
        width: massage.width > 200 ? massage.width + 10 : 210
        color: "#414450"
        border.color: "#06194b"
        border.width: 3
        anchors.horizontalCenterOffset: 0
        opacity: 0
        z: 1
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30
        anchors.horizontalCenter: parent.horizontalCenter

        Text {
            id: massage
            color: "#ffffff"
            font.family: "Times New Roman"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 30
        }
    }

    Connections {
       target: cppMassageBox
       onMassage: {
           console.log("Signal");
           animationOfMassageBox.running = false;
           animationOfMassageBox.running = true;
           massage.text = value;

       }
    }

    SequentialAnimation {
        id: animationOfMassageBox
        NumberAnimation {
            target: massageBox
            properties: "opacity"
            from: 0.0; to: 1.0; duration: 1000
        }
        NumberAnimation {
            duration: 3000
        }
        NumberAnimation {
            target: massageBox
            properties: "opacity"
            from: 1.0; to: 0.0; duration: 1000
        }
    }
}
