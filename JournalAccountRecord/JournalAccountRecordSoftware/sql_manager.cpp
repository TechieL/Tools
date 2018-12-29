#include "sql_manager.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDate>
#include <QMap>
#include <QDebug>
#include "base_tool.h"
#include "sql_instruction.h"
//构造
SqlManager::SqlManager() {
    //复制文件，不覆盖
    if(!QSqlDatabase::contains()) {
        BaseTool::copyFileToPath(":/file/JournalAccountDB.db",m_db_file_name,false);
        QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");//第二参数不提供名字，使用默认名称
        database.setDatabaseName(m_db_file_name);
        if(!database.open()) {
            qDebug()<<database.lastError();
        }
    }
}
//析构
SqlManager::~SqlManager() {
//    QSqlDatabase database = QSqlDatabase::database();
//    database.close();
}
//创建分类
bool SqlManager::InsertCategorySql(QString name) {
    QSqlQuery sql_query;//默认构造使用默认数据库
    sql_query.prepare(mInsertCategorySql);
    sql_query.addBindValue(name);
    if(!sql_query.exec()) {
        qDebug() << sql_query.lastError();
        return false;
    }
    return true;
}
//删除分类
bool SqlManager::DeleteCategorySql(int id) {
    QSqlQuery sql_query;//默认构造使用默认数据库
    sql_query.prepare(mDeleteCategoryByIdSql);
    sql_query.addBindValue(id);
    if(!sql_query.exec()) {
        qDebug() << sql_query.lastError();
        return false;
    }
    return true;
}
//删除分类
bool SqlManager::DeleteCategorySql(QString name) {
    QSqlQuery sql_query;//默认构造使用默认数据库
    sql_query.prepare(mDeleteCategoryByNameSql);
    sql_query.addBindValue(name);
    if(!sql_query.exec()) {
        qDebug() << sql_query.lastError();
        return false;
    }
    return true;
}
//显示分类
QList<CategoryStruct> SqlManager::SelectCategorySql() {
    QSqlQuery sql_query;//默认构造使用默认数据库
    sql_query.prepare(mSelectAllCategorySql);
    QList<CategoryStruct> s;
    if(!sql_query.exec()) {
        qDebug() << sql_query.lastError();
        return s;
    }
    else {
        while(sql_query.next()) {
            s.append({sql_query.value(0).toInt(),sql_query.value(1).toString()});
        }
        return s;
    }
}

bool SqlManager::InsertJournalSql(int catagory_id,
                                  QDate date,
                                  float value,
                                  QString remark,
                                  bool auditing) {
    QSqlQuery sql_query;//默认构造使用默认数据库
    sql_query.prepare(mInsertJournalSql);
    sql_query.bindValue(":catagory",catagory_id);
    sql_query.bindValue(":date",date);
    sql_query.bindValue(":value",value);
    sql_query.bindValue(":remark",remark);
    sql_query.bindValue(":auditing",auditing);
    if(!sql_query.exec()) {
        qDebug() << sql_query.lastError();
        return false;
    }
    return true;
}

QList<JournalStruct> SqlManager::SelectUnauditJournalSql(bool is_all) {
    QSqlQuery sql_query;//默认构造使用默认数据库
    if(is_all) {
        sql_query.prepare(mSelectAllJournalSql);
    }
    else
        sql_query.prepare(mSelectUnauditJournalSql);
    QList<JournalStruct> s;
    if(!sql_query.exec()) {
        qDebug() << sql_query.lastError();
        return s;
    }
    else {
        //建立类型索引
        auto cates = SelectCategorySql();
        QMap<int,QString> imap;
        for(auto cate:cates)
            imap[cate.id] = cate.name;
        while(sql_query.next()) {
            s.append({sql_query.value(0).toLongLong(),
                      imap.find(sql_query.value(1).toInt()).value(),
                     sql_query.value(2).toString(),
                     sql_query.value(3).toFloat(),
                     sql_query.value(4).toString()});
        }
        return s;
    }
}

QList<JournalStruct> SqlManager::SelectMonthJournalSql(QDate date,
                       SqlManager::DataType type) {
    QSqlQuery sql_query;//默认构造使用默认数据库
    sql_query.prepare(mSelectMonthJournalSql);
    sql_query.bindValue(":now_time",date);
    if(type == DataType_Year)
        sql_query.bindValue(":type","%Y");
    else if(type == DataType_Month)
        sql_query.bindValue(":type","%Y-%m");
    else
        sql_query.bindValue(":type","%Y-%m");
    QList<JournalStruct> s;
    if(!sql_query.exec()) {
        qDebug() << sql_query.lastError();
        return s;
    }
    else {
        //建立类型索引
        auto cates = SelectCategorySql();
        QMap<int,QString> imap;
        for(auto cate:cates)
            imap[cate.id] = cate.name;
        while(sql_query.next()) {
            s.append({sql_query.value(0).toLongLong(),
                      imap.find(sql_query.value(1).toInt()).value(),
                     sql_query.value(2).toString(),
                     sql_query.value(3).toFloat(),
                     sql_query.value(4).toString()});
        }
        return s;
    }
}

bool SqlManager::UpdateAuditJournalSql(long long id) {
    QSqlQuery sql_query;//默认构造使用默认数据库
    sql_query.prepare(mUpdateAuditJournalSql);
    sql_query.bindValue(":id",id);
    if(!sql_query.exec()) {
        qDebug() << sql_query.lastError();
        return false;
    }
    return true;
}

double SqlManager::GetSumValue(SqlManager::SumValueType type) {
    QSqlQuery sql_query;//默认构造使用默认数据库

    switch (type) {
    case SumValue_YearOut:
        sql_query.prepare(mSelectOutSql);
        sql_query.bindValue(":type","%Y");
        sql_query.bindValue(":now_time","now");
        break;
    case SumValue_Yearin:
        sql_query.prepare(mSelectInSql);
        sql_query.bindValue(":type","%Y");
        sql_query.bindValue(":now_time","now");
        break;
    case SumValue_MonthOut:
        sql_query.prepare(mSelectOutSql);
        sql_query.bindValue(":type","%Y-%m");
        sql_query.bindValue(":now_time","now");
        break;
    case SumValue_Monthin:
        sql_query.prepare(mSelectInSql);
        sql_query.bindValue(":type","%Y-%m");
        sql_query.bindValue(":now_time","now");
        break;
    case SumValue_AllOut:
        sql_query.prepare(mSelectOutAllTimeSql);
        break;
    case SumValue_Allin:
        sql_query.prepare(mSelectInAllTimeSql);
        break;
    default:
        break;
    }
    if(!sql_query.exec()) {
        qDebug() << sql_query.lastError();
        return 0.0;
    }
    sql_query.next();
    return sql_query.value(0).toDouble();
}

bool SqlManager::DeleteJournal(long long id) {
    QSqlQuery sql_query;//默认构造使用默认数据库
    sql_query.prepare(mDeleteJournalByNameSql);
    sql_query.bindValue(":id",id);
    if(!sql_query.exec()) {
        qDebug() << sql_query.lastError();
        return false;
    }
    return true;
}
