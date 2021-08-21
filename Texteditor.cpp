#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<windows.h>
#include<conio.h>
using namespace std;



void file_delete(char *);

class TextEditor
{
   string current_directory;
   string file_content;
  protected:
   fstream open_file;

 public:  
   TextEditor()
  {
      current_directory=system("cd");
  }
   
  
     void OpenFile();
    string DeleteFile(fstream * FILE);
    void edit_file();
    
};


class Write_into_file
{
    fstream New_File;
      string fileName;
    public:
   Write_into_file(string name)
   {
       fileName=name;
   }
  
    void fileWrite();
    bool checkFile()
    {
        if(New_File)
        return true;
        else
        return false;
    }
    bool Isempty()
    {
        if(New_File.eof()==0)
        return true;
        else
        return 0;
    }
    void FileRead()
       {
        fstream temp;
        temp.open(fileName,ios::in);
        char output;

         while(!temp.eof())
         {
              temp.get(output);
              cout<<output;     
         }
        temp.close();
    }
};






 void TextEditor::OpenFile()
{
   
    string name;
    cout<<endl<<"enter name of file : ";
     cin>>name;
    open_file.open(name,ios::in);

    system("cls");
    if(!open_file)
    {

        cout<<"ERROR : ' "<<name<<" ' file dosen't exsist "<<endl;
        getch();
        return;
    }
    cout<<"\t\t\t**********"<<name<<"\t**********";
    cout<<endl<<"press  Q/close & return to Home"<<endl<<endl;
    char c;
    while(!open_file.eof())
    {
        open_file.get(c);
        cout<<c;
    }

    c=getch();
   
}


void Write_into_file::fileWrite()
{

    New_File.open(fileName,ios::out|ios::app);
  system("cls");

  if (!checkFile())
  {
      cout<<"ERROR : cannot open this file";
      getch();
      return;
  }
  
 
   system("color 17");

  cout<<"\t\t*****\t"<<fileName<<"\t*********";
  
  cout<<endl<<"Press Cltr+Z to save & quit"<<endl<<endl;

  FileRead();
  
  char input;
 input=getchar();
  while(input!=EOF)
 {

    New_File.put(input);
    input=getchar();
 }

  system("cls");  
 cout<<"File is saved at directory ";   
    
 getch();     
    

}




int main()
{
   
   
int choice;
    do{
        system("cls");
   system("color 07");
   
cout<<"welcome to NOTEPAD lite Text Editor......\n\n";
    system("cd"); 
    cout<<endl<<endl;   
    cout<<"press 1: create/edit new file"<<endl;
    cout<<"press 2: open file"<<endl;
    cout<<"press 3: delete file"<<endl;
    cout<<"press 0: quit"<<endl;
    cin>>choice;

if (choice==1)
{
     string name;
    cout<<"\nenter file name : ";
    cin>>name;
     Write_into_file Filler(name);
    Filler.fileWrite();

}else if(choice==2)
{
     TextEditor BlindStudio;
    BlindStudio.OpenFile();
    
}
else if (choice==3)
{
   char delete_file[30];
    cout<<"enter name of file : ";
    cin>>delete_file;
   file_delete(delete_file);
   
}




system("cls");
}while(choice!=0);



return 0;
}


void file_delete(char * name)
{

    
    fstream check;
    check.open(name);
   if (!check)
   {
       cout<<"ERROR : file dosent exist";
       getch();
   }
   else
   {
       check.close();
       int a;
       system("cls"); 
       cout<<"Do you really want to delete file "<<name<<" ?";
       cout<<endl<<"1. YES"<<"\t 2. NO"; 
       cin>>a;
       if (a==1)
       {
           system("cls");
           remove(name);
           cout<<"file Deleted successfuly";
       getch();
       }
       else
       {
           return;
       }
       
       
      
   }
}