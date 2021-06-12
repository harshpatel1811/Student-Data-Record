#include<iostream>
#include<fstream>

using namespace std;
using std::ifstream;

void stopscreen()
{
    cout<<"Press enter To Back\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
  
    system("clear");
}

void sleepcp(int milliseconds) // Cross-platform sleep function
{
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC/1000;
    while (clock() < time_end)
    {
    }
}

void searchtxt(int search_roll_no)            // To perform search in Mytxt.txt file (search by roll no);
{
    ifstream in("Mytxt.txt");
    string line;
    int roll_no;
    string student_name;
    int sem;
    float cgpa;
    bool isfound = false;

    //Example of data: 1,Patel Harsh Babubhai, 5, 7.8

    if(!in)
    {
        cerr<<"File could Not be loaded\n";
    }
    else
    {
        while( getline(in, line, ',') )
    {       
        roll_no = atoi(line.c_str());
        getline(in, student_name, ',');
        getline(in, line, ',');
        sem=atoi(line.c_str());
        getline(in, line, '\n');
        cgpa = (float)atof(line.c_str());

        if(roll_no ==search_roll_no)
        {
        cout<<"Record Found: \n";
        cout<<"Student Name: "<<student_name<<"\n";
        cout<<"Roll No: "<<roll_no<<"\n";
        cout<<"Sem: "<<sem<<"\n";
        cout<<"CGPA: "<<cgpa<<"\n";
        isfound = true;
        }
    }
    }
    if(!isfound)
    {
        cerr<<"OOPS RECORD COULD NOT BE FOUND\n";
    }
}

void ShowRecords()
{
    ifstream in("Mytxt.txt");
    string line;
    int roll_no;
    string student_name;
    int sem;
    float cgpa;


    //Example of data: 1,Patel Harsh Babubhai, 5, 7.8

    if(!in)
    {
        cerr<<"File could Not be loaded\n";
    }
    else
    {
        while( getline(in, line, ',') )
    {       
        roll_no = atoi(line.c_str());
        getline(in, student_name, ',');
        getline(in, line, ',');
        sem=atoi(line.c_str());
        getline(in, line, '\n');
        cgpa = (float)atof(line.c_str());
        
        cout<<"Student Name: "<<student_name<<"\n";
        cout<<"Roll No: "<<roll_no<<"\n";
        cout<<"Sem: "<<sem<<"\n";
        cout<<"CGPA: "<<cgpa<<"\n";
        cout<<"------------------------------\n";
    }
    }
}

bool isrollno_exist(int checkroll_no)
{
    ifstream in("Mytxt.txt");
    string line;
    int roll_no;    
     if(!in)
    {
        cerr<<"File could Not be loaded\n";
    }
    else
    {
        while( getline(in, line, ',') )
            {       
                roll_no = atoi(line.c_str());
                getline(in, line, '\n');

                if(roll_no ==checkroll_no)
                    {
                        return true;
                    }
            }
    }
    return false;
}

void DeleteRecord(int search_roll_no)            // To Delete particular student data
{
    ifstream in("Mytxt.txt");
    fstream tempfile("temp.txt", ios::app);
    string line;
    int roll_no;
    string student_name;
    int sem;
    float cgpa;
    bool isfound = false;

    //Example of data: 1,Patel Harsh Babubhai, 5, 7.8

    if(!in)
    {
        cerr<<"File could Not be loaded\n";
    }
    else
    {
        while( getline(in, line, ',') )
    {       
        roll_no = atoi(line.c_str());
        if(roll_no == search_roll_no)
        {
          isfound =true;
          getline(in, line, '\n');
          continue;
        }
        getline(in, student_name, ',');
        getline(in, line, ',');
        sem=atoi(line.c_str());
        getline(in, line, '\n');
        cgpa = (float)atof(line.c_str());

         
        tempfile<<roll_no<<","<<student_name<<","<<sem<<","<<cgpa<<"\n";
        
    }
    }
  if(!isfound)
  {
    cerr<<"The data is not present in database\n";
  }
  else
  {
    remove("Mytxt.txt");
    rename("temp.txt", "Mytxt.txt");
  }
  
}



char choice;

int main()
{
 do{
     fstream file("Mytxt.txt", ios::app);
     system("clear");
    cout<<"(1) For Enter the New Student data\n";
    cout<<"(2) For Update the Existing Student Data\n";
    cout<<"(3) List All Students Record\n";
    cout<<"(4) Exit The Programm\n\n";
    cout<<"Choice: ";
    cin>>choice;

        if (choice == 49)
        {   system("clear");
            
            unsigned int roll_no;
            cout<<"Enter the Roll No\n";
            cin>>roll_no;
    
            cout<<"Enter the name of Student\n";
            string name;
            cin.ignore();
            getline(cin, name);

            cout<<"Enter the Sem\n";
            unsigned short sem;
            cin>>sem;     

            cout<<"Enter the cgpa of Student\n";
            float cgpa;
            cin>>cgpa;
           
            if(roll_no>0 && !isrollno_exist(roll_no) && sem>0 && cgpa>0)
            {
                file<<roll_no<<","<<name<<","<<sem<<","<<cgpa<<"\n";
                cout<<"Data Saved...\n";
                 sleepcp(2000);
            }

            else
            {
                if(roll_no<0 &&sem<0 && cgpa<0)
                {
                    cout<<"Your one of entry contains zero that should not be\n";
                    stopscreen();
                    break;
                }
                else
                {
                    cout<<"Roll NO Exists\n";
                    stopscreen();
                    break;

                }
            }

           
        }

    else if (choice == 50)
    {
        int search_choice;
        char choice;
        if(file.is_open())
        { 
            do
            {
            system("clear");
            cout<<"(1) Delete the Student by Roll No\n";
            cout<<"(2) To Back\n";
            cin>>choice;
            
            if (choice == 49)
            {
                int delete_choice;
                 system("clear");
                 cout<<"Enter the Roll no of Student\n";
                 cin>>delete_choice;

                 searchtxt(delete_choice);
                 cout<<"---------------------";
                 cout<<"\n\nAre you Sure You Want to Delete this Student data(y/n)?";
                 char yesorno;
                 cin>>yesorno;

                    if(yesorno == 121)
                    {
                        DeleteRecord(delete_choice);
                        cout<<"Deleted\n";
                        stopscreen();
                    }
                    else if(yesorno == 110)
                    {
                        cout<<"Abort..\n";
                        stopscreen();
                    }

                    else
                    {
                        cout<<"Invalid Choice\n";
                        stopscreen();
                    }
                 

            }
            
            }
            while(choice != 50);
        }
    }

    else if(choice == 51)
    {
        ShowRecords();
        stopscreen();
    }
        
 }
 while(choice != 52);
}