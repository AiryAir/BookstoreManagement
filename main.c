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
void allRead();
void allUnread();
void addUnrRea(char sk[30]);



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

        printf("\n===============MENU==============\n\n");
        printf("(1) Add to READ \n(2) Add to UNREAD \n(3) Search READ\n(4) Search UNREAD\n(5) Find highest rated \n(6) Add from unread to read \n(7) Delete from READ\n(8) Delete form UNREAD \n(9) View all read\n(10) View All unread\n(11) EXIT\n\nEnter your choice: ");

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
                printf("not ready yet\n");
                break;

        case 5:

            int top=0;
            top=highestRated();
            printf("%d",top);
            break;

        case 6:

            char key4[30];
            printf("enter the name of the book you just read\n");
            scanf("%s",key4);
            addUnrRea(key4);
            break;

        case 7:

            char key1[30];
            printf("enter the name of the book you want to delete\n");
            scanf("%s",key1);
            deleteRead(key1);
            break;

        case 8:

            char key2[30];
            printf("enter the name of the book you want to delete\n");
            scanf("%s",key2);
            deleteUnread(key2);
            break;

        case 9:  
                printf("All Read\n");
                allRead();
                break;

        case 10:
                printf("All Unread\n");
                allUnread();
                break;

        case 11:

            printf("Terminating\n");
            br=0;
            break;
        
        default:
            printf("Invalid choice. Please try again");

            break;
        }


    }


    
}

void allRead(){

    FILE *inf;
    inf=fopen("read.txt","r");
    struct read r;
    while(fscanf(inf,"%s %s %s %d",r.name,r.author,r.genre,&r.stars)!=EOF){
        printf("%s %s %s %d\n",r.name,r.author,r.genre,r.stars);
    }
}

void allUnread(){
    
        FILE *inf;
        inf=fopen("unread.txt","r");
        struct unread r;
        while(fscanf(inf,"%s %s %s",r.name,r.author,r.genre)!=EOF){
            printf("%s %s %s\n",r.name,r.author,r.genre);
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

    printf("\nEnter the details of the book you just read in the format below\n");
    printf("\nName: "); scanf("%s",&a.name);
    printf("\nAuthor: "); scanf("%s",&a.author);
    printf("\nGenre: "); scanf("%s", &a.genre);
    printf("\nRating (Out of 5): "); scanf("%d",&a.stars);

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

void addUnrRea(char sk[30]){

    struct read a;

    FILE *inf;
    struct unread inp;

    inf = fopen ("unread.txt", "r");
    if (inf == NULL) {
        fprintf(stderr, "\nError to open the file\n");
        //exit (1);
    }
    while(fread(&inp, sizeof(struct unread), 1, inf)){
      printf ("name = %s\n", inp.name);
      if(!strcmp(sk,inp.name)){

        strcpy(a.name,inp.name);
        strcpy(a.author,inp.author);
        strcpy(a.genre,inp.genre);
        printf("rating (out of 5)\n"); scanf("%d",&a.stars);

          break;
          exit(1);
      }
    

   fclose (inf);   
}

    
    FILE *outfile;
     
    // open file for writing
    outfile = fopen ("read.txt", "a");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        //exit (1);
    }
        
     
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
 

    deleteRead(a.name);
    
}
