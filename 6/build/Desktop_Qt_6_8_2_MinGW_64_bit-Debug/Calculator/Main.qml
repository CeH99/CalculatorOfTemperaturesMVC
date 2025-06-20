import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 400
    height: 400
    visible: true
    color: "gray"
    title: qsTr("Temperature Calculator")

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
                text: model.celsius_

                validator: RegularExpressionValidator {
                    regularExpression: /^-?\d*\.?\d{0,3}$/
                }

                onTextChanged: {
                        controller.calculateCelsius(text)
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
                text: model.fahrenheit_

                validator: RegularExpressionValidator {
                    regularExpression: /^-?\d*\.?\d{0,3}$/
                }

                onTextChanged: {
                        controller.calculateFahrenheit(text)
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
                text: model.kelvin_

                validator: RegularExpressionValidator {
                    regularExpression: /^(?:\d+|\d*\.\d{0,3})$/
                }

                onTextChanged: {
                        controller.calculateKelvin(text)
                }
            }
        }
    }
}
