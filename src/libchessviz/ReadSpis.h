#pragma once

void ReadSpis(list_command *head) {
    list_command *p;
    for(p=head->next; p; p=p->next)
    {
        cout << " |-> " << p->Cmd << endl;
        delete(p);
    }
}