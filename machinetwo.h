#ifndef MACHINETWO_H
#define MACHINETWO_H

#include <QObject>
#include <QTimer>
#include <QVariant>
#include <QDebug>

class MachineTwo : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int workload2 READ value WRITE setValue NOTIFY progress2)
    Q_PROPERTY(double runtime2 READ runtime WRITE setRuntime NOTIFY runningtime2)

public:
    explicit MachineTwo(QObject *parent = nullptr);

    // Getter and Setter : m_value
    int value();
    void setValue(QVariant data);

    // Getter and Setter : m_runtime
    double runtime();
    void setRuntime(QVariant data);


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

    double const m_timerInterval = 1000.0;

};

#endif // MACHINETWO_H
