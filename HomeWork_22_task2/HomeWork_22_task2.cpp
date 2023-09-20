﻿#include <iostream>
#include "ConsoleUserInterface.h"
#include "UserApp.h"


//Задание 2. Напишите программу для регистрации пользователей, создать класс
//           «Пользователь».Характеристики «Пользователя» : логин(должен быть уникальным в списке
//           пользователей), пароль, имя, фамилия, адрес, телефон, e - mail(можно добавить поля по
//           желанию, например, список сообщений, даты просмотра аккаунта и т.д.).
// 
//           Для описания полей используйте уже существующий класс «Строка / MyString» и другие
//           пользовательские классы по необходимости.Для хранения пользователей используйте класс
//           «Список / ListOneType» либо «Бинарное дерево поиска / MyTree».Работу программы
//           организуйте при помощи меню :
// 
//            Регистрация
//            − Вход в аккаунт
//            − Список пользователей
//            − Выход из программы
// 
//            При регистрации пользователя необходимо проверить, нет ли пользователя с таким
//            логином, в противном случае вывести сообщение, что такой логин уже используется.
//            При входе в аккаунт необходимо запросить логин.Если такой пользователь существует
//            запросить пароль.В случае ввода верного пароля вывести данные пользователя на экран.
//            В случае ввода неверного пароля можно предложить вариант ввести снова либо выйти
//            отказаться от ввода.
//            При выводе списка пользователей отображать только логины зарегистрированных
//            пользователей.Данные считывать из двоичного файла, в котором записан список
//            пользователей.Если список еще пуст, вывести сообщение.
//            При запуске программы считывать данные из двоичного файла с инициализацией списка
//            пользователей.
//            При выходе из программы сохранять список пользователей в двоичный файл и в
//            текстовый в формате, удобном для чтения.
//            По желанию можно расширить функционал программы.




int main()
{
    system("chcp 1251>nul");

    cout << "\n Для тестирования приложения необходимо\nсоздать двух пользователей и проверить возможность\nотправки сообщений между ними.\n";
    system("pause");
    system("cls");
    UserApp application;
    application.run();

    return 0;
}

