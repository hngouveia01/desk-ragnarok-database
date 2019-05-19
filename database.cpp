#include "database.h"
#include "dbexception.h"
#include "monsterdao.h"

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

namespace {
    const QString databaseType = "QMYSQL";
    const QString databaseHostName = "192.168.1.69";
    const QString databaseName = "rathena_rag";
    const QString databaseUser = "root";
    const QString databasePasswd = "mirolhadb";
}

Database::Database() : m_monsterDAO(m_db)
{
    m_db = QSqlDatabase::addDatabase(databaseType);
    m_db.setHostName(databaseHostName);
    m_db.setDatabaseName(databaseName);
    m_db.setUserName(databaseUser);
    m_db.setPassword(databasePasswd);

    bool ok = m_db.open();

    qDebug() << "DB status:" << m_db.databaseName() << "=" << ok;

    if (m_db.lastError().isValid()) {
        qDebug() << "Error loading database:" << m_db.lastError();
    }

    m_monsterDAO = MonsterDAO(m_db);
}

Database::~Database() {
    m_db.close();
}

void Database::initialize() {
    if (m_db.lastError().isValid()) {
        throw (DbException(m_db.lastError().text()));
    }
    return;
}

void Database::searchMonster(QString& monsterName) {
    m_monsterDAO.search(monsterName);
}

Element Database::fetch() {

}


