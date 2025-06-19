#include "calculatormodel.h"

CalculatorModel::CalculatorModel(double celsius, double fahrenheit, double kelvin)
                               : celsius_(celsius), fahrenheit_(fahrenheit), kelvin_(kelvin){}

double CalculatorModel::getCelsius()
{
    return celsius_;
}

void CalculatorModel::setCelsius(double degree) {
    if (celsius_ != degree) {
        celsius_ = degree;
        emit celsiusChanged(degree);
    }
}

double CalculatorModel::getFahrenheit()
{
    return fahrenheit_;
}

void CalculatorModel::setFahrenheit(double degree) {
    if (fahrenheit_ != degree) {
        fahrenheit_ = degree;
        emit fahrenheitChanged(degree);
    }
}

double CalculatorModel::getKelvin()
{
    return kelvin_;
}

void CalculatorModel::setKelvin(double degree) {
    if (kelvin_ != degree) {
        kelvin_ = degree;
        emit kelvinChanged(degree);
    }
}


