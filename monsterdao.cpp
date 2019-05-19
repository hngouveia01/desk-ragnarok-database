#include "monsterdao.h"
#include "element.h"
#include "dbexception.h"

#include <QSqlDatabase>
#include <QtDebug>
#include <QSqlQuery>

MonsterDAO::MonsterDAO(QSqlDatabase& db) : m_db(db){

}

MonsterDAO::~MonsterDAO() {

}

void MonsterDAO::initialize() {
    qDebug() << "monsterDAO initialize()";
}

void MonsterDAO::search(QString& mob_name) {
    QSqlQuery m_query("SELECT mob_db.image_mob, mob_db.id, mob_db.iName FROM mob_db WHERE mob_db.iName LIKE '%"+ mob_name + "%'");
    bool ok = m_query.exec();

    if (!ok) {
        m_query.finish();
        throw DbException("Monster not found");
    }
}

Element MonsterDAO::fetch() {
    if (!m_query.next()) {
        m_query.finish();
        return Element();
    }

    QString id = m_query.value(1).toString();
    QString name = m_query.value(2).toString();

    QByteArray outByteArray = m_query.value(0).toByteArray();
    QPixmap outPixmap = QPixmap();
    outPixmap.loadFromData(outByteArray);
    QIcon icon = QIcon(outPixmap);

    Element el(id, name, icon);

    return el;
}
