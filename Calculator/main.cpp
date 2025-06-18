#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "calculatormodel.h"
#include <calculatorcontroller.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    CalculatorModel* model = new CalculatorModel(0, 32, 273.15);
    CalculatorController* controller = new CalculatorController(model);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.rootContext()->setContextProperty("model", model);
    engine.rootContext()->setContextProperty("controller", controller);
    engine.loadFromModule("Calculator", "Main");

    return app.exec();
}
