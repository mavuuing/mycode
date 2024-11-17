#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

const int SIZE = 1000; // �������������Ŀ��Ϊ1000

typedef struct {
    int year;           // ���
    float cars;         // ����Դ����������
    float coalconsum;   // ú̿������ռ��
    float pm;           // �����������PM2.5����
} EnergySave;

int totalnume = 0;
EnergySave *eng = new EnergySave[SIZE];

// ���ݶ��뺯��
void Data_Read(char filename[]) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        cout << "���ݶ��뺯�����ļ���ʧ��" << endl;
        return;
    }
    while (fscanf(fp, "%d %f %f %f", &eng[totalnume].year, &eng[totalnume].cars, &eng[totalnume].coalconsum, &eng[totalnume].pm) == 4) {
        totalnume++;
    }
    fclose(fp);
}

// ��ӡ�������
void Print_Energytable(int index) {
    cout << "��ݣ�" << eng[index].year << " "<< "����Դ����������(������)��" << eng[index].cars << " "<< "ú̿������ռ�ȣ�%����" << eng[index].coalconsum << " "<< "����PM2.5��(΢��/������)" << eng[index].pm << endl;
}

// ���ݲ�ѯ����
void Data_Search(int sj) {
    for (int i = 0; i < totalnume; i++) {
        if (sj == eng[i].year) {
            Print_Energytable(i);
            return;
        }
    }
    cout << "δ�ҵ�����ݵ�����" << endl;
}

// �����޸ĺ���
void Data_Modify(int sj, char filename[]) {
    for (int i = 0; i < totalnume; i++) {
        if (sj == eng[i].year) {
            cout << "�����޸ĺ�����ݣ�����Դ����������(������) ú̿������ռ�ȣ�%�� ����PM2.5��΢��/�����ף�" << endl;
            cin >> eng[i].cars >> eng[i].coalconsum >> eng[i].pm;
            // �����ļ��е�����
            ofstream outfile(filename);
            for (int j = 0; j < totalnume; j++) {
                outfile << eng[j].year << " " << eng[j].cars << " " << eng[j].coalconsum << " " << eng[j].pm << endl;
            }
            outfile.close();
            cout << "�����Ѹ���" << endl;
            return;
        }
    }
    cout << "δ�ҵ�����ݵ�����" << endl;
}

// ����ɾ������
void Data_Delete(int sj, char filename[]) {
    bool found = false;
    for (int i = 0; i < totalnume; i++) {
        if (sj == eng[i].year) {
            for (int j = i; j < totalnume - 1; j++) {
                eng[j] = eng[j + 1];
            }
            totalnume--;
            found = true;
            break;
        }
    }
    if (found) {
        // �����ļ��е�����
        ofstream outfile(filename);
        for (int j = 0; j < totalnume; j++) {
            outfile << eng[j].year << " " << eng[j].cars << " " << eng[j].coalconsum << " " << eng[j].pm << endl;
        }
        outfile.close();
        cout << "������ɾ��" << endl;
    } else {
        cout << "δ�ҵ�����ݵ�����" << endl;
    }
}

void Menu_2();

// ���ݲ��뺯��
void Data_Insert(int sj, char filename[]) {
 
        for (int i = 0; i < totalnume; i++) {
            if (sj == eng[i].year) {
                cout << "����ݵ������Ѵ���" << endl;
                return;
            }
        }
        eng[totalnume].year = sj;
        cout << "����������Դ����������(������)��";
        cin >> eng[totalnume].cars;
        cout << "������ú̿������ռ�ȣ�%����";
        cin >> eng[totalnume].coalconsum;
        cout << "�����뱱��PM2.5��(΢��/������)";
        cin >> eng[totalnume].pm;
        totalnume++;

        // �����ļ��е�����
        ofstream outfile(filename, ios::app);
        if (!outfile) {
            cout << "�ļ���ʧ��" << endl;
            return;
        }
        outfile << eng[totalnume - 1].year << " " << eng[totalnume - 1].cars << " " << eng[totalnume - 1].coalconsum << " " << eng[totalnume - 1].pm << endl;
        outfile.close();
        cout << "�����Ѳ���" << endl;
        cout<<"�Ƿ����y/n";
       char ch;
     cin>>ch;
    if (ch == 'y') {
        cout << "��������ݣ�";
        Data_Insert(sj, filename);
    } else {
        Menu_2();
    }
        
    
}

// �˵�����
void Menu_2() {

    cout << "��ӭʹ����Դ���ݲ�ѯϵͳ" << endl;
    cout << "1. ���ݶ���" << endl;
    cout << "2. �����޸�" << endl;
    cout << "3. ����ɾ��" << endl;
    cout << "4. ���ݲ�ѯ" << endl;
    cout << "5. ���ݲ���" << endl;
    cout << "6. �������" << endl;
    cout << "7. �˳�" << endl;
    int n;
    cin >> n;
    switch (n) {
        case 1:
            Data_Read("Data.txt");
            cout << "���ݶ������" << endl;
            break;
        case 2:
            cout << "��������ݣ�";
            int sj1;
            cin >> sj1;
            Data_Modify(sj1, "Data.txt");
            break;
        case 3:
            cout << "��������ݣ�";
            int sj2;
            cin >> sj2;
            Data_Delete(sj2, "Data.txt");
            break;
        case 4:
            cout << "��������ݣ�";
            int sj3;
            cin >> sj3;
            Data_Search(sj3);
            break;
        case 5:
            cout << "��������ݣ�";
            int sj4;
            cin >> sj4;
            Data_Insert(sj4, "Data.txt");
            break;
        case 6:
            for (int i = 0; i < totalnume; i++) {
                Print_Energytable(i);
            }
            break;
        case 7:
            cout << "�����˳�..." << endl;
            delete[] eng;
            exit(0);
        default:
            cout << "��Ч��ѡ��������ѡ��" << endl;
            Menu_2();
            break;
    }
    Menu_2(); // ������ʾ�˵�
}

void Menu_1() {
    int n;
    cout << "��ѡ��: " << endl;
    cout << "1. ��¼" << endl;
    cout << "2. ע��" << endl;
    cout << "3. �˳�" << endl;
    cin >> n;
    if (n == 1 || n == 2) {
        Menu_2();
        cout << "�ɹ���¼" << endl;
    } else {
        cout << "�����˳�..." << endl;
        delete[] eng;
        exit(0);
    }
}

int main() {
    Menu_1();
    return 0;
}