#ifndef MATRICE_H
#define MATRICE_H
#include <vector>
#include <iostream>
template <typename T> class Matrice
{
private:
    int ligne;
    int colonne;
    std::vector<std::vector<T> > mat;
public:
    Matrice(int ligne1,int colonne1, const T& initial);
    Matrice(const Matrice<T>& aCopier);
    void afficher(const Matrice<T>& modele);
    bool equal(Matrice<T>& modele);
    Matrice<T>& operator=(const Matrice<T>& modele);
    int getLigne();
    int getColonne();
    std::vector<std::vector<T> > getMat();
};

template<typename T>
Matrice<T>::Matrice(int ligne1,int colonne1,const T& initial)
{
mat.resize(ligne1);
for(unsigned i=0;i<mat.size();i++){
    mat[i].resize(colonne1,initial);
}
ligne=ligne1;
colonne=colonne1;
}

template<typename T>
int Matrice<T>::getLigne(){
    return ligne;
}

template<typename T>
std::vector<std::vector<T> > Matrice<T>::getMat(){
    return mat;
}

template<typename T>
void Matrice<T>::afficher(const Matrice<T>& modele){

}


template<typename T>
Matrice<T>::Matrice<T>(const Matrice<T>& aCopier){
    ligne=aCopier.getLigne();
    colonne=aCopier.getColonne();
    mat=aCopier.getMat();
}




template<typename T>
int Matrice<T>::getColonne(){
    return colonne;
}


template<typename T>
bool Matrice<T>::equal(Matrice<T>& model){
    if(!ligne==model.getLigne() || !colonne==model.getColonne())
        return false;
   for(int i=0;i<mat.size();i++)
    {
        for(int k=0;k<mat.size();k++)
       {
            if(mat[i][k]==model.getMat()[i][k])
                return false;
        }
    }
    return true;
}







#endif // MATRICE_H
