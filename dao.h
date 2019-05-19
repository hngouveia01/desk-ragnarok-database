#ifndef DAO_H
#define DAO_H

#include "element.h"

#include <QString>

class DAO {
public:
    virtual ~DAO() = 0;
    virtual void initialize() = 0;
    virtual void search(QString& element) = 0;
    virtual Element fetch() = 0;

};

#endif // DAO_H
