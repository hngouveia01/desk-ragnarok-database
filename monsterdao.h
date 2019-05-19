#ifndef MONSTERDAO_H
#define MONSTERDAO_H


#include "dao.h"

#include <QSqlQuery>
#include <QSqlDatabase>

class MonsterDAO : public virtual DAO
{
public:
    MonsterDAO(QSqlDatabase& db);
    virtual ~MonsterDAO();
    void initialize();
    void search(QString& element);
    Element fetch();
private:
    QSqlDatabase m_db;
    QSqlQuery m_query;
};

#endif // MONSTERDAO_H
