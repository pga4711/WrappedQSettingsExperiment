#ifndef WRAPPEDQSETTINGS_H
#define WRAPPEDQSETTINGS_H
#include <QObject>
#include <QString>
#include <QSettings>
#include <QDebug>

class WrappedQSettings : public QObject
{
    Q_OBJECT

public:
    explicit WrappedQSettings(QObject *parent = nullptr);

    //set value. wValue means like "wrapper get value"

    //Q_INVOKABLE bool wValue(      QString  strToSave); //Copy by value. Bad design?
    //    Q_INVOKABLE bool wValue(const QString  strToSave); //Okay const, but really?
    //    Q_INVOKABLE bool wValue(      QString *strToSave); //Copy
    //    Q_INVOKABLE bool wValue(const QString *strToSave); //?
    //    Q_INVOKABLE bool wValue(      QString &strToSave); //Hmm
    Q_INVOKABLE void wSetValue(const QString &inKey, const QVariant &inValue);
    Q_INVOKABLE QVariant wGetValue(const QString &inKey, const QVariant &inDefaultValue = QVariant()) const;// Jag tror inte jag ska göra sådär.

    Q_INVOKABLE bool wContains(const QString &inKey) const;
    Q_INVOKABLE void wSync();
    Q_INVOKABLE QString wStatus() const;

    Q_INVOKABLE void wBeginGroup(const QString &inPrefix);
    Q_INVOKABLE void wEndGroup();

    Q_INVOKABLE QString wApplicationName() const;
    Q_INVOKABLE QString wOrganizationName() const;

signals:


public slots:


private:
    QSettings m_qsettings;

};

#endif // WRAPPEDQSETTINGS_H

