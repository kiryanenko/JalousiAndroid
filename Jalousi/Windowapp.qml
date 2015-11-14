import QtQuick 2.4

Image {
    id: image2
    source: "images/okno-s-fortochkoy_1.jpg"

    Item {
        id: window1
        width: parent.width * 0.34
        anchors.left: parent.left
        anchors.leftMargin: parent.width * 0.092
        anchors.bottom: parent.bottom
        anchors.bottomMargin: parent.width * 0.092
        anchors.top: parent.top
        anchors.topMargin: parent.width * 0.092

        Buttons {
            id: buttons1
            width: parent.width * 0.785
            height: parent.height * 0.73
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            num: 0
        }
    }

    Item {
        id: window2
        width: parent.width * 0.34
        anchors.topMargin: parent.width * 0.405
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.bottomMargin: parent.width * 0.092
        anchors.right: parent.right
        anchors.rightMargin: parent.width * 0.092

        Buttons {
            id: buttons2
            width: parent.width * 0.686
            height: parent.height * 0.97
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            num: 1
        }
    }

    Item {
        id: window3
        width: parent.width * 0.34
        anchors.bottom: parent.bottom
        anchors.bottomMargin: parent.width * 0.718
        anchors.right: parent.right
        anchors.rightMargin: parent.width * 0.092
        anchors.top: parent.top
        anchors.topMargin: parent.width * 0.092

        Buttons {
            id: buttons3
            width: parent.width * 0.392
            height: parent.height * 1.51
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            num: 2
        }
    }
}
