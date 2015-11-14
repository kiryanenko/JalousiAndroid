import QtQuick 2.4

Rectangle {
    property string day
    property bool isOn: false
    property bool selected: state == "On"

    id: rectangle1
    width: 100
    height: 100
    color: "#5b5b5b"
    border.width: 2
    border.color: "#b6b5bc"

    Text {
        id: text1
        color: "#ffffff"
        text: parent.day
        font.family: "Verdana"
        font.bold: true
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: parent.height / 2
    }

    MouseArea {
        id: mouseArea1
        anchors.fill: parent
        onClicked: parent.state == "" ? parent.state = "On" : parent.state = ""
    }

    states: [
        State {
            name: "On"
            when: isOn

            PropertyChanges {
                target: text1
                color: "#00ed0c"
            }

            PropertyChanges {
                target: rectangle1
                border.color: "#00ed0c"
            }
        }
    ]
}

