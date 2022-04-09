#include <stdio.h>
#include <string.h>

/*

   Functions:

   add to read (done)
   add to unread (done)
   seaarch using name (done)
   find highest rated (done)
   add form unread to read 
   delete from read (done)
   delete form unread (done)
   view all read
   view all unread


    */

void addRead();
void addUnread();
void search(char sk[30]);   
void deleteUnread(char sk[30]);
int highestRated();
void deleteRead(char sk[30]);
void addUnrRea();


struct read{

    char name[30];
    char author[30];
    char genre[20];
    int stars;  
    
};

struct unread{

    char name[30];
    char author[30];
    char genre[20];
    
};



int main(){

    int br=1, choice=0;

    while(br){

        printf("MENU\nEnter the option number \n");
        printf("(1) add to read \n(2) add to unread \n(3) search using name\n(4) find highest rated \n(5) add from unread to read \n(6) delete from read\n(7) delete form unread \n(8) exit\n");

        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            addRead();
            break;

        case 2:
            addUnread();
            break;
        case 3:
            char key[30];
            printf("enter the name of the book you want search\n");
            scanf("%s",key);
            search(key);
            break;

        case 4:

            int top=0;
            top=highestRated();
            printf("%d",top);
            break;

        case 5:

            addUnrRea();
            break;

        case 6:

            char key1[30];
            printf("enter the name of the book you want to delete\n");
            scanf("%s",key1);
            deleteRead(key1);
            break;

        case 7:

            char key2[30];
            printf("enter the name of the book you want to delete\n");
            scanf("%s",key2);
            deleteUnread(key2);
            break;

        case 8:

            printf("okay terminating\n");
            br=0;
            break;
        
        default:
            printf("Invalid choice. Please try again");

            break;
        }


    }


    
}



void search(char sk[30]){

    FILE *inf;
    struct read inp;

    inf = fopen ("read.txt", "r");
    if (inf == NULL) {
        fprintf(stderr, "\nError to open the file\n");
        //exit (1);
    }
    while(fread(&inp, sizeof(struct read), 1, inf)){
    
      if(!strcmp(sk,inp.name)){
          
          printf("Name= %s\n Author= %s\n Genre= %s\n Rating =%d\n",inp.name,inp.author,inp.genre,inp.stars);
          break;
          exit(1);
      }
    }

   fclose (inf);   

}

void deleteUnread(char sk[30]){

    FILE *inf;
    struct unread inp;
    struct unread unreadbooks[100]; 
    int counter=0;

    inf = fopen ("unread.txt", "r");
    if (inf == NULL) {
        fprintf(stderr, "\nError to open the file\n");
        //exit (1);
    }
    while(fread(&inp, sizeof(struct unread), 1, inf)){

      strcpy(unreadbooks[counter].name,inp.name);
      strcpy(unreadbooks[counter].author,inp.author);
      strcpy(unreadbooks[counter].genre,inp.genre);

      counter++;
    }

   fclose (inf);   

   for(int i=0;i<counter;i++){
       printf("%s %s %s \n", unreadbooks[i].name, unreadbooks[i].author, unreadbooks[i].genre);
       exit(1);
   }

    FILE *outfile;
     
    // open file for writing
    outfile = fopen ("unread.txt", "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        //exit (1);
    }
 
   for(int i=0;i<counter;i++){
       // write struct to file

    if(strcmp(sk,unreadbooks[i].name)){
    fwrite(&unreadbooks[i], sizeof(struct unread) ,1 ,outfile);
    
       
   }
     
     fclose (outfile);

 
    return;


}

}

void addRead(){

     FILE *outfile;
     
    // open file for writing
    outfile = fopen ("read.txt", "a");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        //exit (1);
    }

    struct read a;

    printf("Enter the details of the book you just read in the format below\n");
    printf("Name\n"); scanf("%s",&a.name);
    printf("Author\n"); scanf("%s",&a.author);
    printf("genre\n"); scanf("%s", &a.genre);
    printf("rating (out of 5)\n"); scanf("%d",&a.stars);    

    /*
    strcpy(a.name,name);
    strcpy(a.author,author);
    strcpy(a.genre,genre);
    a.stars=stars;*/
     
    // write struct to file
    fwrite(&a, sizeof(struct read) ,1 ,outfile);
     
    if(fwrite != 0){
        printf("contents to file written successfully !\n");
    }
    else{
        printf("error writing file !\n");
    }
 
    // close file
    fclose (outfile);
 
    return;

}

void addUnread(){

         FILE *outfile;
     
    // open file for writing
    outfile = fopen ("unread.txt", "a");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        //exit (1);
    }


    struct unread a;

    printf("Enter the details of the book you want to read\n");
    printf("Name\n"); scanf("%s",&a.name);
    printf("Author\n"); scanf("%s",&a.author);
    printf("genre\n"); scanf("%s", &a.genre);

     
    // write struct to file
    fwrite(&a, sizeof(struct unread) ,1 ,outfile);
     
    if(fwrite != 0){
        printf("contents to file written successfully !\n");
    }
    else{
        printf("error writing file !\n");
    }
 
    // close file
    fclose (outfile);
 
    return;

}

int highestRated(){

    FILE *inf;
    struct read inp;

    int highest=0;
    char bookname[30];

    inf = fopen ("read.txt", "r");
    if (inf == NULL) {
        fprintf(stderr, "\nError to open the file\n");
        //exit (1);
    }
    while(fread(&inp, sizeof(struct read), 1, inf)){
      printf ("stars = %d\n", inp.stars);

      if(inp.stars>highest){

          highest=inp.stars;
          strcpy(bookname,inp.name);

      }
    }

   fclose (inf); 

   printf("%s\n",bookname);
   return highest;

}

void deleteRead(char sk[30]){
    FILE *inf;
    struct read inp;
    struct read readbooks[100]; 
    int counter=0;

    inf = fopen ("read.txt", "r");
    if (inf == NULL) {
        fprintf(stderr, "\nError to open the file\n");
        //exit (1);
    }
    while(fread(&inp, sizeof(struct read), 1, inf)){

      strcpy(readbooks[counter].name,inp.name);
      strcpy(readbooks[counter].author,inp.author);
      strcpy(readbooks[counter].genre,inp.genre);
      readbooks[counter].stars=inp.stars;

      counter++;
    }

   fclose (inf);   

   for(int i=0;i<counter;i++){
       printf("%s %s %s %d\n", readbooks[i].name, readbooks[i].author, readbooks[i].genre,readbooks[i].stars);
   }

    FILE *outfile;
     
    // open file for writing
    outfile = fopen ("read.txt", "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        //exit (1);
    }
 
   for(int i=0;i<counter;i++){
       // write struct to file

    if(strcmp(sk,readbooks[i].name)){
    fwrite(&readbooks[i], sizeof(struct read) ,1 ,outfile);

    //printf("written into file\n");
    //printf("%s %s %s %d\n", readbooks[i].name, readbooks[i].author, readbooks[i].genre,readbooks[i].stars);
    }
    // close file
    
       
   }
     
     fclose (outfile);

 
    return;

}

void addUnrRea(){
         FILE *outfile;
     
    // open file for writing
    outfile = fopen ("read.txt", "a");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        //exit (1);
    }

    struct read a;

    printf("Enter the details of the book you just read in the format below\n");
    printf("Name\n"); scanf("%s",&a.name);
    printf("Author\n"); scanf("%s",&a.author);
    printf("genre\n"); scanf("%s", &a.genre);
    printf("rating (out of 5)\n"); scanf("%d",&a.stars);    
     
    // write struct to file
    fwrite(&a, sizeof(struct read) ,1 ,outfile);
     
    if(fwrite != 0){
        printf("contents to file written successfully !\n");
    }
    else{
        printf("error writing file !\n");
    }
 
    // close file
    fclose (outfile);
 
    return;

    deleteRead(a.name);
    
}