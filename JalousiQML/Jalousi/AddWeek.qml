import QtQuick 2.0

Item {
    width: 700
    height: 100

    property int week: 0000000        // 0 - нет будильника     2 - по знаменателям
    property int numweek              // 1 - по числителям      3 - по числ и зн
    property int selectedWeek: numweek * (
                                   day1.selected * 1000000 +
                                   day2.selected * 100000 +
                                   day3.selected * 10000 +
                                   day4.selected * 1000 +
                                   day5.selected * 100 +
                                   day6.selected * 10 +
                                   day7.selected )

    Row {
        id: row1
        anchors.fill: parent

        AddDay {
            id: day1
            width:  parent.height
            height: parent.height
            day: parent.width == 0 ? "" : "Пн"
            isOn: (((week % 10000000) - (week % 1000000)) / 1000000 == numweek) ||
                  (((week % 10000000) - (week % 1000000)) / 1000000 == 3)
        }

        AddDay {
            id: day2
            width:  parent.height
            height: parent.height
            day: parent.width == 0 ? "" : "Вт"
            isOn: (((week % 1000000) - (week % 100000)) / 100000 == numweek) ||
                  (((week % 1000000) - (week % 100000)) / 100000 == 3)
        }

        AddDay {
            id: day3
            width:  parent.height
            height: parent.height
            day: parent.width == 0 ? "" : "Ср"
            isOn: (((week % 100000) - (week % 10000)) / 10000 == numweek) ||
                  (((week % 100000) - (week % 10000)) / 10000 == 3)
        }

        AddDay {
            id: day4
            width:  parent.height
            height: parent.height
            day: parent.width == 0 ? "" : "Чт"
            isOn: (((week % 10000) - (week % 1000)) / 1000 == numweek) ||
                  (((week % 10000) - (week % 1000)) / 1000 == 3)
        }

        AddDay {
            id: day5
            width:  parent.height
            height: parent.height
            day: parent.width == 0 ? "" : "Пт"
            isOn: (((week % 1000) - (week % 100)) / 100 == numweek) ||
                  (((week % 1000) - (week % 100)) / 100 == 3)
        }

        AddDay {
            id: day6
            width:  parent.height
            height: parent.height
            day: parent.width == 0 ? "" : "Сб"
            isOn: (((week % 100) - (week % 10)) / 10 == numweek) ||
                  (((week % 100) - (week % 10)) / 10 == 3)
        }

        AddDay {
            id: day7
            width:  parent.height
            height: parent.height
            day: parent.width == 0 ? "" : "Вс"
            isOn: ((week % 10) == numweek) || ((week % 10) == 3)
        }
    }
}

