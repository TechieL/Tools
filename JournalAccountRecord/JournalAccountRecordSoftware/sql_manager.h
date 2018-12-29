#ifndef SQL_MANAGER_H
#define SQL_MANAGER_H
#include <QString>
#include "system_config.h"
/**
 * @brief The SqlManager class
 */
class SqlManagerPrivate;
class QDate;
class SqlManager {
public:
    enum SumValueType {
        SumValue_YearOut = 10,//年支出
        SumValue_Yearin,//年收入
        SumValue_MonthOut,//月支出
        SumValue_Monthin,//月收入
        SumValue_AllOut,//总支出
        SumValue_Allin,//总收入
    };
    enum DataType {
        DataType_Year = 10,//年
        DataType_Month,//月
    };
    /**
     * @brief 构造
     */
    SqlManager();
    /**
     * @brief 析构
     */
    ~SqlManager();
    /**
     * @brief 创建分类
     * @param name 分类名
     * @return 是否成功
     */
    bool InsertCategorySql(QString name);
    /**
     * @brief 删除分类
     * @param id 分类id
     * @return 是否成功
     */
    bool DeleteCategorySql(int id);
    /**
     * @brief 删除分类
     * @param name 分类名
     * @return 是否成功
     */
    bool DeleteCategorySql(QString name);
    /**
     * @brief 显示分类
     * @param name 分类名
     * @return 分类链表
     */
    QList<CategoryStruct> SelectCategorySql();
    /**
     * @brief 创建流水
     * @param catagory_id 类型id
     * @param date 时间
     * @param value 值
     * @param remark 备注
     * @param auditing 是否审核
     * @return 是否成功
     */
    bool InsertJournalSql(int catagory_id,
                          QDate date,
                          float value,
                          QString remark,
                          bool auditing);
    /**
     * @brief 显示未审核流水
     * @param name 分类名
     * @param is_all 是否显示全部 yes全显示 no只显示未审核
     * @return 链表
     */
    QList<JournalStruct> SelectUnauditJournalSql(bool is_all);
    /**
     * @brief 显示流水
     * @param date 时间
     * @param type 时间类型，年或月
     * @return 链表
     */
    QList<JournalStruct> SelectMonthJournalSql(QDate date, DataType type);
    /**
     * @brief 流水审核通过
     * @param id
     * @return 是否成功
     */
    bool UpdateAuditJournalSql(long long id);
    /**
     * @brief 获得值的和
     * @param type 和类型
     * @return 和
     */
    double GetSumValue(SumValueType type);
    /**
     * @brief 删除流水
     * @param id
     * @return 和
     */
    bool DeleteJournal(long long id);
private:
};

#endif // SQL_MANAGER_H
