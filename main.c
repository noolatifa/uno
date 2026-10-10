#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



//procedure pour effacer les cartes piochées du tableau
void efface (char uno[108][6],int idcarte,int taille)
{
   for(int i=idcarte;i<=taille-1;i++){
        strcpy(uno[i],uno[i+1]);
    }
}



//procedure sound
void sound()
{
  Beep(500,500);
  Beep(300,500);
  Beep(1700,500);
  Beep(1000,500);
  Beep(500,500);
  Beep(800,500);
  Beep(1200,500);

}




//affichage de joueur1
void affichage_joueur1( char joueur1[108][6] ,int j1)
{
    int i ;
    printf ("joueur1:");
    for (i=0;i<j1;i++)
{
    printf("  %s | ",joueur1[i]);
}
    }
    //affichage de joueur2
void affichage_joueur2( char joueur2[108][6] ,int j)
{
    int i ;
    printf ("joueur2:");
    for (i=0;i<j;i++)
{
    printf("  %s | ",joueur2[i]);
}
    }
// pour compter a la fin les points de joueur
 void compter(char joueur[108][6],int j,int reste)
 {
     int i ;
     for (i=0;i<j;i++)
     {
         if ((joueur[i][1]=='+')||(joueur[i][1]=='$')||(joueur[i][1]=='@'))
            {reste=reste+20;}
         else if ((joueur[i][0]=='j')||(joueur[i][0]=='+')){reste=reste+50;}}

     printf ("::%d",reste);

 }
// pour copier un tableau dans un autre
 void copier(char choix[108][6],char joueur[108][6],int j)
 {
     int i ;
     for (i=0;i<j;i++)
    {
        strcpy(choix[i],joueur[i]);
    }

 }


int main()
{
    char uno[108][6]={"V0","V1","V1","V2","V2","V3","V3","V4","V4","V5","V5","V6","V6","V7","V7","V8","V8","V9","V9",
"R0","R1","R1","R2","R2","R3","R3","R4","R4","R5","R5","R6","R6","R7","R7","R8","R8","R9","R9",
"B0","B1","B1","B2","B2","B3","B3","B4","B4","B5","B5","B6","B6","B7","B7","B8","B8","B9","B9",
"J0","J1","J1","J2","J2","J3","J3","J4","J4","J5","J5","J6","J6","J7","J7","J8","J8","J9","J9",
"V+2","V+2","R+2","R+2","B+2","B+2","J+2","J+2",
"V@","V@","R@","R@","B@","B@","J@","J@",
"V$","V$","R$","R$","B$","B$","J$","J$",
"+4","+4","+4","+4",
"joker","joker","joker","joker",
};

char joueur1[30][6];
char joueur2[30][6] ;
char  cartetable[108][6];
char choix1[54][6];
char choix2[54][6];
time_t t;
char couleur;
char couleur_carte[1]="a";
int possible,block,inverse ,select,taille=108,premiertour,choice=0,fois,cpt,indice4,plus_4,j1=7,j2=7,i=0,reponse,c=0;
int finale=0,reste=0;
int stop=0;
int special=0,pioche_sp=0; // off hethy bch tchoufli hkeyet el +4 wala +2 bch ynjm el tour ydour
int seul1=0,seul2=0;
time_t debut, fin ;
double difference ;
char chrono  ;
char nom1[20], nom2[20];
int coul ;
int choix_jeu ;
int tour =0, rejouer=0,x;



printf("-------------------------------------------------- BIENVENUE ^-^ -------------------------------------------------------");
printf("------------------------------------------------------------------------------------------------------------------------\n\n\n\n");
printf("                                                        * \n\n       ");
printf("\n                                                    JOUEUR UNO  \n\n\n\n");
printf("\n                                            AVEC QUI VOULEZ VOUS JOUER?        \n\n\n\n");
printf("                                     ------------- 1- DEUX JOUEURS -------------\n");
printf("                                     ------------- 2- AVEC MACHINE -------------\n");
printf("                                     ------------- 3- QUITTER  :(  -------------\n");
printf("\n\n\n\n------------------------------------------------------------------------------------------------------------------------");
printf("------------------------------------------------------------------------------------------------------------------------");
sound();
sound();

//choix de mode de partie
do{
printf("TAPEZ VOTRE REPONSE  :) \n");
Beep(300,500);
scanf("%d",&choix_jeu);
}while ((choix_jeu!=1)&&(choix_jeu!=2)&&(choix_jeu!=3));

//Diriger l'utilisateur vers le mode de jeu qu'il a choisi :


//Si l'utilisateur a choisi de joueur avec la machine
if(choix_jeu==2)
    {
        printf("__________      ALORS TU AS CHOISI LA MACHINE ! HAHAHA!     __________ \n \n  ");
        printf("__________NOTRE MACHINE EST PROFESSIONELLE ! BON COURAGE ^-^__________ \n");
    }

printf("\n");
while((choix_jeu==1)||(choix_jeu==2)||(rejouer==1)||(rejouer==2)){
//Si l'utilisateur a choisi de joueur avec un autre joueur
if((choix_jeu==1)||(rejouer==1)){



//Début de la partie avec les 2 joueurs

srand( time(&t));//relié à la fonction Rand pour donner des valeurs aléatoires


//distribution des cartes
//remplissage joueur1:
for(i=0;i<j1;i++)
{
select= rand()%(taille+1);

strcpy(joueur1[i],uno[select]);

        strcpy(uno[select],"0");
efface(uno,select,taille);
taille--;

}


// remplissage joueur2:
for(i=0;i<j2;i++)
{
select= rand()%(taille+1);

strcpy(joueur2[i],uno[select]);

        strcpy(uno[select],"0");
efface(uno,select,taille);
taille--;

}
//disposition carte sur table
select=rand()%(taille+1);
strcpy(cartetable[c],uno[select]);
efface(uno,select,taille);
taille--;

// le tour de 1ere joueur dépend de la premier carte sur table si elle est speciale
if((cartetable[c][0]=='+')||(cartetable[c][1]=='@')||(cartetable[c][1]=='$')||(cartetable[c][1]=='+'))
    {pioche_sp=1;}




printf ("---DONNEZ LE NOM DU JOUEUR1 (^-^) : \n");
Beep(300,500);
fflush(stdin);
gets(nom1);
printf ("---DONNEZ LE NOM DU JOUEUR 2 (^-^) : \n");
Beep(300,500);
fflush(stdin);
gets(nom2);
printf (" \n %s :  \n",nom1);
affichage_joueur1(joueur1,j1);
printf("\n------------------------------\n");
printf("\n %s : \n",nom2);
affichage_joueur2(joueur2,j2);
printf("\n------------------------------\n");
printf ("\n");





//choix du premier joueur aléatoirement
premiertour=1+rand()%(2);
if(premiertour==1){printf("                 %s C'EST VOTRE TOUR COMMENCE (^-^)...  \n",nom1);}
else if (premiertour==2){printf("                 %s C'EST VOTRE TOUR COMMENCE (^-^)...  \n",nom2);}






while(finale==0){

if((premiertour==1)&&(finale==0))
    {
cpt=0;
plus_4=0;
possible=0;
block=0;
premiertour=2;
stop=0;
choice=0;
sleep(3);

// affichage carte sur table
  printf("\n********************************TABLE*************************************************\n");
  printf("                    carte sur table = %s\n",cartetable[c]);
  printf("\n**************************************************************************************\n");


// chercher +4 dans tableau joueur1
   i=0;
      while(i<j1)
 {
     if (joueur1[i][0]=='+'){plus_4=1; indice4=i;} i++;
 }



//cas de +4 :
if (((cartetable[c][0]=='+')&&(special==2))||((cartetable[c][0]=='+')&&(pioche_sp==1)))
{  if(pioche_sp==1){pioche_sp=0;}
    block=1;
                   fois=0;
             while((fois<4)&&(j1<j1+4) )
             {select= rand()%(taille+1);
              strcpy(joueur1[j1],uno[select]);
              j1=j1+1;
             efface(uno,select,taille);
             taille--;
             fois++;}

printf("\n -----  %s VOUS DEVEZ PIOCHER 4 CARTES (DEVIL FACE >_<) ------\n",nom1);
Beep(300,500);
printf ("tab j1 apres +4\n");
affichage_joueur1(joueur1,j1);
printf("\n");
// si le joueur dit uno mais il pioche une autre fois
if(seul1==1){seul1=0;}
}



// cas de +2

  else if (((cartetable[c][1]=='+')&&(special==2))||((cartetable[c][1]=='+')&&(pioche_sp==1)))

{   if(pioche_sp==1){pioche_sp=0;}
     block=1;
                   fois=0;
             while((fois<2)&&(j1<j1+2) )

            { select= rand()%(taille+1);
              strcpy(joueur1[j1],uno[select]);
              j1=j1+1;
             efface(uno,select,taille);
             taille--;
             fois++;}
printf("\n -------%s VOUS DEVEZ PRENDRE 2 CARTES (DEVIL FACE >_<) ------\n",nom1);
Beep(300,500);
// si le joueur dit uno mais il pioche une autre fois
if(seul1==1){seul1=0;}
}


  // cas de block
 else if( ((cartetable[c][1]=='@')&&(special==2))||((cartetable[c][1]=='@')&&(pioche_sp==1)) )
   { if(pioche_sp==1){pioche_sp=0;}
       block=1;
    printf ("----------%s  HO HO TU ES BLOQUE (DEVIL FACE >_< )!----------\n",nom1);
     Beep(300,500); }

    // cas de inverser
    else  if (((cartetable[c][1]=='$')&&(special==2))||((cartetable[c][1]=='$')&&(pioche_sp==1)))
  {  if(pioche_sp==1){pioche_sp=0;}
       block=1;
    printf("-------- %s   HO HO ! ON A INVERSE LE TOUR (>_<)  ...--------\n",nom1);
    Beep(300,500);}


    else if((cartetable[c][1]=='j')&&(couleur_carte[0]=='a'))
        {   copier(choix1,joueur1,j1);cpt=1;
          }





        while((block==0)&&(stop==0))
        {

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~%s\n",nom1);
    affichage_joueur1(joueur1,j1);
     printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf ("nombre de cartes j1=%d\n",j1);

//si le joueur a mis +4 sur table il a le droit de choisir une couleur donc il peut jouer avec tous les cartes qu'il posséde
//remplissage tableau choix avec tous les cartes de ce joueur
if (cartetable[c][0]=='+')
    {copier(choix1,joueur1,j1);
     cpt=1;}
//
        else if (cartetable[c][0]!='+')
                {     for(i=0;i<j1;i++)
                          {
                            if((joueur1[i][0]==cartetable[c][0])||((joueur1[i][1]==cartetable[c][1])&&(joueur1[i][0]!='+'))||(joueur1[i][0]=='j')
                                ||((joueur1[i][0]==couleur_carte[0])&&(cartetable[c][0]=='j')))
                                 {
                                    strcpy (choix1[i],joueur1[i]);
                                    cpt=cpt+1;
                                    //compteur de nombre de cartes que le joueur peut jouer avec
                                    }
                             // insertion "x" dabs le tableau choix si la carte n'est pas valide
                            else { strcpy(choix1[i],"x");}
                            }
                }


        // si le joueuer posséde une carte +4 :
        if((cpt==0)&&(plus_4==1)){ strcpy (choix1[indice4],"+4");}
        // si le joueur ne posséde pas une +4 :
        if ((cpt==0)&&(plus_4==0)) {
        // si le joueur dit uno mais il pioche une autre fois
        if(seul1==1)
          {seul1=0;}
        //si le joueur doit piocher une carte
                printf(":::::::::: %s VOUS DEVEZ PIOCHER  UNE CARTE (>_<) :::::::::::::\n",nom1);
                Beep(300,500);
             j1++;

             x= rand()%(taille+1);

             strcpy(joueur1[j1-1],uno[x]);
             efface(uno,select,taille);
             taille--;

             // afichage de la carte piochée et la carte sur table
             printf("****CARTE SUR TABLE EST  %s*****\n",cartetable[c]);
             printf ("CARTE PIOCHEE EST  %s\n",joueur1[j1-1]);
             Beep(300,500);
             //verification sur la carte pioche
             if((joueur1[j1-1][0]==cartetable[c][0])||(joueur1[j1-1][1]==cartetable[c][1])||(joueur1[j1-1][0]=='+')||(joueur1[j1-1][0]=='j')||
                    ( (joueur1[j1-1][0]==couleur_carte[0])&&(cartetable[c][0]=='j') ) )
                        {  do{  printf("-------- %s VOULEZ VOUS JOUER CETTE CARTE ? --------\n 1-oui \n 2-non\n ",nom1);
                        Beep(300,500);
                        scanf("%d",&reponse);} while(reponse!=1 && reponse!=2);
                         if(reponse==1){strcpy(choix1[j1-1],joueur1[j1-1]);}

                         else {strcpy(choix1[j1-1],"x"); possible=1;}
                        }


                        else {strcpy(choix1[j1-1],"x"); possible=1;}}



           // affichage de choix que joueur1 peut jouer avec
           if(possible==0){

           printf("\n----------------------CHOIX1----------------------\n");
           for (i=0;i<j1;i++)
           { printf (" %s | ",choix1[i]);}
           printf("\n----------------------------------------------------\n");
           // affichage de l'indice de choix:
           printf("\n  VOUS POUVEZ CHOISIR UNE CARTE D'INDICE :\n");
           Beep(300,500);

           for (i=0;i<j1;i++)

           {
               if (strcmp(choix1[i],"x")!=0)
           {printf(" %d / ",i+1);}

           }

           do {
                printf("        SAISIR VOTRE CHOIX \n");
                Beep(300,500);
                scanf("%d",&choice);
                } while((strcmp(choix1[choice-1],"x")==0)|| (choice<1) || (choice-1>j1-1));

   c++;
   strcpy(cartetable[c],choix1[choice-1]);
   efface(joueur1,choice-1,j1);
   j1--;}

   stop=1;
   if((cartetable[c][0]=='+')||(cartetable[c][1]=='@')||(cartetable[c][1]=='$')||(cartetable[c][1]=='+')){special=1;}

   //cas de carte joker
   if(cartetable[c][0]=='j'){
   do{ printf("  %s AVEC QUEL COULEUR VOULEZ VOUS CONTINUER ?  \n R:Rouge\nB:Bleu\nJ:jaune\nV:Vert\n ",nom1);
   Beep(300,500);
   getchar();
   scanf("%c",&couleur);


      } while(couleur!='R'&&couleur!= 'B'&&couleur!='J'&&couleur!='V');
couleur_carte[0]=couleur;
couleur_carte[1]='\0';
//couleur_carte contient la nouvelle couleur choisi par le joueur
printf ("COULEUR SUR TABLE EST  %s",couleur_carte);}

 }

            if((block==1)||(reponse==2)||(possible==1))
            {printf("\n --PAS DE CARTE A JOUER DANS CET TOUR (>_<) -- \n");
            Beep(300,500);
            // dans le cas si carte sur table special et deja j2 bloque pour ne sera pas bloque autre fois :
            if(special==1){special=0;}}



// fonction chronométre
if((j1==1)&&(seul1==0)){
        debut=time(NULL) ;

do
{
 printf("APPUYER SUR u POUR ARRETER LE CHRONOMETRE (rapidement..) \n") ;
 Beep(300,500);
 getchar();
 chrono=getch();
} while(chrono!='u') ;

fin=time(NULL) ;
difference = difftime(fin, debut) ;
printf("\n\nIl s'est ecoule %lf secondes\n", difference) ;
if (difference<3){printf("     YESSSS UNOOOOO  (^-^)\n"); seul1=1; Beep(300,500);}
else { seul1=0;
       printf (" %s :      (°-°)  Malheeureusement tu es retard  tu vas prendre  2 cartes !\n",nom1);

              fois=0;
              while((fois<2)&&(j1<j1+2) )

                {
              select= rand()%(taille+1);
              strcpy(joueur1[j1],uno[select]);
              j1=j1+1;
              efface(uno,select,taille);
              taille--;
              fois++;

              }
printf("update %s: \n",nom1);
affichage_joueur1(joueur1,j1);
printf("\n");
// fin else
}
}

//si le joueur a terminé ses cartes
if (j1==0){finale=1;
printf ("\n \n \n ^-^    ^-^ \n");
printf(" \n        ................%s TU A GAGNE  (^-^) ......................... \n \n",nom1);
Beep(300,500);
printf ("             (°_°)   Malheuresement pour %s (SAD)  tu as termine avec  ",nom2);
compter(joueur2,j2,reste);printf (" points !\n"); }

// fin les conditions du premier joueur
}


        ///////////

// si le premier tour joueur est le joueur 2
if ((premiertour==2)&&(finale==0))
    { sleep(3);//pour fournir une experience
cpt=0;
plus_4=0;//verification de l'existence de +4
possible=0;
block=0;
premiertour=1;
stop=0;
choice=0;
  //affichage carte sur table
  printf("\n********************************TABLE*************************************************\n");
  printf("                      carte sur table = %s \n",cartetable[c]);
  printf("\n**************************************************************************************\n");

    // chercher +4 dans tableau joueur1
      i=0;
      while(i<j2)
       {
         if (joueur2[i][0]=='+'){plus_4=1; indice4=i;}i++;
       }
    //cas de +4 :
     if (((cartetable[c][0]=='+')&&(special==1))||((cartetable[c][0]=='+')&&(pioche_sp==1)))
         {         if(pioche_sp==1){pioche_sp=0;}  block=1;
                   fois=0;
                   while((fois<4)&&(j2<j2+4) )
                   {select= rand()%(taille+1);
                   strcpy(joueur2[j2],uno[select]);
                   j2=j2+1;
                   efface(uno,select,taille);
                   taille--;
                   fois++;}
printf("\n ----- %s VOUS DEVEZ PRENDRE 4 CARTES (DEVIL FACE >_<)------\n",nom2);
Beep(300,500);
printf ("tab j2 apres +4\n");
affichage_joueur2(joueur2,j2);
printf("\n");
// pour que le joueur peut tape "u" pour dire uno plus qu'une seule fois
if(seul2==1)
  {seul2=0;}
  }

       // cas de +2

        else if (((cartetable[c][1]=='+')&&(special==1))||((cartetable[c][1]=='+')&&(pioche_sp==1)))
               {
                if(pioche_sp==1){pioche_sp=0;}
                block=1;//pour blocker le joueur apres avoir pioché 2 cartes
                fois=0;// nombre de carte piochées a chaque fois
                while((fois<2)&&(j2<j2+2) ) //condition pour ne pas piocher plus ou moins de 2 cartes

                { select= rand()%(taille+1); //piocher d'une façon aleatoire
                  strcpy(joueur2[j2],uno[select]);
                  j2=j2+1;
                  efface(uno,select,taille);
                  taille--;
                  fois++;}
printf("\n ----- %s VOUS DEVEZ PRENDRE 2 CARTES (DEVIL FACE >_<)-----\n",nom2);
Beep(300,500);

//pour afficher le tableau de joueur apres la carte +2
//printf ("tab j2 apres +2 : \n");
//affichage_joueur2(joueur2,j2);


printf("\n");


// condition pour que le joueur puisse taper "u" pour dire uno plus qu'une seule fois(apres avoir pioché autres cartes
if(seul2==1)
  {seul2=0;}
}

  // cas de block
     else if (((cartetable[c][1]=='@')&&(special==1))||((cartetable[c][1]=='@')&&(pioche_sp==1)))
             {
                 if(pioche_sp==1)
                   {pioche_sp=0;}
              block=1;
              printf ("--------HO HO %s TU ES BLOQUE (>_<) !--------\n",nom2);
              Beep(300,500);

              }


    // cas de inverser
      else  if( ((cartetable[c][1]=='$')&&(special==1)) ||((cartetable[c][1]=='$')&&(pioche_sp==1)))
               {   if(pioche_sp==1){pioche_sp=0;}
               block=1;
               printf("-------- ...HO HO  ON A INVERE LE TOUR (>_<)...--------");
               Beep(300,500);
               }


      else if ((cartetable[c][1]=='j')&&(couleur_carte[0]=='a'))
               {copier(choix2,joueur2,j2); cpt=1;}






        while ((block==0)&&(stop==0))//pour donner la possibilité au joueur suivant de jouer en cas blockage ou l'inversement du sens
        {

         printf("\n~~~~~~~~~~~~~~~~~~~~~~~%s\n",nom2);
         affichage_joueur2(joueur2,j2);
         printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
         printf("nombre de cartes pour joueur 2 =%d\n",j2);

         if (cartetable[c][0]=='+')
            { copier(choix2,joueur2,j2);
              cpt=1;}

         else if (cartetable[c][0]!='+')
            {
            for(i=0;i<j2;i++)
            {    //verification couleur table
                 if((joueur2[i][0]==cartetable[c][0])||((joueur2[i][1]==cartetable[c][1])&&(joueur2[i][0]!='+'))||(joueur2[i][0]=='j')
                 ||((joueur2[i][0]==couleur_carte[0])&&(cartetable[c][0]=='j')))

                  {
                    strcpy (choix2[i],joueur2[i]);
                    cpt=cpt+1;
                  }
                 else {
                        strcpy(choix2[i],"x");}
                 }
    }

               // si le joueuer posséde une carte +4 :
               if((cpt==0)&&(plus_4==1)){ strcpy (choix2[indice4],"+4");}
               // si le joueur ne posséde pas une +4 :
               else if((cpt==0)&&(plus_4==0)){
               // si le joueur dit uno mais il pioche une autre fois
               if(seul2==1)
                {seul2=0;}
                printf(":::::::::: %s VOUS DEVEZ PIOCHE UNE CARTE :::::::::::::\n",nom2);
                Beep(300,500);
                j2++;

                x= rand()%(taille+1);//piocher une carte d'une façon aléatoire

                strcpy(joueur2[j2-1],uno[x]);
                efface(uno,select,taille);
                taille--;



                // verification sur la carte pioche
                printf("****CARTE SUR TABLE EST  %s*****\n",cartetable[c]);
                printf (" \n CARTE PIOCHEE EST %s\n",joueur2[j2-1]);
                Beep(300,500);
                if((joueur2[j2-1][0]==cartetable[c][0])|| (joueur2[j2-1][1]==cartetable[c][1] )||(joueur2[j2-1][0]=='+')||(joueur2[j2-1][0]=='j')||
                     ((joueur2[j2-1][0]==couleur_carte[0])&&(cartetable[c][0]=='j') ) )

                        {  do{  printf("-------- %s VOULEZ VOUS JOUER CETTE CARTE ? --------\n 1-oui \n 2-non\n ",nom2);
                                Beep(300,500);
                                scanf("%d",&reponse);     } while(reponse!=1 && reponse!=2);

                          if(reponse==1){strcpy(choix2[j2-1],joueur2[j2-1]);}
                          else {strcpy(choix2[j2-1],"x"); possible=1;}
                        }


                        else  {strcpy(choix2[j2-1],"x"); possible=1;}
                        }


           // affichage des choix que joueur2 peut jouer avec
              if(possible==0){

              printf("\n----------------------CHOIX2----------------------\n");
              for (i=0;i<j2;i++)
              { printf (" %s | ",choix2[i]);}
              printf("\n-----------------------------------------\n");
              // affichage de l'indice de choix:
              printf("\n JOUEUR 2 VOUS POUVEZ CHOISIR UNE CARTE D'INDICE :\n");
              Beep(300,500);


              for (i=0;i<j2;i++)
              {
                  if (strcmp(choix2[i],"x")!=0)
                  {printf(" %d / ",i+1);}
              }


                do {
                        printf("        SAISIR VOTRE CHOIX \n");
                        Beep(300,500);
                        scanf("%d",&choice); } while((strcmp(choix2[choice-1],"x")==0)|| (choice<1) );

c++;//taille du TALON(cartes sur table)

strcpy(cartetable[c],choix2[choice-1]);
efface(joueur2,choice-1,j2);
j2--;}

stop=1;

     //verification si la carte est speciale
     if((cartetable[c][0]=='+')||(cartetable[c][1]=='@')||(cartetable[c][1]=='$')||(cartetable[c][1]=='+'))
     {special=2;}
     //fin speciale

     //cas de joker
     if(cartetable[c][0]=='j'){
     do{ printf("  %s AVEC QUEL COULEUR VOULEZ VOUS CONTINUER  \n R:Rouge\nB:Bleu\nJ:jaune\nV:Vert\n ",nom2);
     Beep(300,500);
     getchar();//pour vider la case memoire avant de taper la couleur
     scanf("%c",&couleur);


     } while(couleur!='R'&&couleur!= 'B'&&couleur!='J'&&couleur!='V');
couleur_carte[0]=couleur;
couleur_carte[1]='\0';

printf ("COULEUR SUR TABLE EST  %s",&couleur_carte);}


    }

             //sinon
              if ((block==1)||(reponse==2)||(possible==1))
              {printf("\n  PAS DE CARTE A JOUER DANS CET TOUR  \n");
              Beep(300,500);
              if(special==2)
              {special=0;}
    }

// fonction chronométre
if((j2==1)&&(seul2==0))
  { debut=time(NULL) ;

do{//taper  'u' pour dire UNO si le joueur possede une seule carte
printf(" %s APPUYER SUR u POUR ARRETER LE CHRONOMETRE (rapidement..)\n",nom2) ;
Beep(300,500);
chrono=getch();
}while(chrono!='u') ;


fin=time(NULL) ;
difference = difftime(fin, debut) ;
printf("\n\nIl s'est ecoule %lf secondes\n", difference) ;

//verification si le joueur a tapé 'u' apres 3 secondes

 if (difference<3)
    {printf(" \n YEEESSSS ( ^-^ ) UNOOOOOOOOOOOOOOOO ... \n");
    Beep(300,500);
     seul2=1;
    }
 else { seul2=0;
        printf (" %s :     (°-°) Malheeureusement tu es retard  tu vas prendre  2 cartes !\n",nom2);
        //piocher 2  cartes
        fois=0;
        while((fois<2)&&(j2<j2+2) )
            {
             select= rand()%(taille+1);
             strcpy(joueur2[j2],uno[select]);
             j2=j2+1;
             efface(uno,select,taille);
             taille--;
             fois++;
             }

printf("update %s: \n",nom2);
affichage_joueur2(joueur2,j2);
printf("\n");
// fin else
}
}

else if (j2==0)//si le joueur 2 n'a aucune autre carte pour jouer
        {finale=1;
         printf(" \n        ................%s TU A GAGNE  (^-^).........................\n",nom2);
         Beep(300,500);
         printf ("             (°-°)   Malheuresement pour %s (SAD)  tu as termine avec  ",nom1);
         compter(joueur1,j1,reste);printf (" points !\n");  }

// fin joueur2

}

//// si le pioche est vide:
if (taille==0){
for(i=0;i<=c-1;i++)
{
    strcpy(uno[i],cartetable[i]);
    taille++;
}
i=0;
//transfer des cartes sur tables vers le pioche (tableau uno)
while(c!=0) {
efface(cartetable,i,c);
c--;
}
//affichage de carte sur table
 printf ("CARTE SUR TABLE EST  =%s\n",cartetable[c]);
// verification uno
for (i=0;i<taille;i++)
{
    printf(" %s| ",uno[i]);
}
// verification des carte sur table (vide)
for (i=0;i<=c;i++)
{
    printf(" %s| ",cartetable[i]);
}
}






}
//****************************************************************************************************************************

}


//JOUEUR VS MACHINE :
// si le joueur a choisi de jouer avec la machine




else if ((choix_jeu==2)||(rejouer==2)){//rejouer represente le nombre de tours dans cette partie //au moins 2 tours peuvent se derouler
srand( time(&t));

//le traitement du joueur 1 est le similaire à celui des deux joueurs
//remplissage joueur1:
for(i=0;i<j1;i++)
{
select= rand()%(taille+1);
strcpy(joueur1[i],uno[select]);
strcpy(uno[select],"0");
efface(uno,select,taille);
taille--;

}


// remplissage machine:
//la meme methode pour le remplissage des cartes de la machine
for(i=0;i<j2;i++)
{
select= rand()%(taille+1);
strcpy(joueur2[i],uno[select]);
strcpy(uno[select],"0");
efface(uno,select,taille);
taille--;

}


//disposition carte sur table
select=rand()%(taille+1);
strcpy(cartetable[c],uno[select]);
efface(uno,select,taille);
taille--;

//verifivation de l'existance des cartes speciales
if((cartetable[c][0]=='+')||(cartetable[c][1]=='@')||(cartetable[c][1]=='$')||(cartetable[c][1]=='+'))
    {pioche_sp=1;}


//saisie du nom du joueur
premiertour=1+rand()%(2);
printf ("---DONNEZ LE NOM DU JOUEUR 1 (^-^)  : \n");
Beep(300,500);
fflush(stdin);
gets(nom1);
printf (" \n %s :  \n",nom1);
affichage_joueur1(joueur1,j1);
printf("\n------------------------------\n");
printf("\n machine : \n");
affichage_joueur2(joueur2,j2);
printf("\n------------------------------\n");
printf ("\n");
if(premiertour==1){printf("                 %s C'EST VOTRE TOUR COMMENCE (^-^)...  \n",nom1);}
else if (premiertour==2){printf("                 C'EST LE TOUR DE LA MACHINE (^-^)...  \n");}



while(finale==0){

if((premiertour==1)&&(finale==0))
    {
cpt=0;
plus_4=0;
possible=0;
block=0;
inverse=0;
premiertour=2;
stop=0;
choice=0;
sleep(4);


  printf("\n********************************TABLE*************************************************\n");
  printf("                    carte sur table = %s\n",cartetable[c]);
  printf("\n**************************************************************************************\n");

    // chercher +4 dans tableau joueur1
       i=0;
       while(i<j1)
       {
        if (joueur1[i][0]=='+'){plus_4=1; indice4=i;} i++;
       }

    //cas de +4 :
     if (((cartetable[c][0]=='+')&&(special==2))||((cartetable[c][0]=='+')&&(pioche_sp==1)))
        {
             if(pioche_sp==1){pioche_sp=0;}
             block=1;
             fois=0;
             while((fois<4)&&(j1<j1+4) )
             {
             select= rand()%(taille+1);
             strcpy(joueur1[j1],uno[select]);
             j1=j1+1;
             efface(uno,select,taille);
             taille--;
             fois++;
             }
printf("\n -----  %s  VOUS DEVEZ PRENDRE 4 CARTES (DEVIL FACE >__<)------\n",nom1);
Beep(300,500);

printf ("les carte de joueur 1 apres +4\n");
affichage_joueur1(joueur1,j1);printf("\n");

// si le joueur dit uno mais il pioche une autre fois
if(seul1==1)
  {seul1=0;}
}



// cas de +2
   else if (((cartetable[c][1]=='+')&&(special==2))||((cartetable[c][1]=='+')&&(pioche_sp==1)))
    {
         if(pioche_sp==1){pioche_sp=0;}
         block=1;
         fois=0;
         while((fois<2)&&(j1<j1+2) )

         { select= rand()%(taille+1);
           strcpy(joueur1[j1],uno[select]);
           j1=j1+1;
           efface(uno,select,taille);
           taille--;
           fois++;}

printf("\n -------%s VOUS DEVEZ PRENDRE 2 CARTES  (>_<)------\n",nom1);
Beep(300,500);


// si le joueur dit uno mais il pioche une autre fois
if(seul1==1)
  {seul1=0;}
}


// cas de block
else if( ((cartetable[c][1]=='@')&&(special==2))||((cartetable[c][1]=='@')&&(pioche_sp==1)) )
{
    if(pioche_sp==1){pioche_sp=0;}
       block=1;
       printf ("----------%s HO HO  TU ES BLOQUE ( DEVIL FACE >_<)!----------\n",nom1);
       Beep(300,500);
}




    // cas de inverse
    else  if (((cartetable[c][1]=='$')&&(special==2))||((cartetable[c][1]=='$')&&(pioche_sp==1)))
              {  if(pioche_sp==1)
                 {pioche_sp=0;}
               block=1;
               printf("-------- %s   HO HO ! ON A INVERSE LE TOUR (^-^)  ...--------\n",nom1);
               Beep(300,500);
               }

    //couleur carte par defaut contient 'a'
    else if((cartetable[c][1]=='j')&&(couleur_carte[0]=='a'))
        {
         copier(choix1,joueur1,j1);
         cpt=1;
        }





    while((block==0)&&(stop==0))
    {

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~%s\n",nom1);
    affichage_joueur1(joueur1,j1);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf ("numb carte j1=%d\n",j1);

    if (cartetable[c][0]=='+'){copier(choix1,joueur1,j1); cpt=1;}

        else if (cartetable[c][0]!='+')
                {
                 for(i=0;i<j1;i++)
                    {
                      if((joueur1[i][0]==cartetable[c][0])|| ((joueur1[i][1]==cartetable[c][1])&&(joueur1[i][0]!='+') )||(joueur1[i][0]=='j')
                         ||((joueur1[i][0]==couleur_carte[0])&&(cartetable[c][0]=='j')))
                         {
                           strcpy (choix1[i],joueur1[i]); cpt=cpt+1;
                         }
                      else { strcpy(choix1[i],"x");}}}





            // si le joueuer posséde une carte +4 :
            if((cpt==0)&&(plus_4==1)){ strcpy (choix1[indice4],"+4");}

           // si le joueur ne posséde pas une +4 :
           if ((cpt==0)&&(plus_4==0)) {

          // si le joueur dit uno mais il pioche une autre fois
          if(seul1==1)
          {seul1=0;}
           printf(":::::::::: %s VOUS DEVEZ PIOCHER UNE CARTE  :::::::::::::\n",nom1);
           Beep(300,500);
           j1++;

           x= rand()%(taille+1);
           strcpy(joueur1[j1-1],uno[x]);
           efface(uno,select,taille);
           taille--;

           // verification sur la carte pioche
           printf("****CARTE SUR TABLE EST  %s*****\n",cartetable[c]);
           printf (" \n CARTE PIOCHEE EST %s\n",joueur1[j1-1]);
           Beep(300,500);

           if((joueur1[j1-1][0]==cartetable[c][0])||(joueur1[j1-1][1]==cartetable[c][1])||(joueur1[j1-1][0]=='+')||(joueur1[j1-1][0]=='j')||
             ( (joueur1[j1-1][0]==couleur_carte[0])&&(cartetable[c][0]=='j') ) )

                {
                     do{  printf("-------- %s VOULEZ VOUS JOUER CETTE CARTE ? --------\n 1-oui \n 2-non\n ",nom1);
                     Beep(300,500);
                        scanf("%d",&reponse);
                        } while(reponse!=1 && reponse!=2);

                         if(reponse==1){strcpy(choix1[j1-1],joueur1[j1-1]);}
                         else {strcpy(choix1[j1-1],"x"); possible=1;}
                }
            else
                {strcpy(choix1[j1-1],"x"); possible=1;}
            }

//printf("possible=%d\n",possible);
// affichage de choix que joueur1 pouvait jouer

         if(possible==0){

           printf("\n----------------------CHOIX1----------------------\n");
           for (i=0;i<j1;i++)
           { printf (" %s | ",choix1[i]);}
           printf("\n----------------------------------------------------\n");
// affichage de l'indice de choix:
printf("\n  VOUS POUVEZ CHOISIR UNE CARTE D'INDICE :\n");
Beep(300,500);
for (i=0;i<j1;i++)
  {
      if (strcmp(choix1[i],"x")!=0)
         {printf(" %d / ",i+1);}
  }


  do {
        printf("        SAISIR VOTRE CHOIX \n");
        Beep(300,500);
        scanf("%d",&choice);
     } while((strcmp(choix1[choice-1],"x")==0)|| (choice<1) || (choice-1>j1-1));


//insertion carte dans tableau cartes sur table
c++;
strcpy(cartetable[c],choix1[choice-1]);
efface(joueur1,choice-1,j1);
j1--;}


stop=1;
if((cartetable[c][0]=='+')||(cartetable[c][1]=='@')||(cartetable[c][1]=='$')||(cartetable[c][1]=='+'))
    {special=1;}


if(cartetable[c][0]=='j'){
                         do{ printf("  %s AVEC QUEL COULEUR VOULEZ VOUS CONTINUER ? \n R:Rouge\nB:Bleu\nJ:jaune\nV:Vert\n ",nom1);
                         Beep(300,500);
                         getchar();
                         scanf("%c",&couleur);


                          } while(couleur!='R'&&couleur!= 'B'&&couleur!='J'&&couleur!='V');

couleur_carte[0]=couleur;
couleur_carte[1]='\0';

 printf (" \n [COULEUR SUR TABLE EST  %s ]\n",couleur_carte);}

 }

            if((block==1)||(reponse==2)||(possible==1))
            {printf("\n --PAS DE CARTE A JOUER DANS CET TOUR -- \n");
            Beep(300,500);
            if(special==1){special=0;}
            }



//fonction chronométre 3 secondes pour taper 'u'
if((j1==1)&&(seul1==0))
    {
    debut=time(NULL) ;

    do{
        printf("APPUYER SUR u POUR ARRETER LE CHRONOMETRE ... (rapidement ...)\n") ;
        Beep(300,500);
         chrono=getch();
      } while(chrono!='u') ;

    fin=time(NULL) ;
    difference = difftime(fin, debut) ;
    printf("\n\nIl s'est ecoule %lf secondes\n", difference) ;
    if (difference<3)
    {printf("YEEEES UNOOOOO (^-^)  %s \n",nom1); seul1=1; Beep(300,500);}
    else { seul1=0;
           printf (" %s :    (°-°)   MALHEUREUSEMENT TU ES RETARD TU VAS PRENDRE 2 CARTES  !\n",nom1);
           fois=0;

           while((fois<2)&&(j1<j1+2) )
            {
             select= rand()%(taille+1);
             strcpy(joueur1[j1],uno[select]);
             j1=j1+1;
             efface(uno,select,taille);
             taille--;
             fois++;

}
printf("update %s: \n",nom1);
affichage_joueur1(joueur1,j1);
printf("\n");
// fin else
}
}

 if (j1==0){finale=1; printf(" \n        ................%s TU A GAGNE  (^-^) .........................\n",nom1);
 Beep(300,500);
printf ("               (°-°) Malheuresement pour la machine  (SAD)  tu as termine avec  ");
compter(joueur2,j2,reste);printf (" points !\n"); }

  // fin if  joueur1
}


        /////////// machine


if ((premiertour==2)&&(finale==0))
    { sleep(6);
cpt=0;
plus_4=0;
possible=0;
block=0;
inverse=0;
premiertour=1;
stop=0;
choice=0;

  printf("\n********************************TABLE*************************************************\n");
  printf("                      carte sur table = %s \n",cartetable[c]);
  printf("\n**************************************************************************************\n");

    // chercher +4 dans tableau joueur1
      i=0;
      while(i<j2)

      {
       if (joueur2[i][0]=='+'){plus_4=1; indice4=i;}i++;
       }
    //cas de +4 :
      if (((cartetable[c][0]=='+')&&(special==1))||((cartetable[c][0]=='+')&&(pioche_sp==1)))
      {
      if(pioche_sp==1)
        {pioche_sp=0;}
         block=1;
         fois=0;
         while((fois<4)&&(j2<j2+4) )
              {select= rand()%(taille+1);
              strcpy(joueur2[j2],uno[select]);
              j2=j2+1;
              efface(uno,select,taille);
              taille--;
              fois++;}

printf("\n ----- MACHINE PREND 4 CARTES (DEVIL FACE >_<)------\n");
Beep(300,500);
printf ("cartes machine apres +4\n");
affichage_joueur2(joueur2,j2);
printf("\n");
// si le joueur dit uno mais il pioche une autre fois
if(seul2==1){seul2=0;}
  }
  // cas de +2

        else if (((cartetable[c][1]=='+')&&(special==1))||((cartetable[c][1]=='+')&&(pioche_sp==1)))
               {
                   if(pioche_sp==1)
                   {pioche_sp=0;}
                block=1;
                fois=0;
                while((fois<2)&&(j2<j2+2) )

                { select= rand()%(taille+1);
                  strcpy(joueur2[j2],uno[select]);
                  j2=j2+1;
                  efface(uno,select,taille);
                  taille--;
                  fois++;}

printf("\n ----- MACHINE PRENDR 2 CARTES  (DEVIL FACE >_< )-----\n");
Beep(300,500);
//printf ("tab j2 apres +2 : \n");
//affichage_joueur2(joueur2,j2);
printf("\n");
// si le joueur dit uno mais il pioche une autre fois
if(seul2==1)
  {seul2=0;}
}
  // cas de block
     else if (((cartetable[c][1]=='@')&&(special==1))||((cartetable[c][1]=='@')&&(pioche_sp==1)))
            {   if(pioche_sp==1){pioche_sp=0;}
             block=1;
             printf ("--------HO HO MACHINE  BLOCKE  (>_<) !--------\n");
             Beep(300,500);
            }

    // cas de inverser
    else  if( ((cartetable[c][1]=='$')&&(special==1)) ||((cartetable[c][1]=='$')&&(pioche_sp==1)))
    {
       if(pioche_sp==1){pioche_sp=0;}
       block=1;
       printf("-------- ...HO HO  ON A INVERE LE TOUR (>_<) ...--------"); Beep(300,500);}

     //cas de joker (couleur carte par defaut contient 'a'
    //condition pour que si la carte sur table est joker le joueur peut choisir n'importe quel carte
     else if ((cartetable[c][1]=='j')&&(couleur_carte[0]=='a'))
            {copier(choix2,joueur2,j2);
             cpt=1;
             }






    while ((block==0)&&(stop==0))
    {

     printf("\n~~~~~~~~~~~~~~~~~~~~~~~MACHINE \n");
     affichage_joueur2(joueur2,j2);
     printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
     printf("num carte machine =%d\n",j2);

     if (cartetable[c][0]=='+')
        { copier(choix2,joueur2,j2);
          cpt=1;}

     else if (cartetable[c][0]!='+') {

            for(i=0;i<j2;i++)
            {
                if((joueur2[i][0]==cartetable[c][0])|| ((joueur2[i][1]==cartetable[c][1])&&(joueur2[i][0]!='+') )||(joueur2[i][0]=='j')
                 ||((joueur2[i][0]==couleur_carte[0])&&(cartetable[c][0]=='j')))
                {
                    strcpy (choix2[i],joueur2[i]);
                     cpt=cpt+1;
                }
     else { strcpy(choix2[i],"x");}
            }

                                     }

            // si le joueuer posséde une carte +4 :
            if((cpt==0)&&(plus_4==1)){ strcpy (choix2[indice4],"+4");}
           // si le joueur ne posséde pas une +4 :
           else if((cpt==0)&&(plus_4==0)){
           if(seul2==1){seul2=0;}
           printf(":::::::::: MACHINE PIOCHEE UNE CARTE (>_<) :::::::::::::\n");
           Beep(300,500);
           j2++;


            //piocher une caarte
            x= rand()%(taille+1);
            strcpy(joueur2[j2-1],uno[x]);
            efface(uno,select,taille);
            taille--;

             // verification sur la carte pioche
               printf("****CARTE SUR TABLE EST  %s*****\n",cartetable[c]);
               printf (" \n CARTE PIOCHEE EST  %s\n",joueur2[j2-1]);
               Beep(300,500);

             if((joueur2[j2-1][0]==cartetable[c][0])||(joueur2[j2-1][1]==cartetable[c][1])||(joueur2[j2-1][0]=='+')||(joueur2[j2-1][0]=='j')||
                     ((joueur2[j2-1][0]==couleur_carte[0])&&(cartetable[c][0]=='j') ) )
                        { strcpy(choix2[j2-1],joueur2[j2-1]);    }

                        else  {strcpy(choix2[j2-1],"x"); possible=1;}         }


           // affichage de choix que la machine peut jouer avec
              if(possible==0){

           printf("\n----------------------CHOIX MACHINE----------------------\n");
           for (i=0;i<j2;i++)
           { printf (" %s | ",choix2[i]);}
           printf("\n-----------------------------------------------------------\n");

           do {
            //la machine choisi d'une façon aléatoire
           choice=rand()%(j2); } while(strcmp(choix2[choice],"x")==0 );
           //printf ("choix de la machine est %d \n ",choice+1);

//insertion carte sur table
c++;
strcpy(cartetable[c],choix2[choice]);
efface(joueur2,choice,j2);
j2--;}

stop=1;
if((cartetable[c][0]=='+')||(cartetable[c][1]=='@')||(cartetable[c][1]=='$')||(cartetable[c][1]=='+')){special=2;}
    if(cartetable[c][0]=='j'){
  // printf("  machine  Avec quel couleur pouvez vous continuer \n 0:Rouge\n1:Bleu\n2:jaune\n3:Vert\n ");
  //la machine choisi une couleur d'une façon aleatoire
   coul =rand()%(4);
   switch (coul)
   {
       case 0 : couleur='R';break;
        case 1 : couleur='B';break;
         case 2 : couleur='J';break;
          case 3 : couleur='V';break;
   }




couleur_carte[0]=couleur;
couleur_carte[1]='\0';

 printf ("couleur choisi par machine est  %s\n ",couleur_carte); Beep(300,500);}


    }

             //else
              if ((block==1)||(reponse==1)||(possible==1))
                  {printf("\n  PAS DE CARTE A JOUER DANS CET TOUR PAR LA MACHINE (>_<) \n");
                  Beep(300,500);
              if(special==2)
                 {special=0;}
            }

//pas de chronométre pour la machine
if((j2==1)&&(seul2==0)){

printf ("UNOOOOOOO par la machine \n");
Beep(300,500);

}
//si le nombre de cartes de machine= 0
else if (j2==0)
    {finale=1;

  printf(" \n        ................ Machine  GAGNE  (^-^).........................\n");
  Beep(300,500);
  printf ("  \n              Nous vous avions pr%cvenu que notre machine est un joueur coriace (^-^) a la prochaine Amigo \n ",130);
printf ("             (°-°)   Malheuresement pour %s (SAD)  tu as termine avec  ",nom1);
compter(joueur1,j1,reste);printf (" points !\n");  }

  // fin while joueur2

}
//printf ("taille uno =%d\n",taille);
//// si pioche est terminé:
if (taille==0){ //printf ("c=%d\n",c);
for(i=0;i<=c-1;i++)
{
    strcpy(uno[i],cartetable[i]);
    taille++;
}
i=0;
while(c!=0) {

efface(cartetable,i,c);
c--;

}
// verification que carte tale ne change pas
 printf ("carte sur table =%s\n",cartetable[c]);
 // verification uno
for (i=0;i<taille;i++)
{
    printf(" %s| ",uno[i]);
}

for (i=0;i<=c;i++)
{
    printf(" %s| ",cartetable[i]);
}
}






}
/////////////////////////////////////////////////////////////

 }
 if(finale==1){
 do {printf ("\n VOULEZ VOUS REJOUER ? \n 1-OUI \n 2-QUITTER \n ");
 Beep(300,500);
scanf ("%d",&tour ); }while (tour!=1 && tour != 2);
if(tour==1){ finale=0 ; printf ("\n AVEC QUI VOULEZ VOUS REJOUER ?\n 1-DEUX JOUERES \n 2- AVEC MACHINE \n ");
Beep(300,500);
     do {printf ("\n CHOIX : \n "); scanf("%d",&rejouer);} while (rejouer!=1&&rejouer !=2);        }}

}

if ((choix_jeu==3)||(tour==2)){
    system("cls");
    printf("\n\n\n\n\n\n--------------------------------------------------- AU REVOIR !!! ------------------------------------------------------\n\n\n\n\n\n\n");
}
return 0 ;
}
