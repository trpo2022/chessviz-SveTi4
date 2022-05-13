#include "chess.h"

void AddSpisElm(list_command*& tail, string line, int L, int R)
{
    list_command* p;
    string Step = "";
    for (int i = L; i < R; i++)
        Step += line[i];
    if (Step.size() > 0) {
        p = new list_command;
        p->Cmd = Step;
        p->next = NULL;
        p->prev = tail;
        tail->next = p;
        tail = p;
    }
}

void ReadSpis(list_command* head)
{
    list_command* p;
    for (p = head->next; p; p = p->next) {
        cout << " |-> " << p->Cmd << endl;
        delete (p);
    }
}