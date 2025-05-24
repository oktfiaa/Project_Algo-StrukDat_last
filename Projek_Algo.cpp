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

void scheduleLL(string nama_mks, string hari_mks, int jmlh_sks_mks, int tingkat_kesulitan_mks)
{
    node_schedule *baru_s = new node_schedule; // buat node baru
    strncpy(baru_s->nama_mks, nama_mks.c_str(), sizeof(baru_s->nama_mks));
    strncpy(baru_s->hari_mks, hari_mks.c_str(), sizeof(baru_s->hari_mks));
    baru_s->jmlh_sks_mks = jmlh_sks_mks;
    baru_s->tingkat_kesulitan_mks = tingkat_kesulitan_mks;

    baru_s->next = NULL;
    kepala_s = ekor_s = baru_s;
}

void TambahAkhirSchedule(string nama_mks, string hari_mks, int jmlh_sks_mks, int tingkat_kesulitan_mks)
{
    node_schedule *baru_s = new node_schedule();
    strncpy(baru_s->nama_mks, nama_mks.c_str(), sizeof(baru_s->nama_mks));
    strncpy(baru_s->hari_mks, hari_mks.c_str(), sizeof(baru_s->hari_mks));
    baru_s->jmlh_sks_mks = jmlh_sks_mks;
    baru_s->tingkat_kesulitan_mks = tingkat_kesulitan_mks;
    baru_s->next = NULL;
    if (kepala_s == NULL)
    {
        kepala_s = ekor_s = baru_s;
    }
    else
    {
        ekor_s->next = baru_s;
        ekor_s = baru_s;
    }
}

void clearLL_Schedule()
{
    node_schedule *current = kepala_s;
    while (current != NULL)
    {
        node_schedule *hapus = current;
        current = current->next;
        delete hapus;
    }
    kepala_s = NULL;
}

int main(){
    
}