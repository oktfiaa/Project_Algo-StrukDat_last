#include <iostream>
#include <cstring>
using namespace std;

int menu_input_1, menu_show_2;

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

struct PrioritasPlan
{
    char nama_mks[50];
    char hari[50];
    int sks, kesulitan, skor;
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

void clearLL_Assignment()
{
    node_assignment *current = kepala_a;
    while (current != NULL)
    {
        node_assignment *hapus = current;
        current = current->next;
        delete hapus;
    }
    kepala_a = NULL;
}

void assignmentLL(string nama_mka, string hari_mka, int jmlh_sks_mka, int tingkat_kesulitan_mka, string status)
{
    node_assignment *baru_a = new node_assignment(); // baut node baru
    strncpy(baru_a->nama_mka, nama_mka.c_str(), sizeof(baru_a->nama_mka));
    strncpy(baru_a->hari_mka, hari_mka.c_str(), sizeof(baru_a->hari_mka));
    baru_a->jmlh_sks_mka = jmlh_sks_mka;
    baru_a->tingkat_kesulitan_mka = tingkat_kesulitan_mka;
    strncpy(baru_a->status, status.c_str(), sizeof(baru_a->status));
    baru_a->next = NULL;
    kepala_a = ekor_a = baru_a;
}

void TambahAkhirAssignment(string nama_mka, string hari_mka, int jmlh_sks_mka, int tingkat_kesulitan_mka, string status)
{
    node_assignment *baru_a = new node_assignment();
    strncpy(baru_a->nama_mka, nama_mka.c_str(), sizeof(baru_a->nama_mka));
    strncpy(baru_a->hari_mka, hari_mka.c_str(), sizeof(baru_a->hari_mka));
    baru_a->jmlh_sks_mka = jmlh_sks_mka;
    baru_a->tingkat_kesulitan_mka = tingkat_kesulitan_mka;
    strncpy(baru_a->status, status.c_str(), sizeof(baru_a->status));
    baru_a->next = NULL;
    if (kepala_a == NULL)
    {
        kepala_a = ekor_a = baru_a;
    }
    else
    {
        ekor_a->next = baru_a;
        ekor_a = baru_a;
    }
}

void swapString(char *a, char *b)
{
    char temp[50];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

void sorting_schedule_tingkat_kesulitan()
{
    if (kepala_s == NULL)
    {
        return;
    }

    bool swapped;
    node_schedule *start_pointer;
    node_schedule *last_pointer = NULL;

    do
    {
        swapped = false;
        start_pointer = kepala_s;

        while (start_pointer->next != last_pointer)
        {
            if (start_pointer->tingkat_kesulitan_mks > start_pointer->next->tingkat_kesulitan_mks)
            {
                swapString(start_pointer->nama_mks, start_pointer->next->nama_mks);
                swapString(start_pointer->hari_mks, start_pointer->next->hari_mks);
                swap(start_pointer->jmlh_sks_mks, start_pointer->next->jmlh_sks_mks);
                swap(start_pointer->tingkat_kesulitan_mks, start_pointer->next->tingkat_kesulitan_mks);
                swapped = true;
            }
            start_pointer = start_pointer->next;
        }
        last_pointer = start_pointer;
    } while (swapped);
}

void file_schedule()
{
    FILE *file = fopen("schedule_data.txt", "wb");
    if (file != NULL)
    {
        bantu_s = kepala_s;
        while (bantu_s != NULL)
        {
            fwrite(bantu_s, sizeof(node_schedule) - sizeof(node_schedule *), 1, file);
            bantu_s = bantu_s->next;
        }
        fclose(file);
        cout << "Schedule data successfully saved in schedule_data.txt file!" << endl;
    }
    else
    {
        cout << "Failed to open the file to save the schedule data!";
    }
}

void read_file_schedule()
{
    clearLL_Schedule();
    FILE *file = fopen("schedule_data.txt", "rb");
    if (file == NULL)
    {
        cout << "Failed to open the file to save the schedule data!";
        return;
    }

    kepala_s = ekor_s = NULL;

    while (true)
    {
        node_schedule *newS = new node_schedule();
        int read = fread(newS, sizeof(node_schedule) - sizeof(node_schedule *), 1, file);

        if (read != 1)
        {
            delete newS;
            break;
        }

        newS->next = NULL;

        if (kepala_s == NULL)
        {
            kepala_s = ekor_s = newS;
        }
        else
        {
            ekor_s->next = newS;
            ekor_s = newS;
        }
    }

    fclose(file);
}

void file_assignment()
{
    FILE *file = fopen("assignment_data.txt", "wb");
    if (file != NULL)
    {
        bantu_a = kepala_a;
        while (bantu_a != NULL)
        {
            fwrite(bantu_a, sizeof(node_assignment) - sizeof(node_assignment *), 1, file);
            bantu_a = bantu_a->next;
        }
        fclose(file);
        cout << "Assignment data successfully saved in assignment_data.txt file!" << endl;
    }
    else
    {
        cout << "Failed to open the file to save the assignment data!";
    }
}

void read_file_assignment()
{
    FILE *file = fopen("assignment_data.txt", "rb");
    if (file == NULL)
    {
        cout << "Failed to open the file to save the assignment data!";
        return;
    }

    kepala_a = ekor_a = NULL;

    while (true)
    {
        node_assignment *newA = new node_assignment();
        int read = fread(newA, sizeof(node_assignment) - sizeof(node_assignment *), 1, file);

        if (read != 1)
        {
            delete newA;
            break;
        }

        newA->next = NULL;

        if (kepala_a == NULL)
        {
            kepala_a = ekor_a = newA;
        }
        else
        {
            ekor_a->next = newA;
            ekor_a = newA;
        }
    }

    fclose(file);
}

void cetakSchedule()
{
    sorting_schedule_tingkat_kesulitan();
    if (kepala_s == NULL)
    {
        cout << "Empty Linked List\n";
    }
    else
    {
        bantu_s = kepala_s;
        int i = 0;
        cout << "=====================================YOUR SCHEDULE=====================================" << endl;
        while (bantu_s != NULL)
        {
            cout << "        " << i + 1 << ". " << bantu_s->nama_mks
                 << " | Day : " << bantu_s->hari_mks
                 << " | Total of SKS : " << bantu_s->jmlh_sks_mks
                 << " | Dificulty Level : " << bantu_s->tingkat_kesulitan_mks << endl;
            bantu_s = bantu_s->next;
            i++;
        }
        cout << "=======================================================================================" << endl;
    }
}

void cetakAssignment()
{
    read_file_assignment();
    if (kepala_a == NULL)
    {
        cout << "Empty Linked List\n";
    }
    else
    {
        bantu_a = kepala_a;
        int i = 0;
        cout << "====================================YOUR ASSIGNMENT====================================" << endl;
        while (bantu_a != NULL)
        {
            cout << i + 1 << ". " << bantu_a->nama_mka
                 << " | Day : " << bantu_a->hari_mka
                 << " | Total of SKS : " << bantu_a->jmlh_sks_mka
                 << " | Dificulty Level : " << bantu_a->tingkat_kesulitan_mka
                 << " | Status : " << bantu_a->status << endl;
            bantu_a = bantu_a->next;
            i++;
        }
        cout << "=======================================================================================" << endl;
    }
}

void cek_lesson_priority()
{
    FILE *file = fopen("schedule_data.txt", "rb");
    if (file == NULL)
    {
        cout << "Failed to open the file to save the schedule data!" << endl;
        return;
    }

    PrioritasPlan Plan[999];
    int count = 0;

    while (true)
    {
        node_schedule *cek = new node_schedule();
        int read = fread(cek, sizeof(node_schedule) - sizeof(node_schedule *), 1, file);
        if (read != 1)
        {
            delete cek;
            break;
        }

        PrioritasPlan data;
        strcpy(data.nama_mks, cek->nama_mks);
        data.sks = cek->jmlh_sks_mks;
        data.kesulitan = cek->tingkat_kesulitan_mks;
        // data.hari = konversiHari(cek->hari_mks);
        strcpy(data.hari, cek->hari_mks);
        data.skor = data.sks * 100 + data.kesulitan * 10;
        Plan[count++] = data;
        delete cek;
    }
    fclose(file);

    if (count == 0)
    {
        cout << "Tidak ada data schedule yang bisa diproses.\n";
        return;
    }

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (Plan[j].skor > Plan[i].skor)
            {
                swap(Plan[i], Plan[j]);
            }
        }
    }

    cout << "====================== LESSON PLAN PRIORITY ======================" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << i + 1 << ". " << Plan[i].nama_mks
             << " | SKS: " << Plan[i].sks
             << " | Kesulitan: " << Plan[i].kesulitan
             << " | Hari nilai: " << Plan[i].hari
             << " | Skor: " << Plan[i].skor << endl;
    }
    cout << "==================================================================" << endl;
}

void lesson_plan()
{
    int pil_lesson, difficulty, sks;
    string deleteScheduleName, day;
    do
    {
        cout << "=======================" << endl;
        cout << "1. Priority lessons" << endl;
        cout << "2. Delete lesson" << endl;
        cout << "3. Return to main menu" << endl;
        cout << "=======================" << endl;
        cout << "Choose : ";
        cin >> pil_lesson;
        system("clear");

        switch (pil_lesson)
        {
        case 1:
            // cek_lesson_priority();
            break;

        case 2:
            read_file_schedule();
            // cek_lesson_priority();
            cout << "Enter schedule name to delete : ";
            cin.ignore(); // untuk bersihkan buffer
            getline(cin, deleteScheduleName);
            cout << "Schedule credit : ";
            cin >> sks;
            cout << "Schedule difficulty : ";
            cin >> difficulty;
            cout << "Schedule day : ";
            cin.ignore();
            getline(cin, day);
            system("clear");
            // hapus_lesson(deleteScheduleName.c_str(), day.c_str(), sks, difficulty);
            break;

        case 3:
            system("clear");
            return;
            break;

        default:
            break;
        }
    } while (pil_lesson != 3);
}

void menu_input(int &pilih_menu_input)
{
    do
    {
        string nama_mks, hari_mks, nama_mka, hari_mka, status;
        int jmlh_inputs, jmlh_inputa, jmlh_sks_mks, tingkat_kesulitan_mks, jmlh_sks_mka, tingkat_kesulitan_mka;
        // int totals = 0;
        // int totala = 0;

        cout << "===============================" << endl;
        cout << "Choose input menu : " << endl;
        cout << "===============================" << endl;
        cout << "1. Schedule input" << endl;
        cout << "2. Assigment input" << endl;
        cout << "3. Return to main menu" << endl;
        cout << "===============================" << endl;
        cout << "Choose input menu : ";
        cin >> menu_input_1;
        cin.ignore();
        system("clear");
        switch (menu_input_1)
        {
        case 1:
            read_file_schedule();
            cout << "Enter shedule quantity : ";
            cin >> jmlh_inputs;
            cin.ignore();

            for (int i = 0; i < jmlh_inputs; i++)
            {
                cout << "================INPUT SCEDULE================\n";
                cout << "Input the course name : ";
                getline(cin, nama_mks);
                cout << "Day : ";
                getline(cin, hari_mks);
                cout << "Total of SKS : ";
                cin >> jmlh_sks_mks;
                cout << "Level of difficulty [1-10]: ";
                cin >> tingkat_kesulitan_mks;
                cin.ignore();
                cout << "=============================================\n";

                if (kepala_s == NULL)
                {
                    scheduleLL(nama_mks, hari_mks, jmlh_sks_mks, tingkat_kesulitan_mks);
                }
                else
                {
                    TambahAkhirSchedule(nama_mks, hari_mks, jmlh_sks_mks, tingkat_kesulitan_mks);
                }
            }
            system("clear");
            file_schedule();
            // totals += jmlh_inputs;
            // system("clear");

            break;

        case 2:
            read_file_assignment();
            cout << "Enter assignment quantity : ";
            cin >> jmlh_inputa;
            cin.ignore();

            for (int j = 0; j < jmlh_inputa; j++)
            {
                cout << "==============INPUT ASSIGNMENT==============\n";
                cout << "Input the course name : ";
                getline(cin, nama_mka);
                cout << "Deadline : ";
                getline(cin, hari_mka);
                cout << "Total of SKS : ";
                cin >> jmlh_sks_mka;
                cout << "Level of difficulty [1-10]: ";
                cin >> tingkat_kesulitan_mka;
                cin.ignore();
                // cout << "Status : ";
                // getline(cin, status);
                status = "Unfinished";
                cout << "============================================\n";

                if (kepala_a == NULL)
                {
                    assignmentLL(nama_mka, hari_mka, jmlh_sks_mka, tingkat_kesulitan_mka, status);
                }
                else
                {
                    TambahAkhirAssignment(nama_mka, hari_mka, jmlh_sks_mka, tingkat_kesulitan_mka, status);
                }
            }
            system("clear");
            file_assignment();
            // totala += jmlh_inputa;

            break;

        case 3: // kembali ke menu utama
            system("clear");
            return;
            break;

        default:
            // cout << "Please select available input menu : " << endl;
            break;
        }
    } while (menu_input_1 != 3);
}

void menu_show(int pilih_menu_show)
{
    do
    {
        getchar();
        cout << "========================" << endl;
        cout << "Choose show menu : " << endl;
        cout << "========================" << endl;
        cout << "1. Schedule show" << endl;
        cout << "2. Assigment show" << endl;
        cout << "3. Return to main menu" << endl;
        cout << "========================" << endl;
        cout << "Choose show menu : ";
        cin >> menu_show_2;
        system("clear");
        switch (menu_show_2)
        {
        case 1:
            clearLL_Schedule();
            read_file_schedule();
            cetakSchedule();
            break;

        case 2:
            clearLL_Assignment();
            read_file_assignment();
            cetakAssignment();
            break;

        case 3:
            getchar();
            system("clear");
            return;
            break;

        default:
            break;
        }
    } while (menu_show_2 != 3);

    system("clear");
}

int main(){
    
}