#pragma once

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
