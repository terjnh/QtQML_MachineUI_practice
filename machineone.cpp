#include "machineone.h"

MachineOne::MachineOne(QObject *parent) : QObject(parent)
{
    m_timer.setInterval(m_timerInterval);
    connect(&m_timer, &QTimer::timeout, this, &MachineOne::timeout);
}

int MachineOne::value()
{
    qInfo() << "Returning value: " << m_value;
    return m_value;
}

void MachineOne::setValue(QVariant data)
{
    qInfo() << "Setting value";
    m_value = data.toInt();
    emit progress();
}

double MachineOne::runtime()
{
    qInfo() << "Returning Runtime Value: " << m_runtime;
    return m_runtime;
}

void MachineOne::setRuntime(QVariant data)
{
    qInfo() << "Setting Runtime Value";
    m_runtime = data.toDouble();
    emit runningtime();
}

void MachineOne::start()
{
    setValue(0);
    setRuntime(0.0);
    m_timer.start();
    emit started();
}

void MachineOne::stop()
{
    m_timer.stop();
    emit stopped();
}

void MachineOne::pause()
{
    m_timer.stop();
    emit paused();
}

void MachineOne::resume()
{
    m_timer.start();
    emit resumed();
}

void MachineOne::timeout()
{
    m_value = m_value + 1;
//    qDebug() << "Value: " << m_value;
    emit progress();
    m_runtime = m_runtime + (m_timerInterval / 1000.0);
//    qDebug() << "Run Time: " << m_runtime;
    emit runningtime();

    if(m_value > 99) stop();
}
