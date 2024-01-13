// Name: Kanishk
// Date: 2023-04-06
// Garage Management

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

//Contains numbers of structure to write data in file
struct userCount{
    int count;
};

//Contain the Data of cars
typedef struct Cars{
    int year;
    char make[20];
    char model[20];
    char owner[50];
} Car;

// THe main structure
struct prt{
    char mechanic[50];
    char garage[50];
    Car car;
    char problem[100];
    char part[50];
    float partCost;
    float laborHours;
    float repairCost;
    struct prt* next;
};

//Declaring Structure and function
struct prt *MemoryCleanUp(struct prt *start);
int convert(char word[50],char word2[50]);
void DisplayLinkedList(struct prt *start);
struct prt *GenerateLinkedList();
void searchByName(struct prt *start);
bool choice();
void linkedlist_w(struct prt *start, struct userCount *time);
struct prt* read_linked_list_from_file();
void sort(struct prt *start);
void deleteEntry(struct prt *start,struct userCount *time);
void modify(struct prt *start);
//-------------------------------------------------------------------------------------------

int main(){

    //Base structure point that will contain the address of starting of linked list.
    struct prt * base =NULL;
    int option;
    int ch;
    bool condition = true;
    struct userCount *time = NULL;
    if(choice() == false){
        time = (struct userCount*)malloc(sizeof(struct userCount));
        base = read_linked_list_from_file(time);
        puts("Data Uploaded..");
    }else{
        time = (struct userCount*)malloc(sizeof(struct userCount));
        time ->count = 0;
    }

    while(condition){
        puts("1) Add new entries \n");
        puts("2) Browse entries \n");
        puts("3) Modify entry \n");
        puts("4) Delete entry \n");
        puts("5) Save data \n");
        puts("6) Search Mechanic Name \n");
        puts("7) Exit");
        scanf("%d",&option);
        while ( (ch = getchar() ) != '\n' && ch != EOF );
        
    
        switch(option){    
            case 1: base = GenerateLinkedList(base,time);break;  //optional  
            case 2: DisplayLinkedList(base);
                    break;  
            case 3: modify(base); break;
            case 4: deleteEntry(base,time); break;
            case 5: linkedlist_w(base,time); break;  //optional  
            case 6: searchByName(base); break;
            case 7: condition = false;
                    MemoryCleanUp(base);
                    break;
            default: puts("INVALID...");       
        }  
    }

    puts("finished");
}
struct prt *GenerateLinkedList(struct prt* start1,struct userCount *pastCount){
    // Declaring pointer for Start Last New
    struct prt *start = NULL, *last = NULL, *new = NULL;
    // struct userCount *time = NULL;
    char keepGoing = 'y';
    int ch;
    if (start1 != NULL){
        start = start1;
        new = start1;
        // time = pastCount;
    }
    while (keepGoing == 'y'){
    if (start == NULL){
        new = (struct prt *)malloc(sizeof(struct prt));
        if (new == NULL) {
            puts("memory allocation error");
            exit(1);
        }

        //assign address of new to start
        start = new;

        //collect the values to store in the first node
        puts("Enter Mechanic Name:"); scanf("%s", new->mechanic);
        while ( (ch = getchar() ) != '\n' && ch != EOF );
        puts("Enter Garage:"); scanf("%s", new->garage);
        while ( (ch = getchar() ) != '\n' && ch != EOF );
        puts("Enter Car year"); scanf("%d", &new->car.year);
        while ( (ch = getchar() ) != '\n' && ch != EOF );
        puts("Enter Car Make:"); scanf("%s", &new->car.make);
        while ( (ch = getchar() ) != '\n' && ch != EOF );
        puts("Enter Car Model:"); scanf("%s", &new->car.model);
        while ( (ch = getchar() ) != '\n' && ch != EOF );
        puts("Enter Car Owner Name"); scanf("%s", new->car.owner);
        while ( (ch = getchar() ) != '\n' && ch != EOF );
        puts("Enter Car Problem"); scanf("%s", new->problem);
        while ( (ch = getchar() ) != '\n' && ch != EOF );
        puts("Enter type of car parts require"); scanf("%s", new->part);
        while ( (ch = getchar() ) != '\n' && ch != EOF );
        puts("Enter Car Part Cost"); scanf("%f", &new->partCost);
        while ( (ch = getchar() ) != '\n' && ch != EOF );
        puts("Enter Car Labour Hour"); scanf("%f", &new->laborHours);
        while ( (ch = getchar() ) != '\n' && ch != EOF );
        new ->repairCost = new->partCost * new->laborHours;

        //Make the next to null which means nothing follows afterward
        new->next = NULL;

        //Count the Structures
        pastCount->count += 1;

    } else{
        last = start;
        while (last->next != NULL) {
                last = last->next;
            }
        
        new = (struct prt *)malloc(sizeof(struct prt));
        if (new == NULL) {
            puts("memory allocation error");
            exit(true);
        }

        //tie it into the old list
        last->next = new;
        //fill in data
        //collect the values to store in the first node
        puts("Enter Mechanic Name:"); scanf("%s", new->mechanic);
        while ( (ch = getchar() ) != '\n' && ch != EOF );
        puts("Enter Garage:"); scanf("%s", new->garage);
        while ( (ch = getchar() ) != '\n' && ch != EOF );
        puts("Enter Car year"); scanf("%d", &new->car.year);
        while ( (ch = getchar() ) != '\n' && ch != EOF );
        puts("Enter Car Make:"); scanf("%s", &new->car.make);
        while ( (ch = getchar() ) != '\n' && ch != EOF );
        puts("Enter Car Model:"); scanf("%s", &new->car.model);
        while ( (ch = getchar() ) != '\n' && ch != EOF );
        puts("Enter Car Owner Name"); scanf("%s", new->car.owner);
        while ( (ch = getchar() ) != '\n' && ch != EOF );
        puts("Enter Car Problem"); scanf("%s", new->problem);
        while ( (ch = getchar() ) != '\n' && ch != EOF );
        puts("Enter type of car parts require"); scanf("%s", new->part);
        while ( (ch = getchar() ) != '\n' && ch != EOF );
        puts("Enter Car Part Cost"); scanf("%f", &new->partCost);
        while ( (ch = getchar() ) != '\n' && ch != EOF );
        puts("Enter Car Labour Hour"); scanf("%f", &new->laborHours);
        while ( (ch = getchar() ) != '\n' && ch != EOF );
        new ->repairCost = new->partCost * new->laborHours;

        
        new->next = NULL;
        //Count the number of structures
        pastCount->count += 1;
    }

    //Ask for new node
    puts("Create new node?");
    scanf("%c", &keepGoing);
    while ( (ch = getchar() ) != '\n' && ch != EOF );}
    

    return start;
}
void DisplayLinkedList(struct prt *start){
    
    //Sort the previous linked list
    sort(start);
    if(start == NULL){
        puts("Data Not Available");
    }else{
        struct prt *move = start;

        while (move->next != NULL) {
        printf("Mechanic Name:%s \n",move -> mechanic);
        printf("Garage Name  :%s \n",move -> garage);
        printf("Car Year     :%d \n", move -> car.year);
        printf("Car Make     :%s \n", move -> car.make);
        printf("Car Model    :%s \n", move -> car.model);
        printf("Car Owner    :%s \n", move -> car.owner);
        printf("Car Problem  :%s \n",move -> problem);
        printf("Parts Require:%s \n",move -> part);
        printf("Parts Cost   :%.2f \n",move -> partCost);
        printf("Labour Hours :%.2f \n",move -> laborHours);
        printf("Repair Cost  :%.2f \n",move -> repairCost);
        printf("-----------------------------------\n");
        move = move->next;
    }

    // Printing the end of linked list with points to NULL 
        printf("Mechanic Name:%s \n",move -> mechanic);
        printf("Garage Name  :%s \n",move -> garage);
        printf("Car Year     :%d \n", move -> car.year);
        printf("Car Make     :%s \n", move -> car.make);
        printf("Car Model    :%s \n", move -> car.model);
        printf("Car Owner    :%s \n", move -> car.owner);
        printf("Car Problem  :%s \n",move -> problem);
        printf("Parts Require:%s \n",move -> part);
        printf("Parts Cost   :%.2f \n",move -> partCost);
        printf("Labour Hours :%.2f \n",move -> laborHours);
        printf("Repair Cost  :%.2f \n",move -> repairCost);
        puts("\n");
    }
    
}

bool choice(){
    char inpt[100];
    struct user *userr = NULL;
    int ch;
    puts("Start With New Data Press YES, Otherwise Type NO");
    scanf("%s", &inpt);
    while ( (ch = getchar() ) != '\n' && ch != EOF );
    if(strcmp("YES",inpt) == 0){
        return true;
    }else{
        return false;
    }
}

void linkedlist_w(struct prt *start,struct userCount *time){
    FILE* file;
    file = fopen("xyz.txt","w");
    if (file == NULL) {
        puts("File does not have data");
    }else{
        fprintf(file, "%d\n", time->count);
        while(start ->next != NULL){
        fprintf(file, "%s\n", start->mechanic);
        fprintf(file, "%s\n", start->garage);
        fprintf(file, "%d\n", start->car.year);
        fprintf(file, "%s\n", start->car.make);
        fprintf(file, "%s\n", start->car.model);
        fprintf(file, "%s\n", start->car.owner);
        fprintf(file, "%s\n", start->problem);
        fprintf(file, "%s\n", start->part);
        fprintf(file, "%.2f\n", start->partCost);
        fprintf(file, "%.2f\n", start->laborHours);
        fprintf(file, "%.2f\n", start->repairCost);
        start = start -> next;}
        fprintf(file, "%s\n", start->mechanic);
        fprintf(file, "%s\n", start->garage);
        fprintf(file, "%d\n", start->car.year);
        fprintf(file, "%s\n", start->car.make);
        fprintf(file, "%s\n", start->car.model);
        fprintf(file, "%s\n", start->car.owner);
        fprintf(file, "%s\n", start->problem);
        fprintf(file, "%s\n", start->part);
        fprintf(file, "%.2f\n", start->partCost);
        fprintf(file, "%.2f\n", start->laborHours);
        fprintf(file, "%.2f\n", start->repairCost);
        puts("Uploaded Successfully.....");
    }
    fclose(file);
   
}

struct prt* read_linked_list_from_file(struct userCount *time) {
    FILE* file = fopen("xyz.txt", "r");
    if (file == NULL) {
        return NULL;
    }
    struct prt* head = NULL;
    struct prt* tail = NULL;
    // time = (struct userCount*)malloc(sizeof(struct userCount));

    char mechanic[50];
    char garage[50];
    int year;
    char make[20];
    char model[20];
    char owner[50];
    char problem[100];
    char part[50];
    float partCost;
    float laborHours;
    float repairCost;
    struct prt* old = NULL;

    fscanf(file,"%d",&time->count);
    // node = (struct prt1 *)malloc(sizeof(struct prt1));
    for(int i = 0; i<time -> count;i++){
        old = (struct prt *)malloc(sizeof(struct prt));

        //Copying the data line by line of structure from the text file to variable. 
        fscanf(file, "%s",mechanic);
        fscanf(file, "%s",garage);
        fscanf(file, "%d",&year);
        fscanf(file, "%s",make);
        fscanf(file, "%s",model);
        fscanf(file, "%s",owner);
        fscanf(file, "%s",problem);
        fscanf(file, "%s",part);
        fscanf(file, "%f",&partCost);
        fscanf(file, "%f",&laborHours);
        fscanf(file, "%f",&repairCost);
        
        //Inserting Data to the structure 
        strcpy(old->mechanic, mechanic);
        strcpy(old-> garage, garage);
        old-> car.year = year;
        strcpy(old-> car.make, make);
        strcpy(old-> car.model, model);
        strcpy(old-> car.owner, owner);
        strcpy(old-> problem, problem);
        strcpy(old-> part, part);
        old-> partCost = partCost;
        old-> laborHours = laborHours;
        old-> repairCost = repairCost;
        
        old->next = NULL;

        //Taking the initial structure of the linked list
        if (head == NULL) {
            head = old;
        }else{
            //Inserting the address of last array to the new structure.
            tail->next = old;
        }
        tail = old;
    }
    fclose(file);
    return head;
}
void searchByName(struct prt *start){
    char name[50];
    char structName[50];
    int ch;
    puts("Enter Mechanic Name");
    scanf("%s",name);
    while ( (ch = getchar() ) != '\n' && ch != EOF );
    for(int j = 0; name[j] != '\0'; j++){
      name[j] = tolower(name[j]);
    }
    while(true){
        strcpy(structName, start->mechanic);
        for(int j = 0; structName[j] != '\0'; j++){
        structName[j] = tolower(structName[j]);}
        if(strcmp(name,structName) == 0){
            printf("-----------------------------------\n");
            printf("Mechanic Name:%s \n",start-> mechanic);
            printf("Garage Name  :%s \n",start-> garage);
            printf("Car Year     :%d \n",start -> car.year);
            printf("Car Make     :%s \n",start -> car.make);
            printf("Car Model    :%s \n",start -> car.model);
            printf("Car Owner    :%s \n",start -> car.owner);
            printf("Car Problem  :%s \n",start-> problem);
            printf("Parts Require:%s \n",start-> part);
            printf("Parts Cost   :%.2f \n",start -> partCost);
            printf("Labour Hours :%.2f \n",start -> laborHours);
            printf("Repair Cost  :%.2f \n",start -> repairCost);
            printf("-----------------------------------\n");
            break;
        }
        else if(start -> next == NULL){
            puts("NO FOUNDS ERROR 404\n");
            break;
        }else{
            start = start -> next;
        }  
    }
}

void modify(struct prt *start){

    if(start == NULL){
        puts("No Data \n");
    }else{
        int find;
        int ch;
        puts("Enter index of it in the list: \n");
        scanf("%d",&find);
        while ( (ch = getchar() ) != '\n' && ch != EOF );
        struct prt* new = start;
        if(find == 1){
            puts("Enter Mechanic Name:"); scanf("%s", new->mechanic);
            while ( (ch = getchar() ) != '\n' && ch != EOF );
            puts("Enter Garage:"); scanf("%s", new->garage);
            while ( (ch = getchar() ) != '\n' && ch != EOF );
            puts("Enter Car year"); scanf("%d", &new->car.year);
            while ( (ch = getchar() ) != '\n' && ch != EOF );
            puts("Enter Car Make:"); scanf("%s", &new->car.make);
            while ( (ch = getchar() ) != '\n' && ch != EOF );
            puts("Enter Car Model:"); scanf("%s", &new->car.model);
            while ( (ch = getchar() ) != '\n' && ch != EOF );
            puts("Enter Car Owner Name"); scanf("%s", new->car.owner);
            while ( (ch = getchar() ) != '\n' && ch != EOF );
            puts("Enter Car Problem"); scanf("%s", new->problem);
            while ( (ch = getchar() ) != '\n' && ch != EOF );
            puts("Enter Car part require"); scanf("%s", new->part);
            while ( (ch = getchar() ) != '\n' && ch != EOF );
            puts("Enter Car Part Cost"); scanf("%f", &new->partCost);
            while ( (ch = getchar() ) != '\n' && ch != EOF );
            puts("Enter Car Labour Hour"); scanf("%f", &new->laborHours);
            while ( (ch = getchar() ) != '\n' && ch != EOF );
            new ->repairCost = new->partCost * new->laborHours;
        }else{
            for (int i = 0;find > i; i++){
                if(find == (i+1)){
                    puts("Enter Mechanic Name:"); scanf("%s", new->mechanic);
                    while ( (ch = getchar() ) != '\n' && ch != EOF );
                    puts("Enter Garage:"); scanf("%s", new->garage);
                    while ( (ch = getchar() ) != '\n' && ch != EOF );
                    puts("Enter Car year"); scanf("%d", &new->car.year);
                    while ( (ch = getchar() ) != '\n' && ch != EOF );
                    puts("Enter Car Make:"); scanf("%s", &new->car.make);
                    while ( (ch = getchar() ) != '\n' && ch != EOF );
                    puts("Enter Car Model:"); scanf("%s", &new->car.model);
                    while ( (ch = getchar() ) != '\n' && ch != EOF );
                    puts("Enter Car Owner Name"); scanf("%s", new->car.owner);
                    while ( (ch = getchar() ) != '\n' && ch != EOF );
                    puts("Enter Car Problem"); scanf("%s", new->problem);
                    while ( (ch = getchar() ) != '\n' && ch != EOF );
                    puts("Enter Car part require"); scanf("%s", new->part);
                    while ( (ch = getchar() ) != '\n' && ch != EOF );
                    puts("Enter Car Part Cost"); scanf("%f", &new->partCost);
                    while ( (ch = getchar() ) != '\n' && ch != EOF );
                    puts("Enter Car Labour Hour"); scanf("%f", &new->laborHours);
                    while ( (ch = getchar() ) != '\n' && ch != EOF );
                    new ->repairCost = new->partCost * new->laborHours;
                }else{
                    new = new -> next;}
        }
        }
    }
}
void deleteEntry(struct prt *start, struct userCount *time){
    int find;
    int ch;

    struct prt *snd = NULL;
    struct prt *new = NULL;
    if (start == NULL){
        puts("No Data Available");
    }else{
        puts("Enter the Index of the Data want to delete: \n");
        scanf("%d",&find);
        while ( (ch = getchar() ) != '\n' && ch != EOF );
        
        new = start;
        if(find == 1){
            free(new);
            time ->count -= 1;
        }else if(time->count >= find){
            for (int i = 0;find > i; i++){
                if(i == (find - 1)){
                    snd -> next = new -> next;
                    free(new);
                    time ->count -= 1;
                }else{
                    snd = new;
                    new = new -> next;
                }
            }
        }
    }
}

void sort(struct prt *start)
{
    struct prt *ptr, *ptr2;
    char s1[50], s2[50], s3[50], s4[50], s5[50], s6[50], s7[50];
    int a, b , c , d;
    
    for (ptr = start; ptr != NULL; ptr = ptr->next)
    {
        for (ptr2 = ptr->next; ptr2 != NULL; ptr2 = ptr2->next)
        {
            if (convert(ptr->mechanic, ptr2->mechanic) > 0)
            {
                // swap book names
                strcpy(s7, ptr->mechanic);
                strcpy(ptr->mechanic, ptr2->mechanic);
                strcpy(ptr2->mechanic, s7);

                strcpy(s1, ptr ->garage);
                strcpy(ptr-> garage, ptr2 ->garage);
                strcpy(ptr2-> garage, s1);
                
                
                a = ptr ->car.year;     
                ptr-> car.year = ptr2 ->car.year;
                ptr2-> car.year = a;

                strcpy(s2, ptr ->car.make);
                strcpy(ptr-> car.make, ptr2 ->car.make);
                strcpy(ptr2-> car.make, s2);


                strcpy(s3, ptr ->car.model);
                strcpy(ptr-> car.model, ptr2 ->car.model);
                strcpy(ptr2-> car.model, s3);


                strcpy(s4, ptr ->car.owner);
                strcpy(ptr-> car.owner, ptr2 ->car.owner);
                strcpy(ptr2-> car.owner, s4);
                
                
                strcpy(s5, ptr ->problem);
                strcpy(ptr-> problem, ptr2 ->problem);     
                strcpy(ptr2-> problem, s5);


                strcpy(s6, ptr ->part);
                strcpy(ptr-> part, ptr2 ->part);
                strcpy(ptr2-> part, s6);

                b = ptr ->partCost;
                ptr-> partCost = ptr2 ->partCost;
                ptr2-> partCost = b;

                c = ptr ->laborHours;
                ptr-> laborHours = ptr2 ->laborHours;
                ptr2-> laborHours = c;

                d = ptr ->repairCost;
                ptr-> repairCost = ptr2 ->repairCost;
                ptr2-> repairCost = d;
                
            }
        }
    }
}

// return an Integer value after comparing the string
int convert(char word[50],char word2[50]){
    for(int j = 0; word[j] != '\0'; j++){
      word[j] = tolower(word[j]);
    }
    for(int l = 0; word2[l] != '\0'; l++){
      word2[l] = tolower(word2[l]);
    }
    return strcmp(word, word2);
    
}

// to clean up the memory
struct prt *MemoryCleanUp(struct prt *start){
    struct prt *move = start;

    while (move->next != NULL) {
        struct prt* lst = move;
        move = move->next;
        free(lst);
    }
    //free last node
    free(move);

    puts("all done");

    return NULL;
}
