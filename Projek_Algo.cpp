#include <iostream>
using namespace std;

struct node_schedule
{
    char nama_mks[50], hari_mks[50];
    int jmlh_sks_mks, tingkat_kesulitan_mks;
    node_schedule *next; // pointer ke node berikutnya
};

// node linked list assignment
struct node_assignment
{
    char nama_mka[50], hari_mka[50], status[20];
    int jmlh_sks_mka, tingkat_kesulitan_mka;
    node_assignment *next; // pointer ke node berikutnya
};

// buat kepala/head, ekor, bantu linked lisnya
node_schedule *kepala_s = NULL;
node_schedule *ekor_s = NULL;
node_schedule *bantu_s = NULL;
node_assignment *kepala_a = NULL;
node_assignment *ekor_a = NULL;
node_assignment *bantu_a = NULL;

void menu(int &pilmenu)
{

    cout << "============= MENU =============" << endl;
    cout << "================================" << endl;
    cout << "1. Schedule & Assignment Input" << endl;
    cout << "2. Schedule & Assignment Show" << endl;
    cout << "3. Leasson Plan" << endl;
    cout << "4. Check-List Lesson" << endl;
    cout << "5. Notes" << endl;
    cout << "0. Exit Program" << endl;
    cout << "================================" << endl;
    cout << " Select the Menu : ";
    cin >> pilmenu;
    cout << "================================" << endl;
    system("clS");
}

int main(){
    
}