import QtQuick 2.0
import QtQuick.Controls 2.5

import com.company.machineone 1.0

Button {
        icon.color: "transparent"
        icon.width: 50; icon.height: 50
        width: 120
        height: 60
        text: ""
        anchors.verticalCenter: parent.verticalCenter

        background: Rectangle {
            id: btnRect
            implicitWidth: parent.width
            implicitHeight: parent.height
            border.width: 0
            color: "#efefef"  // I update background color by this
        }

        // onClicked: machineOne.start();
}

