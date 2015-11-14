import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    width: 500
    height: 700

    Rectangle {
        id: rectangle1
        color: "#ffffab"
        anchors.fill: parent

        Image {
            id: image1
            sourceSize.height: 80
            sourceSize.width: 80
            anchors.fill: parent
            fillMode: Image.Tile
            source: "/images/7.jpg"

            PathView {
                id: view
                anchors.fill: parent
                model: VisualItemModel {
                    Item {
                        width: image1.width
                        height: image1.height
                        Alarm {
                            width:  parent.width
                            height: parent.height
                        }
                    }
                    Item {
                        width: image1.width
                        height: image1.height
                        Windowapp {
                            width:  parent.width < parent.height ? parent.width - 50 : parent.height - 50
                            height: parent.width < parent.height ? parent.width - 50 : parent.height - 50
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter: parent.horizontalCenter
                        }
                    }
                }

                path: Path {
                    startX: - view.width
                    startY: 0

                    PathQuad {
                        x: 2 *view.width
                        y: 0
                        controlX: view.width / 2
                        controlY: view.height
                    }
                }
            }
        }
    }
}
