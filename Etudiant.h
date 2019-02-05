#pragma once
#include <iostream>
using namespace std;

class CEtudiant
{
public:
	CEtudiant(); //constructeur par d�faut
	~CEtudiant();//destructeur
private:
	// Nom de l'�tudiant
	char* m_pNom;
	// Num�ro de l'�tudiant
	int m_Numero;
	// Nombre de notes
	int m_Nb_notes;
	// Tableau de notes
	double* m_pNotes;
public:
	// Calcul de la moyenne
	double Moyenne();
private:
	// la valeur moyenne
	double m_Moyenne;
public:
	CEtudiant(char* nom, int numero, int nombre_notes);

	//fonctions amies
	friend istream& operator >> (istream& is, CEtudiant& E);
	friend ostream& operator << (ostream& os, CEtudiant& E);
};

