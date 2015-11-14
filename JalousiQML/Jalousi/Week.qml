import QtQuick 2.4

Row {
    property int week        // 0 - нет будильника     2 - по знаменателям
    property int numweek     // 1 - по числителям      3 - по числ и зн
    property bool enable

    Dayweek {
        color: (((week % 10000000) - (week % 1000000)) / 1000000 == numweek) ||
               (((week % 10000000) - (week % 1000000)) / 1000000 == 3) ? "#b6ff00" : "#ffffff"
        text: enable ? qsTr("Пн ") : ""
    }
    Dayweek {
        color: (((week % 1000000) - (week % 100000)) / 100000 == numweek) ||
               (((week % 1000000) - (week % 100000)) / 100000 == 3) ? "#b6ff00" : "#ffffff"
        text: enable ? qsTr("Вт ") : ""
    }
    Dayweek {
        color: (((week % 100000) - (week % 10000)) / 10000 == numweek) ||
               (((week % 100000) - (week % 10000)) / 10000 == 3) ? "#b6ff00" : "#ffffff"
        text: enable ? qsTr("Ср ") : ""
    }
    Dayweek {
        color: (((week % 10000) - (week % 1000)) / 1000 == numweek) ||
               (((week % 10000) - (week % 1000)) / 1000 == 3) ? "#b6ff00" : "#ffffff"
        text: enable ? qsTr("Чт ") : ""
    }
    Dayweek {
        color: (((week % 1000) - (week % 100)) / 100 == numweek) ||
               (((week % 1000) - (week % 100)) / 100 == 3) ? "#b6ff00" : "#ffffff"
        text: enable ? qsTr("Пт ") : ""
    }
    Dayweek {
        color: (((week % 100) - (week % 10)) / 10 == numweek) ||
               (((week % 100) - (week % 10)) / 10 == 3) ? "#b6ff00" : "#ffffff"
        text: enable ? qsTr("Сб ") : ""
    }
    Dayweek {
        color: (week % 10 == numweek) || (week % 10 == 3) ? "#b6ff00" : "#ffffff"
        text: enable ? qsTr("Вс") : ""
    }
}

