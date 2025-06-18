#ifndef CALCULATORCONTROLLER_H
#define CALCULATORCONTROLLER_H

#include <QObject>

#include "calculatormodel.h"

class CalculatorController : public QObject
{
    Q_OBJECT
public:
    explicit CalculatorController(CalculatorModel* model, QObject *parent = nullptr);

    Q_INVOKABLE void   setCelsius(QString degree);
    Q_INVOKABLE void   setFahrenheit(QString degree);
    Q_INVOKABLE void   setKelvin(QString degree);

    Q_INVOKABLE double getCelsius();
    Q_INVOKABLE double getFahrenheit();
    Q_INVOKABLE double getKelvin();

    Q_INVOKABLE void   calculateCelsius();
    Q_INVOKABLE void   calculateFahrenheit();
    Q_INVOKABLE void   calculateKelvin();

private:
    CalculatorModel* model_;

};

#endif // CALCULATORCONTROLLER_H
