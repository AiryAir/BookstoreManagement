#include <stdio.h>
#include <string.h>

void addRead();
void addUnead();
void search(char sk[30]);

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

    char sk[30]="kriti";

    //addRead(); addRead();
    search(sk);

    /*

   Functions:


/
   add to read (done)
   add to unread (done)
   seaarch using name
   find highest rated
   add form unread to read 
   delete from read 
   delete form unread


    */
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
      printf ("name = %s\n", inp.name);
      if(!strcmp(sk,inp.name)){
          printf("%s %s %s %s\n",inp.name,inp.author,inp.genre,inp.stars);
          break;
      }
    }

   fclose (inf);
   

}

void addRead(){

     FILE *outfile;
     
    // open file for writing
    outfile = fopen ("read.txt", "a");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    char name[30], author[30], genre[20]; int stars;

    struct read a;

    printf("Enter the details of the book you just read in the format below\n");
    printf("Name\n"); scanf("%s",&a.name);
    printf("Author\n"); scanf("%s",&a.author);
    printf("genre\n"); scanf("%s", &a.genre);
    printf("rating (out of 5)\n"); scanf("%d",&stars);    

    /*
    strcpy(a.name,name);
    strcpy(a.author,author);
    strcpy(a.genre,genre);
    a.stars=stars;*/
     
    // write struct to file
    fwrite(&a, sizeof(struct read) ,1 ,outfile);
     
    if(fwrite != 0)
        printf("contents to file written successfully !\n");
    else
        printf("error writing file !\n");
 
    // close file
    fclose (outfile);
 
    return 0;

}
/*

void addUnread(){

     FILE *outfile;
     
    // open file for writing
    outfile = fopen ("unread.txt", "a");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    char name[30], author[30], genre[20]; 

    printf("Enter the details of the book you just read in the format below\n");
    printf("Name\n"); scanf("%s",name);
    printf("Author\n"); scanf("%s",author);
    printf("genre\n"); scanf("%s", genre);

    struct unread a={name,author,genre};
     
    // write struct to file
    fwrite(&a, sizeof(struct unread) ,1 ,outfile);
     
    if(fwrite != 0)
        printf("contents to file written successfully !\n");
    else
        printf("error writing file !\n");
 
    // close file
    fclose (outfile);
 
    return 0;

}

*/