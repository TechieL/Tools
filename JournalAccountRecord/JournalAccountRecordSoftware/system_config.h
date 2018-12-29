#pragma once
/**
 * @brief 分类结构体
 */
struct CategoryStruct {
    int id;//分类id
    QString name;//分类名
};
/**
 * @brief 流水结构体
 */
struct JournalStruct {
    long long id;//分类id
    QString catagory;//分类
    QString date;//日期
    float value;//值
    QString remark;//备注
};
