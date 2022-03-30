// Hospital system
#include <iostream>
using namespace std;
// Global Variable
const int Max_Specialization = 20;
const int Max_Queue = 5;

string names[Max_Specialization + 1][Max_Queue + 1];
int status[Max_Specialization + 1][Max_Queue + 1];
int Queue_length[Max_Specialization + 1];

// Menu Function Display options to user to choice from them
// it returns choice value to be used in anthor function
int menu()
{
    int choice = -1;
    while (choice == -1)
    {
        cout << "\n Enter Yout Choice: " << endl;
        cout << " 1)Add New Patinet " << endl;
        cout << "2) Print All Patinets" << endl;
        cout << "3) Get Next Patinet" << endl;
        cout << "4) Exit " << endl;

        cin >> choice;

        if (!(1 <= choice && choice <= 4))
        {
            cout << "Invalid Choice , Try again \n ";
            choice = -1;
        }
    }
    return choice;
}

// shift left function  moves the each patient to the left
// help in removing patient
void shift_left(int spec, string names_sp[], int status_sp[])
{
    int len = Queue_length[spec];
    for (int i = 1; i < len; ++i){
        names_sp[i - 1] = names_sp[i];
        status_sp[i - 1] = status_sp[i];
    }
    Queue_length[spec]--;
}
// Move each patient to the right. E.g if patient in position 5, it will be in 6
// Help in adding patient

void shift_right(int spec, string names_sp[], int status_sp[])
{
    int len = Queue_length[spec];
    for (int i = len - 1; i >= 0; --i)
    {
        names_sp[i + 1] = names_sp[i];
        status_sp[i + 1] = status_sp[i];
    }
    Queue_length[spec]++;
}

bool add_patient()
{
    int spec;
    string name;
    int st;

	cout << "Enter specialization, name, statis: ";
	cin >> spec >> name >> st;

    int pos = Queue_length[spec];

    if (pos >= Max_Queue)
    {
        cout << "Sorry , Cannot add More Patient for this specialization" << endl;
        return false;
    }
    if (st == 0)
    {
        names[spec][pos] = name;
        status[spec][pos] = st;
        Queue_length[spec]++;
    }
    else
    {
        shift_right(spec, names[spec], status[spec]);
        names[spec][0] = name;
        status[spec][0] = st;
    }

    return true;
}
void print_patinet(int spec, string names_sp[], int status[])
{
    int len = Queue_length[spec];
    if (len == 0)
    {
        return;
    }

    cout << "Ther are " << len << " Patient in specialization " << spec << endl;
    for (int i = 0; i < len; i++)
    {
        cout << names_sp[i] << " ";
        if (status[1])
        {
            cout << "urgent\n";
        }
        else
        {
            cout << "regualr" << endl;
        }
    }
    cout << "\n\n";
}
void print_patients()
{
    cout << "***************************************************" << endl;
    for (int spec = 0; spec < Max_Specialization; ++spec)
    {
        print_patinet(spec, names[spec], status[spec]);
    }
}

void Get_Next_Patient()
{
    int spec;
    cout << "Enter the Specialization\n";
    cin >> spec;
    int len = Queue_length[spec];
    if (len == 0)
    {
        cout << "No patinet at the moment , Have rest Dr\n";
        return;
    }

    // let patient goes with Dr
    cout << names[spec][0] << " Please Go with Dr\n";
    shift_left(spec, names[spec], status[spec]);
}
void hospital_system()
{
    while (true)
    {
        int choice = menu();
        if (choice == 1)
        {
            add_patient();
        }
        else if (choice == 2)
        {
            print_patients();
        }
        else if (choice == 3)
        {
            Get_Next_Patient();
        }
        else
        {
            break;
        }
    }
}
int main()
{
    hospital_system();
    return 0;
}