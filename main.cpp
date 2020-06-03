#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "machineone.h"
#include "machinetwo.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    // Register C++ class with QML
    qmlRegisterType<MachineOne>("com.company.machineone", 1, 0, "MachineOne");
    qmlRegisterType<MachineTwo>("com.company.machinetwo", 1, 0, "MachineTwo");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
