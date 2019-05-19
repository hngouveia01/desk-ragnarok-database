#ifndef ELEMENT_H
#define ELEMENT_H

#include <QString>
#include <QIcon>

class Element
{
public:
    Element();
    Element(QString& id, QString& name, QIcon& icon);
    void setName(QString& name);
    QString getName() const;
    bool isEmpty() const;
private:
    bool m_empty;

    QString m_id;
    QString m_name;
    QIcon m_icon;

};

#endif // ELEMENT_H
