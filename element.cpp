#include "element.h"

#include <QString>

Element::Element() {
    m_empty = true;
}

Element::Element(QString& id, QString& name, QIcon& icon) {
    m_id = id;
    m_name = name;
    m_icon = icon;
    m_empty = false;
}

bool Element::isEmpty() const {
    return m_empty;
}

void Element::setName(QString &name) {
    m_name = name;
}

QString Element::getName() const {
    return m_name;
}
