#ifndef CALCULATORMODEL_H
#define CALCULATORMODEL_H

#include <QObject>

class CalculatorModel : public QObject
{
private:
    double celsius_, fahrenheit_, kelvin_;

    Q_OBJECT
    Q_PROPERTY(double celcius_ READ getCelcius WRITE setCelcius NOTIFY celsiusChanged)
    Q_PROPERTY(double fahrenheit_ READ getCelcius WRITE setCelcius NOTIFY fahrenheitChanged)
    Q_PROPERTY(double kelvin_ READ getKelvin WRITE setKelvin NOTIFY kelvinChanged)

public:
    explicit CalculatorModel(double celsius, double fahrenheit, double kelvin);
    double   getCelsius();
    void     setCelsius(double degree);
    double   getFahrenheit();
    void     setFahrenheit(double degree);
    double   getKelvin();
    void     setKelvin(double degree);

signals:
    void celsiusChanged(double degree);
    void fahrenheitChanged(double degree);
    void kelvinChanged(double degree);
};

#endif // CALCULATORMODEL_H
