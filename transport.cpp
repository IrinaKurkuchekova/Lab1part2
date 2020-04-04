//---------------------------------------------------
#include <iostream>
#include <fstream>
#include "transport.h"
using namespace std;

//namespace simple_transport {
    // Ввод параметров самолета из файла
    void airplane::InData(ifstream& ifst) {
        ifst >> range >> carrying >> speed >> distance;
    }

    // Вывод параметров самолета в поток
    void airplane::Out(ofstream& ofst) {
        ofst << "It is Airplane: range = " << range
            << ", carrying = " << carrying
            << ", speed = " << speed
            << ", distance = " << distance
            << endl;
    }

    // Ввод параметров поезда из потока
    void train::InData(ifstream& ifst) {
        ifst >> number >> speed >> distance;
    }

    // Вывод параметров поезда в поток
    void train::Out(ofstream& ofst) {
        ofst << "It is Train: number = "
            << number << ", speed = " << speed
            << ", distance = " << distance << endl;
    }

    // Ввод параметров обобщенного транспорта из файла
    transport* transport::In(ifstream& ifst) {
        transport* tr;
        int k;
        ifst >> k;
        switch (k) {
        case 1:
            tr = new airplane;
            break;
        case 2:
            tr = new train;
            break;
        default:
            return 0;
        }
        tr->InData(ifst);
        return tr;
    }


    // Инициализация контейнера
    ListContainer::ListContainer() : len(0) { }

    // Очистка контейнера от элементов
    // (освобождение памяти)
    void ListContainer::Clear()
    {
        list* l = nullptr;
        list* l_next;
        for (int i = 0; i < len; i++)
        {
            if (i == 0)
                l = cont;
            l_next = l->next;
            delete l;
            l = l_next;
        }
        len = 0;
    }

    // Ввод содержимого контейнера из указанного потока
    void ListContainer::In(ifstream& ifst)
    {
        list* l;
        list* l_prev = nullptr;
        while (!ifst.eof())
        {
            transport* tr = transport::In(ifst);
            if (tr != 0)
            {
                l = new list;
                l->tr = tr;
                if (len > 0)
                    l_prev->next = l;
                else
                    cont = l;
                l_prev = l;
                len++;
            }
        }
    }

    // Вывод содержимого контейнера в указанный поток
    void ListContainer::Out(ofstream& ofst)
    {
        list* l = nullptr;
        list* l_next;

        ofst << "Container contains " << len
            << " elements." << endl;
        for (int i = 0; i < len; i++)
        {
            ofst << i << ": ";
            if (i == 0)
                l = cont;
            l->tr->Out(ofst);
            l_next = l->next;
            l = l_next;
        }
    }

//} // end simple_transport namespace