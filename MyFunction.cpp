#include "MyFunction.h"
void MenuMain()
{
    std::cout << "1.Register\n";
    std::cout << "2.Editing\n";
    std::cout << "3.List of account\n";
}
void MenuApp()
{
    std::cout << "1.Zalo\n";
    std::cout << "2.Facebook\n";
    std::cout << "3.Skype\n";
    std::cout << "4.More option\n";
    std::cout << "5.Exit\n";
}
bool checkName(std::string name)
{
    for (int i = 0; i < name.size(); ++i)
    {
        if ((int)name[i] < 65 || (int)name[i] > 91 && (int)name[i] < 97 || (int)name[i] > 123)
        {
            std::cout << "Enter again\n";
            return false;
        }
    }
    return true;
}
bool checkId(std::string id)
{
    if (id[0] == '0')
    {
        return false;
    }
    if (id.size() < 8)
    {
        return false;
    }
    for (int i = 1; i < id.size(); ++i)
    {
        if (!isdigit(id[i]))
        {
            return false;
        }
    }
    return true;
}
void RegisterNameAndId(Account X[], int &amount, std::vector<std::string> &saveName, std::vector<std::string> &saveId)
{
    // name
    do
    {
    again:
        std::string name;
        std::cout << "Enter name of account: ";
        getline(std::cin, name);
        if (checkName(X[amount].name) == false)
        {
            std::cout << "Your input is wrong!.Please enter name again\n";
        }
        else
        {
            auto it = find(begin(saveName), end(saveName), name);
            if (it == end(saveName))
            {
                X[amount].name = name;
                saveName.push_back(name);
                break;
            }
            else
            {
                std::cout << "Your name used. Thus, using new name\n";
                goto again;
            }
        }
    } while (true);
    // id
    do
    {
    againId:
        std::string id;
        std::cout << "Enter id of account: ";
        getline(std::cin, id);

        if (checkId(X[amount].id) == false)
        {
            std::cout << "Your input is wrong\n.Please enter id again\n";
            goto againId;
        }
        else
        {
            auto it = find(begin(saveId), end(saveId), id);
            if (it == end(saveId))
            {
                X[amount].id = id;
                saveId.push_back(id);
            }
        }
    } while (true);
}
std::string chooseApp()
{
optionAgain:
    std::cout << "Enter app you want to register: ";
    int app;
    std::cin >> app;
    switch (app)
    {
    case 1:
    {
        return "Zalo";
    }
    case 2:
    {
        return "Facebook";
    }
    case 3:
    {
        return "Skype";
    }
    case 4:
    {
        do
        {
            std::string nameOfApp;
            std::cout << "Enter app you want to register: ";
            std::cin >> nameOfApp;
            if (checkName(nameOfApp))
            {
                return nameOfApp;
            }
            else
            {
                std::cout << "Please enter again\n";
            }
        } while (true);
        break;
    }
    case 5:
    {
        system("CLS");
        MenuMain();
        return "";
        break;
    }
    default:
    {
        std::cout << "Enter your choose again\n";
        goto optionAgain;
        break;
    }
    }
    return "";
}
bool checkPassWord(std::string passWord)
{
    if (passWord.size() < 8)
    {
        return false;
    }
    int upper, lower, character, digit;
    for (int i = 0; i < passWord.size(); ++i)
    {
        if (isdigit(passWord[i]))
        {
            digit = 1;
        }
        if (islower(passWord[i]))
        {
            lower = 1;
        }
        if (isupper(passWord[i]))
        {
            upper = 1;
        }
        if (!isdigit(passWord[i]) && !islower(passWord[i]) && !isupper(passWord[i]))
        {
            character = 1;
        }
    }
    return digit + lower + upper + character == 4;
}
std::string choosePassWord(std::vector<std::string> &savePassWord)
{
    std::string passWord;
    do
    {
    secondChance:
        std::cout << "Enter password for this app: ";
        std::cin >> passWord;
        if (checkPassWord(passWord))
        {
            std::cout << "Your password is not suitable!. Please entering again!\n";
            goto secondChance;
        }
        else
        {
            auto it = find(savePassWord.begin(), savePassWord.end(), passWord);
            if (it == end(savePassWord))
            {

                std::cout << "Are you sure your password is: ";
                std::cout << passWord << '\n';
                std::cout << "If you sure with your choice, please enter Y/y. Otherwise, enter N/n to change\n";
                char Sure;
                switch (Sure)
                {
                case 'Y':
                case 'y':
                {
                    savePassWord.push_back(passWord);
                    return passWord;
                }
                case 'N':
                case 'n':
                {
                    goto secondChance;
                    break;
                }
                }
            }
            else
            {
                std::cout << "This password used. Please using other password\n";
            }
        }
    } while (true);
}
void RegisterAppAndPassWord(Account X[], int amount, std::vector<std::string> &savePassWord)
{
nextchoice:
    X[amount].app.push_back(chooseApp());
    X[amount].password.push_back(choosePassWord(savePassWord));
    std::cout << "Saved password for app " << X[amount].app.back() << " of " << X[amount].name << "( " << X[amount].id << " )\n";
optionagain:
    std::cout << "Do you want to continue registering app and password?. Enter Y/y for Yes or N/n for No\n";
    char option;
    std::cin >> option;
    switch (option)
    {
    case 'Y':
    case 'y':
    {
        ++amount;
        goto nextchoice;
        break;
    }
    case 'N':
    case 'n':
    {
        goto nextchoice;
        break;
    }
    default:

    {
        std::cout << "Your option is not correct!. Please entering again\n";
        goto optionagain;
        break;
    }
    }
}
void FindId(std::vector<std::string> saveId, int &index)
{
    do
    {
        std::cout << "Enter id that you want to find: ";
        std::string id;
        std::cin >> id;
        auto it = find(begin(saveId), end(saveId), id);
        if (it == end(saveId))
        {
            std::cout << "Can not find this id!. Please entering again\n";
        }
        else
        {
            index = it - begin(saveId);
            break;
        }
    } while (true);
}
void outputInformation(Account X[], int index)
{
    std::cout << "The information of " << X[index].name << "( " << X[index].id << " ) is: \n";
    for (int i = 0; i < X[index].app.size(); ++i)
    {
        std::cout << i + 1 << ". " << X[index].app[i] << " " << X[index].password[i] << '\n';
    }
    std::cout << X[index].app.size() + 1 << "Exit!\n";
}
void OptionTwo(std::vector<std::string> saveId, Account X[], std::vector<std::string> &app, std::vector<std::string> &savePassWord)
{
    int index = 0;
    FindId(saveId, index);
    system("CLS");
    outputInformation(X, index);
    int optionAppToChange;
    std::cout << "Enter app you want to change: ";
    std::cin >> optionAppToChange;
    if (optionAppToChange != X[index].app.size())
    {
        std::cout << "\nWe recorded your option. Now, tell we know you want to change name of app or password\n";
        std::cout << std::setw(20) << "Enter Y/y for changing name and N/n for changing password\n";
        char optionChange;
        std::cin >> optionChange;
        switch (optionChange)
        {
        case 'Y':
        case 'y':
        {
        inputAgainNewNameOfApp:
            std::string newNameOfApp;
            std::cout << "Enter new name of old app " << X[index].app[optionAppToChange - 1] << ": ";
            std::cin >> newNameOfApp;
            if (checkName(newNameOfApp))
            {
                std::cout << "Enter Y/y if you want to change name of this app as: " << newNameOfApp << '\n';
                std::cout << "Otherwise, enter N/n\n";
                char agreeChangeName;
                std::cout << "Your option is: ";
                std::cin >> agreeChangeName;
                switch (argeeChangeName)
                {
                case 'Y':
                case 'y':
                {
                    std::cout << "Name of " << X[index].app[optionAppToChange - 1] << "changed to: " << newNameOfApp << '\n';
                    X[index].app[optionAppToChange - 1] = newNameOfApp;
                    system("CLS");
                    outputInformation(X, index);
                    break;
                }
                case 'N':
                case 'n':
                {
                    goto inputAgainNewNameOfApp;
                    break;
                }
                default:
                {
                    std::cout << "Your input is incorrect! Please entering again\n";
                    break;
                }
                }
            }
            else
            {
                std::cout << "\nThe alternate name is not suitable. Thus, entering other\n";
                goto inputAgainNewNameOfApp;
            }
            break;
        }
        case 'N':
        case 'n':
        {
        secondChanceToChangeNewPassWord:
            std::cout << "Enter new password you want to change for this app: ";
            std::string newPassWord;
            std::cin >> newPassWord;
            if (checkPassWord(newPassWord))
            {
                auto it = find(begin(savePassWord), end(savePassWord), newPassWord);
                if (it == end(savePassWord))
                {
                    std::cout << "Your password changed to: " << newPassWord << '\n';
                    std::cout << "Do you argee with new password? Enter Y/y for YES or N/n for No\n";
                    char agreeChangePassWord;
                    std::cout << "Please entering your option: ";
                    std::cin >> agreeChangePassWord;
                    switch (agreeChangePassWord)
                    {
                    case 'Y':
                    case 'y':
                    {
                        std::cout << "Password changed to: " << newPassWord << '\n';
                        X[index].password[it - begin(savePassWord)] = newPassWord;
                        system("CLS");
                        outputInformation(X, index);
                        break;
                    }
                    case 'N':
                    case 'n':
                    {
                        goto secondChanceToChangeNewPassWord;
                        break;
                    }
                    default:
                    {
                        std::cout << "Your input is incorrect! Please entering again\n";
                        break;
                    }
                    }
                }
                else
                {
                    std::cout << "Your password used. Please entering new password!\n";
                    goto secondChanceToChangeNewPassWord;
                }
            }
            break;
        }
        default:
        {
            std::cout << "Your input is incorrect!. Please entering again!\n";
            goto secondChanceToChangeNewPassWord;
            break;
        }
        }
    }
    else
    {
        system("CLS");
        MenuMain();
    }
}
void OptionThree(Account X[], int amount)
{
    for (int i = 0; i < amount; ++i)
    {
        std::cout << X[i].name << " " << X[i].id << '\n';
        std::cout << X[i].app.size() << " app" << '\n';
    }
}