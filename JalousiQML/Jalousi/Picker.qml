import QtQuick 2.0

Item {
    id: item1
    property int count: 24
    property int current: 0
    property int currentNow: view.currentIndex + 2 - Math.floor((view.currentIndex + 2) / count) * count

    width: 100
    height: 150
    clip: true

    PathView {
        id: view
        pathItemCount: 5
        anchors.fill: parent
        model: parent.count
        currentIndex: current - 2

        path: Path {
            startX: view.width / 2
            startY: - view.height / 6
            PathLine {
                x: view.width / 2
                y: view.height * 1.5
            }
        }
        delegate: Item {
            width: view.width
            height: view.height / 3

            Text {
                text: (model.index < 10 ? "0" : "") + model.index
                font.pixelSize: parent.height * 0.9
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                opacity: opacity
            }
        }
    }
    Rectangle {
        y: (parent.height / 3) - (height / 2)
        width: parent.width * 0.7
        height: 6
        color: "#17fae3"
        anchors.horizontalCenter: parent.horizontalCenter
    }
    Rectangle {
        y: (parent.height * 2/3) - (height / 2)
        width: parent.width * 0.7
        height: 6
        color: "#17fae3"
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Rectangle {
        id: rectangle1
        z: -1
        anchors.fill: parent
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#000000"
            }
            GradientStop {
                position: 0.5
                color: "#ffffff"
            }
            GradientStop {
                position: 1
                color: "#000000"
            }
        }
    }
}
