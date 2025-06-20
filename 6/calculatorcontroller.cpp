#include "calculatorcontroller.h"

CalculatorController::CalculatorController(CalculatorModel* model, QObject *parent)
    : model_(model) , QObject{parent}
{
    model_->setCelsius(0);
    model_->setFahrenheit(32);
    model_->setKelvin(273.15);
    in_run = false;
}


void CalculatorController::setCelsius(QString degree)
{
    bool ok = false;
    degree.replace(",", ".");
    double change = degree.toDouble(&ok);

    if(ok && change >= -273.15 && change <= 9999) {
        this->model_->setCelsius(change);
    }
}

void CalculatorController::setFahrenheit(QString degree)
{
    bool ok = false;
    degree.replace(",", ".");
    double change = degree.toDouble(&ok);

    if(ok && change >= -9999 && change <= 9999) {
        this->model_->setFahrenheit(change);
    }
}

void CalculatorController::setKelvin(QString degree)
{
    bool ok = false;
    degree.replace(",", ".");
    double change = degree.toDouble(&ok);

    if(ok && change >= 0 && change <= 9999) {
        this->model_->setKelvin(change);
    }
}

void CalculatorController::calculateCelsius(QString degree)
{
    if(in_run)
        return;

    in_run = true;
    this->setCelsius(degree);
    this->model_->setFahrenheit(std::round((this->model_->getCelsius() * 9.0 / 5.0 + 32.0) * 100) / 100);
    this->model_->setKelvin    (std::round((this->model_->getCelsius() + 273.15)            * 100) / 100);
    in_run = false;
}

void CalculatorController::calculateFahrenheit(QString degree)
{
    if(in_run)
        return;

    in_run = true;
    this->setFahrenheit(degree);
    this->model_->setCelsius (std::round(((this->model_->getFahrenheit() - 32.0) * 5.0 / 9.0)        * 100) / 100);
    this->model_->setKelvin  (std::round(((this->model_->getFahrenheit() - 32.0) * 5.0 / 9.0 + 273.15) * 100) / 100);
    in_run = false;
}

void CalculatorController::calculateKelvin(QString degree)
{
    if(in_run)
        return;

    in_run = true;
    this->setKelvin(degree);
    this->model_->setCelsius   (std::round((this->model_->getKelvin() - 273.15)            * 100) / 100);
    this->model_->setFahrenheit(std::round(((this->model_->getKelvin() - 273.15) * 9.0 / 5.0 + 32.0) * 100) / 100);
    in_run = false;
}


