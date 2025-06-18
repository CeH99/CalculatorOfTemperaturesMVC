#include "calculatormodel.h"

CalculatorModel::CalculatorModel(double celsius, double fahrenheit, double kelvin)
                               : celsius_(celsius), fahrenheit_(fahrenheit), kelvin_(kelvin){}

double CalculatorModel::getCelsius()
{
    return celsius_;
}

void   CalculatorModel::setCelsius(double degree)
{
    celsius_ = degree;
}

double CalculatorModel::getFahrenheit()
{
    return fahrenheit_;
}

void   CalculatorModel::setFahrenheit(double degree)
{
    fahrenheit_ = degree;
}

double CalculatorModel::getKelvin()
{
    return kelvin_;
}

void   CalculatorModel::setKelvin(double degree)
{
    kelvin_ = degree;
}
