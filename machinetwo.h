#ifndef MACHINETWO_H
#define MACHINETWO_H

#include <QObject>
#include <QTimer>
#include <QVariant>
#include <QDebug>

class MachineTwo : public QObject
{
    Q_OBJECT
public:
    explicit MachineTwo(QObject *parent = nullptr);

signals:
    // Q_PROPERTY SIGNALS
    void progress2();
    void runningtime2();

    void started2();
    void stopped2();
    void paused2();
    void resumed2();

public slots:
    void start2();
    void stop2();
    void pause2();
    void resume2();

private slots:
    void timeout();  // handle actual timer here

private:
    QTimer m_timer;
    int m_value;
    double m_runtime;

};

#endif // MACHINETWO_H
