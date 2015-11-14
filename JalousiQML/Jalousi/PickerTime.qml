import QtQuick 2.4

Rectangle {
    id: rectangle1
    width: 250
    height: 300

    property int time: 0700
    property int currentTime: hourse.currentNow * 100 + minute.currentNow

    Picker {
        id: hourse
        width: parent.width / 2 +1
        height: parent.height
        count: 24
        current: (parent.time - parent.time % 100) / 100
    }
    Picker {
        id: minute
        x: parent.width / 2
        width: parent.width / 2
        height: parent.height
        count: 60
        current: parent.time % 100
    }

    Text {
        id: text1
        text: qsTr(":")
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: parent.height / 3 * 0.9
    }
}

