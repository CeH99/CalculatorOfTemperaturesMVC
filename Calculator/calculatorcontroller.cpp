#include "calculatorcontroller.h"

CalculatorController::CalculatorController(CalculatorModel* model, QObject *parent)
    : model_(model) , QObject{parent}
{
    model_->setCelsius(0);
    model_->setFahrenheit(32);
    model_->setKelvin(273.15);
}


void CalculatorController::setCelsius(QString degree)
{
    bool ok = false;
    double change = degree.toDouble(&ok);

    if(ok) {
        this->model_->setCelsius(change);
    }
}

void CalculatorController::setFahrenheit(QString degree)
{
    bool ok = false;
    double change = degree.toDouble(&ok);

    if(ok) {
        this->model_->setFahrenheit(change);
    }
}

void CalculatorController::setKelvin(QString degree)
{
    bool ok = false;
    double change = degree.toDouble(&ok);

    if(ok) {
        this->model_->setKelvin(change);
    }
}

void CalculatorController::calculateCelsius()
{
    this->model_->setFahrenheit(this->model_->getCelsius() * 9/5 + 32);
    this->model_->setKelvin(this->model_->getCelsius() + 273.15);
}

void CalculatorController::calculateFahrenheit()
{
    this->model_->setCelsius((this->model_->getFahrenheit() - 32) * 5/9);
    this->model_->setKelvin((this->model_->getFahrenheit() - 32) * 5/9 + 273.15);
}

void CalculatorController::calculateKelvin()
{
    this->model_->setCelsius(this->model_->getKelvin() - 273.15);
    this->model_->setFahrenheit((this->model_->getKelvin() - 273.15) * 9/5 + 32);
}

double CalculatorController::getCelsius()
{
    return this->model_->getCelsius();
}

double CalculatorController::getFahrenheit()
{
    return this->model_->getFahrenheit();
}

double CalculatorController::getKelvin()
{
    return this->model_->getKelvin();
}
