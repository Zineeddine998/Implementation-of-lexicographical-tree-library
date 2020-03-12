

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

typedef int bool;
typedef char *string255;
typedef char *string2;

#define True 1
#define False 0

  /** ImplC)mentation **\: ARBRE BINAIRE DE STRUCTURES**/

  /** Structures statiques **/

typedef struct Tcb Type_Tcb;
typedef Type_Tcb *Typestr_Tcb;
typedef string2 Type1_Tcb;
typedef bool Type2_Tcb;
struct Tcb
{
  Type1_Tcb Champ1;
  Type2_Tcb Champ2;
};

Type1_Tcb
Struct1_Tcb (Typestr_Tcb S)
{
  return S->Champ1;
}

Type2_Tcb
Struct2_Tcb (Typestr_Tcb S)
{
  return S->Champ2;
}

void
Aff_struct1_Tcb (Typestr_Tcb S, Type1_Tcb Val)
{
  strcpy (S->Champ1, Val);
}

void
Aff_struct2_Tcb (Typestr_Tcb S, Type2_Tcb Val)
{
  S->Champ2 = Val;
}


  /** Arbres de recherche binaire **/

typedef Typestr_Tcb Typeelem_ATcb;
typedef struct Noeud_ATcb *Pointeur_ATcb;

struct Noeud_ATcb
{
  Typeelem_ATcb Val;
  Pointeur_ATcb Fg;
  Pointeur_ATcb Fd;
  Pointeur_ATcb Pere;
};

Typeelem_ATcb
Info_ATcb (Pointeur_ATcb P)
{
  return P->Val;
}

Pointeur_ATcb
Fg_ATcb (Pointeur_ATcb P)
{
  return P->Fg;
}

Pointeur_ATcb
Fd_ATcb (Pointeur_ATcb P)
{
  return P->Fd;
}

Pointeur_ATcb
Pere_ATcb (Pointeur_ATcb P)
{
  return P->Pere;
}

void
Aff_info_ATcb (Pointeur_ATcb P, Typeelem_ATcb Val)
{
  Typeelem_ATcb _Temp;
  _Temp = malloc (sizeof (Typestr_Tcb));
  _Temp->Champ1 = malloc (2 * sizeof (string2));
  /* Affectation globale de structure */
  strcpy (_Temp->Champ1, Val->Champ1);
  _Temp->Champ2 = Val->Champ2;
  Val = _Temp;
  P->Val = Val;
}

void
Aff_fg_ATcb (Pointeur_ATcb P, Pointeur_ATcb Q)
{
  P->Fg = Q;
}

void
Aff_fd_ATcb (Pointeur_ATcb P, Pointeur_ATcb Q)
{
  P->Fd = Q;
}

void
Aff_pere_ATcb (Pointeur_ATcb P, Pointeur_ATcb Q)
{
  P->Pere = Q;
}

void
Creernoeud_ATcb (Pointeur_ATcb * P)
{
  *P = (struct Noeud_ATcb *) malloc (sizeof (struct Noeud_ATcb));
  (*P)->Val = malloc (sizeof (Typestr_Tcb));
  (*P)->Val->Champ1 = malloc (2 * sizeof (string2));
  (*P)->Fg = NULL;
  (*P)->Fd = NULL;
  (*P)->Pere = NULL;
}

void
Liberernoeud_ATcb (Pointeur_ATcb P)
{
  free (P);
}


  /** ImplC)mentation **\: LISTE DE CHAINES DE CARACTERES**/

  /** Listes lin?aires cha?n?es **/

typedef string255 Typeelem_Ls;
typedef struct Maillon_Ls *Pointeur_Ls;

struct Maillon_Ls
{
  Typeelem_Ls Val;
  Pointeur_Ls Suiv;
};

Pointeur_Ls
Allouer_Ls (Pointeur_Ls * P)
{
  *P = (struct Maillon_Ls *) malloc (sizeof (struct Maillon_Ls));
  (*P)->Val = malloc (255 * sizeof (string255));
  (*P)->Suiv = NULL;
}

void
Aff_val_Ls (Pointeur_Ls P, Typeelem_Ls Val)
{
  strcpy (P->Val, Val);
}

void
Aff_adr_Ls (Pointeur_Ls P, Pointeur_Ls Q)
{
  P->Suiv = Q;
}

Pointeur_Ls
Suivant_Ls (Pointeur_Ls P)
{
  return (P->Suiv);
}

Typeelem_Ls
Valeur_Ls (Pointeur_Ls P)
{
  return (P->Val);
}

void
Liberer_Ls (Pointeur_Ls P)
{
  free (P);
}




   /**Liste Lineaires doublement chainees**/

typedef string255 Typeelem_Ls;
typedef struct Maillon_Lsd *Pointeur_Lsd;

struct Maillon_Lsd
{
  Typeelem_Ls Val;
  Pointeur_Lsd Suiv;
  Pointeur_Lsd Prec;
};

Pointeur_Ls
Allouer_Lsd (Pointeur_Lsd * P)
{
  *P = (struct Maillon_Lsd *) malloc (sizeof (struct Maillon_Lsd));
  (*P)->Val = malloc (255 * sizeof (string255));
  (*P)->Suiv = NULL;
  (*P)->Prec = NULL;
}

void
Aff_val_Lsd (Pointeur_Lsd P, Typeelem_Ls Val)
{
  strcpy (P->Val, Val);
}

void
Aff_adr_suiv (Pointeur_Lsd P, Pointeur_Lsd Q)
{
  P->Suiv = Q;
}

void
Aff_adr_prec (Pointeur_Lsd P, Pointeur_Lsd Q)
{
  P->Prec = Q;
}

Pointeur_Lsd
Suivant_Lsd (Pointeur_Lsd P)
{
  return (P->Suiv);
}

Pointeur_Lsd
Precedent_Lsd (Pointeur_Lsd P)
{
  return (P->Prec);
}

Typeelem_Ls
Valeur_Lsd (Pointeur_Lsd P)
{
  return (P->Val);
}

void
Liberer_Lsd (Pointeur_Lsd P)
{
  free (P);
}







  /** Variables du programme principal **/
Pointeur_ATcb A;
Typestr_Tcb V;
Pointeur_ATcb R;
int N;
int M;
int L;
int Continuer;
bool B;
string255 Expression;
Pointeur_Ls Tete;
Pointeur_Ls Tete5;
Pointeur_Ls P;
string255 _Px1;
string255 Table[100];


  /** Fonctions standards **/

int
Aleanombre (int N)
{
  return (rand () % N);
}

char *
Aleachaine (int N)
{
  int k;
  char *Chaine = malloc (N + 1);

  char Chr1[26] = "abcdefghijklmnopqrstuvwxyz";
  char Chr2[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  for (k = 0; k < N; k++)
    switch (rand () % 2)
      {
      case 0:
	*(Chaine + k) = Chr1[rand () % 26];
	break;
      case 1:
	*(Chaine + k) = Chr2[rand () % 26];
	break;
      }
  Chaine[k] = '\0';

  return (Chaine);
}

int
Longchaine (string255 Ch)
{
  return strlen (Ch);
}

char *
Caract (string255 Ch, int I)
{
  char *s = malloc (2);
  s[0] = Ch[I - 1];
  s[1] = '\0';
  return s;
}


  /** Initialisation d'une structure **/
void
Init_struct_Tcb (Typestr_Tcb S, Type_Tcb S_)
{
  strcpy (S->Champ1, S_.Champ1);
  S->Champ2 = S_.Champ2;
}


  /** Prototypes des fonctions **/

void Generer_mots (int *M1, int *L1, Pointeur_Ls * Tete1,int choix);
void mots_fich (Pointeur_Ls * Tete1, int choix);
string2 Carac (Pointeur_ATcb * R);
bool Bool (Pointeur_ATcb * R);
void Inner_insert (Pointeur_ATcb * R, string255 * Mot, int *Pos);
void Insert (Pointeur_ATcb * N, string255 * Mot);
void Inner_affich (Pointeur_ATcb * R, string255 * Mot);
void Affich_arb (Pointeur_ATcb * R);
void Inner_rech (Pointeur_ATcb * R, string255 * Exp_reg, int *Pos,
		 string255 * Mot_trouve);
void Rech_arb (Pointeur_ATcb * R, string255 * Exp_reg);
void fenetres_glissantes (Pointeur_Lsd * Tete5,int choix,string255 Expression);
int controle_requete (string255 Expression);

  /**GENERATION DES MOTS **/
void
Generer_mots (int *M1, int *L1, Pointeur_Ls * Tete1,int choix)
{
      /** Variables locales **/
  int I;
  Pointeur_Ls P;
  Pointeur_Ls Q;

      /** Corps du module **/
  P = NULL;
  Q = NULL;
  *Tete1 = NULL;
  for (I = 1; I <= *M1; ++I)
    {
      Allouer_Ls (&Q);
      Aff_val_Ls (Q, Aleachaine (Aleanombre (*L1) + 1));
      Aff_adr_Ls (Q, NULL);
      if ((P != NULL))
	{
	  Aff_adr_Ls (P, Q);
	}
      else
	{
	  *Tete1 = Q;
	};
      P = Q;

    };
    if(choix ==1)
    {
  P = *Tete1;
  while ((P != NULL))
    {
      printf (" %s  |", Valeur_Ls (P));
      Sleep (100);
      P = Suivant_Ls (P);
    }
    }

    };


    /**Recuperer les mots du fichier et creer une liste composee de ces mots**/
void
mots_fich (Pointeur_Ls * Tete1, int choix)
{
  FILE *fp;
  int i = 1;
  int max;
  char ch;
  char mot[25];
  Pointeur_Ls P;
  Pointeur_Ls Q;
  P = NULL;
  Q = NULL;
  *Tete1 = NULL;

  fp = fopen ("file.txt", "r");

  while (ch = getc (fp) != EOF)	//parcourir le fichier
    {
      //incrementer le nombre de mots
      fscanf (fp, "%s", &mot);	//recuperer le mot
      i++;
    }
  max = i;			//le nombre de mots trouves
  fclose (fp);

  int special (char mot[14])	//renvoie 1 si le mot contient des caracters speciaux
  {
    for (i = 0; i < strlen (mot); i++)
      {
	if (!
	    ((mot[i] >= 'a' && mot[i] <= 'z')
	     || (mot[i] >= 'A' && mot[i] <= 'Z')))

	  return 1;
      }
    return 0;
  }
  fp = fopen ("file.txt", "r");	//lecture du fichier

  for (i = 1; i < max; i++)
    {
      fscanf (fp, "%s", &mot);
      if (!(special (mot) == 1))
	{
	  Allouer_Ls (&Q);
	  Aff_val_Ls (Q, mot);
	  Aff_adr_Ls (Q, NULL);
	  if ((P != NULL))
	    {
	      Aff_adr_Ls (P, Q);
	    }
	  else
	    {
	      *Tete1 = Q;
	    };
	  P = Q;


	}

    }
  fclose (fp);
  if (choix == 1)//Demander a l'utilisateur si le contenu du fichier doit etre affiche
    {

      P = *Tete1;
      printf ("%s", "|");
      while ((P != NULL))
	{
	  printf ("  %s  |", Valeur_Ls (P));
	  Sleep (100);
	  P = Suivant_Ls (P);

	};

    }

  return 0;
}
  /** Fonctions definies dans l'enonce **/

string2
Carac (Pointeur_ATcb * R)
{
      /** Variables locales **/
  string2 Carac2;
  string2 C;

      /** Corps du module **/
  C = malloc (2 * sizeof (string2));
  Carac2 = malloc (2 * sizeof (string2));
  strcpy (C, Struct1_Tcb (Info_ATcb (*R)));
  strcpy (Carac2, C);

  return Carac2;
}

bool
Bool (Pointeur_ATcb * R)
{
      /** Variables locales **/
  bool Bool2;
  bool Test;

      /** Corps du module **/
  Test = Struct2_Tcb (Info_ATcb (*R));
  Bool2 = Test;

  return Bool2;
}

  /*****    procedure recursive qui insert un mot caractere par caractere dans un arbre binaire  *****/
void
Inner_insert (Pointeur_ATcb * R, string255 * Mot, int *Pos)
{
      /** Variables locales **/
  Pointeur_ATcb A;
  Pointeur_ATcb Nv_n;
  Pointeur_ATcb Temp;
  Typestr_Tcb V;
  bool Etat;
  Type_Tcb S_V;
  int _Px1;
  int _Px2;
  int _Px3;

      /** Corps du module **/
  V = malloc (sizeof (Typestr_Tcb));
  V->Champ1 = malloc (2 * sizeof (string2));
  /*ne rien faire (parcour du mot terminC)) */
  if (*Pos > Longchaine (*Mot))
    {
      ;
    }
  /*parcour du mot pas encore terminC) */
  else
    {
      if (*R == NULL)
	{
	  Etat = (*Pos == Longchaine (*Mot));
	  S_V.Champ1 = malloc (2 * sizeof (string2));
	  strcpy (S_V.Champ1, Caract (*Mot, *Pos));
	  S_V.Champ2 = Etat;
	  Init_struct_Tcb (V, S_V);
	  Creernoeud_ATcb (&A);
	  Aff_info_ATcb (A, V);
	  *R = A;
	  Temp = Fg_ATcb (*R);
	  _Px1 = (*Pos + 1);
	  Inner_insert (&Temp, &*Mot, &_Px1);
	  Aff_fg_ATcb (*R, Temp);
	}
      else
	{
	  if ((strcmp (Caract (*Mot, *Pos), Carac (&*R)) == 0))
	    {
	      /*on test le champs bool, si a vrai on laisse, sinon on fait mise C  jour */
	      if ((!Bool (&*R)))
		{
		  Etat = (*Pos == Longchaine (*Mot));
		  Aff_struct2_Tcb (Info_ATcb (*R), Etat);

		};
	      Temp = Fg_ATcb (*R);
	      _Px2 = *Pos + 1;
	      Inner_insert (&Temp, &*Mot, &_Px2);
	      Aff_fg_ATcb (*R, Temp);
	    }
	  else
	    {
	      if ((strcmp (Caract (*Mot, *Pos), Carac (&*R)) > 0))
		{
		  Temp = Fd_ATcb (*R);
		  Inner_insert (&Temp, &*Mot, &*Pos);
		  Aff_fd_ATcb (*R, Temp);
		}
	      else
		{
		  /*quand la nouvelle lettre inserC)e C  droite est plus petite */
		  /*on change completement le chainage */
		  if ((strcmp (Caract (*Mot, *Pos), Carac (&*R)) < 0))
		    {
		      Creernoeud_ATcb (&A);
		      Nv_n = A;
		      Etat = (*Pos == Longchaine (*Mot));
		      S_V.Champ1 = malloc (2 * sizeof (string2));
		      strcpy (S_V.Champ1, Caract (*Mot, *Pos));
		      S_V.Champ2 = Etat;
		      Init_struct_Tcb (V, S_V);
		      Aff_info_ATcb (Nv_n, V);
		      Aff_fd_ATcb (Nv_n, *R);
		      if ((Pere_ATcb (*R) == NULL))
			{
			  *R = Nv_n;
			}
		      else
			{
			  Temp = Pere_ATcb (*R);
			  Aff_fd_ATcb (Temp, Nv_n);
			  Aff_pere_ATcb (*R, Temp);

			};
		      Temp = Fg_ATcb (Nv_n);
		      _Px3 = *Pos + 1;
		      Inner_insert (&Temp, &*Mot, &_Px3);
		      Aff_fg_ATcb (Nv_n, Temp);

		    };

		};

	    };

	};

    };

}

  /*****   procedure qui englobe inner_insert avec moins de parametres *****/
void
Insert (Pointeur_ATcb * N, string255 * Mot)
{
      /** Variables locales **/
  int _Px1;

      /** Corps du module **/
  _Px1 = 1;
  Inner_insert (&*N, &*Mot, &_Px1);

}


  /*****   procedure recursive qui ecrit tout les mots contenu dans un arbre  *****/
void
Inner_affich (Pointeur_ATcb * R, string255 * Mot)
{
      /** Variables locales **/
  string255 Nv_mot;
  string255 _Sx;
  Pointeur_ATcb _Px1;
  Pointeur_ATcb _Px2;


      /** Corps du module **/
  Nv_mot = malloc (255 * sizeof (string255));
  _Sx = malloc (255 * sizeof (string255));
    /**nnne rien faire**/
  if ((*R == NULL))
    {
      ;
    }
  else
    {
      strcpy (_Sx, *Mot);
      strcpy (Nv_mot, strcat (_Sx, Struct1_Tcb (Info_ATcb (*R))));
      if ((Bool (&*R)))
	{
	  printf (" %s  |", Nv_mot);
	  Sleep (100);
	};
      _Px1 = Fg_ATcb (*R);
      Inner_affich (&_Px1, &Nv_mot);
      _Px2 = Fd_ATcb (*R);
      Inner_affich (&_Px2, &*Mot);

    };

}

  /*****   procedure qui englobe inner_affich avec moins de parametres *****/
void
Affich_arb (Pointeur_ATcb * R)
{
      /** Variables locales **/
  string255 Mot;

      /** Corps du module **/
  Mot = malloc (255 * sizeof (string255));
  strcpy (Mot, "");
  Inner_affich (&*R, &Mot);

}

  /*****   procedure recursive qui cherche les mots qui valide la requete dans un arbre *****/
void
Inner_rech (Pointeur_ATcb * R, string255 * Exp_reg, int *Pos,
	    string255 * Mot_trouve)
{
      /** Variables locales **/
  string255 _Sx;
  string255 chaine;
  Pointeur_ATcb _Px1;
  int _Px2;
  string255 _Px3;
  Pointeur_ATcb _Px4;
  Pointeur_ATcb _Px5;
  int _Px6;
  string255 _Px7;
  Pointeur_ATcb _Px8;
  Pointeur_ATcb _Px9;
  int _Px10;
  string255 _Px11;
  Pointeur_ATcb _Px12;
  int _Px13;
  Pointeur_ATcb _Px14;
  string255 _Px15;
  Pointeur_ATcb _Px16;
  Pointeur_ATcb _Px17;

      /** Corps du module **/
  _Sx = malloc (255 * sizeof (string255));
  _Px3 = malloc (255 * sizeof (string255));
  _Px7 = malloc (255 * sizeof (string255));
  _Px11 = malloc (255 * sizeof (string255));
  _Px15 = malloc (255 * sizeof (string255));
  if (*Pos > Longchaine (*Exp_reg))
    {
      ;
    }
  else
    {
      if ((*R == NULL))
	{
	  ;
	}
      else
	{
	  if ((*Pos == 1))
	    {
	      if ((strcmp (Caract (*Exp_reg, *Pos), "A") < 0)
		  || (strcmp (Caract (*Exp_reg, *Pos), "z") > 0))
		{
		  printf (" %s",
			  "Expression reguliere non valide. Le caractere doit etre entre A et z.");
		}
	      else
		{
		  if ((strcmp (Caract (*Exp_reg, *Pos), Carac (&*R)) == 0))
		    {
		      if ((*Pos == Longchaine (*Exp_reg)))
			{
			  if ((Bool (&*R)))
			    {
			      strcpy (_Sx, *Mot_trouve);
			      strcat (_Sx, Carac (&*R));
			      FILE *fp = fopen ("file2.txt", "a");
			      fprintf (fp, "%s ", _Sx);
			      fclose (fp);

			    };
			}
		      else
			{
			  if ((Bool (&*R)))
			    {
			      if ((*Pos + 1 == Longchaine (*Exp_reg))
				  &&
				  (strcmp (Caract (*Exp_reg, *Pos + 1), "*")
				   == 0))
				{
				  strcpy (_Sx, *Mot_trouve);
				strcat (_Sx, Carac (&*R));
				  FILE *fp = fopen ("file2.txt", "a");
				  fprintf (fp, "%s ", _Sx);
				  fclose (fp);

				};

			    };
			  strcpy (_Sx, *Mot_trouve);
			  _Px1 = Fg_ATcb (*R);
			  _Px2 = *Pos + 1;
			  strcpy (_Px3, strcat (_Sx, Carac (&*R)));
			  Inner_rech (&_Px1, &*Exp_reg, &_Px2, &_Px3);

			};
		    }
		  else
		    {
		      _Px4 = Fd_ATcb (*R);
		      Inner_rech (&_Px4, &*Exp_reg, &*Pos, &*Mot_trouve);

		    };

		};
	    }
	  else
	    {
	      if ((strcmp (Caract (*Exp_reg, *Pos), Carac (&*R)) == 0))
		{
		  if ((*Pos == Longchaine (*Exp_reg)))
		    {
		      if ((Bool (&*R)))
			{
			  strcpy (_Sx, *Mot_trouve);
			  strcat (_Sx, Carac (&*R));
			  FILE *fp = fopen ("file2.txt", "a");
			  fprintf (fp, "%s ", _Sx);
			  fclose (fp);
			};
		    }
		  else
		    {
		      if ((Bool (&*R)))
			{
			  if ((*Pos + 1 == Longchaine (*Exp_reg))
			      && (strcmp (Caract (*Exp_reg, *Pos + 1), "*") ==
				  0))
			    {
			      strcpy (_Sx, *Mot_trouve);
			    strcat (_Sx, Carac (&*R));
			      FILE *fp = fopen ("file2.txt", "a");
			      fprintf (fp, "%s ", _Sx);
			      fclose (fp);
			    };

			};
		      strcpy (_Sx, *Mot_trouve);
		      _Px5 = Fg_ATcb (*R);
		      _Px6 = *Pos + 1;
		      strcpy (_Px7, strcat (_Sx, Carac (&*R)));
		      Inner_rech (&_Px5, &*Exp_reg, &_Px6, &_Px7);

		    };
		}
	      else
		{
		  if ((strcmp (Caract (*Exp_reg, *Pos), "?") == 0))
		    {
		      if ((*Pos == Longchaine (*Exp_reg)))
			{
			  if ((Bool (&*R)))
			    {
			      strcpy (_Sx, *Mot_trouve);
			      strcat (_Sx, Carac (&*R));
			      FILE *fp = fopen ("file2.txt", "a");
			      fprintf (fp, "%s ", _Sx);
			      fclose (fp);
			    };
			  _Px8 = Fd_ATcb (*R);
			  Inner_rech (&_Px8, &*Exp_reg, &*Pos, &*Mot_trouve);
			}
		      else
			{
			  if ((Bool (&*R)))
			    {
			      if ((*Pos + 1 == Longchaine (*Exp_reg))
				  &&
				  (strcmp (Caract (*Exp_reg, *Pos + 1), "*")
				   == 0))
				{
				  strcpy (_Sx, *Mot_trouve);
				strcat (_Sx, Carac (&*R));
				  FILE *fp = fopen ("file2.txt", "a");
				  fprintf (fp, "%s ", _Sx);
				  fclose (fp);
				};

			    };
			  strcpy (_Sx, *Mot_trouve);
			  _Px9 = Fg_ATcb (*R);
			  _Px10 = *Pos + 1;
			  strcpy (_Px11, strcat (_Sx, Carac (&*R)));
			  Inner_rech (&_Px9, &*Exp_reg, &_Px10, &_Px11);
			  _Px12 = Fd_ATcb (*R);
			  Inner_rech (&_Px12, &*Exp_reg, &*Pos, &*Mot_trouve);

			};
		    }
		  else
		    {
		      if ((strcmp (Caract (*Exp_reg, *Pos), "*") == 0))
			{
			  _Px13 = *Pos + 1;
			  Inner_rech (&*R, &*Exp_reg, &_Px13, &*Mot_trouve);
			  if (((*Pos == Longchaine (*Exp_reg)) && Bool (&*R)))
			    {
			      strcpy (_Sx, *Mot_trouve);
			      strcat (_Sx, Carac (&*R));

			      FILE *fp = fopen ("file2.txt", "a");
			      fprintf (fp, "%s ", _Sx);
			      fclose (fp);

			    };
			  strcpy (_Sx, *Mot_trouve);
			  _Px14 = Fg_ATcb (*R);
			  strcpy (_Px15, strcat (_Sx, Carac (&*R)));
			  Inner_rech (&_Px14, &*Exp_reg, &*Pos, &_Px15);
			  _Px16 = Fd_ATcb (*R);
			  Inner_rech (&_Px16, &*Exp_reg, &*Pos, &*Mot_trouve);
			}
		      else
			{
			  _Px17 = Fd_ATcb (*R);
			  Inner_rech (&_Px17, &*Exp_reg, &*Pos, &*Mot_trouve);

			};

		    };

		};

	    };

	};

    };



}

  /*****   Procedure qui englobe inner_rech avec moins de parametres *****/

void
Rech_arb (Pointeur_ATcb * R, string255 * Exp_reg)
{
      /** Variables locales **/
  int _Px1;
  string255 _Px2;


      /** Corps du module **/
  _Px2 = malloc (255 * sizeof (string255));
  _Px1 = 1;
  strcpy (_Px2, "");
  FILE *fp3 = fopen ("file2.txt", "w");

  fclose (fp3);
  Inner_rech (&*R, &*Exp_reg, &_Px1, &_Px2);

}
 /**Fonction d'affichage par les fenetres glissantes **/
void
fenetres_glissantes (Pointeur_Lsd * Tete5,int choix,string255 Expression)
{  /**Variables locals **/
  FILE *fp;
  int i = 1;
  int ichoix;
  int max;
  int pas;
  int status;
  int temp;
  char ch;
  char mot[25];
  Pointeur_Lsd P;
  Pointeur_Lsd Q;
  Pointeur_Ls L;
  Pointeur_Ls current;
  Pointeur_Ls current2;


  P = NULL;
  Q = NULL;
  L = NULL;
  *Tete5 = NULL;
   /** Fonction pour afficher les n resultats suivants dans la liste **/
   void avancer (Pointeur_Lsd * current, int pas)
   {  int i=0;
   Pointeur_Lsd t;
       while((*current!=NULL) &&(i < pas))
       {   t=*current;
           printf ("  %s  |", Valeur_Lsd (*current));
            Sleep (100);
           *current = Suivant_Lsd (*current);
           i++;
       }
       if(*current==NULL)
       {
                 printf ("%s", "| Fin des resultats");
                 printf ("%s", "\n    ");
                 Sleep (100);
                 *current = t;
       }
   }



  /**Fonction pour afficher les n resultats precedents dans la liste **/


   void reculer(Pointeur_Lsd * current, int pas)
   {  int i=0;
      Pointeur_Ls t;
       while((*current!=NULL)&&(i<pas))
       {  t=*current;
         *current=Precedent_Lsd (*current);
            if(*current!=NULL) printf ("  %s  |", Valeur_Lsd (*current));
          Sleep(100);
         i++;
       } if(*current==NULL)
       {
                 printf ("%s  |", "| Debut des resultats");
                 printf ("%s", "\n         ");
                 Sleep (100);
                 *current=t;
       }
   }

  /** Fonction pour afficher les n derniers resultats dans la liste **/
  void derniers (Pointeur_Ls **Tete5,int pas)
  {  int i;
    Pointeur_Lsd L = *Tete5;


    while (Suivant_Lsd (L) != NULL)
      {
	L = Suivant_Lsd (L);
      }
      if(pas==1)
    {
        printf ("  %s  |", Valeur_Lsd (L));
        return;
    }
    //  printf("%s",Suivant_Lsd(L));
    for (i = 0; i < pas; i++)
      {
	printf ("  %s  |", Valeur_Lsd (L));
	Sleep (100);
	L = Precedent_Lsd (L);
      }
    printf ("%s", "\n");
    *Tete5=L;
  }
  int premiers(Pointeur_Lsd * current,int pas)
  {  int i;

for ( i = 0; i < pas; i++){
      printf ("  %s  |", Valeur_Lsd (*current));
	Sleep (100);
	if(Suivant_Lsd(*current)!=NULL){
	*current = Suivant_Lsd(*current);
	}else{
	    printf("%s  |"," Fin des resultats");
	    return ;
	}
  }
  }



  fp = fopen ("file2.txt", "r");
   i=1;
   ch = fgetc (fp);
  while (ch != EOF)
    {
       if(ch==' '||ch=='\n')
                    {
                        i++;
                    }
                     ch=fgetc(fp);

    }
  max = i;
  fclose (fp);

  int special (char mot[14])
  {  int i;
    for (i = 0; i < strlen (mot); i++)
      {
	if (!
	    ((mot[i] >= 'a' && mot[i] <= 'z')
	     || (mot[i] >= 'A' && mot[i] <= 'Z')))

	  return 1;
      }
    return 0;
  }
  fp = fopen ("file2.txt", "r");
  //printf("\n%d",max);
  if(choix==1)
  {
       printf (" %s", "\n   Les mots qui verifient la requete    : ");
	    printf (" %s", Expression);
	    printf (" %s", " : | ");

  }
  for (i = 0; i < max-1; i++)
    {
      fscanf (fp, "%s", &mot);

      if (!(special (mot) == 1))
	{ if(choix==1)
	        {printf("%s   |",mot);
	        Sleep(100);
	        }
	  Allouer_Lsd (&Q);
	  Aff_val_Lsd (Q, mot);
	  Aff_adr_suiv (Q, NULL);
	  Aff_adr_prec (Q, NULL);
	  if ((P != NULL))
	    {
	      Aff_adr_suiv (P, Q);
	      Aff_adr_prec (Q, P);
	    }
	  else
	    {
	      *Tete5 = Q;
	    };
	  P = Q;


	}
	Q=P;

    }
  fclose (fp);
  P = *Tete5;


  printf ("%s", "\n");
  current = *Tete5;
  current2 = *Tete5;


  printf ("%s\n", "  ");
pas:  printf ("  %s",
	  "\n                Choisissez le pas du parcours     :     ");


  status = scanf (" %d", &pas);
	while (status != 1)
	  {
	    while ((temp = getchar ()) != EOF && temp != '\n');
	    printf ("\n\n\tInput invalide ! Donnez un nombre : ");
	    status = scanf ("%d", &pas);
	  }
  printf ("%s", " \n ");
  printf ("%s", "Le resultat de la requete : |");
   current = *Tete5;
      premiers (&current, pas);

menufennetres:printf ("  %s",
	  "\n              Choisissez la methode de parcours :  ");
	  printf("%s","\n");

  printf ("  %s",
	  "\n                     1) Avancer                                         \n");

  printf ("  %s",
	  "\n                     2) Reculer                                         \n");

  printf ("  %s",
	  "\n                     3) Afficher les premiers resultats                  \n");

  printf ("  %s",
	  "\n                     4) Afficher les derniers resultats                  \n");


  printf ("  %s",
	  "\n                     5) Quitter l'affichage des requetes                  \n");
  printf ("  %s", "\n                    Votre choix  :  ");


  scanf ("%d", &ichoix);

      printf ( " %s", "\n________________________________________________________________________________________________________________________\n" ) ;

  switch (ichoix)
    {
    case 1:
      printf ("%s", "Les resultats suivants    : |");
      avancer (&current, pas);
      goto menufennetres;

      break;

    case 2:
      printf ("%s", "Les resultats precedents    : |");
      reculer (&current, pas);
      goto menufennetres;

      break;

    case 4:
      printf ("%s", "\nLes derniers elements du resultats   : |");
      current = *Tete5;
       if(max==2){

        printf ("  %s  |", Valeur_Lsd (current));
        goto menufennetres;

    }
      current = *Tete5;
      derniers (&current, pas);
      goto menufennetres;


      break;

    case 3:
      printf ("%s", "\nLes premiers elements du resultats   : |");
      current = *Tete5;
      premiers (&current, pas);

      goto menufennetres;

      break;



    case 5:

      break;
    default:
      printf ("%s", " \n       Veuillez Choisir une valeur valide :    ");

        goto menufennetres;
      break;
    }
}

/** Fonction de controle de saisie de requete **/
int
controle_requete (string255 Expression)/**Renvoie 1 si la requete introduite contient un caractere non alphabetique et differents de * et ? **/
{  int i;
  for ( i = 0; i < strlen (Expression); i++)
    {
      if (!
	  ((Expression[i] >= 'a' && Expression[i] <= 'z')|| (Expression[i] >= 'A' && Expression[i] <= 'Z')|| (Expression[i] == '*' || Expression[i] == '?'))){
	return 1;
    }
	else if((Expression[i]==Expression[i+1])&&(Expression[i]=='*'))
         {
             return 1;
         }
    }
  return 0;

}
int requete_vide()/**rends 1 si le resultat de la requete est vide **/
{
FILE *fp=fopen("file2.txt","r");



if (NULL != fp) {
    fseek (fp, 0, SEEK_END);
 int  size = ftell(fp);

    if (0 == size) {
        return 1;
    }else{return 0;}

}
}


/**Programme principal **/
int
main (int argc, char *argv[])
{  /**Variables du programme principal **/
  int Choix;
  int status, temp,temp1,temp2,temp3;
  char cq[2];
  V = malloc (sizeof (Typestr_Tcb));
  V->Champ1 = malloc (2 * sizeof (string2));
  Expression = malloc (255 * sizeof (string255));
  _Px1 = malloc (255 * sizeof (string255));

  printf (" %s",
	  "          @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
  Sleep (100);
  printf (" %s",
	  "          @           ____________________________________________________________________           @\n");
  Sleep (100);
  printf (" %s",
	  "          @@         |                                                                    |         @@\n");
  Sleep (100);
  printf (" %s",
	  "          @@@        |                            Tp -02- ALSDD                           |        @@@\n");
  Sleep (100);
  printf (" %s",
	  "          @@@@       |                                                                    |       @@@@\n");
  Sleep (100);
  printf (" %s",
	  "          @@@@@      |                                                                    |      @@@@@\n");
  Sleep (100);
  printf (" %s",
	  "          @@@@@@     |            IMPLEMENTATION OF LEXICOGRAPHICAL TREE                  |     @@@@@@\n");
  Sleep (100);
  printf (" %s",
	  "          @@@@@@@    |                                                                    |    @@@@@@@\n");
  Sleep (100);
  printf (" %s",
	  "          @@@@@@     |                                                                    |     @@@@@@\n");
  Sleep (100);
  printf (" %s",
	  "          @@@@@      |                                                                    |      @@@@@\n");
  Sleep (100);
  printf (" %s",
	  "          @@@@       |                                                                    |       @@@@\n");
  Sleep (100);
  printf (" %s",
	  "          @@@        |                                                                    |        @@@\n");
  Sleep (100);
  printf (" %s",
	  "          @@         |____________________________________________________________________|         @@\n");
  Sleep (100);
  printf (" %s",
	  "          @                                                                                          @\n");
  Sleep (100);
  printf (" %s",
	  "          @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
  Sleep (100);
  printf (" %s",
	  "                                                                                            \n");
  Sleep (100);
  printf (" %s",
	  "                                                                                            \n");
  printf (" %s",
	  "                                                                                            \n");
    printf ( " %s", "\n________________________________________________________________________________________________________________________\n" ) ;




menu:				/**l'etiquette menu nous permet de se brancher a nouveau au debut apres la lecture du choix.**/
  printf ("\n                          MENU :");
  printf ("%s", "\n");
  printf (" %s",
	  "\n       Veuillez choissir Le mode d'introduction des mots :                      \n");
  printf (" %s",
	  "                                                                                            \n");

  printf ("  %s",
	  "                     1) Mots introduits par saisie.                                         \n");
  printf ("  %s",
	  "                     2) Mots intorduits par fichier                                          \n");
  printf (" %s",
	  "                                                                                            \n");

  printf (" %s", "          Saisissez votre choix s'il vous plait :   ");
  status = scanf ("%d", &Choix); /**************Boucle utilisee afin d'empecher l'utilisateur de faire passer un caractere non pris en charge*************/
  while (status != 1)
    {
      while ((temp = getchar ()) != EOF && temp != '\n');
      printf ("\n\n\tInput invalide ! Donnez un nombre : ");
      status = scanf ("%d", &Choix);/**Introduire le choix de l'utilisateur a nouveau **/
    }


  switch (Choix)		/** L'option de l'introduction des mots **/
    {
    case 1:			/** Par saisie**/
      {


      menusaisie:


	system ("cls");		/** Nettoyer l'interface **/



	printf (" %s",
		"\n   Entrez le nombre de mots que vous voulez inserer : ");
	status = scanf (" %d", &M);
	while (status != 1)
	  {
	    while ((temp = getchar ()) != EOF && temp != '\n');
	    printf ("\n\n\tInput invalide ! Donnez un nombre : ");
	    status = scanf ("%d", &M);
	  }
	printf (" %s", "\n   Entrez la taille maximale des mots :  ");
	status = scanf (" %d", &L);
	while (status != 1)/**Controle de saisie **/
	  {
	    while ((temp = getchar ()) != EOF && temp != '\n');
	    printf ("\n\n\tInput invalide ! Donnez un nombre : ");
	    status = scanf ("%d", &L);
	  }

affiche:	  printf("%s","\n         Afficher les mots generes ?           \n"      );
	  printf("%s","\n           1) Oui   \n");
	  printf("%s","\n           2) Non    \n ");
	  printf("%s","\n           Votre Choix    :   ");
	  scanf("%d",&temp3);
	  switch(temp3)
	  {

	      case 1:
	             printf("%s","\n");
	printf ("%s", "\n   La liste des mots generes :");

	Tete = NULL;
	Generer_mots (&M, &L, &Tete,1);
	R = NULL;
	P = Tete;
	printf (" %s\n", " ");
	break;
          case 2:
              Tete = NULL;
	Generer_mots (&M, &L, &Tete,0);
	R = NULL;
	P = Tete;
	printf (" %s\n", " ");
	break;
          default :
            printf("%s","\n     Veuillez Entrer une valeur valide ");
            goto affiche;


	  }
	  printf("%s","\n");
	        printf ( " %s", "\n________________________________________________________________________________________________________________________\n" ) ;
      printf("%s","\n");

	printf (" %s\n", " ");
	printf (" %s", "\n   Insertion des mots generes dans l'arbre ");
	Sleep (200);
	printf ("%s", ".");
	Sleep (200);
	printf ("%s", ".");
	Sleep (200);
	printf ("%s", ".");
	printf (" %s\n", " ");
	while ((P != NULL))/**Insertion des mots a partir de la liste **/
	  {
	    strcpy (_Px1, Valeur_Ls (P));
	    Insert (&R, &_Px1);
	    P = Suivant_Ls (P);

	  };
	printf (" %s\n", " ");
	printf (" %s",
		"  Verification de la compatibilite de l'arbre cree avec les resultats precedents");
	Sleep (200);
	printf ("%s", ".");
	Sleep (200);
	printf ("%s", ".");
	Sleep (200);
	printf ("%s", ".");
	Sleep (200);
	printf ("%s\n", "");
	printf (" %s", "\n   Voici les mots trouves dans l'arbre : ");
	Affich_arb (&R);
	printf ("\n%s", "");
	printf ("%s", "\n   (Verification terminee avec succes)");/**Liste des mots trouvee identique a celle des mots introduits a la seule difference de l'ordre**/
	printf ("%s", "\n");
    printf ( " %s", "\n________________________________________________________________________________________________________________________\n" ) ;

	printf (" %s", " ");
	printf (" %s", " ");
	Continuer = 1;
	while ((Continuer != 0))
	  {
type:	    printf (" %s",
		    "\n   Veuillez entrer une requete (expression) afin de rechercher des mots dans l'arbre : ");
	      scanf (" %[^\n]", Expression);
	    while (controle_requete (Expression) == 1)
	      {
		printf ("%s   ",
			"\n\n     La requete contient un caractere non pris en charge,Veuillez inserer une nouvelle requete  : ");
		scanf (" %[^\n]", Expression);
	      }




	   // printf (" %s", "\n   Les mots qui verifient la requete  : ");
	    //printf (" %s", Expression);
	    //printf (" %s", " : ");
	    Rech_arb (&R, &Expression);
	     if(requete_vide()==1){
                printf("%s","\n");
            printf("%s","\n            Le resultat de la requete est vide,veuillez reessayer ");
        printf("%s","\n");
            goto type;
	    }
	    fenetres_glissantes(&Tete5,1,Expression);
        remove ("file2.txt");
    printf ( " %s", "\n________________________________________________________________________________________________________________________\n" ) ;
     printf (" %s", "\n");
      printf (" %s", "\n");
	    printf (" %s",
		    "   Voulez vous continuer (1 pour relancer une nouvelle requete , 0 pour revenir au menu principale) : \n");
		     printf (" %s", "\n");
		      printf (" %s", "\n");
    printf ( " %s", "\n________________________________________________________________________________________________________________________\n" ) ;
	    scanf (" %d", &Continuer);
	    printf (" %s", "");
	    system ("cls");

	  };
	break;
      }
    case 2:
      {
	Tete = NULL;
	Tete5 = NULL;
	system ("cls");
      affichage:printf ("%s",
		"\n         Voulez Vous Affficher Le Contenu de fichier ? \n");
	printf ("%s", "\n                 1)Oui       \n ");
	printf ("%s", "\n                 2)Non       \n ");
	printf ("%s", "\n           Votre choix :    ");
	scanf ("%d", &temp);

	switch (temp)
	  {
	  case 1:
	    printf ("%s", "\nLe contenu du fichier  :");
	    mots_fich (&Tete, 1);
	     printf (" %s", "\n");
	      printf (" %s", "\n");
    printf ( " %s", "\n_________________________________________________________________________________________________________________________\n" ) ;
	    break;
	  case 2:
	    mots_fich (&Tete, 2);
	    break;
	  default:
	    printf ("%s",
		    "\n              Veuillez choisir une valeur valide   ");
	    goto affichage;
	    break;
	  }
	R = NULL;
	P = Tete;
	printf (" %s\n", " ");
	printf (" %s", "\n   Insertion des mots generes dans l'arbre ");
	Sleep (200);
	printf ("%s", ".");
	Sleep (200);
	printf ("%s", ".");
	Sleep (200);
	printf ("%s", ".");
	printf (" %s\n", " ");
	while ((P != NULL))/**Insertion des mots dans l'arbre **/	  {
	    strcpy (_Px1, Valeur_Ls (P));
	    Insert (&R, &_Px1);
	    P = Suivant_Ls (P);

	  };
	printf (" %s\n", " ");
	printf (" %s",
		"  Verification de la compatibilite de l'arbre cree avec les resultats precedents");
	Sleep (200);
	printf ("%s", ".");
	Sleep (200);
	printf ("%s", ".");
	Sleep (200);
	printf ("%s", ".");
	Sleep (200);
	printf ("%s\n", "");
	printf (" %s", "\n   Voici les mots trouves dans l'arbre : ");
	Affich_arb (&R);
	printf ("\n%s", "");
	printf ("%s", "\n   (Verification terminee avec succes)");
	printf ("%s", "\n");
	printf ("%s", "\n");
    printf ( " %s", "\n_________________________________________________________________________________________________________________________\n" ) ;
	printf (" %s", " ");
	printf (" %s", " ");
	printf ("%s", "\n");
	Continuer = 1;
	while ((Continuer != 0))
	  {
	    printf ("%s", "\n");
	  requete:printf (" %s",
		    "\n   Veuillez entrer une requete (expression) afin de rechercher des mots dans l'arbre : ");
	    printf (" %s", "");
	    scanf (" %[^\n]", Expression);
	    while (controle_requete (Expression) == 1)
	      {
		printf ("%s   ",
			"\n\n     La requete contient un caractere non pris en charge,Veuillez inserer une nouvelle requete  : ");
		scanf (" %[^\n]", Expression);
	      }


	    //system ("cls");
	     Rech_arb (&R, &Expression);
	    if(requete_vide()==1){
                printf("%s","\n");
            printf("%s","\n            Le resultat de la requete est vide,veuillez reessayer ");
        printf("%s","\n");
            goto requete;
	    }

	  resultrequte:
	    printf ("%s",
		    "\n        Voulez vous Afficher tous les resultats de la requete  ?\n");
	    printf ("%s", "\n                       1) Oui  \n");
	    printf ("%s",
		    "\n                       2) Non(Passer directement a l'affichage par les fenetres glissantes) \n");
	    printf ("%s", "\n                 Votre choix    :     ");
	    scanf ("%d", &temp1);
	    switch (temp1)
	      {
	      case 1:
	          system ("cls");
	           printf (" %s", "\n");
               printf (" %s", "\n");
               printf ( " %s", "\n_________________________________________________________________________________________________________________________\n" ) ;
	           printf ("%s", "\n       ");

	    printf (" %s\n", "");
	    printf ("%s",
		    "\n              Affichage par fenetres glissantes ");
		    printf ("%s", "\n       ");
		    printf ("%s", "\n       ");
    printf ( " %s", "\n________________________________________________________________________________________________________________________\n" ) ;
             fenetres_glissantes(&Tete5,1,Expression);
             remove("file2.txt");
		break;
	      case 2:
	          system ("cls");
	          printf (" %s", "\n");
               printf (" %s", "\n");
               printf ( " %s", "\n_________________________________________________________________________________________________________________________\n" ) ;
	           printf ("%s", "\n       ");

	    printf (" %s\n", "");
	    printf ("%s",
		    "\n              Affichage par fenetres glissantes ");
		    printf ("%s", "\n       ");
		    printf ("%s", "\n       ");
    printf ( " %s", "\n________________________________________________________________________________________________________________________\n" ) ;
             fenetres_glissantes(&Tete5,0,Expression);
              remove("file2.txt");

		break;

	      default:
		printf ("%s",
			"\n          Veuillez saisir une valeur valide     ");

		goto resultrequte;

		break;


	      }




contenu:    printf ( " %s", "\n________________________________________________________________________________________________________________________\n" ) ;
     printf (" %s", "\n");
      printf (" %s", "\n");
	    printf (" %s",
		    "   \nVoulez vous continuer (1 Pour relancer une nouvelle requete , 0 Pour revenir au menu principal) :     ");

		      scanf("%d",&temp2);
		      if(temp2==1)
              {   system ("cls");
                  goto requete;

                  }else if(temp2==0)
                  {   system ("cls");
                     goto menu;

                     }else{

                      printf("%s","\n Veuillez saisir une valeur valide :");
                       goto contenu;

                                 }




    printf ( " %s", "\n________________________________________________________________________________________________________________________\n" ) ;
	  };

	remove ("file2.txt");
	break;
      }

    default:
      {
	printf ("\n\tATTENTION ! Option non exixtente dans le menu!! S'il vous plait choissisez 1 ou 2 la prochaine fois.");	// Avertissement

      }


    }

  printf ("\n\n\tVoulez vous continuer ou quitter le programme? (C Pour continuer(revenir au menu principal), Q POUR QUITTER) : ");	// option pour continuer l'utilisation ou quitter le programme
  scanf ("%s", &cq);		// lecture du choix pour contiuer ou sortir .
  if ((_stricmp (cq, "C") == 0 || _stricmp (cq, "c") == 0))
    {
      system ("cls");
      goto menu;
    }				// si le choix est 'C' ou 'c' on se branche C  l'etiquette menu, sinon on quitte le programme.
  else
    {
      printf ("\n\n\t Merci d'avoir utiliser notre programme!\n\n");
      exit (1);
    }
  return 0;
}
