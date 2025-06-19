import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 400
    height: 400
    visible: true
    color: "gray"
    title: qsTr("Temperature Calculator")

    property bool updating: false

    Column {
        anchors.centerIn: parent
        spacing: 10

        Text {
            text: "Temperature\n  Calculator"
            font.pixelSize: 50
            horizontalAlignment: Text.AlignHCenter
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
        }

        // ==== Celsius ====
        Row {
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter

            Text {
                text: "Celsius"
                width: 100
                verticalAlignment: Text.AlignVCenter
            }

            TextField {
                id: celsius
                width: 200
                placeholderText: "0"
                text: Number(model.celsius_).toFixed(2)

                validator: DoubleValidator {
                    bottom: -273.15
                    top: 9999
                }

                onEditingFinished: {
                    if (!acceptableInput) return;
                    updating = true;
                    controller.setCelsius(text)
                    controller.calculateCelsius()
                    updating = false;
                }
            }
        }

        // ==== Fahrenheit ====
        Row {
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter

            Text {
                text: "Fahrenheit"
                width: 100
                verticalAlignment: Text.AlignVCenter
            }

            TextField {
                id: fahrenheit
                width: 200
                placeholderText: "32"
                text: Number(model.fahrenheit_).toFixed(2)

                validator: DoubleValidator {
                    bottom: -9999
                    top: 9999
                }

                onEditingFinished: {
                    if (!acceptableInput) return;
                    updating = true;
                    controller.setFahrenheit(text)
                    controller.calculateFahrenheit()
                    updating = false;
                }
            }
        }

        // ==== Kelvin ====
        Row {
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter

            Text {
                text: "Kelvin"
                width: 100
                verticalAlignment: Text.AlignVCenter
            }

            TextField {
                id: kelvin
                width: 200
                placeholderText: "273.15"
                text: Number(model.kelvin_).toFixed(2)

                validator: DoubleValidator {
                    bottom: 0
                    top: 9999
                }

                onEditingFinished: {
                    if (!acceptableInput) return;
                    updating = true;
                    controller.setKelvin(text)
                    controller.calculateKelvin()
                    updating = false;
                }
            }
        }
    }
}
