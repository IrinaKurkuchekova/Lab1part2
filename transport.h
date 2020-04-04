#pragma once
//---------------------------------------------------
#ifndef __transport_atd__
#define __transport_atd__

#include <fstream>
using namespace std;
//namespace simple_transport {
    // �����, ����������� ��� ��������� ������.
    // �������� �����������, �����������, ��� �����,
    // �������� ����������
    class transport {
    public:
        // �������������, ���������� � ���� ������ �� ������
        static transport* In(ifstream& ifst);
        virtual void InData(ifstream& ifst) = 0; // ����
        virtual void Out(ofstream& ofst) = 0; // �����
    };

    class airplane : public transport {
        int range, carrying, speed, distance;
    public:
        // �������������� ��������� ������
        void InData(ifstream& ifst); // ����
        void Out(ofstream& ofst); // �����
        airplane() {} // �������� ��� �������������.
    };

    class train : public transport {
        int number, speed, distance;
    public:
        // �������������� ��������� ������
        void InData(ifstream& ifst); // ����
        void Out(ofstream& ofst); // �����
        train() {} // �������� ��� �������������.
    };

    struct list {
        transport* tr;
        list* next;
    };

    // ���������� ��������� �� ������ ����������������� ������
    class ListContainer {
        enum { max_len = 100 }; // ������������ �����
        int len; // ������� �����
        list* cont;
    public:
        void In(ifstream& ifst); // ����
        void Out(ofstream& ofst); // �����
        void Clear(); // ������� ���������� �� �����
        ListContainer(); // ������������� ����������
        ~ListContainer() { Clear(); } // ���������� ����������
    };
//} 
#endif

