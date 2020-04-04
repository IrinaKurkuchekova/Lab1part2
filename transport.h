#pragma once
//---------------------------------------------------
#ifndef __transport_atd__
#define __transport_atd__

#include <fstream>
using namespace std;
//namespace simple_transport {
    // Класс, обобщающает все имеющиеся фигуры.
    // Является абстрактным, обеспечивая, тем самым,
    // проверку интерфейса
    class transport {
    public:
        // иденитфикация, порождение и ввод фигуры из потока
        static transport* In(ifstream& ifst);
        virtual void InData(ifstream& ifst) = 0; // ввод
        virtual void Out(ofstream& ofst) = 0; // вывод
    };

    class airplane : public transport {
        int range, carrying, speed, distance;
    public:
        // переопределяем интерфейс класса
        void InData(ifstream& ifst); // ввод
        void Out(ofstream& ofst); // вывод
        airplane() {} // создание без инициализации.
    };

    class train : public transport {
        int number, speed, distance;
    public:
        // переопределяем интерфейс класса
        void InData(ifstream& ifst); // ввод
        void Out(ofstream& ofst); // вывод
        train() {} // создание без инициализации.
    };

    struct list {
        transport* tr;
        list* next;
    };

    // Простейший контейнер на основе однонаправленного списка
    class ListContainer {
        enum { max_len = 100 }; // максимальная длина
        int len; // текущая длина
        list* cont;
    public:
        void In(ifstream& ifst); // ввод
        void Out(ofstream& ofst); // вывод
        void Clear(); // очистка контейнера от фигур
        ListContainer(); // инициализация контейнера
        ~ListContainer() { Clear(); } // утилизация контейнера
    };
//} 
#endif

