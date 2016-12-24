#include<stdlib.h>
#include<stdio.h>


void initialiseMat(int max){
    
    
    int mat[100][100];
    // initilisation de la ligne
    for (int i=1; i<max+1 ; i++){
        mat[0][i]=i;
    }
    for (int i=1; i<max+1 ; i++){
        mat[i][0]=i;
    }
    
    for (int i=1; i<max+1 ; i++){
        for (int j=1; j<max+1 ; j++){
            printf("donne la valeur de mat[%d][%d] \n ",i-1,j-1);
            
            scanf("%d",&mat[i][j]);
        }
        
    }
    
        for (int i=0; i<max+1 ; i++){
            for (int j=0; j<max+1 ; j++){
                printf("%d ",mat[i][j]);
            }
            printf(" \n");
        }
    
    
    
    
    int vect1[2][max];
    int som=0;
    
    
    //initialisation du vecteur 1
    
    
    for (int i=1; i<max+1 ; i++){
        for (int j=1; j<max+1 ; j++){
            if (mat[i][j]){
                som++;
            }
        }
        vect1[0][i-1]=som;
        vect1[1][i-1]=i;
        som=0;
        
    }
    //affichage de vecteur 1
    
    printf("*******************************************\n");
    printf("les degerts :");
    for (int i=0; i<max ; i++){
        printf("- %d -",vect1[0][i]);
        
    }
    printf("\n");
    
    printf("les sommets :");
    for (int i=0; i<max ; i++){
        printf("- %d -",vect1[1][i]);
        
    }
    printf("\n");
    
    
    
    
    int a=0;
    int b=0;
    int vect2[2][max];
    
    // initialisation du vecteur 2
    for (int i=0; i<max ; i++){
        vect2[0][i]=vect1[0][i];
        vect2[1][i]=vect1[1][i];
    }
    
    //trie du vecteur 2 par odre decroisant
    for (int i=0; i<max ; i++){
        
        for (int j=i+1; j<max ; j++){
           
            if (vect2[0][i]<vect2[0][j]){
                
                a=vect2[0][i];
                vect2[0][i]=vect2[0][j];
                vect2[0][j]=a;
                
                b=vect2[1][i];
                vect2[1][i]=vect2[1][j];
                vect2[1][j]=b;
                
            }
            
        }
        
    }
    
    printf("*******************************************\n");
    printf("apres le trie \n");
    //affichage de vecteur 2
    
    printf("les degerts :");
    for (int i=0; i<max ; i++){
        printf("- %d -",vect2[0][i]);
        
    }
    
    printf("\n");
    
    printf("les sommets :");
    for (int i=0; i<max ; i++){
        printf("- %d -",vect2[1][i]);
        
    }
    
    printf("\n");
    
    int vectcolor[2][max];
    int color=0;
    //mise a 0 du vecteurcolore
    for (int i=0; i<max ; i++){
        
        vectcolor[0][i]=0;
        vectcolor[1][i]=vect2[1][i];
    }
    
    
    for (int i=0; i<max ; i++){
        
        if(vectcolor[0][i]==0){
            color++;
            vectcolor[0][i]=color;
        }
        
        for (int j=i+1; j<max ; j++){
            // si il ne sont pas adjacent
            if (!mat[vect2[1][i]][vect2[1][j]]){
                vectcolor[0][j]=color;
            }
        }
        
        
        
    }
    
    //affichage de vecteurcolor
    
    printf("*******************************************\n");
    printf(" affichagedu vecteur color \n");
    printf("les couleur :");
    for (int i=0; i<max ; i++){
        printf("- %d -",vectcolor[0][i]);
        
    }
    printf("\n");
    printf("les sommets :");
    for (int i=0; i<max ; i++){
        printf("- %d -",vectcolor[1][i]);
        
    }
    
    printf("\n");
    
    printf("le nombre de couleur est %d \n",color);

}

int main(int argc, char *argv[]){
    
    printf("donnez le nombre de sommet pour le graphe");
    
    int nbrS;
    scanf("%d",&nbrS);
    printf("*******************************************\n");
    
    initialiseMat(nbrS);
    
}
