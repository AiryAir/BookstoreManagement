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


//all functions declared here
void addRead();
void addUnread();
void search(char sk[30]);
void searchUnread(char sk[30]);   
void deleteUnread();
int highestRated();
void deleteRead(char sk[30]);
//void addUnrRea();
void allRead();
void allUnread();
void addUnrRea(char sk[30]);


//struct for books that have been read
//includes name, author, rating, and genre
struct read{

    char name[30];
    char author[30];
    char genre[20];
    int stars;  
    
};

//struct for books that have not been read
//includes name, author and genre

struct unread{

    char name[30];
    char author[30];
    char genre[20];
    
};



//main function, ie, the menu of the program
//the user can choose from the following options

int main(){

    int br=1, choice=0;

    while(br){

        printf("\n===============MENU==============\n\n");
        printf("(1) Add to READ \n(2) Add to UNREAD \n(3) Search READ\n(4) Search UNREAD\n(5) Find highest rated \n(6) Add from unread to read \n(7) View all read\n(8) View All unread\n(9) EXIT\n\nEnter your choice: ");

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
            printf("\nEnter the name of the book you want to find: ");
            scanf("%s",key);
            search(key);
            break;

        case 4:
            char key0[30];
            printf("\nEnter the name of the book you want to find1: ");
            scanf("%s",key);
            searchUnread(key);
            break;

        case 5:
            int top=0;
            top=highestRated();
            printf("%d",top);
            break;

        case 6:
            char key4[30];
            printf("Mark book as read\n");
            printf("Enter name of book: ");
            scanf("%s",key4);
            addUnrRea(key4);
            break;

        case 7:
            printf("\nAll Read\n");
            allRead();
            break;

        case 8:
            printf("All Unread\n");
            allUnread();
            break;

        case 9:  
            printf("\n**** G O O D B Y E ****\n\n");
            br=0;
            break;
            
        default:
            printf("Invalid choice. Please try again");
            break;
        }
    } 
}

void searchUnread(char sk[30]){

    //file pointer
    FILE *inf;

    //struct to store the data (inp being input)
    struct read inp;

    //open file, read.txt in read mode
    inf = fopen ("unread.txt", "r");

    //if function for if file exists or not
    if (inf == NULL) {
        fprintf(stderr, "\nError to open the file\n");
        //exit (1);
    }

    //while loop to read the file
    //fread if file read, input is stored in inp, size of read, file name

    //pointer to a block of memory, size in bytes of each element to be read
    //number of elements, each one with a size of size bytes
    //pointer to a FILE object that specifies an input stream
    while(fread(&inp, sizeof(struct unread), 1, inf)){
    
    //if statement to compare strings, ie, input given and to see if it exists in the file
      if(!strcmp(sk,inp.name)){
          printf("\nSearching...\n");
          printf("NAME: %s\nAUTHOR: %s\nGENRE: %s\n",inp.name,inp.author,inp.genre);
          break;
          exit(1);
      }
      else{
            printf("\nSearching...\n");
            printf("No book found\n");
            break;
            exit(1);
      }
    }

    //close file
    fclose (inf);

}

//function for to display all books that have been read
void allRead(){

    //file pointer
    FILE *inf;

    //open file read.txt in read mode
    inf=fopen("read.txt","r");

    //read data from unread in the format of read struct and print it till end of file (eof)
    struct read r;
   
    while(fread(&r,sizeof(struct read),1,inf)){
            printf("\nNAME: %s\nAUTHOR: %s\nGENRE: %s\nRATING: %d\n",r.name,r.author,r.genre,r.stars);
        }
}


//function for to display all books that have not been read
void allUnread(){
        
        //file pointer
        FILE *inf;
        //char filename[100], c;
        //open file unread.txt in read mode
        inf=fopen("unread.txt","r");

        //read data from unread in the format of unread struct and print it till end of file (eof)
        struct unread r;

        while(fread(&r,sizeof(struct unread),1,inf)){
            printf("\nNAME: %s\nAUTHOR: %s\nGENRE: %s\n\n",r.name,r.author,r.genre);
        }
}


//function to search for a book that has been read
void search(char sk[30]){

    //file pointer
    FILE *inf;

    //struct to store the data (inp being input)
    struct read inp;

    //open file, read.txt in read mode
    inf = fopen ("read.txt", "r");

    //if function for if file exists or not
    if (inf == NULL) {
        fprintf(stderr, "\nError to open the file\n");
        //exit (1);
    }

    //while loop to read the file
    //fread if file read, input is stored in inp, size of read, file name

    //pointer to a block of memory, size in bytes of each element to be read
    //number of elements, each one with a size of size bytes
    //pointer to a FILE object that specifies an input stream
    while(fread(&inp, sizeof(struct read), 1, inf)){
    
    //if statement to compare strings, ie, input given and to see if it exists in the file
      if(!strcmp(sk,inp.name)){
          printf("\nSearching...\n");
          printf("NAME: %s\nAUTHOR: %s\nGENRE: %s\nRATING: %d\n",inp.name,inp.author,inp.genre,inp.stars);
          break;
          exit(1);
      }
      else{
            printf("\nSearching...\n");
            printf("No book found\n");
            break;
            exit(1);
      }
    }

    //close file
    fclose (inf);

}

void deleteUnread(){
    FILE *inp;
    FILE *inp1;
    struct unread s;
    
    int j,name,found=0;

    inp = fopen("unread.txt","r");
    inp1 = fopen("unread1.txt","w");
    printf("enter name of book to delete: ");
    scanf("%s",name);
    
    while(fread(&s,sizeof(struct unread),1,inp)){
        if(s.name==name){
            found=1;
        }
        else{
            fwrite(&s,sizeof(struct unread),1,inp1);
        }
        
    }
    fclose(inp);  
    fclose(inp1);
    if(found){
        inp1 = fopen("unread1.txt","r");
        inp = fopen("unread.txt","w");

        while(fread(&s,sizeof(struct unread),1,inp1)){
            fwrite(&s,sizeof(struct unread),1,inp);
        }
    fclose(inp);
    fclose(inp1);
    }
    return;
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

    // write struct to file
    fwrite(&a, sizeof(struct read) ,1 ,outfile);
     
    if(fwrite != 0){
        printf("\nContents to file written successfully!\n");
    }
    else{
        printf("Error writing to file!\n");
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

    printf("\nEnter the details of the book you want to read\n");
    printf("\nName:"); scanf("%s",&a.name);
    printf("\nAuthor:"); scanf("%s",&a.author);
    printf("\nGenre: "); scanf("%s", &a.genre);

     
    // write struct to file
    fwrite(&a, sizeof(struct unread) ,1 ,outfile);
     
    if(fwrite != 0){
        printf("\nContents to file written successfully!\n");
    }
    else{
        printf("Error writing file!\n");
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
      //printf ("stars = %d\n", inp.stars);

      if(inp.stars>highest){

          highest=inp.stars;
          
          strcpy(bookname,inp.name);

      }
    }

   fclose (inf); 

   printf("\nHighest Rated Book: %s\n",bookname);
   printf("Rating: ");
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
       printf("Deleting the following data:\n");
       printf("NAME: %s\nAUTHOR: %s\nGENRE: %s\nRATING:%d\n", readbooks[i].name, readbooks[i].author, readbooks[i].genre,readbooks[i].stars);
       exit(1);
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
        printf("Rating (out of 5)\n"); scanf("%d",&a.stars);

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
        printf("Book marked as read!\n");
        exit(1);
    }
    else{
        printf("error writing file !\n");
    }
 
    // close file
    fclose (outfile);
 

    deleteRead(a.name);
    return;
}
