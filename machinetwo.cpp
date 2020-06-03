#include "machinetwo.h"

MachineTwo::MachineTwo(QObject *parent) : QObject(parent)
{
    m_timer.setInterval(m_timerInterval);
    connect(&m_timer, &QTimer::timeout, this, &MachineTwo::timeout);
}

int MachineTwo::value()
{
    qInfo() << "Returning value (M2): " << m_value;
    return m_value;
}

void MachineTwo::setValue(QVariant data)
{
    qInfo() << "Setting value (M2)";
    m_value = data.toInt();
    emit progress2();
}

double MachineTwo::runtime()
{
    qInfo() << "Returning Runtime Value (M2): " << m_runtime;
    return m_runtime;
}

void MachineTwo::setRuntime(QVariant data)
{
    qInfo() << "Setting Runtime Value (M2)";
    m_runtime = data.toDouble();
    emit runningtime2();
}

void MachineTwo::start2()
{
    setValue(0);
    setRuntime(0.0);
    m_timer.start();
    emit started2();
}

void MachineTwo::stop2()
{
    m_timer.stop();
    emit stopped2();
}

void MachineTwo::pause2()
{
    m_timer.stop();
    emit paused2();
}

void MachineTwo::resume2()
{
    m_timer.start();
    emit resumed2();
}

void MachineTwo::timeout()
{
    m_value = m_value + 1;
    emit progress2();
    m_runtime = m_runtime + (m_timerInterval / 1000.0);
    emit runningtime2();

    if(m_value > 99) stop2();
}
