import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.4
import QtQuick.Window 2.11
import QtQuick.Layouts 1.11
import mycustom.cpp.types.wrappedqsettings 1.0

Window {
    visible: true
    width: 640
    height: 480


    WrappedQSettings {
        id: wrQSettings
    }

    ColumnLayout{
        anchors.fill: parent

        RowLayout {
            Label {
                text: "Persist data by a QSettings-wrapper."
            }
        }

        RowLayout {

            Label {
                text: "Setting one: "
            }

            TextField {
                implicitHeight: 50
                implicitWidth: 100
                onTextChanged: {
                    wrQSettings.wBeginGroup("settingsSectionA")
                    wrQSettings.wSetValue("setting1", text)
                    wrQSettings.wEndGroup()
                    settingsSectionASetting2AsPropLabel.text = wrQSettings.wGetValue("settingsSectionA/setting1")
                }
            }

            Switch {
                id: aSwitch
                text: "My switch"

                onCheckedChanged: {

                    wrQSettings.wBeginGroup("settingsSectionA")
                    wrQSettings.wSetValue("setting2", checked)
                    wrQSettings.wEndGroup()
                }
            }

            Button {
                text: "status :"
                onClicked: {
                    text = "status: " + wrQSettings.wStatus()
                }
            }
        }

        RowLayout {
            Button {
                text: "Get settingsSectionA setting1: "
                onClicked: {
                    settingsSectionASetting1Label.text = "settingsSectionA setting1: " + wrQSettings.wGetValue("settingsSectionA/setting1")
                }
            }

            Label {
                id: settingsSectionASetting1Label

                Component.onCompleted: {
                    text = "FIRST STARTUP TEXT: " + wrQSettings.wGetValue("settingsSectionA/setting1")
                }
            }
        }

        RowLayout {
            Button {
                text: "Get settingsSectionA setting2: "
                onClicked: {
                    settingsSectionASetting2Label.text = "settingsSectionA setting2: " + wrQSettings.wGetValue("settingsSectionA/setting2")
                }
            }

            Label {
                id: settingsSectionASetting2Label

                Component.onCompleted: {
                    text = "FIRST STARTUP TEXT: " + wrQSettings.wGetValue("settingsSectionA/setting2")
                }
            }
        }

        RowLayout {
            Label {
                text: "Get settingsSectionA setting1 BUT INSTANTLY (LIKE A PROEPRTY): "
            }

            Label {
                id: settingsSectionASetting2AsPropLabel
            }
        }

    }
}
