#include <iostream>
#include <fstream>
#include "iShape.h"
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"
#include "Ellipse.h"

using namespace std;

//Задание 3. Создайте абстрактный класс Shape для рисования плоских фигур.Определите
//           виртуальные методы :
//               -Show() — вывод на экран информации о фигуре,
//               -Save() — сохранение данных фигуры в двоичный файл,
//               -Load() — считывание данных фигуры из двоичного файла.
// 
//           Определите производные классы :
//               -Square — квадрат, который характеризуется координатами левого верхнего угла и
//                длиной стороны;
//               -Rectangle — прямоугольник с заданными координатами верхнего левого угла и
//                размерами;
//               -Circle — окружность с заданными координатами центра и радиусом;
//               -Ellipse — эллипс с заданными координатами верхнего угла описанного вокруг него
//                прямоугольника со сторонами, параллельными осям координат, и размерами этого
//                прямоугольника.
// 
//           Создайте массив фигур, сохраните фигуры в двоичный файл, загрузите в другой массив и
//           отобразите информацию о каждой из фигур.
//



int main()
{
    system("chcp 1251>nul");
    ////////////////////////SAVE///////////////////////////////////////////
   
    cout << "\nМассив фигур для записи в бинарный файл.\n";

    iShape** ptr_shape_to_bin = new iShape * [4] {nullptr};

    ptr_shape_to_bin[0] = new Square(1, 3, 5);
    ptr_shape_to_bin[1] = new Rectangle(5, 4, 8, 3);
    ptr_shape_to_bin[2] = new Circle(3, 5, 8);
    ptr_shape_to_bin[3] = new Ellipse(4, 2, 8, 4);
    
    for (int i = 0; i < 4; i++)
    {
        ptr_shape_to_bin[i]->Show();
        cout << endl;
    }
    cout << endl;
    ofstream to_bin("shapes.dat", ios::binary);

    for (int i = 0; i < 4; i++)
    {
        ptr_shape_to_bin[i]->Save(to_bin); // проверка в методе
    }
    
    to_bin.close();

    for (int i = 0; i < 4; i++)
    {
        delete ptr_shape_to_bin[i];
    }
    delete[] ptr_shape_to_bin;

    ////////////////////////LOAD///////////////////////////////////////////

    cout << "\nМассив фигур прочитанный из бинарного файла.\n";
    iShape** ptr_shape_from_bin = new iShape * [4] {nullptr};

    ptr_shape_from_bin[0] = new Square;
    ptr_shape_from_bin[1] = new Rectangle;
    ptr_shape_from_bin[2] = new Circle;
    ptr_shape_from_bin[3] = new Ellipse;

    ifstream to_shape("shapes.dat", ios::binary);

    for (int i = 0; i < 4; i++)
    {
        ptr_shape_from_bin[i]->Load(to_shape); // проверка в методе
    }

    to_shape.close();

    for (int i = 0; i < 4; i++)
    {
        ptr_shape_from_bin[i]->Show();
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < 4; i++)
    {
        delete ptr_shape_from_bin[i];
    }
    delete[] ptr_shape_from_bin;

    system("pause");
}


