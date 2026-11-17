#include<stdio.h>
#include<string.h>

struct student
{
    char regNo[20];
    char name[30];
    int m1,m2,m3;
    int total;
    float percentage;
    char result[10];
};
int main()
{
    struct student s[50];
    int count=0,choice,i,found;
    char key [20];
    FILE *fp;

    do
    {
        printf("\n1. Add student record");
        printf("\n2. Display all records");
        printf("\n3. Search record by registration number");
        printf("\n4. Write recors from file");
        printf("\n5. Read records from file");
        printf("\n6. Exit");
        printf("\n enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            if(count == 50)
            {
                printf("record limit reached");
                break;
            }
            printf("Enter registration number: ");
            scanf("%s", s[count].regNo);
            printf("Enter student name (one word): ");
            scanf("%s", s[count].name);
            printf("enter marks of 3 subjects: ");
            scanf("%d %d %d", &s[count].m1, &s[count].m2, &s[count].m3);
             
            if(s[count].m1 < 0|| s[count].m1>100 || s[count].m2 < 0 || s[count].m2 > 100 || s[count].m3 < 0 || s[count].m3 > 100)
            {
                printf("Invalid marks .\n");
                break;
            }
            s[count].total = s[count].m1 + s[count].m2 + s[count].m3;
            s[count].percentage = s[count].total / 3.0f;

            if (s[count].m1>=35 && s[count].m2 >=35 && s[count].m3 >=35)
            {
                strcpy(s[count].result, "Pass");
            }
            else
            
                strcpy(s[count].result, "Fail");

            count++;
            printf("Record added successfully.\n");
            break;

            case2:
            if(count == 0)
            {
                printf("No records available.\n");
                break;
            }
            for(i=0; i<count; i++)
            {
                printf("\nRegistration Number: %s", s[i].regNo);
                printf("\nName: %s", s[i].name);
                printf("\nMarks: %d, %d, %d", s[i].m1, s[i].m2, s[i].m3);
                printf("\nTotal: %d", s[i].total);
                printf("\nPercentage: %.2f", s[i].percentage);
                printf("\nResult: %s\n", s[i].result);
            }
            break;

            case3:
            printf("Enter registration number to search: ");
            scanf("%s", key);
            found = 0;
            for(i=0; i<count; i++)
            {
                if(strcmp(s[i].regNo, key) == 0)
                {
                    
                    
                    printf("\nName: %s", s[i].name);
                     printf("\nTotal: %d", s[i].total);
                    printf("\nPercentage: %.2f", s[i].percentage);
                    printf("\nResult: %s\n", s[i].result);
                    found = 1;
                    break;
                }
            }
            if(found == 0)
            printf("record not found.\n");
            break;

            case 4:
            fp=fopen("student.txt","w");

            if(fp==NULL)
            {
                printf("unable to open file.\n");
                break;
            }
            for(i=0;i<count;i++)
            {
                fprintf(fp,"%s %s %d %d %d %d %f %s\n,s[i].regNo,s[i].name,s[i].m1,s[i].m2,s[i].m3,s[i].total,s[i].percentage,s[i].result");
            }
            fclose(fp);
            printf("records written to student.txt.\n");
            break;

            case 5:
            fp=fopen("student.txt","r");

            if(fp == NULL)
            {
                printf("unable to open students.txt.\n");
                break ;
            }
            count = 0;

            while(count < 50 &&
            fscanf(fp,"%s %s %d %d %d %d %f %s",
            s[count].regNo,s[count].name,
        &s[count].m1,&s[count].m2,&s[count].m3,
         &s[count].total,&s[count].percentage,
        s[count].result) == 8)
        {
            count++;
        }
        fclose(fp);
        printf("%d record(s) read from student.txt.\n",count);
        break;

        case 6:
        printf("program ended.\n");
        break;

        default:
        printf("Invalid choice.\n");
    }
}
while(choice != 6);
return 0;
}



        

    

