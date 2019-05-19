#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>


#include "element.h"
#include "monsterdao.h"


class Database
{
public:
    Database();
    ~Database();
    void initialize();
    void searchMonster(QString& monsterName);
    Element fetch();
private:
    QSqlDatabase m_db;
    MonsterDAO m_monsterDAO;
};

#endif // DATABASE_H
