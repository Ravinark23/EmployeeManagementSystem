
//Employee Management System


#include <stdio.h>
#include<stdlib.h>

struct employee 
{
    int emp_id;
    char name[50];
    char dep[50];
    int age;
    float salary;
};
typedef struct employee Emp;        // New Name to struct employee


void Insert();      // to insert records
void Display();     //to display records
void Search();      //to search records
void Update();      //to update records
void Delete();      //to delete records
int main()
{
    printf("\n__________________________________________________________________________________\n");
    printf("\n*********************WEL-COME TO EMPLOYEE MANAGEMENT SYSTEM***********************");
    int ch;
    do
    {
        printf("\n___________________________________________________________________________________\n");
        printf("\n1.Add New Record\n2.Display All Records\n3.Search Record\n4.Update Record\n5.Delete Record\n6.Exit ---------------------------------------------------------------------\n\nEnter your Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:Insert();
            break;
        case 2:Display();
            break;
        case 3:Search();
            break;
        case 4:Update();
            break;
        case 5:Delete();
            break;
        case 6:
            printf("\n_______________________________________________________________________________________\n");
            printf("\n***************************************THANK YOU*****************************************");
            printf("\n______________________________________________________________________________________\n");
            break;
        default:
            printf("\nIncorrect Choice..Try Again...!\n");
        }
    } while (ch != 6);
}

void Insert()       // Insert Records
{
    FILE *fp;
    fp=fopen("D:/cp/Projects/Employees.txt","a+");
    if(fp==NULL)
    {
        printf("\nUnable to access file........Try Again....!!");
    }
    else
    {
        printf("\n----------------------------------------INSERT RECORDS-------------------------------------\n");
        int n;
        printf("\nEnter the no of Records you want to insert : ");
        scanf("%d",&n);
        Emp *e;
        e=(Emp*)calloc(n,sizeof(Emp));
        for(int i=0;i<n;i++)
        {
            printf("\n\n__________________EMPLOYEE %d__________________\n",i+1);
            printf("\nEnter Employee ID : ");
            scanf("%d",&e[i].emp_id);
            printf("Enter Employee Full Name(Name Middle_Name Sur_Name) : ");
            scanf("\n");
            scanf("%[^\n]s",e[i].name);
            printf("Enter Employee Department : ");
            scanf("\n");
            scanf("%[^\n]s",e[i].dep);
            printf("Enter Employee Age : ");
            scanf("%d",&e[i].age);
            printf("Enter Employee Salary : ");
            scanf("%f",&e[i].salary);
            fwrite(e+i,sizeof(Emp),1,fp);
        }
        printf("\n-----------------------------RECORD INSERTED SUCCESSFULLY-------------------------------\n");
    }
    fclose(fp);
}

void Display()      // Display Records
{
    FILE *fp;
    fp=fopen("D:/cp/Projects/Employees.txt","r");
    if(fp==NULL)
    {
        printf("\nUnable to access file........Try Again....!!");
    }
    else
    {
        printf("\n----------------------------------DISPLAYING RECORDS---------------------------------------\n");
        Emp e;
        printf("\n_______________________________________________________________________________________________\n");
        printf("\tID\t\tNAME\t\t\tDEPARTMENT\t\tAGE\t\tSALARY");
        printf("\n_______________________________________________________________________________________________\n");
        while(fread(&e, sizeof(Emp),1,fp))
        {
            printf("\t%d\t%s    \t%s\t \t \t%d\t\t%0.2f\n",e.emp_id,e.name,e.dep,e.age,e.salary);
        }
    }
    fclose(fp);
}

void Search()   //Search Records
{
    FILE *fp;
    fp=fopen("D:/cp/Projects/Employees.txt","r");
    if(fp==NULL)
    {
        printf("\nUnable to access file........Try Again....!!");
    }
    else
    {
        Emp e;
        printf("\nEnter the Employee ID you want to search : ");
        int ID,found=0;
        scanf("%d",&ID);

         while(fread(&e, sizeof(Emp),1,fp))
        {
            if(e.emp_id==ID)
            {
                printf("\nRecord Found...!");
                printf("\n_______________________________________________________________________________________________\n");
                printf("\tID\t\tNAME\t\t\tDEPARTMENT\t\tAGE\t\tSALARY");
                printf("\n_______________________________________________________________________________________________\n");
                printf("\t%d\t%s    \t%s\t \t \t%d\t\t%0.2f\n",e.emp_id,e.name,e.dep,e.age,e.salary);
                found=1;
                break;
            }
        }
        if(found==0)
        {
            printf("\n....Record not found.........Try Again......!\n");
        }
    }
    fclose(fp);   
}

void Update()   //Update Records
{
    FILE *fp,*fp1;
    
    if(fp==NULL)
    {
        printf("\nUnable to access file........Try Again....!!");
    }
    else
    {
        fp=fopen("D:/cp/Projects/Employees.txt","r");
        fp1=fopen("D:/cp/Projects/Temp.txt","w");
        Emp e;
        int ch;
        printf("\nEnter the Employee ID you want to Update : ");
        int ID,found=0;
        scanf("%d",&ID);

         while(fread(&e, sizeof(Emp),1,fp))
        {   
             if(e.emp_id==ID)
            {
                printf("\nCurrent Details Available for this Roll no %d : \n",ID);
                printf("\n_______________________________________________________________________________________________\n");
                printf("\tID\t\tNAME\t\t\tDEPARTMENT\t\tAGE\t\tSALARY");
                printf("\n_______________________________________________________________________________________________\n");
                printf("\t%d\t%s    \t%s\t \t \t%d\t\t%0.2f\n",e.emp_id,e.name,e.dep,e.age,e.salary);
                found=1;
                
                do
                {
                printf("\n___________________________________________________________________________________________________________\n");
                printf("\nWhat would you like to update..\n1.Name\n2.Department\n3.Age\n4.Salary\n5.All information:\n6.Exit\nEnter Your Choice---------------------------------------------------------\n\n");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1:
                     printf("\nEnter New Employee Full Name : ");
                     scanf("\n");
                    scanf("%[^\n]s",e.name);
                    break;
                    case 2:
                     printf("\nEnter New Employee Department : ");
                    scanf("\n");
                    scanf("%[^\n]s",e.dep);
                    break;
                    case 3:
                    printf("\nEnter New Employee Age : ");
                    scanf("%d",&e.age);
                    break;
                    case 4:
                    printf("\nEnter New Employee Salary : ");
                    scanf("%f",&e.salary);
                    break;
                    case 5:
                     printf("\nEnter New Employee Full Name : ");
                    scanf("\n");
                    scanf("%[^\n]s",e.name);
                    printf("Enter New Employee Department : ");
                    scanf("\n");
                    scanf("%[^\n]s",e.dep);
                    printf("Enter New Employee Age : ");
                    scanf("%d",&e.age);
                    printf("Enter New Employee Salary : ");
                    scanf("%f",&e.salary);
                    break;
                    case 6:break;
                    default: printf("\nIncorrect Choice............Try Again....!\n"); break;
                }
                if(ch!=6)
                {
                printf("\nWould You like to do some more updations with this record...{Y/N) : ");
                char c;
                scanf("\n");
                scanf("%c",&c);
                if(c=='y' || c=='Y')
                {
                  continue;
                }
                else
                {
                    break;
                }
                }

                }while (ch!=6);
               
            }
            fwrite(&e,sizeof(Emp),1,fp1);
        }
        fclose(fp);
        fclose(fp1);
       
        if(found==1)
        {
             fp=fopen("D:/cp/Projects/Employees.txt","w+");
             fp1=fopen("D:/cp/Projects/Temp.txt","r+");
             while(fread(&e, sizeof(Emp),1,fp1))
             {
                  fwrite(&e,sizeof(Emp),1,fp);
             }
            fclose(fp);
            fclose(fp1);
            if(ch!=6)
            {
            printf("\nRecord Updated Successfully..........!\n");
            }
        }
        else
        {
            printf("\nThe Eployee ID is not found........Try Again.........!\n");
        }
    }
}
void Delete()   //Delete Records
{
    FILE *fp,*fp1;
    
    if(fp==NULL)
    {
        printf("\nUnable to access file........Try Again....!!");
    }
    else
    {
        fp=fopen("D:/cp/Projects/Employees.txt","r");
        fp1=fopen("D:/cp/Projects/Temp.txt","w");
        Emp e;
        printf("\nEnter the Employee ID you want to Delete : ");
        int ID,found=0;
        scanf("%d",&ID);

         while(fread(&e, sizeof(Emp),1,fp))
        {
            if(e.emp_id==ID)
            {
                found=1;   
            } 
            else
            {
                 fwrite(&e,sizeof(Emp),1,fp1);
            }
        }
        fclose(fp);
        fclose(fp1);
       
        if(found==1)
        {
             fp=fopen("D:/cp/Projects/Employees.txt","w+");
             fp1=fopen("D:/cp/Projects/Temp.txt","r+");
             while(fread(&e, sizeof(Emp),1,fp1))
             {
                  fwrite(&e,sizeof(Emp),1,fp);
             }
              fclose(fp);
             fclose(fp1);
             printf("\nRecord Deleted Successfully..........!\n");
        }
        else
        {
            printf("\nThe Eployee ID is not found........Try Again.........!\n");
        }  
    }
}