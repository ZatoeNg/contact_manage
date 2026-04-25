#pragma once

// TODO: 在此处引用程序需要的其他标头。
#include <string>
#include <iostream>

//宏定义
#define Max 1000

namespace Linkman {
    typedef struct Person {
        std::string m_Name;
        int m_Sex;
        int m_Age;
        std::string m_Phone;
        std::string m_address;
    } Persons;

    typedef struct addressList {
        //保存的联系人数组
        Person PersonArray[Max];

        //记录当前联系人个数
        int m_Size = 0;
    } addressLists;
};

class Contacts {
public:
    //添加模块
    static void Add(Linkman::addressLists *addList);

    //删除模块
    static void Delete(Linkman::addressLists *addList);

    //修改模块
    static void Update(Linkman::addressLists *addList);

    //查找模块
    static void Find(const Linkman::addressLists *addList);

    //显示联系人列表模块
    static void Show(const Linkman::addressLists *addList);

    //清空联系人列表模块
    static void Clear(Linkman::addressLists *addList);

public:
    Contacts() = default;

    ~Contacts() = default;
};
