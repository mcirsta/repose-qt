#include "paramtablerow.h"

ParamTableRow::ParamTableRow()
{
    ParamTableRow("", "");
}

ParamTableRow::ParamTableRow(QString key, QString value)
{
    m_key = key;
    m_value = value;
}

const QString& ParamTableRow::key() const
{
    return m_key;
}

void ParamTableRow::setKey(const QString& newKey)
{
    m_key = newKey;
}

const QString& ParamTableRow::value() const
{
    return m_value;
}

void ParamTableRow::setValue(const QString& newValue)
{
    m_value = newValue;
}
