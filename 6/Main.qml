import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 400
    height: 400
    visible: true
    color : "gray"
    title: qsTr("Temperature Calculator")

    property bool updating: false

    Text {
        text: "Temperature\n   Calculator"
        font.pixelSize: 50
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -150
        color: "white"
    }

    Column {
        anchors.centerIn: parent
        spacing: 10

        // ==== Celsius ====
        Row {
            spacing: 10
            Text {
                text: "Celsius"
                width: 100
            }

            TextField {
                id: celsius
                width: 200
                placeholderText: "0"

                validator: DoubleValidator {
                    bottom: -273.15
                    top: 9999
                }

                onTextChanged: {
                    if (updating || !acceptableInput)
                        return;
                    updating = true;
                    controller.setCelsius(text)
                    controller.calculateCelsius()
                    fahrenheit.text = Number(controller.getFahrenheit()).toFixed(2)
                    kelvin.text = Number(controller.getKelvin()).toFixed(2)
                    updating = false;
                }
            }
        }

        // ==== Fahrenheit ====
        Row {
            spacing: 10
            Text {
                text: "Fahrenheit"
                width: 100
            }

            TextField {
                id: fahrenheit
                width: 200
                placeholderText: "32"

                validator: DoubleValidator {
                    bottom: -9999
                    top: 9999
                }

                onTextChanged: {
                    if (updating || !acceptableInput)
                        return;
                    updating = true;
                    controller.setFahrenheit(text)
                    controller.calculateFahrenheit()
                    celsius.text = Number(controller.getCelsius()).toFixed(2)
                    kelvin.text = Number(controller.getKelvin()).toFixed(2)
                    updating = false;
                }
            }
        }

        // ==== Kelvin ====
        Row {
            spacing: 10
            Text {
                text: "Kelvin"
                width: 100
            }

            TextField {
                id: kelvin
                width: 200
                placeholderText: "273.15"

                validator: DoubleValidator {
                    bottom: 0
                    top: 9999
                }

                onTextChanged: {
                    if (updating || !acceptableInput)
                        return;
                    updating = true;
                    controller.setKelvin(text)
                    controller.calculateKelvin()
                    celsius.text = Number(controller.getCelsius()).toFixed(2)
                    fahrenheit.text = Number(controller.getFahrenheit()).toFixed(2)
                    updating = false;
                }
            }
        }
    }
}
