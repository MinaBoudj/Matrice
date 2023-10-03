#include<iostream>

using namespace std;

struct tabInt{
    int ** ptab;
    int nbligne, nbcol;
};

using  Matrice = tabInt; //une matrice tableau de 2D

//multiplication de 2 matrice de mm taille
Matrice matriceMult(Matrice mat1, Matrice mat2){
    Matrice s;
    if(mat1.nbcol==mat2.nbligne){//cas ou mult est possible
        for(int i=0; i<mat1.nbcol; i++){
            for(int j=0; j<mat2.nbcol; i++){
                s.ptab[i][j] = 0;
                for(int k=0; k<mat1.nbligne; k++){
                    s.ptab[i][j] += mat1.ptab[i][k] + mat2.ptab[k][j];
                }
            }
        }
    }else{
        cout << "Matrice de dimension differente multiplication impossible" <<endl;
    }
    return s;
}

int main(){
    Matrice mat1, mat2;

    //initalisation des deux matrice
    initMatrice(mat1);
    initMatrice(mat2);

    //affichage des deux matrices
    afficherMatrice(mat1);
    afficherMatrice(mat2);

    
    return 0;
}
