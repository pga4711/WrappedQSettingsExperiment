#include "wrappedqsettings.h"
#include <QDebug>
#include <QString>

WrappedQSettings::WrappedQSettings(QObject *parent) : QObject(parent), m_qsettings(QSettings::IniFormat, QSettings::UserScope, QStringLiteral("TheCompany"), QStringLiteral("SaveSettingsAppExp"))
{
}

void WrappedQSettings::wSetValue(const QString &inKey, const QVariant &inValue)
{
    m_qsettings.setValue(inKey, inValue);
}

QVariant WrappedQSettings::wGetValue(const QString &inKey, const QVariant &inDefaultValue) const //look in the h-file.
{
    //i dont know actually  //TODO, IS THIS RIGHT?
    //If the inKey does not exists, then QVariant QSettings::value returns defaultValue
    if (inDefaultValue==QVariant()) //Om då användaren inte skickat in något. Då skapar jag ju en defaultgrej (headerfilen har jag deklarerat det). När jag har ensån vill jag inte skicka in den.
        return m_qsettings.value(inKey); //Låt denna mixtra med QVariant() själv. Jag vet inte alls vad som händer om jag själv skickar in en defaultgrej.
    else //Oj, användaren skickar in något på inDefaultValue-QVarianten. Då skickar jag väl in den fina dådå. Hängslen och livrem somsagt.
        return m_qsettings.value(inKey, inDefaultValue);
}

bool WrappedQSettings::wContains(const QString &inKey) const
{
    return m_qsettings.contains(inKey);
}

void WrappedQSettings::wSync()
{
    m_qsettings.sync();
}

QString WrappedQSettings::wStatus() const
{
    QSettings::Status x = m_qsettings.status();
    if (x == QSettings::NoError)
        return "QSettings::NoError";
    else if (x == QSettings::AccessError)
        return "QSettings::AccessError";
    else if (x == QSettings::FormatError)
        return "QSettings::FormatError";
    else
        return "SERIOUS PROBLEMS WITH STATUS";
}

void WrappedQSettings::wBeginGroup(const QString &inPrefix)
{
    m_qsettings.beginGroup(inPrefix);
}

void WrappedQSettings::wEndGroup()
{
    m_qsettings.endGroup();
}

QString WrappedQSettings::wApplicationName() const
{
    return m_qsettings.applicationName();
}

QString WrappedQSettings::wOrganizationName() const
{
    return m_qsettings.organizationName();
}
