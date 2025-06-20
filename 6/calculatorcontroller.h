#ifndef CALCULATORCONTROLLER_H
#define CALCULATORCONTROLLER_H

#include <QObject>

#include "calculatormodel.h"

class CalculatorController : public QObject
{
    Q_OBJECT

public:
    explicit CalculatorController(CalculatorModel* model, QObject *parent = nullptr);

    void               setCelsius(QString degree);
    void               setFahrenheit(QString degree);
    void               setKelvin(QString degree);

    Q_INVOKABLE void   calculateCelsius(QString degree);
    Q_INVOKABLE void   calculateFahrenheit(QString degree);
    Q_INVOKABLE void   calculateKelvin(QString degree);

private:
    CalculatorModel* model_;
    bool             in_run;

};

#endif // CALCULATORCONTROLLER_H
