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
    Q_PROPERTY(double runtime READ runtime WRITE setRuntime NOTIFY runningtime)

public:
    explicit MachineOne(QObject *parent = nullptr);

    // Getter and Setter : m_value
    int value();
    void setValue(QVariant data);

    // Getter and Setter : m_runtime
    double runtime();
    void setRuntime(QVariant data);

    // Modify Timer Interval here (Time it takes to complete 1% of progressbar)
    double const m_timerInterval = 1000.0;

signals:
    // Q_PROPERTY SIGNALS
    void progress();
    void runningtime();

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
    double m_runtime;

};

#endif // MACHINEONE_H
