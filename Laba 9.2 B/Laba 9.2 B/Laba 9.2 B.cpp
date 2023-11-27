#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Spec {
    KN = 1,
    IT,
    ME,
    FIT,
    WT
};

struct Student {
    int id;
    std::string surname;
    int course;
    Spec spec;
    union {
        int physics;
        int math;
        int it;
        int programming;
        int num_methods;
        int pedagogy;
    };
};

void Create(Student* students, const int N) {
    int spec;

    for (int i = 0; i < N; i++) {
        cout << "������� � " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();
        students[i].id = i + 1;

        std::cout << "�������: "; std::cin >> students[i].surname;
        std::cout << "����: "; std::cin >> students[i].course;
        std::cout << "������������ (" <<
            "��: " << KN << ", " <<
            "��: " << IT << ", " <<
            "���: " << ME << ", " <<
            "��: " << FIT << ", " <<
            "��: " << WT << "):" << std::endl;

        std::cin >> spec;
        students[i].spec = (Spec)spec;
        cout << "Գ����: "; cin >> students[i].physics;
        cout << "����������: "; cin >> students[i].math;
        switch (students[i].spec) {
        case KN:
            cout << "�������������: "; cin >> students[i].programming;
            break;
        case IT:
            cout << "������� ������: "; cin >> students[i].num_methods;
            break;
        case ME:
        case WT:
        case FIT:
            cout << "���������: "; cin >> students[i].pedagogy;
        }
        cout << endl;

    }
}

string getSpecStr(Spec s) {
    switch (s) {
    case KN:
        return "��";
    case IT:
        return "��";
    case ME:
        return "���";
    case FIT:
        return "��";
    case WT:
        return "��";
    default:
        return "�������";
    }
}

void PrintHeader() {
    cout << "========================================================================================================="
        << endl;
    cout << "| �  | ������� | ���� | ������������ | Գ���� | ���������� | ������������� | ���. ������ | ��������� |"
        << endl;
    cout << "========================================================================================================="
        << endl;
}

void Print(const Student* p, int N) {
    PrintHeader();

    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << right << i + 1 << " ";
        cout
            << "| " << setw(8) << right << p[i].surname << " "
            << "| " << setw(5) << left << p[i].course
            << "| " << setw(14) << left << getSpecStr(p[i].spec)
            << "| " << setw(7) << right << p[i].physics
            << "| " << setw(11) << right << p[i].math;
        switch (p[i].spec) {
        case KN:
            cout << "| " << setw(14) << right << p[i].programming << "|" << setw(14) << "|" << setw(13) << "|" << endl;
            break;
        case IT:
            cout << "| " << setw(15) << "|" << setw(13) << right << p[i].num_methods << "|" << setw(13) << "|" << endl;
            break;
        case ME:
        case FIT:
        case WT:
            cout << "| " << setw(15) << "|" << setw(14) << "|" << setw(12) << right << p[i].pedagogy << "|" << endl;
            break;
        }
        cout << "---------------------------------------------------------------------------------------------------------";
        cout << endl;
    }
    cout << endl;
}

void Sort(Student* s, const int N) {
    Student tmp;
    for (int i0 = 0; i0 < N - 1; i0++) {
        for (int i1 = 0; i1 < N - i0; i1++) {
            if ((s[i1].spec < s[i1 + 1].spec)
                || (s[i1].spec == s[i1 + 1].spec && s[i1].course < s[i1 + 1].course)
                || (s[i1].spec == s[i1 + 1].spec && s[i1].course == s[i1].course && s[i1].surname > s[i1 + 1].surname)) {
                tmp = s[i1];
                s[i1] = s[i1 + 1];
                s[i1 + 1] = tmp;
            }
        }
    }
}

int* IndexSort(Student* s, const int N) {
    int* I = new int[N];
    for (int i = 0; i < N; i++)
        I[i] = i;

    int i, j, value;
    for (i = 1; i < N; i++) {
        value = I[i];
        for (
            j = i - 1; j >= 0 &&
            ((s[I[j]].spec < s[value].spec)
                || (s[I[j]].spec == s[value].spec && s[I[j]].course < s[value].course)
                || (s[I[j]].spec == s[value].spec && s[I[j]].course == s[value].course && s[I[j]].surname < s[value].surname));
            j--
            ) {
            I[j + 1] = I[j];
        }

        I[j + 1] = value;
    }
    return I;
}

void PrintIndexSorted(Student* p, int* I, const int N) {
    
    cout << "========================================================================================================="
        << endl;
    cout << "| �  | ������� | ���� | ������������ | Գ���� | ���������� | ������������� | ���. ������ | ��������� |"
        << endl;
    cout << "========================================================================================================="
        << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << right << i + 1 << " ";
        cout
            << "| " << setw(8) << right << p[i].surname << " "
            << "| " << setw(5) << left << p[i].course
            << "| " << setw(14) << left << getSpecStr(p[i].spec)
            << "| " << setw(7) << right << p[i].physics
            << "| " << setw(11) << right << p[i].math;
        switch (p[i].spec) {
        case KN:
            cout << "| " << setw(14) << right << p[i].programming << "|" << setw(14) << "|" << setw(13) << "|" << endl;
            break;
        case IT:
            cout << "| " << setw(15) << "|" << setw(13) << right << p[i].num_methods << "|" << setw(13) << "|" << endl;
            break;
        case ME:
        case FIT:
        case WT:
            cout << "| " << setw(15) << "|" << setw(14) << "|" << setw(12) << right << p[i].pedagogy << "|" << endl;
            break;
        }
        cout << "---------------------------------------------------------------------------------------------------------";
        cout << endl;
    }
    cout << endl;
}

int BinSearch(Student* p, const int N, const int course, const Spec spec, const string surname)
{
    int L = 0, R = N - 1, m;
    do {
        m = (L + R) / 2;
        if (p[m].surname == surname && p[m].course == course && p[m].spec == spec)
            return m;
        if ((p[m].surname < surname)
            || (p[m].surname == surname && p[m].spec < spec)
            || (p[m].surname == surname && p[m].spec == spec) && p[m].course < course)
        {
            L = m + 1;
        }
        else
        {
            R = m - 1;
        }
    } while (L <= R);

    return -1;
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Vvedit N: "; cin >> N;
    cout << endl;

    int menu;
    int find;
    string surname;
    unsigned course;
    int ispec;

    Spec spec{};

    Student* a = new Student[N];

    Create(a, N);
    Print(a, N);

    do {
        cout << endl << endl;
        cout << "������� ��: " << endl;
        cout << " [1] - ���� ����� �� �����" << endl;
        cout << " [2] - Գ����� ������������� ������" << endl;
        cout << " [3] - �������� ������������� ������" << endl;
        cout << " [4] - �������� �����" << endl;
        cout << " [0] - ����� � ��������" << endl;
        cout << " ������ �������� �������: "; cin >> menu;
        cout << endl << endl;
        switch (menu) {
        case 1:
            Print(a, N);
            break;
        case 2:
            Sort(a, N);
            break;
        case 3:
            IndexSort(a, N);
            PrintIndexSorted(a, IndexSort(a, N), N);
            break;
        case 4:
            cin.get();
            cin.sync();
            cout << "������ ������� ��������: "; cin >> surname;
            cout << "������ ������������ (1 - RI, 2 - KN, 3 - VP, 4 - PZ): ";
            cin >> ispec;
            spec = (Spec)ispec;
            cin.get();
            cin.sync();
            cout << "������ ����: "; cin >> course;

            find = BinSearch(a, N, course, spec, surname);
            if (find != -1) {
                cout << "������� " << surname << " ��������� �� ������������: " << spec << endl;
            }
            else
                cout << "������� " << surname << " �� ��������� �� ������������: " << spec << endl;
            break;
        case 0:
            break;

        }
    } while (menu != 0);

    delete[] a;
    return 0;
}