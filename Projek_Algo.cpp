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

void clsLL_Schedule()
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

void clsLL_Assignment()
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
    clsLL_Schedule();
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

//MENU 5 NOTES
struct node_notes
{ // konsepnya user isi notes dan disimpan di file pointer 
    char isinotes[9999], judulnotes[999], tanggal[20];
    node_notes *next;
};

node_notes *kepala_n = NULL; // buat kepala node notes
node_notes *ekor_n = NULL;   // buat ekor node notes
node_notes *bantu_n = NULL;

void clsNotes(){
    node_notes *current = kepala_n;
    while (current != NULL)
    {
        node_notes *hapus = current;
        current = current->next;
        delete hapus;
    }
    kepala_n = NULL;
    ekor_n = NULL;
}

void baca_notes() {
    clsNotes();

    FILE *file= fopen("notes.txt", "rb");
    if(file == NULL){
        return;
    }

    // kepala_n = ekor_n = NULL;

    while(true){
        node_notes *baru_n = new node_notes;

        int read = fread(baru_n, sizeof(node_notes) - sizeof(node_notes*), 1, file);

        if(read != 1){
            delete baru_n;
            break;
        }

        baru_n->next = NULL;

        if(kepala_n == NULL){
            kepala_n = ekor_n = baru_n;
        }else{
            ekor_n->next = baru_n;
            ekor_n = baru_n;
        }
    }

    fclose(file);
}

void simpan_notes_ke_file() {
    FILE *file = fopen("notes.txt", "wb");
    if (file != NULL) {
        node_notes *bantu_n = kepala_n;
        while (bantu_n != NULL) {
            fwrite(bantu_n, sizeof(node_notes) - sizeof(node_notes*), 1, file);
            bantu_n = bantu_n->next;
        }
        fclose(file);
    } else {
        cout << "Failed to save notes to file!" << endl;
    }
}

void input_notes()
{
    baca_notes();

    node_notes *baru_n = new node_notes;
    baru_n->next = NULL;

    cin.ignore(); 

    cout << "Tittle : ";
    cin.getline(baru_n->judulnotes, sizeof(baru_n->judulnotes));

    cout << "Write your note : ";
    cin.getline(baru_n->isinotes, sizeof(baru_n->isinotes));

    cout << "Date [yyyy-mm-dd]: "; 
    cin.getline(baru_n->tanggal, sizeof(baru_n->tanggal));

    // cin.get();
    // system("cls");

    if (kepala_n == NULL) {
        kepala_n = ekor_n = baru_n;
    } else {
        ekor_n->next = baru_n;
        ekor_n = baru_n;
    }

    simpan_notes_ke_file();

    cout << "Note saved to file: notes.txt" << endl;
}

void cetak_notes()
{
    baca_notes();

    node_notes *bantu_n = kepala_n;
    if (bantu_n == NULL) {
        cout << "No notes found." << endl;
        return;
    }

    int i = 1;
    while (bantu_n != NULL)
    {
        cout << "=============== Note" << i << "=============" << endl;
        cout << "Tittle  : " << bantu_n->judulnotes << endl;
        cout << "Content  : " << bantu_n->isinotes << endl;
        cout << "Date  : " << bantu_n->tanggal << endl;
        cout << "====================================\n";
        bantu_n = bantu_n->next;
        i++;
    }
    cin.get();
    system("cls");
}

void sort_notes_by_date(){
    baca_notes();

    if (kepala_n == NULL) {
        cout << "No notes to sort." << endl;
        return;
    }

    //pindah linked list ke array
    node_notes *NOTES[9999];
    int count = 0;
    bantu_n = kepala_n;
    while (bantu_n != NULL && count < 9999) {
        NOTES[count++] = bantu_n;
        bantu_n = bantu_n->next;
    }


    //bubble sort by date
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (strcmp(NOTES[j]->tanggal, NOTES[j + 1]->tanggal) > 0) {
                swap(NOTES[j], NOTES[j + 1]);
            }
        }
    }


    cout << "====================== Note ======================" << endl;
    for (int i = 0; i < count; i++) {
        cout << "Tittle  : " << NOTES[i]->judulnotes << endl;
        cout << "Content : " << NOTES[i]->isinotes << endl;
        cout << "Date    : " << NOTES[i]->tanggal << endl;
        cout << "===============================================" << endl;
    }
}

//sequential
void search_notes_by_tittle(){
    baca_notes();

    if (kepala_n == NULL) {
        cout << "Notes empty" << endl;
        return;
    }

    cin.ignore();
    char cari[9999];
    cout << "Write the title of the notes to search : ";
    cin.getline(cari, sizeof(cari));

    node_notes *bantu_n = kepala_n;
    bool found = false;

    while (bantu_n != NULL)
    {
        if (strcmp (bantu_n -> judulnotes, cari) == 0)
        {
            cout << "====================== Notes ======================" << endl;
            cout << "Tittle  : " << bantu_n->judulnotes << endl;
            cout << "Content : " << bantu_n->isinotes << endl;
            cout << "Date    : " << bantu_n->tanggal << endl;
            cout << "===============================================" << endl;
            found = true;
            break;
        }
        bantu_n = bantu_n -> next;
        // cin.get();
        // system("cls");
    }
    if (!found)
    {
        cout << "Note with title " << cari << " not found" << endl;
        cout << "Click Enter to return the Notes Menu" << endl;
        // cin.get();
        // system("cls");
    }
}

void hapus_notes(){
    baca_notes();

    if (kepala_n == NULL) {
        cout << "Notes empty" << endl;
        return;
    }

    char cari_hapus[9999];
    cin.ignore();

    cout << "Enter the title of the note to be deleted :";
    cin.getline(cari_hapus, sizeof(cari_hapus));


    if (strcmp(kepala_n->judulnotes, cari_hapus) == 0) {
        node_notes* hapus = kepala_n;
        kepala_n = kepala_n->next;
        if (hapus == ekor_n) { 
            ekor_n = NULL;
        }
        delete hapus;
        cout << "Note with tittle " << cari_hapus << " successfully deleted" << endl;
        cout << "Click Enter to return the Notes Menu" << endl;
        simpan_notes_ke_file();
        return;
    } else {
        node_notes* bantu_n = kepala_n;
        bool deleted = false;

        // Loop sampai bantu_n->next bernilai NULL (jangan sampai NULL saat akses .next)
        while (bantu_n->next != NULL) {
            if (strcmp(bantu_n->next->judulnotes, cari_hapus) == 0) {
                node_notes* hapus = bantu_n->next;
                bantu_n->next = hapus->next;

                if (hapus == ekor_n) {
                    ekor_n = bantu_n;
                }

                delete hapus;
                cout << "Note with tittle " << cari_hapus << " successfully deleted" << endl;
                cout << "Click Enter to return the Notes Menu" << endl;
                deleted = true;
                simpan_notes_ke_file();
                break;
            }
            bantu_n = bantu_n->next;
        }
        if (!deleted) {
            cout << "Note with title \"" << cari_hapus << "\" not found." << endl;
            cout << "Click Enter to return the Notes Menu" << endl;
            cin.get();
        }
    }
}

void menu_notes(){
    int menu_notes_3;
    do
    {
        // getchar();
        cout << "========================" << endl;
        cout << "Choose notes menu : " << endl;
        cout << "========================" << endl;
        cout << "1. Input note" << endl;
        cout << "2. Show note by asc date" << endl;
        cout << "3. Search note by tittle" << endl;
        cout << "4. Delete note" << endl;
        cout << "5. Return to main menu" << endl;
        cout << "========================" << endl;
        cout << "Choose show menu : ";
        cin >> menu_notes_3;
        // getchar();
        system("cls");
        switch (menu_notes_3)
        {
        case 1:
            input_notes();
            break;

        case 2:
            sort_notes_by_date();
            // system("cls");
            break;

        case 3 : 
            search_notes_by_tittle();
            // system("cls");
            break;

        case 4 : 
            hapus_notes();
            break;

        case 5:
            getchar();
            system("cls");
            return;
            break;

        default:
            break;
        }
    } while (menu_show_2 != 5);

    system("cls");
}

int konversiHari(char *hari)
{
    string h = hari;

    if (h == "Monday" or h == "monday")
        return 1;
    else if (h == "Tuesday" or h == "tuesday")
        return 2;
    else if (h == "Wednesday" or h == "wednesday")
        return 3;
    else if (h == "Thursday" or h == "thursday")
        return 4;
    else if (h == "Friday" or h == "friday")
        return 5;
    else if (h == "Saturday" or h == "saturday")
        return 6;
    else if (h == "Sunday" or h == "sunday")
        return 7;
    else
        return 8;
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

void hapus_lesson(const char *namaSchedule,const char* day, int sks, int difficulty)
{

    node_schedule *current = kepala_s;
    node_schedule *prev = NULL;

    while (current != NULL)
    {
        if ((strcmp(current->nama_mks, namaSchedule) == 0) && 
            (strcmp(current->hari_mks, day) == 0) &&
            (current->jmlh_sks_mks == sks) &&
            (current->tingkat_kesulitan_mks == difficulty))
        {
            if (current == kepala_s)
            {
                kepala_s = kepala_s->next;
                if (current == ekor_s)
                {
                    ekor_s = NULL;
                }
            }
            else
            {
                if (prev != NULL)
                {
                    prev->next = current->next;
                    if (current == ekor_s)
                    {
                        ekor_s = prev;
                    }
                }
            }
            delete current;
            file_schedule();
            cout << "Data \"" << namaSchedule << "\" berhasil dihapus dan file diperbarui.\n";
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Data \"" << namaSchedule << "\" tidak ditemukan.\n";
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
        system("cls");

        switch (pil_lesson)
        {
        case 1:
            cek_lesson_priority();
            break;

        case 2:
            read_file_schedule();
            cek_lesson_priority();
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
            system("cls");
            hapus_lesson(deleteScheduleName.c_str(), day.c_str(), sks, difficulty);
            break;

        case 3:
            system("cls");
            return;
            break;

        default:
            break;
        }
    } while (pil_lesson != 3);
}

void mark()
{
    string assignment_name, day;
    int SKS, difficulty;
    char sure_or_not;

    read_file_assignment();
    cetakAssignment();
    node_assignment *bantucek = kepala_a;

    while (bantucek != NULL)
    {
        /*MENU UNTUK "ENTER ASSIGNMENT YOU WANT TO CHECKLIST. NANTI DI DALA
        MNYA DITANYAIN YAKIN ATAU TIDAK, KALAU TIDAK NANTI RETURN. KALAU YAKIN LANJUT"*/

        while (true)
        {
            cout << "Assignment name to checklist : ";
            cin >> assignment_name;
            cout << "Deadline : ";
            cin >> day;
            cout << "SKS amount : ";
            cin >> SKS;
            cout << "Difficulty level : ";
            cin >> difficulty;
            cout << "Type 'Y/y' to confirm completion, or 'N/n' to cancel: ";
            cin >> sure_or_not;
            system("cls");
            if (sure_or_not == 'Y' || sure_or_not == 'y')
            {
                bool found = false;
                bantucek = kepala_a;

                while (bantucek != NULL)
                {
                    if (bantucek->nama_mka == assignment_name && bantucek->hari_mka == day && bantucek->jmlh_sks_mka == SKS && bantucek->tingkat_kesulitan_mka == difficulty)
                    {
                        if (strcmp(bantucek->status, "Finished") == 0)
                        {
                            cout << "INFO : Assignment status already setted to 'finished'!" << endl;
                        }
                        else
                        {
                            strcpy(bantucek->status, "Finished");
                            found = true;
                            cout << "INFO : Assignment status updated to 'finished'!" << endl;
                            file_assignment();
                            return;
                        }
                        return;
                    }
                    bantucek = bantucek->next;
                    system("cls");
                }

                if (!found)
                {
                    cout << "No matching assignment found.\n";
                    return;
                }
            }
            else if (sure_or_not == 'N' || sure_or_not == 'n')
            {
                system("cls");
                return;
            }
            else
            {
                cout << "Invalid input. Please type 'Y' to confirm or 'N' to cancel.\n";
                cin.ignore();
                cin.get();
                system("cls");
            }
        }
    }
}

void revert()
{
    string assignment_name, day;
    int SKS, difficulty;
    char sure_or_not;

    read_file_assignment();
    cetakAssignment();

    while (true)
    {
        cout << "Assignment name to revert checklist : ";
        cin >> assignment_name;
        cout << "Deadline : ";
        cin >> day;
        cout << "SKS amount : ";
        cin >> SKS;
        cout << "Difficulty level : ";
        cin >> difficulty;
        cout << "Type 'Y/y' to revert assignment status, or 'N/n' to cancel: ";
        cin >> sure_or_not;
        system("cls");
        if (sure_or_not == 'Y' || sure_or_not == 'y')
        {
            node_assignment *helpcek = kepala_a; // reset pointer setiap input

            bool found = false;
            while (helpcek != NULL)
            {
                if (strcmp(helpcek->nama_mka, assignment_name.c_str()) == 0 &&
                    strcmp(helpcek->hari_mka, day.c_str()) == 0 &&
                    helpcek->jmlh_sks_mka == SKS &&
                    helpcek->tingkat_kesulitan_mka == difficulty &&
                    strcmp(helpcek->status, "Finished") == 0)
                {
                    strcpy(helpcek->status, "Unfinished");
                    cout << "INFO : Status reverted to 'Unfinished'.\n";
                    found = true;
                    file_assignment(); // simpan setelah update
                    return;
                }
                helpcek = helpcek->next;
                system("cls");
            }

            if (!found)
            {
                cout << "No matching finished assignment found.\n";
            }
        }
        else if (sure_or_not == 'N' || sure_or_not == 'n')
        {
            system("cls");
            return;
        }
        else
        {
            cout << "Invalid input. Please type 'Y' to revert status or 'N' to cancel.\n";
            cin.ignore();
            cin.get();
            system("cls");
        }
    }
}

void show_unfinished()
{
    read_file_assignment();
    node_assignment *current = kepala_a;
    node_assignment *last = ekor_a;

    int i = 0;
    cout << "\n=====================UNFINISHED ASSIGNMENT========================" << endl;
    while (current != NULL)
    {
        if (strcmp(current->status, "Unfinished") == 0)
        {
            cout << i + 1 << ". " << current->nama_mka
                 << " | Day : " << current->hari_mka
                 << " | Total of SKS : " << current->jmlh_sks_mka
                 << " | Dificulty Level : " << current->tingkat_kesulitan_mka
                 << " | Status : " << current->status << endl;
            i++;
        }
        current = current->next;
    }
    cout << "==================================================================" << endl;
}

void show_finished()
{
    read_file_assignment();
    node_assignment *current = kepala_a;
    node_assignment *last = ekor_a;

    int i = 0;
    cout << "\n=====================UNFINISHED ASSIGNMENT========================" << endl;
    while (current != NULL)
    {
        if (strcmp(current->status, "Finished") == 0)
        {
            cout << i + 1 << ". " << current->nama_mka
                 << " | Deadline : " << current->hari_mka
                 << " | Total of SKS : " << current->jmlh_sks_mka
                 << " | Dificulty Level : " << current->tingkat_kesulitan_mka
                 << " | Status : " << current->status << endl;
            i++;
        }
        current = current->next;
    }
    cout << "==================================================================" << endl;
}

void delete_checklist(const char *namaAssignment, const char *hariAssignment, int sks, int kesulitan)
{
    node_assignment *current = kepala_a;
    node_assignment *prev = NULL;
    bool found = false;

    while (current != NULL)
    {
        if (
            strcmp(current->nama_mka, namaAssignment) == 0 &&
            strcmp(current->hari_mka, hariAssignment) == 0 &&
            current->jmlh_sks_mka == sks &&
            current->tingkat_kesulitan_mka == kesulitan)
        {
            if (strcmp(current->status, "Finished") != 0)
            {
                cout << "ERROR: Assignment ditemukan, tetapi belum selesai. Tidak dapat dihapus.\n";
                return;
            }

            found = true;

            // Hapus node
            if (current == kepala_a)
            {
                kepala_a = kepala_a->next;
                if (current == ekor_a)
                {
                    ekor_a = NULL;
                }
            }
            else
            {
                prev->next = current->next;
                if (current == ekor_a)
                {
                    ekor_a = prev;
                }
            }

            delete current;
            file_assignment();
            cout << "INFO: Assignment \"" << namaAssignment << "\" berhasil dihapus.\n";
            return;
        }

        prev = current;
        current = current->next;
    }

    if (!found)
    {
        cout << "ERROR: Assignment tidak ditemukan dengan kriteria tersebut.\n";
    }
}

void checklist_lesson()
{
    int pil_checklist, assignmentAmount, Assignment_div_lvl;
    string AssignmentName, assignmentDay;

    do
    {
        cout << "==================================" << endl;
        cout << "1. Mark the checklist as complete" << endl;
        cout << "2. Revert status to unfinished" << endl;
        cout << "3. Show only unfinished checklists" << endl;
        cout << "4. Show completed checklist" << endl;
        cout << "5. Delete completed checklist" << endl;
        cout << "6. Return to main menu" << endl;
        cout << "==================================" << endl;
        cout << "Choose : ";
        cin >> pil_checklist;
        system("cls");

        switch (pil_checklist)
        {
        case 1:
            mark();
            break;

        case 2:
            revert();
            break;

        case 3:
            show_unfinished();
            break;

        case 4:
            show_finished();
            break;

        case 5:
            read_file_schedule();
            show_finished();
            cout << "Assignment name to delete : ";
            cin.ignore(); // untuk bersihkan buffer
            getline(cin, AssignmentName);
            cout << "Assignment Deadline : ";
            cin >> assignmentDay;
            cout << "Assignment SKS amount : ";
            cin >> assignmentAmount;
            cout << "Assignment difficulty level : ";
            cin >> Assignment_div_lvl;
            system("cls");
            // hapus_lesson(deleteAssignmentName.c_str());

            delete_checklist(AssignmentName.c_str(), assignmentDay.c_str(), assignmentAmount, Assignment_div_lvl);
            break;

        case 6:
            return;
            break;

        default:
            break;
        }
    } while (pil_checklist != 6);
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
        system("cls");
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
            system("cls");
            file_schedule();
            // totals += jmlh_inputs;
            // system("cls");

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
            system("cls");
            file_assignment();
            // totala += jmlh_inputa;

            break;

        case 3: // kembali ke menu utama
            system("cls");
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
        system("cls");
        switch (menu_show_2)
        {
        case 1:
            clsLL_Schedule();
            read_file_schedule();
            cetakSchedule();
            break;

        case 2:
            clsLL_Assignment();
            read_file_assignment();
            cetakAssignment();
            break;

        case 3:
            getchar();
            system("cls");
            return;
            break;

        default:
            break;
        }
    } while (menu_show_2 != 3);

    system("cls");
}

int main(){
    int pilmenu, pilih_menu_input, pilih_menu_show;

    do
    {
        menu(pilmenu);
        switch (pilmenu)
        {
        case 1:
            menu_input(pilih_menu_input);
            break;

        case 2:
            menu_show(pilih_menu_show);
            break;

        case 3:
            lesson_plan();
            break;

        case 4:
            checklist_lesson();
            break;

        case 5:
            menu_notes();
            break;

        case 0:
            break;

        default:
            break;
        }
    } while (pilmenu != 0);
}