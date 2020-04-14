#include <bits/stdc++.h>
using namespace std;

#define ll long long;
int list_size = 0;
int n;

float round_two(float var)
{
    float value = (int)(var * 100 + .0);
    return (float)value / 100;
}

struct date
{
    string day;
    string month;
    string year;
};

struct student
{
    string name;
    int id;
    char sex;
    date *birth;
    float grade;
};

struct Node
{
    student *data;
    Node *next;
};

void print_node(Node *target)
{
    cout << target->data->id << " "
         << target->data->name << " ["
         << target->data->sex << "] ("
         << target->data->birth->day << "/"
         << target->data->birth->month << "/"
         << target->data->birth->year << ") "
         << target->data->grade << endl;
}

void print_list(Node *root)
{
    Node *ptr;
    ptr = root;
    if (ptr->data == NULL)
    {
        cout << "NONE" << endl;
        return;
    }
    while (ptr->next != NULL)
    {
        print_node(ptr);
        ptr = ptr->next;
    }
    print_node(ptr);
}

void list_pb(Node *root, student *data)
{
    Node *temp;
    temp = new Node;
    temp->data = data;
    temp->next = NULL;
    Node *ptr;
    ptr = root;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void list_pf(Node *root, student *data)
{
    Node *ptr;
    ptr = new Node;
    ptr->data = root->data;
    ptr->next = root->next;
    root->data = data;
    root->next = ptr;
}

void list_rb(Node *root)
{
    Node *ptr;
    ptr = root;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = NULL;
}

student* read(string in,int size){
    int cnt = 0,j;
    string id, day, month, year, grade;
    student *stu;
    stu = new student;
    date *birth;
    birth = new date;
    for (j = 0; j < size - 2; j++)
    {
        if (in[j] == '$' && in[j + 1] == '$' && in[j + 2] == '$')
        {
            j += 2;
            cnt++;
            continue;
        }
        if (in[j] == '/')
        {
            cnt++;
            continue;
        }
        switch (cnt)
        {
        case 0:
            stu->name.push_back(in[j]);
            break;
        case 1:
            id.push_back(in[j]);
            break;
        case 2:
            stu->sex = in[j];
            break;
        case 3:
            day.push_back(in[j]);
            break;
        case 4:
            month.push_back(in[j]);
            break;
        case 5:
            year.push_back(in[j]);
            break;
        case 6:
            grade.push_back(in[j]);
            break;
        default:
            break;
        }
    }
    stu->id = stoi(id);
    birth->day = day;
    birth->month = month;
    birth->year = year;
    stu->birth = birth;
    float temp_grade = stof(grade);
    stu->grade = round_two(temp_grade);
    return stu;
}

int main()
{
    float grade_floor, grade_ceil;
    string in, key;
    cin >> n;
    int i, size,j,search_id;
    bool found = false;
    bool first = true;
    Node *search_list;
    search_list = new Node;
    search_list->next = NULL;
    search_list->data = NULL;
    Node *rec;
    rec = new Node;
    rec->next = NULL;
    rec->data = NULL;
    Node *ptr;
    ptr = rec;
    for (i = 0; i < n; i++)
    {
        cin >> in;
        size = in.size();
        int j;
        if (i == 0)
        {
            rec->data = read(in,size);
        }
        else
        {
            list_pb(rec, read(in,size));
            list_size++;
        }
    }
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> key;
        size = in.size();
        student *stu;
        stu = new student;
        date *birth;
        birth = new date;
        if (key == "AF")
        {
            cin >> in;
            size = in.size();
            list_pf(rec, read(in,size));
            list_size++;
        }
        else if (key == "AB")
        {
            cin >> in;
            size = in.size();
            list_pb(rec, read(in,size));
            list_size++;
            
        }
        else if (key == "DB")
        {
            list_rb(rec);
        }
        else if (key == "DF")
        {
            rec = rec->next;
        }
        else if (key == "ST")
        {
            cout << list_size + 1 << endl;
        }
        else if (key == "SA")
        {
            print_list(rec);
        }
        else if (key == "SC")
        {
            //id-search
            cin >> in;
            search_id = stoi(in);
            while (ptr->data->id != search_id && ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            if (ptr->data->id == search_id)
            {
                print_node(ptr);
            }
            else
            {
                cout << "NONE" << endl;
            }
        }
        else if (key == "SN")
        {
            //name in = {sub-name}*
            cin >> in;
            first = true;
            Node *search_list;
            search_list = new Node;
            search_list->next = NULL;
            search_list->data = NULL;
            Node *ptr;
            ptr = rec;
            size = in.size();
            while (ptr != NULL)
            {
                found = false;
                if (in[0] == ptr->data->name[0] || in[0] == '*')
                {
                    for (j = 0; j < size; j++)
                    {
                        if (in[j] == '*')
                        {
                            found = true;
                            continue;
                        }
                        if (in[j] != ptr->data->name[j])
                        {
                            found = false;
                            break;
                        }
                        found = true;
                    }
                }
                if (found)
                {
                    if (first)
                    {
                        search_list->data = ptr->data;
                        first = false;
                    }
                    else
                    {
                        list_pb(search_list, ptr->data);
                    }
                }
                ptr = ptr->next;
            }
            print_list(search_list);
        }
        else if (key == "SG")
        {
            //grade floor ceil
            cin >> grade_floor >> grade_ceil;
            first = true;
            Node *search_list;
            search_list = new Node;
            search_list->next = NULL;
            search_list->data = NULL;
            Node *ptr;
            ptr = rec;
            while (ptr != NULL)
            {
                found = false;
                if (ptr->data->grade >= grade_floor)
                {
                    if (ptr->data->grade <= grade_ceil)
                    {
                        found = true;
                    }
                }
                if (found)
                {
                    if (first)
                    {
                        search_list->data = ptr->data;
                        first = false;
                    }
                    else
                    {
                        list_pb(search_list, ptr->data);
                    }
                }
                ptr = ptr->next;
            }
            print_list(search_list);
        }
        else if (key == "SS")
        {
            //sex M or F
            cin >> in;
            found;
            first = true;
            Node *search_list;
            search_list = new Node;
            search_list->next = NULL;
            search_list->data = NULL;
            Node *ptr;
            ptr = rec;
            while (ptr != NULL)
            {
                found = false;
                if (ptr->data->sex == in[0])
                {
                    found = true;
                }
                if (found)
                {
                    if (first)
                    {
                        search_list->data = ptr->data;
                        first = false;
                    }
                    else
                    {
                        list_pb(search_list, ptr->data);
                    }
                }
                ptr = ptr->next;
            }
            print_list(search_list);
        }
        else if (key == "SD")
        {
            //birth in this.month
            cin >> in;
            first = true;
            Node *search_list;
            search_list = new Node;
            search_list->next = NULL;
            search_list->data = NULL;
            Node *ptr;
            ptr = rec;
            while (ptr != NULL)
            {
                found = false;
                if (ptr->data->birth->month == in)
                {
                    found = true;
                }
                if (found)
                {
                    if (first)
                    {
                        search_list->data = ptr->data;
                        first = false;
                    }
                    else
                    {
                        list_pb(search_list, ptr->data);
                    }
                }
                ptr = ptr->next;
            }
            print_list(search_list);
        }
    }
}