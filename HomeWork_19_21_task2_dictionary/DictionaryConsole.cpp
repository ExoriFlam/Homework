#include <Windows.h>
#include <conio.h>
#include "MyString.h"
#include "DictionaryConsole.h"

DictionaryConsole::DictionaryConsole() : hConsole(GetStdHandle(STD_OUTPUT_HANDLE)), param{ 3 }, chose{ false }, eng{ "" }, ru{""} {}

void DictionaryConsole::init()
{
    menu[0] = "    Добавить перевод.    ";
    menu[1] = "  Показать весь словарь. ";
    menu[2] = "    Поиск в словаре.     ";
    menu[3] = "   Записать в файл ТXТ.  ";
    menu[4] = "   Записать в файл BIN.  ";
    menu[5] = "    Показать ТХТ файл    ";
    menu[6] = "         Выход.          ";
}

void DictionaryConsole::draw_menu()
{
    console_cursor_visible();

    menu[param][0] = '-';
    menu[param][1] = '>';

    for (int i = 0; i < 7; i++)
    {   
       
        if (i != param) set_color(8);
        else set_color(14);
        
        setcur(8, i + 6);
        cout << menu[i];
    }
}

void DictionaryConsole::input()
{
    if (_kbhit)
    {
        switch (_getch())
        {
        case UP:
            param = (param <= 0) ? 6 : param - 1;
            break;
        case DOWN:
            param = (param >= 6) ? 0 : param + 1;
            break;
        case ENTER:
            chose = true;
            break;

        default:
            break;
        }
    }

}

bool DictionaryConsole::get_chose() const
{
    return chose;
}

void DictionaryConsole::set_chose(bool chose)
{
    this->chose = chose;
}

void DictionaryConsole::choice(bool prm)
{
    
    enum { ADD = 0, SHOW, SEARCH, WHRITE_TXT, WHRITE_BIN, SHOW_TXT, EXIT};
    switch (param)
    {
    case ADD:
    {
        
        if (prm)
        {
            system("cls");
            set_color(14);
            setcur(9, 6);
            cout << "Введите слово на английском.   \n\t>";
            cin >> eng;

            system("cls");
            setcur(9, 6);
            cout << "Введите слово на русском.      \n\t>";
            cin >> ru;
            system("cls");
           
        }
        else
        {
            system("cls");
            setcur(9, 6);
            cout << "Данное слово уже существует.   \n\t>";
            _getch();
            system("cls");
        }
        
    }
    break;

    case SHOW:
    {
        system("cls");
        set_color(14);
        
        
    }
        break;
    case SEARCH:
    {
      
        set_color(14);
        
        if (prm)
        {
            system("cls");
            setcur(9, 6);
            cout << "Введите слово для поиска перевода     \n\t> ";
            cin >> eng;
           
        }
        else
        {
            setcur(1, 8);
            cout <<"перевод: "<< ru;
            _getch();
            system("cls");
        }
        
        
        
    }
        break;

    case WHRITE_TXT:
    {
        system("cls");
        set_color(14);
        setcur(9, 6);
        if (prm)
        {
            setcur(9, 6);
            cout << "Файл успешно записан в формате TXT.";
            Sleep(1500);
        }
        else
        {
            setcur(9, 6);
            cout << "Не удалось записать файл.";
            Sleep(1500);
        }
        system("cls");
    }
        break;

    case WHRITE_BIN:
    {
        system("cls");
        set_color(14);
        setcur(9, 6);
        if (prm)
        {
            setcur(9, 6);
            cout << "Файл успешно записан в формате TXT.";
            Sleep(1500);
        }
        else
        {
            setcur(9, 6);
            cout << "Не удалось записать файл.";
            Sleep(1500);
        }
        system("cls");
    }
        break;

    case SHOW_TXT:
    {
        
        if (prm)
        {
            system("start Dictionary.txt");
        }
    }
    break;

    case EXIT:
    {
        if (prm)
        {
            system("cls");
            set_color(14);
            setcur(9, 6);
            cout << "Завершение работы.";
            Sleep(3000);
            exit(0);
        }
    }
        break;

    
    default:
        break;

    }


}

void DictionaryConsole::set_buff_eng(const MyString& str)
{
    this->eng = str;
}

void DictionaryConsole::set_buff_ru(const MyString& str)
{
    this->ru = str;
}

void DictionaryConsole::set_color(int ForgC)
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

void DictionaryConsole::set_color(int text, int fon)
{
	SetConsoleTextAttribute(hConsole, (fon << 4) + text);
}

void DictionaryConsole::setcur(int x, int y)
{
    COORD coord;

    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(hConsole, coord);
}

void DictionaryConsole::console_cursor_visible(bool show, short size)
{
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hConsole, &structCursorInfo);
    structCursorInfo.bVisible = show;
    structCursorInfo.dwSize = size;
    SetConsoleCursorInfo(hConsole, &structCursorInfo);

}
