#include "userinterface.hpp"

using namespace std;

UserInterface::UserInterface(ListSongs* l) : listRef(l) { }

void UserInterface::mainMenu() {
    size_t opc;

    do {
        cout << "iSpotify Music" << endl;
        cout << "Lista de Exitos" << endl << endl;
        cout << " #R | CANCION / AUTOR(ES) / INTERPRETE(S)" << endl << endl;
        cout << listRef->toString() << endl;
        cout << "1. Agregar nueva cancion" << endl;
        cout << "2. Eliminar una cancion" << endl;
        cout << "3. Borrar todas las canciones" << endl;
        cout << "4. Buscar una cancion" << endl;
        cout << "5. Salir" << endl << endl;
        cout << "Escoge una opcion: ";
        cin >> opc;
        cin.ignore();

        switch (opc) {
            case 1:
                addSong();
                break;

            case 2:
                deleteSong();
                break;

            case 3:
                deleteAllSongs();
                break;

            case 4:
                findSong();
                break;

            case 5:
                cout << "Gracias por usar el programa :)" << endl;
                exit(0);
                break;

            default:
                cout << "Opcion invalida" << endl;
                cout << "Presiona ENTER para continuar. . .";
                getchar();
                system("cls");
                break;
            }
        }
    while (opc != 5);
    }

void UserInterface::addSong() {
    Song song;
    int rank;
    string str;
    Name name;
    char repeat;

    do {
        cout << "Posicion en el ranking: ";
        cin >> rank;
        song.setRanking(rank);

        cin.ignore();

        cout << endl << "Nombre de la cancion: ";
        getline(cin, str);
        song.setSongName(str);

        cout << endl << "Autor de la cancion" << endl;
        cout << "Nombre(s): ";
        getline(cin, str);
        name.setFirst(str);

        cout << "Apellido(s): ";
        getline(cin, str);
        name.setLast(str);

        song.setAuthor(name);

        cout << endl << "Interprete de la cancion" << endl;
        cout << "Nombre(s): ";
        getline(cin, str);
        name.setFirst(str);
        cout << "Apellido(s): ";
        getline(cin, str);
        name.setLast(str);

        song.setInterpreter(name);

        listRef->insertSong(listRef->getLastPos(), song);

        cout << endl << "Quieres agregar otra cancion? (s/n): ";
        cin >> repeat;
        repeat = toupper(repeat);
        }
    while (repeat == 'S');

    if (repeat == 'N') {
        system("cls");
        }

    if (repeat != 'S' or repeat != 'N') {
        cout << "Opcion invalida!" << endl;
        cout << "Presiona ENTER para continuar. . .";
        getchar();
        system("cls");
        }
    }

void UserInterface::deleteSong() {
    int pos;
    char repeat;

    do {
        system("cls");

        cout << "Posicion de la cancion en la lista que desea eliminar: ";
        cin >> pos;

        try {
            listRef->deleteSong(pos);
            }
        catch(ListException ex) {
            cout << "Algo salio mal: " << ex.what() << endl;
            }

        cout << "Desea eliminar otra cancion? (s/n): ";
        cin >> repeat;
        repeat = toupper(repeat);
        }
    while(repeat == 'S');

    if(repeat == 'N') {
        system("cls");
        }

    if(repeat != 'S' or repeat != 'N') {
        cout << "Tecla invalida!" << endl;
        cout << "Presiona ENTER para continuar. . .";
        getchar();
        system("cls");
        }
    }

void UserInterface::deleteAllSongs() {
    listRef->deleteAll();
    }

void UserInterface::findSong() {
    Song song;
    Name name;
    string str;
    int pos;
    size_t opc;

    cout << "Buscar por" << endl;
    cout << "1) Nombre de la cancion" << endl;
    cout << "2) Nombre del interprete" << endl;
    cout << "Opcion: ";
    cin >> opc;
    cin.ignore();

    if(!(opc == 1 or opc == 2)) {
        cout << "Opcion invalida" << endl;
        cout << "Presione ENTER para continuar. . .";
        getchar();
        system("cls");
        }

    if(opc == 1){
        cout << "Nombre de la cancion a buscar: ";
        getline(cin, str);

        song.setSongName(str);

        pos = listRef->findSongLinear(song);
        //pos = listRef->findSongBinary(song);

        cout << endl;

        cout << "La cancion " << str;
        if(pos == -1) {
            cout << " no se encuentra en la lista" << endl << endl;
            cout << "Presione ENTER para continuar. . .";
            getchar();
            system("cls");
        } else {
            cout << " se encuentra en la posicion " << pos << " de la lista";
            cout << endl << endl;
            cout << "Registro encontrado: " << endl;
            cout << listRef->retrieve(pos).toMp3() << endl;
        }
    }

    if(opc == 2){
        cout << "Interprete a buscar" << endl;
        cout << "Nombre(s): ";
        getline(cin, str);
        name.setFirst(str);
        cout << "Apellido(s): ";
        getline(cin, str);
        name.setLast(str);

        song.setInterpreter(name);

        pos = listRef->findSongLinear(song);
        //pos = listRef->findSongBinary(song);

        cout << endl;

        cout << "El interprete " << name.toString();
        if(pos == -1) {
            cout << " no se encuentra en la lista" << endl << endl;
            cout << "Presione ENTER para continuar. . .";
            getchar();
            system("cls");
        } else {
            cout << " se encuentra en la posicion " << pos << " de la lista";
            cout << endl << endl;
            cout << "Registro encontrado: " << endl;
            cout << listRef->retrieve(pos).toMp3() << endl;
        }
    }
    }