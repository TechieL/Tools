#pragma once
#include <QString>
const static QString m_db_file_name = "JournalAccountDB.db";///数据库地址
//类目相关
const static QString mInsertCategorySql =
        "insert into category values (null,?)";//增，name名字
const static QString mDeleteCategoryByIdSql =
        "delete from category where id = ?";//删，基于id
const static QString mDeleteCategoryByNameSql =
        "delete from category where name = ?";//删，基于name
const static QString mUpdateCategorySql =
        "update category set name = :name where id = :id";//改，基于id
const static QString mSelectAllCategorySql =
        "select * from category";//查询所有
///流水相关
const static QString mInsertJournalSql =
        "insert into journal values (null,:catagory,:date,:value,:remark,:auditing)";//增，日志
const static QString mSelectAllJournalSql =
        "select * from journal ORDER BY data DESC, id DESC";//查询所有
const static QString mSelectMonthJournalSql =
        "select * from journal where strftime(:type,:now_time)"
        " = strftime(:type, data) ORDER BY data DESC, id DESC";//查询年月
const static QString mSelectUnauditJournalSql =
        "select * from journal where auditing = 0 "
        "ORDER BY data DESC, id DESC";//查询未审核结果
const static QString mUpdateAuditJournalSql =
        "update journal set auditing = 1 where id = :id";//改审核通过，基于id，
const static QString mDeleteJournalByNameSql =
        "delete from journal where id = :id";//删，基于id
///金额相关计算
const static QString mSelectOutSql =//计算除工资以外，金额和
        "select sum(value) from journal where catagory != 7  "
        "and  strftime(:type,:now_time) = strftime(:type, data)";
const static QString mSelectInSql =//计算工资，金额和
        "select sum(value) from journal where catagory = 7  "
        "and  strftime(:type,:now_time) = strftime(:type, data)";
const static QString mSelectOutAllTimeSql =//计算除工资以外，金额和，所有时间
        "select sum(value) from journal where catagory != 7";
const static QString mSelectInAllTimeSql =//计算工资，金额和,所有时间
        "select sum(value) from journal where catagory = 7";
