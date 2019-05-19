#ifndef DBEXCEPTION_H
#define DBEXCEPTION_H

#include <QString>


class DbException
{
public:
   DbException(const QString& msg);
  ~DbException();

   QString getMessage() const;
private:
   QString msg_;
};

#endif // DBEXCEPTION_H
