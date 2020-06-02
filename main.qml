import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

import com.company.machineone 1.0

/*
  Further practice from Section 11:
  Making a UI with machine(s) running in the background
  - Add a timer to display duration a machine has been running for
  */

Window {
    id: window
    visible: true
    width: 640
    height: 480
    color: "#d9d5d5"
    title: qsTr("Hello World")

    Component.onCompleted: {
        progressBar.value = machineOne.workload
        startBtn.enabled = true
        stopBtn.enabled = false
        pauseBtn.enabled = false
        resumeBtn.enabled = false

        console.log("Progress: " + progressBar.value)
    }

    MachineOne {
        id: machineOne


    }

    Column {
        id: column1
        width: 590
        height: 150
        spacing: 0
        anchors.top: parent.top
        anchors.topMargin: 80
        anchors.horizontalCenter: parent.horizontalCenter

        Row {
            id: row1a
            width: column1.width
            height: 30
            spacing: 50

            Label {
                id: lblMachine1
                text: qsTr("Machine 1")
                font.bold: true
            }

            Label {
                id: lblStatus1
                text: qsTr("Status")
                font.pointSize: 16
            }
        }

        Row {
            id: row1b
            width: column1.width
            height: 40
            anchors.verticalCenter: parent.verticalCenter

            ProgressBar {
                id: progressBar
                width: 540
                height: parent.height
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 20
                value: 0.5
            }
        }

        Row {
            id: row1c
            width: column1.width
            height: column1.height - (row1a.height + row1b.height)
            spacing: 20
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0

            Button {
                id: startBtn
                width: 120
                height: 60
                text: qsTr("Start")
                anchors.verticalCenter: parent.verticalCenter
            }

            Button {
                id: stopBtn
                width: 120
                height: 60
                text: qsTr("Stop")
                anchors.verticalCenter: parent.verticalCenter
            }

            Button {
                id: pauseBtn
                width: 120
                height: 60
                text: qsTr("Pause")
                anchors.verticalCenter: parent.verticalCenter
            }

            Button {
                id: resumeBtn
                width: 120
                height: 60
                text: qsTr("Resume")
                anchors.verticalCenter: parent.verticalCenter
            }
        }

    }
}
