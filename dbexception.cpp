#include "dbexception.h"

DbException::DbException(const QString& msg) : msg_(msg) {

}

DbException::~DbException() {

}

QString DbException::getMessage() const {
    return msg_;
}
