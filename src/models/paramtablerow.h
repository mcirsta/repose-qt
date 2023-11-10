#ifndef PARAMTABLEROW_H
#define PARAMTABLEROW_H

#include <QString>

class ParamTableRow {
public:
    ParamTableRow();
    ParamTableRow(QString key, QString value);

    const QString& key() const;
    void setKey(const QString& newKey);

    const QString& value() const;
    void setValue(const QString& newValue);

    bool isEmpty() const { return m_key.isEmpty() && m_value.isEmpty(); }

private:
    QString m_key;
    QString m_value;
};

#endif // PARAMTABLEROW_H
