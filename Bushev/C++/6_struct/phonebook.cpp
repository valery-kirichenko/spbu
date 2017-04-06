#include <iostream>
#include <map>
#include <string>
#include <windows.h>

using namespace std;

struct _note{
    bool del = false;
    string data[4];
};

void del(map<int, _note> &notes, int mmax){
    int id;
    cout << "Enter id for deletion : ";
    cin >> id;

    if(--id > mmax || id < 0 || notes[id].del){
        cout << "You missed, try another id..." << endl;
    }else{
        notes[id].del = true;
        cout << "You have successfully deleted note #" << (id+1) << endl;
    }

    cout << endl;
    system("pause");
}

void show(map<int, _note> notes, int id){
    bool used = 0;

    for(int i = 0; i < id+1; i++){
        if(notes[i].del) continue;

        cout << "[" << (i+1) << "] ";

        for(int j = 0; j < 4; j++){
            cout << notes[i].data[j] << ((j != 2) ? " " : ", ");
        }

        cout << endl;
        used = true;
    }

    if(used){ cout << endl; system("pause"); }
}

void add(map<int, _note> &notes, int id){
    string data;
    cout << "Enter <num>, <fname>, <lname>, <comment>: " << endl;

    for(int i = 0; i < 4; i++){
        cin >> notes[id].data[i];
    }

    cout << "Successfully written...\n\n";
    system("pause");
}

int main(){
    int id = -1;
    map<int, _note> notes;

    while(true){
        system("cls");

        cout << "The worst phonebook ever is always happy to see you..." << endl << endl;

        cout << "Allowed commands: \n" << endl;
        cout << "\"+\" - to add new number" << endl;
        cout << "\"-\" - to show written notes" << endl;
        cout << "\"id\" - to delete some foe" << endl;
        cout << endl << "\"e\" - to stop it\n" << endl;

        string result;
        cout << "Your choice? "; cin >> result;

        system("cls");

        if(result == "e"){
            break;
        }else if(result == "+"){
            add(notes, ++id);
        }else if(result == "-"){
            show(notes, id);
        }else{
            del(notes, id);
        }
    }

	system("pause");
	return 0;
}
