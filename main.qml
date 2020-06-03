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
    title: qsTr("Machine Template")

    Component.onCompleted: {
        progressBar.value = 0
        startBtn.enabled = true
        stopBtn.enabled = false
        pauseBtn.enabled = false
        resumeBtn.enabled = false

        console.log("Progress: " + progressBar.value)
    }

    MachineOne {
        id: machineOne

        // Receive SIGNALS from machineone.h, then camelCase
        onStarted: {
            startBtn.enabled = false
            stopBtn.enabled = true
            pauseBtn.enabled = true
            resumeBtn.enabled = false
            lblStatus1.text = "Started..."
        }

        onStopped: {
            startBtn.enabled = true
            stopBtn.enabled = false
            pauseBtn.enabled = false
            resumeBtn.enabled = false
            lblStatus1.text = "Stopped!"
            progressbar.value = 0.0
        }

        onPaused: {
            startBtn.enabled = false
            stopBtn.enabled = true
            pauseBtn.enabled = false
            resumeBtn.enabled = true
            lblStatus1.text = "Paused..."
        }

        onResumed: {
            startBtn.enabled = false
            stopBtn.enabled = true
            pauseBtn.enabled = true
            resumeBtn.enabled = false
            lblStatus1.text = "Resumed"
        }

        onProgress: {
            lblStatus1.text = "Progress: " + machineOne.workload + "%"
            progressBar.value = (machineOne.workload * 0.01)
        }

        onRunningtime: {
            lblRunTime1.text = "Total Run-Time: " + (Math.round(machineOne.runtime * 100) / 100) + " s"
        }

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
                anchors.right: parent.right
                anchors.rightMargin: 350
                font.pointSize: 16
            }

            Label {
                id: lblRunTime1
                color: "#000000"
                text: qsTr("Run-Time")
                font.pointSize: 16
                anchors.right: parent.right
                anchors.rightMargin: 50
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

            CustomBtn1 {
                id: startBtn
                icon.source: "qrc:/images/images/start.png"
                text: qsTr("Start")
                onClicked: machineOne.start();
            }

            CustomBtn1 {
                id: stopBtn
                icon.width: 30; icon.height: 30
                icon.source: "qrc:/images/images/stop.png"
                text: qsTr("  Stop")
                onClicked: machineOne.stop();
            }

            CustomBtn1 {
                id: pauseBtn
                icon.width: 45; icon.height: 45
                icon.source: "qrc:/images/images/pause.jpg"
                text: qsTr("Pause")
                onClicked: machineOne.pause();

                background: Rectangle{
                    color: '#f6f6f6'
                }
            }

            CustomBtn1 {
                id: resumeBtn
                icon.source: ""
                text: qsTr("Resume")
                onClicked: machineOne.resume();
            }
        }

    }
}
