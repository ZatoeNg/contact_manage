#include "contact_manage.h"

//添加模块
void Contacts::Add(Linkman::addressLists *addList) {
    if (addList->m_Size == Max) {
        std::cout << "通讯录已达存储最大值!!!" << std::endl;
        return;
    } else {
        //姓名模块
        std::string name;
        std::cout << "请输入名字:";
        std::cin >> name;
        addList->PersonArray[addList->m_Size].m_Name = name;


        //性别模块
        int Sex = 0;
        std::cout << "请输入性别（1--男，2--女）:";

        while (true) {
            std::cin >> Sex;

            if (Sex == 1 || Sex == 2) {
                addList->PersonArray[addList->m_Size].m_Sex = Sex;
                break;
            }
            std::cout << "性别有误，请重新输入:";
        }

        //年龄模块
        int age = 0;
        std::cout << "请输入年龄:";

        while (true) {
            std::cin >> age;

            if (age >= 0) {
                addList->PersonArray[addList->m_Size].m_Age = age;
                break;
            }
            std::cout << "年龄有误，请重新输入:";
        }

        //电话模块
        std::string Phone;
        std::cout << "请输入电话号码:";
        std::cin >> Phone;
        addList->PersonArray[addList->m_Size].m_Phone = Phone;

        //家庭住址模块
        std::string address;
        std::cout << "请输入家庭住址:";

        std::cin >> address;
        addList->PersonArray[addList->m_Size].m_address = address;

        //更新通讯录人数
        addList->m_Size++;
        std::cout << "添加成功!!!" << std::endl << std::endl;
    }
}

//删除模块
void Contacts::Delete(Linkman::addressLists *addList) {
    std::string name;
    int flag = -1;
    std::cout << "请输入需要删除的联系人:";
    std::cin >> name;

    //清除
    for (int i = 0; i <= addList->m_Size; i++) {
        if (name == addList->PersonArray[i].m_Name) {
            addList->PersonArray[i].m_Name = "";
            addList->PersonArray[i].m_Age = 0;
            addList->PersonArray[i].m_Sex = 0;
            addList->PersonArray[i].m_Phone = "";
            addList->PersonArray[i].m_address = "";
            flag = 1;
            std::cout << "删除完成!!!" << std::endl << std::endl;
        } else if (i >= addList->m_Size && flag == -1) std::cout << "查无此人!!!" << std::endl << std::endl;
    }

    //重新排序
    for (int t = 0; t <= addList->m_Size; t++) {
        for (int y = 0; y <= addList->m_Size - t; y++) {
            if (addList->PersonArray[y].m_Name.empty()) {
                addList->PersonArray[y].m_Name = addList->PersonArray[y + 1].m_Name;
                addList->PersonArray[y].m_Age = addList->PersonArray[y + 1].m_Age;
                addList->PersonArray[y].m_Sex = addList->PersonArray[y + 1].m_Sex;
                addList->PersonArray[y].m_Phone = addList->PersonArray[y + 1].m_Phone;
                addList->PersonArray[y].m_address = addList->PersonArray[y + 1].m_address;

                addList->PersonArray[y + 1].m_Name = "";
                addList->PersonArray[y + 1].m_Age = 0;
                addList->PersonArray[y + 1].m_Sex = 0;
                addList->PersonArray[y + 1].m_Phone = "";
                addList->PersonArray[y + 1].m_address = "";
            }
        }
    }

    //计算并缩减列表个数
    for (int ty = 0; ty <= addList->m_Size; ty++)if (addList->PersonArray[ty].m_Name.empty())addList->m_Size = ty;
}

//修改模块
void Contacts::Update(Linkman::addressLists *addList) {
    std::string name;
    int ID;

    while (true) {
        std::cout << "请输入需要修改的联系人名字:";
        std::cin >> name;

        std::cout << "请输入需要修改的联系人编号:";
        std::cin >> ID;
        std::cout << std::endl;

        if (name == addList->PersonArray[ID].m_Name) {
            std::cout << "请输入修改后的名字:";
            std::cin >> addList->PersonArray[ID].m_Name;

            std::cout << "请输入修改后的年龄:";
            std::cin >> addList->PersonArray[ID].m_Age;

            std::cout << "请输入修改后的性别（1--男，2--女）:";
            std::cin >> addList->PersonArray[ID].m_Sex;

            std::cout << "请输入修改后的电话:";
            std::cin >> addList->PersonArray[ID].m_Phone;

            std::cout << "请输入修改后的地址:";
            std::cin >> addList->PersonArray[ID].m_address;

            std::cout << "修改成功!!!" << std::endl << std::endl;

            return;
        } else std::cout << "输入错误，请重新输入!!!" << std::endl << std::endl;
    }
}

//查找模块
void Contacts::Find(const Linkman::addressLists *addList) {
    std::string name;
    int count = 0;
    std::cout << "请输入需要查找的联系人名字:";
    std::cin >> name;
    std::cout << std::endl;

    for (int i = 0; i <= addList->m_Size; i++) {
        if (name == addList->PersonArray[i].m_Name) {
            std::cout << "人员编号:" << i << std::endl;
            std::cout << "姓名:" << addList->PersonArray[i].m_Name << std::endl;
            std::cout << "性别:" << (addList->PersonArray[i].m_Sex == 1 ? "男" : "女") << std::endl;
            std::cout << "年龄:" << addList->PersonArray[i].m_Age << std::endl;
            std::cout << "电话:" << addList->PersonArray[i].m_Phone << std::endl;
            std::cout << "住址:" << addList->PersonArray[i].m_address << std::endl;
            std::cout << std::endl;
            count++;
        }
    }
}

//显示模块
void Contacts::Show(const Linkman::addressLists *addList) {
    if (addList->m_Size != 0) {
        for (int i = 0; i <= (addList->m_Size - 1); i++) {
            std::cout << "人员编号:" << i << std::endl;
            std::cout << "姓名:" << addList->PersonArray[i].m_Name << std::endl;
            std::cout << "性别:" << (addList->PersonArray[i].m_Sex == 1 ? "男" : "女") << std::endl;
            std::cout << "年龄:" << addList->PersonArray[i].m_Age << std::endl;
            std::cout << "电话:" << addList->PersonArray[i].m_Phone << std::endl;
            std::cout << "住址:" << addList->PersonArray[i].m_address << std::endl;
            std::cout << std::endl;
        }
    } else std::cout << "当前无记录!!!" << std::endl << std::endl;
}

//清除模块
void Contacts::Clear(Linkman::addressLists *addList) {
    if (addList->m_Size != 0) {
        for (int i = addList->m_Size; i >= 0; i--) {
            addList->PersonArray[i].m_Name = "";
            addList->PersonArray[i].m_Age = 0;
            addList->PersonArray[i].m_Sex = 0;
            addList->PersonArray[i].m_Phone = "";
            addList->PersonArray[i].m_address = "";
        }
        addList->m_Size = 0;
        std::cout << "清除成功!!!" << std::endl << std::endl;
    } else {
        std::cout << "操作无效，当前联系人为空!!!" << std::endl << std::endl;
    }
}
