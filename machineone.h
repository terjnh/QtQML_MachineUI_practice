#ifndef MACHINEONE_H
#define MACHINEONE_H

#include <QObject>
#include <QTimer>
#include <QVariant>
#include <QDebug>

class MachineOne : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int workload READ value WRITE setValue NOTIFY progress)

public:
    explicit MachineOne(QObject *parent = nullptr);

    int value();
    void setValue(QVariant data);

signals:
    void progress();
    void started();
    void stopped();
    void paused();
    void resumed();

public slots:
    void start();
    void stop();
    void pause();
    void resume();

private slots:
    void timeout();  // handle actual timer here

private:
    QTimer m_timer;
    int m_value;

};

#endif // MACHINEONE_H
