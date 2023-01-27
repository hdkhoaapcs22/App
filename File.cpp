/*name has no special characters and digit. Otherwise, enter again
id has 8 characters and no start by 0 and has no special characters. Otherwise, enter again
name of app has no special characters and digit. Check to make sure. Otherwise, enter again
out -> saved name and id that just input
check saved to know that want to continue saving. Y to continue and no to return menu
With option 2:
output all data. Input: "Enter id that you want to change"
output app of that id. If has no id -> enter again
enter Y if change name of app and N to change pass
-> enter Y if want to change name of app again
output in4 angin after changing
With option 3:
output name, id and amonut of app of each person
*/
#include <iostream>
#include <fstream>
#include "MyFunction.h"

int main()
{
    MenuMain();
    std::cout << "Enter your option: ";
    int option;
    std::cin >> option;
    Account X[1000001];
    int amount = 0;
    std::vector<std::string> saveName, saveId, savePassWord;
    switch (option)
    {
    case 1:
    {
        std::ofstream out("The first input.txt");
        if (!out.is_open())
        {
            std::cout << "Error!\n";
        }
        else
        {
            RegisterNameAndId(X, amount, saveName, saveId);
            RegisterAppAndPassWord(X, amount, savePassWord);
            out << X[amount].name << " ";
            out << X[amount].id << '\n';
            for (int i = 0; i < X[amount].app.size(); ++i)
            {
                out << std::setw(30) << ": " << X[amount].app[i] << " " << X[amount].password[i] << '\n';
            }
            ++amount;
        }
        out.close();
        break;
    }
    case 2:
    {
        for (int i = 0; i < amount; ++i)
        {
            std::cout << X[i].name << " " << X[i].id << '\n';
        }
        OptionTwo();
        break;
    }
    case 3:
    {
        break;
    }
    default:
    {
    }
    }
}