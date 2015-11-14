import QtQuick 2.4

Item {
    property int num

    Image {
        id: arrow_bottom
        width: parent.width
        height: parent.width
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.horizontalCenter: parent.horizontalCenter
        source: "images/arrow_bottom.png"

        MouseArea {
            id: buttomMouse
            anchors.fill: parent
            onPressed: JalousiDevice.down(num);
        }
    }

    Image {
        id: downarrow
        width: parent.width * 0.57
        height: parent.width * 0.35
        z: 1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: parent.width * 0.184
        source: "images/downarrow.png"

        MouseArea {
            id: downMouse
            anchors.fill: parent
            onPressed: JalousiDevice.down(num);
            onReleased: JalousiDevice.stop(num);
        }
    }

    Image {
        id: uparrow
        width: parent.width * 0.57
        height: parent.width * 0.35
        z: 1        
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: - parent.width * 0.184
        source: "images/uparrow.png"

        MouseArea {
            id: upMouse            
            anchors.fill: parent
            onPressed: JalousiDevice.up(num);
            onReleased: JalousiDevice.stop(num);
        }
    }

    Image {
        id: arrow_top
        width: parent.width
        height: parent.width
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.horizontalCenter: parent.horizontalCenter
        source: "images/arrow_top.png"

        MouseArea {
            id: topMouse
            anchors.fill: parent
            onPressed: JalousiDevice.up(num);
        }
    }

    states: [
        State {
            name: "top"
            when: topMouse.pressed
            PropertyChanges {
                target: arrow_top
                scale: 0.9
            }
        },
        State {
            name: "up"
            when: upMouse.pressed
            PropertyChanges {
                target: uparrow
                scale: 0.9
            }
        },
        State {
            name: "down"
            when: downMouse.pressed
            PropertyChanges {
                target: downarrow
                scale: 0.9
            }
        },
        State {
            name: "botton"
            when: buttomMouse.pressed
            PropertyChanges {
                target: arrow_bottom
                scale: 0.9
            }
        }
    ]
}
