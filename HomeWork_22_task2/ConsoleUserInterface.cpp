#include <Windows.h>
#include <conio.h>
#include "MyString.h"
#include "ConsoleUserInterface.h"
#include "Defenitions.h"
using namespace std;

ConsoleUserInterface::ConsoleUserInterface() :
    hConsole(GetStdHandle(STD_OUTPUT_HANDLE)), param{ 0 }, chose{ false },
    state_menu{ 0 }, input_login{ "" }, input_password{ "" }, input_message{ "" }, current_user_login{ "отсутсвует" }, buffer{ "" }, buffer_msg{""} {}

void ConsoleUserInterface::init()
{

    switch (state_menu)
    {
    case START_MENU:

    {
        menu[0] = "  Регистрация пользователя";
        menu[1] = "  Аутификация пользователя";
        menu[2] = "     Выход из приложения. ";
       
    }
    break;

    case USER_MENU:

    {
        menu[0] = "     Личная Информация    ";
        menu[1] = "     Написать Сообщение   ";
        menu[2] = "     Выход из аккаунта    ";
                         
    }
    break;

    default:
        break;
    }
   
    
}

void ConsoleUserInterface::draw_menu()
{
    console_cursor_visible();
    
    set_color(14);
    setcur();
    cout << "\nТекущий пользователь : " << current_user_login;

    for (int i = 0; i < 3; i++)
    {
        
        menu[param][0] = '-';
        menu[param][1] = '>';
        

        if (i != param) set_color(8);
        else set_color(14);
        
        
        setcur(8, i + 6);
        cout << menu[i];
        
    }
   
}

void ConsoleUserInterface::input()
{
    if (_kbhit)
    {
        switch (_getch())
        {
        case UP:
            param = (param <= 0) ? 2 : param - 1;

            break;
        case DOWN:
            param = (param >= 2) ? 0 : param + 1;
            break;
        case ENTER:
           
            chose = true;
            break;

        default:
            break;
        }
    }

}

void ConsoleUserInterface::set_state_menu(int state)
{
    this->state_menu = state;
}

bool ConsoleUserInterface::get_chose() const
{
    return chose;
}

void ConsoleUserInterface::set_chose(bool chose)
{
    this->chose = chose;
}

void ConsoleUserInterface::choice(int state)
{
    if (state_menu == START_MENU)
    {
        switch (this->param)
        {

        case REGISTER:
        {
            switch (state)
            {
            case ACTION:
            {
                MyString temp;
                system("cls");
                set_color(14);
                cout << "\nТекущий пользователь : " << current_user_login;

                set_color(4);
                setcur(8, 3);
                cout << "Для имени минимальная длина 2 символа, а для других полей - 3 символа.";
                setcur(8, 4);
                cout << "Минимальная длина электронной почты 7 символов, включая обязательный символ '@'.";
                setcur(8, 5);
                cout << "Для записи даты требуется использовать любой разделитель, который не является цифрой.";
                set_color(8);
               
                setcur(8, 6);
                cout << "Введите желаемый логин..:";
                set_color(14);
                cin >> temp;
                set_color(8);
                temp_user.set_login(temp);

                setcur(8, 7);
                cout << "Введите желаемый пароль.:";
                set_color(14, 14);
                cin >> temp;
                set_color(8, 0);
                temp_user.set_password(temp);

                setcur(8, 8);
                cout << "Введите ваш Email.......:";
                set_color(14);
                cin >> temp;
                set_color(8);
                temp_user.set_email(temp);

                setcur(8, 9);
                cout << "Введите ваше имя........:";
                set_color(14);
                cin >> temp;
                set_color(8);
                temp_user.set_name(temp);

                setcur(8, 10);
                cout << "Введите вашу фамилию....:";
                set_color(14);
                cin >> temp;
                set_color(8);
                temp_user.set_surename(temp);

                setcur(8, 11);
                cout << "Введите дату рождения дд.мм.гггг:";
                set_color(14);
                cin >> temp;
                set_color(8);
                temp_user.set_birthday(temp);

                set_color(14);

                system("cls");
            }
            break;

            case SUCCESS:
            {

                system("cls");
                set_color(14);
                cout << "\nТекущий пользователь : " << current_user_login;
               
                setcur(8, 6);
                set_color(2);
                cout << "Регистрация прошла успешно!";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
                Sleep(100);
                set_color(8);
                
                system("cls");
            }
            break;

            case FAIL:
            {
                system("cls");
                set_color(14);
                cout << "\nТекущий пользователь : " << current_user_login;
                set_color(8);
                setcur(8, 6);
                set_color(4);
                cout << "Регистрация не удалась, повторите попытку!";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
                Sleep(100);
                set_color(8);
                system("cls");
            }
            break;

            default:
                break;
            }


        }
        break;

        case LOGIN:
        {
            system("cls");

            switch (state)
            {
            case ACTION:
            {
                system("cls");
                set_color(14);
                cout << "\nТекущий пользователь : " << current_user_login;
                set_color(8);
                setcur(8, 8);
                cout << "Введите ваш логин:  ";
                set_color(14);
                cin >> input_login;
                set_color(8);

                setcur(8, 9);
                cout << "Введите ваш пароль: ";
                set_color(14, 14);
                cin >> input_password;
                set_color(8, 0);
            }
            break;
            case SUCCESS:
            {

                system("cls");
                set_color(14);
                cout << "\nТекущий пользователь : " << current_user_login;

                setcur(8, 6);
                set_color(2);
                cout << "Авторизация прошла успешно!";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
                Sleep(100);
                set_color(8);
                system("cls");
            }
            break;
            case FAIL:
            {
                system("cls");
                set_color(14);
                cout << "\nТекущий пользователь : " << current_user_login;

                setcur(8, 6);
                set_color(4);
                cout << "Ошибка! Попробуйте снова";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
                Sleep(100);
                set_color(8);
                system("cls");
            }
            break;
            default:
                break;
            }


            system("cls");

        }
        break;

        case EXIT:
        {
            system("cls");
            setcur(8, 6);
            cout << "\n Завершение работы.";
            Sleep(500);
            cout << ".";
            Sleep(500);
            cout << ".";
            Sleep(500);
            cout << ".";
            Sleep(100);
            system("cls");
        }

        default:
            break;

        }
    }
    else if (state_menu == USER_MENU)
    {
        switch (this->param)
        {
        case USER_INFO:
        {
            system("cls");
            set_color(14);
            cout << "\nТекущий пользователь : " << current_user_login;

           
        }
        break;

        case SEND_MESSAGE:
        {
           
            set_color(14);
            switch (state)
            {
            case ACTION:
            {
                cout << "\nСписок доступных пользователей";
                cout << "\nВыбирите кому написать сообщение\n";
                cout << "->";
                cin >> buffer;
               
            }
            break;
            case SUCCESS:
            {
                system("cls");
                setcur(8, 6);
                cout << "\nВведите сообщение: ";
                cin >> buffer_msg;
                system("cls");

                setcur(8, 6);
                set_color(2);
                cout << "Cообщение доставлено успешно!";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
                Sleep(100);
                set_color(8);
            }
                break;
            case FAIL:
            {
                system("cls");
                set_color(4);
                setcur(8, 6);
                cout << "\nТакого email не существует!";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
                Sleep(100);
                set_color(8);
                
            }
                break;
            default:
                break;
            }
            
            
           

        }
        break;

        case LOGOUT:
        {
            system("cls");
            current_user_login = "отсутсвует";
        }
        break;

        default:
            break;
        }
    }

}



void ConsoleUserInterface::set_color(int ForgC)
{
    WORD wColor;
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hConsole, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hConsole, wColor);
    }
    return;
}

void ConsoleUserInterface::set_color(int text, int fon)
{
    SetConsoleTextAttribute(hConsole, (fon << 4) + text);
}

void ConsoleUserInterface::setcur(int x, int y)
{
    COORD coord;

    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(hConsole, coord);
}

void ConsoleUserInterface::console_cursor_visible(bool show, short size)
{
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hConsole, &structCursorInfo);
    structCursorInfo.bVisible = show;
    structCursorInfo.dwSize = size;
    SetConsoleCursorInfo(hConsole, &structCursorInfo);

}
