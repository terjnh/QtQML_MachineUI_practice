#include "machineone.h"

MachineOne::MachineOne(QObject *parent) : QObject(parent)
{
    m_timer.setInterval(1000);
    connect(&m_timer, &QTimer::timeout, this, &MachineOne::timeout);
}

int MachineOne::value()
{
    qInfo() << "Returning value";
    return m_value;
}

void MachineOne::setValue(QVariant data)
{
    qInfo() << "Setting value";
    m_value = data.toInt();
    emit progress();
}

void MachineOne::start()
{
    setValue(0);
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
    m_value++;
    emit progress();
    if(m_value > 99) stop();
}
