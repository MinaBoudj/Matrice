#include<iostream>
#include<random>

using namespace std;

struct Matrice{
    int nl; //nombre de lignes
    int nc; //nombre de colonnes
    double** tab2d; //tableau de reel
};
//allouer matrice 2d
void allouer(Matrice mat,int  n,int  m){
    mat.tab2d = new double*[m]; //allocation des colonnes  
    for(int i=0; i<m; i++){
        mat.tab2d[i] = new double[n]; //allocations des lignes
    }
}
//construire une matrice nulle de n lignes et m colonnes
Matrice zeros(int n, int m){
    Matrice mat;
    mat.nc = m;
    mat.nl = n;

    mat.tab2d = new double*[m]; //allocation des colonnes  
    for(int i=0; i<m; i++){
        mat.tab2d[i] = new double[n]; //allocations des lignes
    }

    for(int i=0; i<mat.nl; i++){
        for(int j=0; j<mat.nc; j++){
            mat.tab2d[i][j] = 0;
        }
    }
    return mat;
}

//afficher une matrice 
void afficher_mat(Matrice mat){
    cout << "La matrice " << endl;
    for(int i=0; i<mat.nl; i++){
        for(int j=0; j<mat.nc; j++){
            cout << " | " << mat.tab2d[i][j];
        }
        cout << " | " <<endl;
    }
}

//affecter le reel x à une matrice M
//precondition : <= i < M.nl && 0<= j < M.nc
void affecte_coeff(Matrice &M, int i, int j, double x){
    M.tab2d[i][j] *=x; 
}

//renvoie la valeur de la matrice[i][j]
//precontion : <= i < M.nl && 0<= j < M.nc
double coeff(Matrice M, int i, int j){
    return M.tab2d[i][j];
}

//construire la matrice identite de taille n
Matrice identite(int n){
    Matrice mat;
    mat.nc = n;
    mat.nl = n;
    mat.tab2d = new double*[n]; //allocation des colonnes  
    for(int i=0; i<n; i++){
        mat.tab2d[i] = new double[n]; //allocations des lignes
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j)
                mat.tab2d[i][j] = 1;
            else 
                mat.tab2d[i][j] = 0;
        }
    }
    return mat;
}

//la somme de matrice 
Matrice somme(Matrice A, Matrice B){
    Matrice mat;

    if(A.nc == B.nc && A.nl == B.nl){//somme possible
        for(int i=0; i<A.nl; i++){
            for(int j=0; j<A.nc; j++){
                mat.tab2d[i][j] = A.tab2d[i][j] + B.tab2d[i][j];
            }
        }
    }
    return mat;
}

//la multiplication de matrice
Matrice multiplication(Matrice A, double x){
    Matrice mat;

    for(int i=0; i<A.nl; i++){
        for(int j=0; j<A.nc; j++){
            mat.tab2d[i][j] = A.tab2d[i][j]*x;
        }
    }
    return mat;
}

//le produit de deux matrice 
Matrice produit(Matrice A, Matrice B){
    Matrice mat;
    double som;
    if(A.nc == B.nl){//somme possible
        for(int i=0; i<A.nl; i++){
            for(int j=0; j<B.nc; j++){
                som = 0;
                for(int k=0; k<A.nl; k++){
                    som  += A.tab2d[i][k] * B.tab2d[k][j];
                }
                mat.tab2d[i][j] = som;
            }
        }
    }
    return mat;
}

//construire une matrice de dimensions (n,m) avec coefficient aléatoire
Matrice hasard(int n, int m){
    Matrice mat = zeros(n, m);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            mat.tab2d[i][j] = (double)(rand()/((double)RAND_MAX +1.0));
        }
    }
    return mat;
}

//liberer la memoire 
void libere(Matrice & M){
    for(int i = 0; i < M.nc; i++ ){
        delete [] M.tab2d[i]; //desallouer premiere dimension
    }

    delete[] M.tab2d;   //desallouer la deuxieme dimension
}

int main(){
    Matrice mat, mat2;

    mat = zeros(2, 3);
    mat2 = zeros(3,4);
    afficher_mat(mat);
    afficher_mat(mat2);
    cout << endl;

    mat = identite(4);
    afficher_mat(mat);
    cout << endl;
    libere(mat);
    libere(mat2);
    return 0;
}