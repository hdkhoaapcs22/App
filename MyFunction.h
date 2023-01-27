#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
struct Account
{
    std::string name;
    std::string id;
    std::vector<std::string> app;
    std::vector<std::string> password;
};
void MenuMain();
void MenuApp();
void RegisterNameAndId(Account X[], int &amount, std::vector<std::string> saveName, std::vector<std::string> saveId);
void RegisterAppAndPassWord(Account X[], int amount, std::vector<std::string> savePassWord);
void OptionTwo(std::vector<std::string> saveId);
void OptionThree(Account X[], int amount);