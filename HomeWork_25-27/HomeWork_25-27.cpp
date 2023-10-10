#include <iostream>
#include <string>
#include <cstring>
#include "MyString.h"
#include "My_Array.h"

using namespace std;

void erase_in_range(string& src, size_t begin, size_t end) throw (out_of_range);

void show_digit_position(const string& src);

void replace_to_substr(string& src, const string to_find, const string to_replace);

void erase_substr(string& src, const string& sub_str);

void show_every_line(const string& str, string add_delim = "");

void compress_and_write(const string& str)throw (ios_base::failure);

void remove_coments(string& str)throw (out_of_range);

int main()
{
    system("chcp 1251>nul");

   /* Задание 1. Удалить из строки символы в заданном диапазоне позиций, которые вводятся с
                 клавиатуры.Осуществить проверку переданного диапазона.
   */

    string str = "I have to go to the university now but I will come back soon.";
    cout << str;
    cout << "\nВведите начальный индекс для удаления диапазона: ";
    int start, end;
    cin >> start;
    cout << "\nВведите конечный индекс: ";
    cin >> end;

    try
    {
        erase_in_range(str, start, end);
    }
    catch(const out_of_range& exe)
    {
        cout <<  exe.what() << endl;
    }
    
    cout << str;

    cout << endl;
    system("pause");
    system("cls");

   /* Задание 2.Найти все вхождения символа - цифры в строку, вывести символ и его позицию в
                строке, посчитать количество.Пример работы программы :
                Строка: Год рождения 1998, день 17, месяц 5
                Результат поиска цифр в строке :
                цифра 1 в позиции : 13
                цифра 9 в позиции : 14
                цифра 9 в позиции : 15
                цифра 8 в позиции : 16
                цифра 1 в позиции : 24
                цифра 7 в позиции : 25
                цифра 5 в позиции : 34
   */

    string str2 = "Год рождения 1998, день 17, месяц 5";
    cout << str2;
    show_digit_position(str2);

    cout << endl;
    system("pause");
    system("cls");

    /*Задание 3. Для строки заменить все вхождения подстроки на другую строку.Например:
                 Исходная строка : The old man and old sea
                 Замена : old на young
                 Строка после замены : The young man and young sea
    */

    string str3 = "The old man and old sea";
    cout << "\nИсходная строка : " << str3;
    replace_to_substr(str3, "old", "young");
    cout <<"\nСтрока после замены : "<< str3;


    cout << endl;
    system("pause");
    system("cls");

   /* Задание 4.  В строке удалить все вхождения подстроки.Строку и подстроку можно
                  инициализировать на этапе разработки или вводить с клавиатуры.
   */
    string str4 = "I have to go to the university now but I will come back soon.";
    cout << str4 << endl;
    cout << "\nВведите слово для поиска и удаления : ";
    string str4tmp;
    cin.get();
    getline(cin, str4tmp);
    erase_substr(str4, str4tmp);
    cout << str4;

    cout << endl;
    system("pause");
    system("cls");
   /* Задание 5. Выделить из строки все слова(лексемы) без возможного знака препинания и
                 вывести их на экран(с новой строки).Пример работы программы :
                 Исходная строка : Я свой дом нарисовал, облака и дождик.Мне никто не помогал, я уже...
                Я
                свой
                дом
                нарисовал
                облака
                и
                дождик
                Мне
                никто
                не
                помогал
                я
                уже
   */
   
    string str5 = "Я свой дом нарисовал, облака и дождик. Мне никто не помогал, я уже...";
    cout << "\nСтрока для вывода: \n" << str5 << "\nВторым параметром функции можно добавить дополнительные разделители show_every_line(str5,\"!:\")\n";
    show_every_line(str5);

    cout << endl;
    system("pause");
    system("cls");
    /*Задание 6. Добавьте в уже написанные классы(два - три класса на выбор) механизм обработки исключений.
                 На ваш выбор генерируйте исключения в случае ошибок.Например, нехватка памяти, попытка удаления
                 из пустого списка, деление на нуль, неверная дата и т.д.Продемонстрируйте на примерах работу кода.
    */

    MyString str6(10, 'f');
    cout << "\nПопытка обратиться за длину строки MyString.cout << str6[15];\n";

    try
    {
        cout << str6[15];
    }
    catch (const out_of_range& exe)
    {
        cout << exe.what() << endl;
    }

    int arr[5] = { 1,2,3,4,5 };

    cout << "\nПопытка создать MyArray  с неверными аргументами. MyArray arr1(-12, arr);\n";
    try
    {
        MyArray arr1(-12, arr);
    }
    catch (const invalid_argument& exe)
    {
        cout << exe.what() << endl;
    }

    cout << endl;
    system("pause");
    system("cls");
   /* Задание 7. В строке текста записаны слова, разделенные пробелами в произвольном количестве.
                 Сжатие текста состоит в том, что между словами оставляется по одному пробелу,
                 а пробелы перед первым словом и после последнего слова удаляются.Сжатый текст
                 записать в другой файл.Если строка содержит только пробелы, то все они сохраняются.
   */
    string str7 = R"(        Sun                 of the    sleepless! Melancholy star!
                     Whose      tearful beam glows               tremulously  far,
                     That show’st the            darkness thou canst not dispel,
                     How            like art thou               to        joy remember’d      well!               )" ;

    cout << "\nСтрока перед процедурой сжатия пробелов и записи в файл.\n==============================================================\n";
    cout << str7 <<endl;

    try
    {
        compress_and_write(str7);
    }
    catch (const ios_base::failure& exe)
    {
        cout << exe.what() << endl;
    }

    system("pause");

    system("start compresed_str.txt");

    cout << endl;
    system("pause");
    system("cls");
    //Задание 8. Дан текст программы на С++.Удалите все комментарии в нем.Комментарии начинаются с "//"
    //           и продолжаются до конца текущей строки или начинаются с "/*" и заканчиваются "*/".
    
    string str8 = R"(
    // сравнение по умолчанию (operator <)	                 
    // сортировка первых 5-ти элементов
    /*
       cout << "\nВектор после сортировки по возрастанию(все значания) : ";
       sort(v5.begin(), v5.end());
       show(v5);
    */ 


    // надо закомментировать сортировку выше
	cout << "\nВектор после сортировки  по возрастанию(диапазона от v5[2] до предпоследнего элемента ): \n";
	sort(v5.begin() + 2, v5.end() - 1);
	show(v5);)";

    cout <<"\nСтрока до удаления коментариевn\n==============================================================\n" << str8;
    try
    {
        remove_coments(str8);
    }
    catch (const out_of_range& exe)
    {
        cout << exe.what() << endl;
    }
    cout << endl;
    cout << "\nСтрока после удаления коментариевn\n==============================================================\n" << str8;
    cout << endl;
    system("pause");
    system("cls");
    return 0;
}

  

////////////////////////////_Задание 1._//////////////////////////////////////
void erase_in_range(string& src, size_t begin, size_t end)
{
    if (begin < src.length() && end < src.length() && begin <= end)
    {
        src.erase(begin, end - begin + 1);
    }
    else
    {
        throw out_of_range("Index is out of range");
    }
}
////////////////////////////_Задание 2._//////////////////////////////////////
void show_digit_position(const string& src)
{
    for (int i = 0; i < src.length(); ++i)
    {
        if ((src[i] >= '0' && src[i] <= '9') || (src[i] >= 192 && src[i] <= 207))
        {
            cout << "\nцифра " << src[i] << " в позиции " << i;
        }
    }
    
}
////////////////////////////_Задание 3._//////////////////////////////////////
void replace_to_substr(string& src, const string to_find, const string to_replace)
{
    size_t position = src.find(to_find);

    while (position != string::npos)
    {
        src.replace(position, to_find.length(), to_replace);
       
        position = src.find(to_find);
    }
}
////////////////////////////_Задание 4._//////////////////////////////////////
void erase_substr(string& src, const string& sub_str)
{
    size_t position = src.find(sub_str);

    while (position != string::npos)
    {
        src.erase(position, sub_str.length());
        position = src.find(sub_str);
    }
    
    position = src.find("  ");

    while (position != string::npos)
    {
        src.erase(position, 1);
        position = src.find("  ");
    }

}
////////////////////////////_Задание 5._//////////////////////////////////////
void show_every_line(const string& str, string add_delim)
{
    string delimetr = " ,.";
    delimetr += add_delim;
    char* context = nullptr;
    char* t = strtok_s(const_cast<char*>(str.c_str()), delimetr.c_str(), &context);
    while (t)
    {
        cout << t << endl;
        t = strtok_s(nullptr, delimetr.c_str(), &context);
    }

}
////////////////////////////_Задание 7._//////////////////////////////////////
void compress_and_write(const string& str)
{
    int space_cnt = 0;
    string result;
    bool in_word = false;

    for (char c : str)
    {
        if (c != ' ')
        {
            result += c;
            in_word = true;
        }
        else
        {
            space_cnt++;

            if (in_word)
            {
                result += ' ';
                in_word = false;
            }
        }
    }

    if (space_cnt == str.length())
    {
        result = string(space_cnt, ' ');
    }
    
    ofstream f_out("compresed_str.txt");
    if (f_out.is_open())
    {
        f_out << result;
        f_out.close();
        cout << "\nСтрока успешно записанна в файл!";
    }
    else
    {
        throw ios_base::failure("Не удалось открыть файл для записи.");
    }
   
}
////////////////////////////_Задание 8._//////////////////////////////////////
void remove_coments(string& str)
{
 
    size_t position_single_begin = str.find("//");
    size_t position_single_end;

    while (position_single_begin != string::npos)
    {
        position_single_end = str.find('\n', position_single_begin);

        if (position_single_end != string::npos)
        {
            erase_in_range(str, position_single_begin, position_single_end);
        }
        
        position_single_begin = str.find("//");
        
        
    }

    size_t position_multi_begin = str.find("/*");
    size_t position_multi_end;

    while (position_multi_begin != string::npos)
    {
        position_multi_end = str.find("*/", position_multi_begin);

        if (position_multi_end != string::npos)
        {
            erase_in_range(str, position_multi_begin , position_multi_end + 1);
        }

        position_multi_begin = str.find("/*");

    }
   
}