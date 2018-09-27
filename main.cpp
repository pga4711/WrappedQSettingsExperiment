#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <wrappedqsettings.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setOrganizationName("TheCompany");
    QCoreApplication::setOrganizationDomain("intranet.thecompany");
    QCoreApplication::setApplicationName("SaveSettingsAppExp");




    QGuiApplication app(argc, argv);



    qmlRegisterType<WrappedQSettings>("mycustom.cpp.types.wrappedqsettings", 1 , 0 , "WrappedQSettings");




    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
