#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

const int SIZE = 1000; // 假设最大数据条目数为1000

typedef struct {
    int year;           // 年份
    float cars;         // 新能源汽车保有量
    float coalconsum;   // 煤炭消费量占比
    float pm;           // 北京近年年均PM2.5数据
} EnergySave;

int totalnume = 0;
EnergySave *eng = new EnergySave[SIZE];

// 数据读入函数
void Data_Read(char filename[]) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        cout << "数据读入函数，文件打开失败" << endl;
        return;
    }
    while (fscanf(fp, "%d %f %f %f", &eng[totalnume].year, &eng[totalnume].cars, &eng[totalnume].coalconsum, &eng[totalnume].pm) == 4) {
        totalnume++;
    }
    fclose(fp);
}

// 打印输出函数
void Print_Energytable(int index) {
    cout << "年份：" << eng[index].year << " "<< "新能源汽车保有量(百万辆)：" << eng[index].cars << " "<< "煤炭消费量占比（%）：" << eng[index].coalconsum << " "<< "北京PM2.5：(微克/立方米)" << eng[index].pm << endl;
}

// 数据查询函数
void Data_Search(int sj) {
    for (int i = 0; i < totalnume; i++) {
        if (sj == eng[i].year) {
            Print_Energytable(i);
            return;
        }
    }
    cout << "未找到该年份的数据" << endl;
}

// 数据修改函数
void Data_Modify(int sj, char filename[]) {
    for (int i = 0; i < totalnume; i++) {
        if (sj == eng[i].year) {
            cout << "输入修改后的数据：新能源汽车保有量(百万辆) 煤炭消费量占比（%） 北京PM2.5（微克/立方米）" << endl;
            cin >> eng[i].cars >> eng[i].coalconsum >> eng[i].pm;
            // 更新文件中的数据
            ofstream outfile(filename);
            for (int j = 0; j < totalnume; j++) {
                outfile << eng[j].year << " " << eng[j].cars << " " << eng[j].coalconsum << " " << eng[j].pm << endl;
            }
            outfile.close();
            cout << "数据已更新" << endl;
            return;
        }
    }
    cout << "未找到该年份的数据" << endl;
}

// 数据删除函数
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
        // 更新文件中的数据
        ofstream outfile(filename);
        for (int j = 0; j < totalnume; j++) {
            outfile << eng[j].year << " " << eng[j].cars << " " << eng[j].coalconsum << " " << eng[j].pm << endl;
        }
        outfile.close();
        cout << "数据已删除" << endl;
    } else {
        cout << "未找到该年份的数据" << endl;
    }
}

void Menu_2();

// 数据插入函数
void Data_Insert(int sj, char filename[]) {
 
        for (int i = 0; i < totalnume; i++) {
            if (sj == eng[i].year) {
                cout << "该年份的数据已存在" << endl;
                return;
            }
        }
        eng[totalnume].year = sj;
        cout << "请输入新能源汽车保有量(百万辆)：";
        cin >> eng[totalnume].cars;
        cout << "请输入煤炭消费量占比（%）：";
        cin >> eng[totalnume].coalconsum;
        cout << "请输入北京PM2.5：(微克/立方米)";
        cin >> eng[totalnume].pm;
        totalnume++;

        // 更新文件中的数据
        ofstream outfile(filename, ios::app);
        if (!outfile) {
            cout << "文件打开失败" << endl;
            return;
        }
        outfile << eng[totalnume - 1].year << " " << eng[totalnume - 1].cars << " " << eng[totalnume - 1].coalconsum << " " << eng[totalnume - 1].pm << endl;
        outfile.close();
        cout << "数据已插入" << endl;
        cout<<"是否继续y/n";
       char ch;
     cin>>ch;
    if (ch == 'y') {
        cout << "请输入年份：";
        Data_Insert(sj, filename);
    } else {
        Menu_2();
    }
        
    
}

// 菜单函数
void Menu_2() {

    cout << "欢迎使用能源数据查询系统" << endl;
    cout << "1. 数据读入" << endl;
    cout << "2. 数据修改" << endl;
    cout << "3. 数据删除" << endl;
    cout << "4. 数据查询" << endl;
    cout << "5. 数据插入" << endl;
    cout << "6. 数据输出" << endl;
    cout << "7. 退出" << endl;
    int n;
    cin >> n;
    switch (n) {
        case 1:
            Data_Read("Data.txt");
            cout << "数据读入完成" << endl;
            break;
        case 2:
            cout << "请输入年份：";
            int sj1;
            cin >> sj1;
            Data_Modify(sj1, "Data.txt");
            break;
        case 3:
            cout << "请输入年份：";
            int sj2;
            cin >> sj2;
            Data_Delete(sj2, "Data.txt");
            break;
        case 4:
            cout << "请输入年份：";
            int sj3;
            cin >> sj3;
            Data_Search(sj3);
            break;
        case 5:
            cout << "请输入年份：";
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
            cout << "正在退出..." << endl;
            delete[] eng;
            exit(0);
        default:
            cout << "无效的选择，请重新选择" << endl;
            Menu_2();
            break;
    }
    Menu_2(); // 继续显示菜单
}

void Menu_1() {
    int n;
    cout << "请选择: " << endl;
    cout << "1. 登录" << endl;
    cout << "2. 注册" << endl;
    cout << "3. 退出" << endl;
    cin >> n;
    if (n == 1 || n == 2) {
        Menu_2();
        cout << "成功登录" << endl;
    } else {
        cout << "正在退出..." << endl;
        delete[] eng;
        exit(0);
    }
}

int main() {
    Menu_1();
    return 0;
}