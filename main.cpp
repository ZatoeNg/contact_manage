//
// Created by Administrator on 2024/11/17.
//
#include "contact_manage.h"

using namespace Linkman;

void showMenu() {
    std::cout << "***** Welcome to Contacts! *****" << std::endl;
    std::cout << "***** 1:添加联系人 *****" << std::endl;
    std::cout << "***** 2:联系人列表 *****" << std::endl;
    std::cout << "***** 3:删除联系人 *****" << std::endl;
    std::cout << "***** 4:查询联系人 *****" << std::endl;
    std::cout << "***** 5:更新联系人 *****" << std::endl;
    std::cout << "***** 6:清空联系人 *****" << std::endl;
    std::cout << "***** 0:退出 *****" << std::endl;
    std::cout << "***** ************ *****" << std::endl;
}

int main() {
    system("chcp 65001 > nul");

    int select = 0;
    char clearConsole = ' ';

    addressLists abs;

    while (true) {
        showMenu();
        std::cout << "Enter your choice :";
        std::cin >> select;

        switch (select) {
            case 1: //添加
                Contacts::Add(&abs);
                break;
            case 2: //显示
                Contacts::Show(&abs);
                break;
            case 3: //删除
                Contacts::Delete(&abs);
                break;
            case 4: //查找
                Contacts::Find(&abs);
                break;
            case 5: //更新
                Contacts::Update(&abs);
                break;
            case 6: //清空
                Contacts::Clear(&abs);
                break;
            default: //退出
                std::cout << "Welcome to next use" << std::endl;
                break;
        }
        if (select == 0) break;

        std::cout << "是否清空控制台:y or n??:";
        std::cin >> clearConsole;
        if (clearConsole == 'y')system("cls");
    }
    return 0;
}
